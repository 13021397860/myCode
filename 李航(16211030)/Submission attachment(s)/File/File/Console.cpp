#include "Console.h"
#include "ObligatoryCourse.h"
#include "Course.h"
#include "ElectiveCourse.h"
#include <iostream>
#include "Student.h"
#include <string>
#include <fstream>
#include "Exception.h"
int Console::classID() const {
	return ClassID;
}
Console* Console::myConsole = nullptr;
Console::Console(){
	buildCourse();
	buildStudent();
}
Console::~Console(){
	for (int i = 0; i < ocNum; i++) {
		if (oc[i] != nullptr) {
			delete oc[i];
		}
	}
	for (int i = 0; i < ecNum; i++) {
		if (ec[i] != nullptr) {
			delete ec[i];
		}
	}
	if (student != nullptr) {
		delete student;
	}
}
int Console::run() {
	char ops;
	int del;
	char again;
	do {
		displayMenu();
		int con = 1;
		int oper = 0;
		do {
			std::cin >> ops;
		} while (check());
		switch (ops) {
		case 'A':
			std::cout << *student;
			do {
				std::cout << "OC[1] or EC[2]:";
				do {
					std::cin >> oper;
					if (!check() && oper != 2 && oper != 1) {
						OORException ex(ClassID);
						throw ex;
					}
				} while (check() || (oper != 2 && oper != 1));
				std::cout << std::endl;
				selectCourse(oper);
				std::cout << "Continue[1] or Not[0]";
				do {
					std::cin >> con;
					if (!check() && con != 0 && con != 1) {
						OORException ex(ClassID);
						throw ex;
					}
				} while (check()||(con != 0 && con != 1));
				std::cout << std::endl;
			} while (con != 0);
			break;
		case 'R':
			std::cout << *student;
			do {
				std::cout << "输入删除的课程序号（输入0退出删除）:";
				do {
					std::cin >> del;
				} while (check());
				try {
					student->removeCourse(del);
				}
				catch (MyException& ex) {
					ex.show();
				}
				std::cout << *student;
			} while (del != 0);
			break;
		case 'S':
			setCourseScore();
			break;
		case 'C':
			int cale;
			try {
				cale=student->caleCredit();
			}
			catch (MyException& ex) {
				ex.show();
				cale = -1;
			}
			if (student != nullptr && cale!=-1) {
				
				std::cout << "绩点成绩："<<cale << std::endl;
			}
			break;
		case 'F': {
			std::cout << "请输入文件位置：";
			std::string fName;
			do {
				std::cin.clear();
				std::cin >> fName;
			} while (check());
			std::ofstream outputf(fName);
			while (!outputf) {
				FTUIException ex(ClassID);
				throw ex;
				std::cin.clear();
				std::cin >> fName;
				if (check()) {
					//std::cout << "输入错误！请重新输入！\n";
				}
				else {
					outputf.open(fName);
				}
			}
			outputf << *student;
			break;
		}
		default:
			FTUIException ex(ClassID);
			throw ex;
			break;
		}
		std::cout << "Again?[Y/N]:";
		do{
			std::cin.clear();
			std::cin >> again;
			if (!check() && again != 'Y' && again != 'N') {
				FTUIException ex(ClassID);
				throw ex;
			}
		}while (check() || (again != 'Y' && again != 'N'));
	} while (again=='Y');
	return 0;
}
Console* Console::creatConsole() {
	if (myConsole == nullptr) {
		myConsole = new Console;
		return myConsole;
	}
	else {
		return myConsole;
	}
}
int Console::displayMenu()const {
	std::cout << "Add Course[A]  Remove Course[R]  Set Grade[S] Get CaleScore[C] Save Information to File[F]" << std::endl;
	return 0;
}
bool Console::buildStudent() {
	if (student == nullptr) {
		int ID;
		char name[100];
		int year, month, day;
		std::cout << "Student`s ID: ";
		do{
			std::cin >> ID;
		} while (check());
		std::cout << "Student`s name: ";
		do {
			std::cin >> name;
		} while (check());
		std::cout << "Student`s birthday: ";
		do {
			std::cin >> year >> month >> day;
		} while (check());
		Date birthday(year, month, day);
		student=new Student(ID, name, birthday);
		return true;
	}
	return false;
}
const Console& Console::buildCourse() {
	ocNum = ecNum = 0;
	std::cout << "请输入必修课文件位置：";
	std::string tempOfName;
	int tempOfCredit;
	do {
		std::cin >> OClassFile;
	} while (check());
	std::cout << "请输入选修课文件位置：";
	do {
		std::cin >> EClassFile;
	} while (check());
	std::ifstream OFile(OClassFile);
	std::ifstream EFile(EClassFile);
	for (; ocNum <= MAX_SIZE && OFile >> tempOfName >> tempOfCredit; ocNum++) {
		if (ocNum == MAX_SIZE) continue;
		oc[ocNum]=new ObligatoryCourse(tempOfName, tempOfCredit);
	}
	if (ocNum > MAX_SIZE) {
		IOOBException ex(ClassID);
		throw ex;
	}
	for (; ecNum <= MAX_SIZE && EFile >> tempOfName >> tempOfCredit; ecNum++) {
		if (ecNum == MAX_SIZE) continue;
		ec[ecNum] = new ElectiveCourse(tempOfName, tempOfCredit);
	}
	if (ecNum > MAX_SIZE) {
		IOOBException ex(ClassID);
		throw ex;
	}
	return *this;
}
const void Console::selectCourse(int op) {
	int courseNumber;
	if (op == 1) {
		for (int i = 0; i < ocNum; i++) {
			std::cout << *oc[i] << "[" << i << "]" << std::endl;
		}
		bool ok = false;
		do {
			std::cin >> courseNumber;
			ok = false;
			if (courseNumber >= ocNum || courseNumber < 0) {
				std::cout << "输入不在范围内！\n";
				ok = true;
			}
		} while (check() || ok);
		try {
			student->addCourse(*oc[courseNumber]);
		}
		catch (MyException& ex) {
			ex.show();
		}
	}
	else if (op == 2) {
		for (int i = 0; i < ecNum; i++) {
			std::cout << *ec[i] << "[" << i << "]" << std::endl;
		}
		bool ok = false;
		do {
			std::cin >> courseNumber;
			ok = false;
			if (courseNumber >= ecNum || courseNumber < 0) {
				std::cout << "输入不在范围内！\n";
				ok = true;
			}
		} while (check() || ok);
		try {
			student->addCourse(*ec[courseNumber]);
		}
		catch (MyException& ex) {
			ex.show();
		}
	}
	std::cout << *student;
}
bool Console::setCourseScore() {
	int changegrade,Og;
	char Eg;
	do {
		std::cout << *student;
		std::cout << "输入修改成绩编号（输入0结束）：";
		bool ok;
		do {
			ok = false;
			std::cin >> changegrade;
			if (changegrade > student->getCourseNumber() || changegrade < 0) {
				std::cout << "输入不在范围内!\n";
				ok = true;
			}
		} while (check() || ok);
		if (changegrade != 0) {
			try {
				student->getCourse(changegrade);
			}
			catch (MyException& ex) {
				ex.show();
				continue;
			}
			if (typeid(student->getCourse(changegrade)) == typeid(ElectiveCourse)) {
				std::cout << "输入新成绩(A,B,C,D,E)：";
				do{
					std::cin >> Eg;
				} while (check());
				student->changeGrade(changegrade, Eg);
			}
			else if (typeid(student->getCourse(changegrade)) == typeid(ObligatoryCourse)) {
				std::cout << "输入新成绩：(数字)";
				do {
					std::cin >> Og;
				} while (check());
				student->changeGrade(changegrade, Og);
			}
			student->printGrade(changegrade);
		}
	} while (changegrade != 0);
	return true;
}
bool Console::check() {
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		return true;
	}
	std::cin.clear();
	return false;
}
