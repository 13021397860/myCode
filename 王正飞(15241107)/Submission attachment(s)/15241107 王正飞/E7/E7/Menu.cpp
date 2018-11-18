#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

#include "Menu.h"
#include "Exception.h"

#define MaxCourse 100

using namespace std;

ObligatoryCourse obligatory_course[MaxCourse];
ElectiveCourse elective_course[MaxCourse];

ifstream obligatory_course_file("files/ObligatoryCourse.txt", ios::in);
ifstream elective_course_file("files/ElectiveCourse.txt", ios::in);

int input, obligatory_course_num, elective_course_num;
string str;
Course *course;
bool running = true, student_prepared = false;

Student *student = new Student();

const void Menu::MainMenu()
{
	obligatory_course_num = elective_course_num = 0;
	LoadCourse();
	while (running)
	{
		try { PrepareStudent(); Operation(); }
		catch (Exception exception) { CutOffRule(); cout << exception.what() << endl; };
	}
}

const void Menu::InputStudentInformation()
{
	int input_year, input_month, input_date;
	cout << "Please input your name: "; getline(cin, str); student->SetName(str);
	while (1)
	{
		cout << "Please input your birth year:  "; InputOption(input_year);
		cout << "Please input your birth month: "; InputOption(input_month);
		cout << "Please input your birth date:  "; InputOption(input_date);
		student->SetBirthday(input_year, input_month, input_date);
		if (student->isCorrectBirthday()) break;
		throw Exception("TIME");
	}
	cout << endl;
}

const void Menu::Operation()
{
	CutOffRule();
	cout << "Please input your operation:\n0.Choose course\n1.View my state\n2.Remove course\n3.Motify score\n4.Save\n5.Load\n6.Exit\n";
	InputOption(input);
	switch (input)
	{
	case 0: ChooseCourse(); break;
	case 1:	ViewState(); break;
	case 2: RemoveCourse(); break;
	case 3: MotifyScore(); break;
	case 4: Save(); break;
	case 5: Load(); break;
	case 6: Exit(); break;
	default: throw Exception("OPTION"); break;
	}
}

const void Menu::ChooseCourse()
{
	CutOffRule();
	cout << "Please input the type of the course you want to choose:\n0.Obligatory Course\n1.Elective Course\n";
	InputOption(input);
	switch (input)
	{
	case 0: ChooseObligatoryCourse(); break;
	case 1: ChooseElectiveCourse(); break;
	default: throw Exception("OPTION"); break;
	}
}

const void Menu::ViewState()
{
	CutOffRule();
	cout << *student;
}

const void Menu::RemoveCourse()
{
	CutOffRule();
	if (!student->GetCourseNumber()) throw Exception("The student has no courses");
	else
	{
		cout << "Please input the course you want to remove:\n";
		student->ShowCurrentCourse();
		InputOption(input);
		if (student->RemoveCourse(input)) cout << "Course removed successfully\n";
		else throw Exception("OPTION");
	}
}

const void Menu::Exit()
{
	running = false;
}

const void Menu::ChooseObligatoryCourse()
{
	CutOffRule();
	cout << "Please input the obligatory course you want to choose:\n";
	for (int i = 0;i < obligatory_course_num;i++) cout << i << "." << obligatory_course[i] << endl;
	InputOption(input);
	if (input < 0 || input >= elective_course_num) throw Exception("OPTION");
	course = new ObligatoryCourse(obligatory_course[input]);
	student->AddCourse(course);
}

const void Menu::ChooseElectiveCourse()
{
	CutOffRule();
	cout << "Please input the elective course you want to choose:\n";
	for (int i = 0;i < elective_course_num;i++) cout << i << "." << elective_course[i] << endl;
	InputOption(input);
	if (input < 0 || input >= elective_course_num) throw Exception("OPTION");
	course = new ElectiveCourse(elective_course[input]);
	student->AddCourse(course);
}

const void Menu::MotifyScore()
{
	CutOffRule();
	if (!student->GetCourseNumber()) throw Exception("The student has no courses");
	cout << "Please input the course whose score you want to motify:\n";
	student->ShowCurrentCourse();
	InputOption(input);
	if (input < 0 || input >= student->GetCourseNumber() || !student->SetCourseScore(input)) throw Exception("OPTION");
	cout << "Score motified successfully\n";
}

const void Menu::CutOffRule()
{
	cout << "----------------------------------------\n";
}

const void Menu::LoadCourse()
{
	if (!obligatory_course_file || !elective_course_file) cout << "The files cannot be opened\n";
	else
	{
		string input_name; int input_credit_hour, input_mark; char input_grade;
		while (obligatory_course_file >> input_name >> input_credit_hour >> input_mark)
			obligatory_course[obligatory_course_num++] = ObligatoryCourse(input_name, input_credit_hour, input_mark);
		while (elective_course_file >> input_name >> input_credit_hour >> input_grade)
			elective_course[elective_course_num++] = ElectiveCourse(input_name, input_credit_hour, input_grade);
	}
}

const void Menu::Save()
{
	CutOffRule();
	ofstream student_file("files/Student.txt", ios::trunc);
	if (!student_file) cout << "Save failed\n";
	else
	{
		student_file << *student;
		cout << "Saved successfully\n";
	}
}

const void Menu::Load()
{
	CutOffRule();
	ifstream student_file("files/Student.txt", ios::in);
	if (!student_file) cout << "Loaded failed\n";
	else
	{
		string file, input_str, input_name = "", course_name, course_credit_hour, course_grade;
		int input_year, input_month, input_date;
		stringstream temp;
		bool course_content = false, full_name = false;
		while (student->GetCourseNumber()) student->RemoveCourse(0);
		while (student_file >> file)
		{
			if (file == "Name:")
			{
				if (!course_content)
				{
					while (!full_name)
					{
						student_file >> input_str;
						input_name += input_str;
						if (input_str[input_str.length() - 1] == ',') full_name = true;
						else input_name += ' ';
					}
					student->SetName(input_name.substr(0, input_name.length() - 1));
					course_content = true;
				}
				else
				{
					student_file >> input_str;
					course_name = input_str.substr(0, input_str.length() - 1);
					while (student_file >> input_str) if (input_str == "Hour:") { student_file >> course_credit_hour; break; }
					while (student_file >> input_str) if (input_str == "Grade:") { student_file >> course_grade; break; }
					stringstream shour, sgrade;
					int thour, tgrade;
					shour << course_credit_hour.substr(0, course_credit_hour.length() - 1);
					shour >> thour;
					sgrade << course_grade;
					sgrade >> tgrade;
					for (int i = 0;i < obligatory_course_num;i++)
						if (obligatory_course[i].GetName() == course_name)
						{
							course = new ObligatoryCourse(course_name, thour, tgrade);
							student->AddCourse(course);
						}
					for (int i = 0;i < elective_course_num;i++)
						if (elective_course[i].GetName() == course_name)
						{
							course = new ElectiveCourse(course_name, thour, tgrade);
							student->AddCourse(course);
						}
				}
			}
			else if (file == "Birthday:")
			{
				student_file >> input_str;
				for (int i = 0;i < input_str.length();i++) if (input_str[i] == '-') input_str[i] = ' ';
				temp << input_str;
				temp >> input_year >> input_month >> input_date;
				student->SetBirthday(input_year, input_month, input_date);
			}
		}
		cout << "Loaded successfully\n";
	}
}

const void Menu::PrepareStudent()
{
	if (student_prepared) return;
	cout << "Do you want to load the original file:\n0.Yes\n1.No\n";
	InputOption(input);
	switch (input)
	{
	case 0:	Load(); break;
	case 1: InputStudentInformation(); break;
	default: throw Exception("OPTION"); break;
	}
	student_prepared = true;
}

const bool Menu::InputOption(int &input_option)
{
	string option; bool legal = false;
	while (!legal)
	{
		if (getline(cin, option))
		{
			if (option == "") continue;
			legal = true;
			for (int i = 0;i < option.length();i++)
				if (!isdigit(option[i]))
				{
					if (i == 0 && option[i] == '-') continue;
					cout << "Please enter an integer, try again\n";
					legal = false;
					break;
				}
		}
		else return false;
	}
	stringstream temp;
	temp << option;
	temp >> input_option;
	return true;
}