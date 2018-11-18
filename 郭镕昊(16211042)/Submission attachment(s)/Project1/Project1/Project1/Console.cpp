#include "Console.h"
#include "Student.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Date.h"
#include "MyException.h"
#include<typeinfo>
#include<iostream>
#include<fstream>

using namespace std;

Console::Console()
{
	ocNumber = ecNumber = 0;
}

Console::~Console()
{
	//puts("start destruction");
	if (student != NULL) delete student;
	//puts("student deleted");
	for (int i = 0; i < ocNumber; i++)
	{
		delete oc[i];
	}
	for (int i = 0; i < ecNumber; i++)
	{
		delete ec[i];
	}
	//puts("ec destructor");*/
}

int Console::run() {
	buildCourse();
	buildStudent();

	char filename[300];
	ofstream *ofile;

	int choice = displayMenu();
	while (choice) {
		switch (choice)
		{
			case 1:
			case 2:
				student->addCourse(selectCourse(choice));
				break;
			case 3:
				cout << *student;
				break;
			case 4:
				setCourseScore();
				break;
			case 5:
				cout << "Please Input Filename.\n";
				cin >> filename;
				ofile = new ofstream(filename);
				if (ofile == NULL) {
					cerr << "Cannot create such a file!\n";
					break;
				}
				(*ofile) << *student;
				ofile->close();
				delete ofile;
				break;
			default:
				cerr << "Wrong input.\n";
				break;
			//case 5:string coursename; cin << coursename;student->remove(coursename);

		}
		choice = displayMenu();
	}
	return 0;
}

int Console::displayMenu() const
{
	int option = 0;
	cout << "Menu:\n"
		<< "\t 1. ObligatoryCourse\n"
		<< "\t 2. ElectiveCourse\n"
		<< "\t 3. Get student' s infomation\n"
		<< "\t 4. Set score\n"
		<< "\t 5. Save achievement\n"
		<< "\t 0. Exit\n";
	// << "\t 5. remove course\n"
	cout << "Please input your choice:";
	cin >> option;
	return option;
}

Course * Console::selectCourse(int op)
{
	int choice = 0;
	switch (op)
	{
		case 1:
			cout << "Please choose obligatory course:\n";
			for (int i = 0; i < ocNumber; i++)
			{
				cout << "\t " << i + 1 << ". " << *oc[i] << '\n';
			}
			cout << "\t 0. cancel\n";
			cin >> choice;
			if (choice != 0) return oc[choice - 1];
			break;
		case 2:
			cout << "Please choose elective course:\n";
			for (int i = 0; i < ecNumber; i++)
			{
				cout << "\t " << i + 1 << " " << *ec[i] << '\n';
			}
			cout << "\t 0. cancel\n";
			cin >> choice;
			if (choice != 0) return ec[choice - 1];
			break;
		default:
			break;
	}
	return NULL;
}

bool Console::setCourseScore()
{
	int mark = 0;
	char grade = '\0';
	for (int i = 0; i < student->getCourseNumber(); i++) {
		if (typeid(ObligatoryCourse) == typeid((*student)[i])) {
			cout << "必修课程“" << (*student)[i].getName() << "”的成绩(0-100)：";
			while (1) {
				try {
					cin >> mark;
					dynamic_cast<ObligatoryCourse&>((*student)[i]).setMark(mark);
					break;
				}
				catch (MyException ex) {
					cout << "格式错误，必修课程“" << (*student)[i].getName() << "”的成绩(0-100)：";
				}
			}
		}
		else if (typeid(ElectiveCourse) == typeid((*student)[i])) {
			cout << "选修课程“" << (*student)[i].getName() << "”的成绩(A-E)：";
			while (1) {
				try {
					cin >> grade;
					dynamic_cast<ElectiveCourse&>((*student)[i]).setGrade(grade);
					break;
				}
				catch (MyException ex) {
					cout << "格式错误，选修课程“" << (*student)[i].getName() << "”的成绩(A-E)：";
				}
			}
		}
		else {
			return 0;
		}
	}
	return 1;
}

Console & Console::buildStudent()
{
	char *name = new char[30];
	int y, m, d;
	cout << "请输入学生姓名和出生年月日，并以空格分离：\n";
	cin >> name;
	while (1) {
		cin >> y >> m >> d;
		try {
			Date birth(y, m, d);
			student = new Student(name, y, m, d);
			break;
		}
		catch (MyException ex) {
			cout << "格式错误，输入合法生日日期: \n";
		}
	}
	return *this;
}

Console & Console::buildCourse()
{
	char filename[] = ".\\data\\CourseList.txt";
	ifstream ifile(filename);
	int catalog, credit;
	string cname;
	ocNumber = ecNumber = 0;
	if (!ifile) return *this;
	while (ifile >> catalog >> cname >> credit) {
		switch (catalog)
		{
		case 1:
			oc[ocNumber++] = new ObligatoryCourse(cname, credit);
			break;
		case 2:
			ec[ecNumber++] = new ElectiveCourse(cname, credit);
			break;
		default:
			break;
		}
	}
	ifile.close();
	/*ocNumber = 3;
	oc[0] = new ObligatoryCourse("math", 5);
	oc[1] = new ObligatoryCourse("c++", 5);
	oc[2] = new ObligatoryCourse("physics", 4);
	ecNumber = 3;
	ec[0] = new ElectiveCourse("Music", 2);
	ec[1] = new ElectiveCourse("Education", 2);
	ec[2] = new ElectiveCourse("Self rescue", 1);
	//ifile.close();*/
	return *this;
}
