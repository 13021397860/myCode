


#include "stdafx.h"

#include"Console.h"
#include<cstring>
#include<iostream>
#include<cstdio>
#include "Date.h"
#include "Student.h"
#include<fstream>
#include"MyException.h"

using namespace std;

int Console::run(void) {

	int op;
	Course* course;
	string name; int t, y, m, d, si; bool flag = true; string str;
	char stuname[100] = { 0 };
	y = -1; m = 0; d = 0;
	name = "";
	Course *courseList[100];
	int coursenum = 0;

	cout << "请输入学生姓名: " << endl;
	cin >> stuname;

	cout << "请输入学生出生年月日（例: 2000 1 1）" << endl;
	while (!(y >= 0 && m > 0 && d > 0)) {
		try {
			cin >> y >> m >> d;
			if (cin.fail()) { throw MyException(MyException::EXPECTION_DATE); }
			else if (!(y >= 0 && m > 0 && d > 0)) { throw MyException(MyException::EXPECTION_DATE); }
		}
		catch (MyException e) {
			cout << e << endl;
			cin.clear();
			cin.ignore();
			//cout << "请[重新]输入学生出生年月日（例: 2000 1 1）" << endl;
		}
	}

	Student s(stuname, new Date(y, m, d));
	fstream f;
	string str2, type;
	char score;

	while (true) {
		try {
			cout << "1.输出学生信息 2.添加备选课程 3.删除备选课程 4.选课 5.退选 6.指定课程成绩 7.查询学生总成绩与绩点" << endl << "8.保存备选课程到文件 9.从文件恢复备选课程" << endl << "10.保存学生信息到文件 11.从文件恢复学生信息 0.退出程序" << endl;
			cin >> op;
			if (cin.fail())throw MyException();
			switch (op)
			{
			case 1:
				cout << s << endl;
				break;
			case 2:
				cout << "1.必修课 2.选修课" << endl;
				cin >> op;
				if (cin.fail())throw MyException();
				cout << "请输入：课程名 学分" << endl;
				if (op == 1) {
					cin >> name >> t;
					if (cin.fail())throw MyException();
					course = new ObligatoryCourse(name, t);
					courseList[++coursenum] = course;
					//s.addCourse(course);
				}
				else if (op == 2) {
					cin >> name >> t;
					if (cin.fail())throw MyException();
					course = new ElectiveCourse(name, t);
					courseList[++coursenum] = course;
					//s.addCourse(course);
				}
				else {
					cout << "非法输入" << endl;
				}
				break;
			case 3:
				cout << "您希望删除第几门备选课程？" << endl;
				cin >> t;
				if (cin.fail())throw MyException();
				if (t > 0 && t <= coursenum) {
					for (int i = t; i < coursenum - 1; i++) {
						courseList[i] = courseList[i + 1];
					}
					coursenum--;
				}
				else {
					cout << "删除失败，当前只有" << coursenum << "门备选课!" << endl;
					throw MyException(MyException::EXPECTION_OVERFLOW);
				}

				break;
			case 4:
				cout << "备选课程如下：" << endl;
				for (int i = 1; i <= coursenum; i++) {
					cout << "课程" << i << ": " << *(courseList[i]) << endl;
				}
				cout << "请输入您想选第几门课程：" << endl;
				cin >> t;
				if (cin.fail())throw MyException();
				if (t > 0 && t <= coursenum) {
					if (typeid(*(courseList[t])).name() == typeid(ObligatoryCourse).name()) {
						course = new ObligatoryCourse(courseList[t]->getName(), courseList[t]->getCreditHour());
						s.addCourse(course);
					}
					if (typeid(*(courseList[t])).name() == typeid(ElectiveCourse).name()) {
						course = new ElectiveCourse(courseList[t]->getName(), courseList[t]->getCreditHour());
						s.addCourse(course);
					}
					cout << "选课成功！" << endl;
				}
				else {
					cout << "选课失败，当前只有" << coursenum << "门备选课!" << endl;
					throw MyException(MyException::EXPECTION_OVERFLOW);
				}
				break;
			case 5:
				cout << "请输入想删除已选的第几门课程：" << endl;
				cin >> t;
				if (cin.fail())throw MyException();
				if (s.removeCourse(t)) {
					cout << "删除成功!" << endl;
				}
				else {
					cout << "删除失败，当前学生只有" << s.getCourseCount() << "门课!" << endl;
					throw MyException(MyException::EXPECTION_OVERFLOW);
				};
				break;
			case 6:
				cout << "请输入课程序号与成绩:（例： 必修课:1 100 选修课:1 A）" << endl;

				cin >> y >> str;
				if (cin.fail())throw MyException();
				flag = true;

				for (int i = 0; i < str.length(); i++) {
					if (str[i] > '9' || str[i] < '0') {
						flag = false;
						break;
					}
				}
				if (flag) {
					si = 0;
					for (int i = 0; i < str.length(); i++) {
						si *= 10;
						si += str[i] - '0';
					}
					if (s.setScore(y, si)) {
						cout << "设置成功" << endl;
					}
					else {
						cout << "设置失败! 请确认: 1.课程序号是否正确 2.必修课只能使用整形分数，选修课只能使用A、B、C、D、E" << endl;
						throw MyException(MyException::EXPECTION_GRADE);
					}
				}
				else {
					if (s.setScore(y, str[str.length() - 1])) {
						cout << "设置成功" << endl;
					}
					else {
						cout << "设置失败! 请确认: 1.课程序号是否正确 2.必修课只能使用整形分数，选修课只能使用A、B、C、D、E" << endl;
						throw MyException(MyException::EXPECTION_GRADE);
					}
				}

				break;
			case 7:
				cout << s << endl;
				cout << "绩点:" << s.calcCredit() << endl << endl;
				break;
			case 8:
				f.open("course.txt", ios::out);
				for (int i = 1; i <= coursenum; i++) {
					f << *(courseList[i]) << endl;
				}
				f.close();
				cout << "保存到course.txt成功" << endl;
				break;
			case 9:
				f.open("course.txt", ios::in);
				coursenum = 0;
				while (f >> str2) {
					f >> name;
					f >> str2;
					f >> y;
					f >> str2;
					f >> str2;
					f >> type;
					if (type == "必修课") {
						course = new ObligatoryCourse(name, y);
						courseList[++coursenum] = course;
					}if (type == "选修课") {
						course = new ElectiveCourse(name, y);
						courseList[++coursenum] = course;
					}
				}
				f.close();
				break;
			case 10:
				f.open("student.txt", ios::out);
				f << s;
				f.close();
				cout << "保存到student.txt成功" << endl;
				break;
			case 11:
				f.open("student.txt", ios::in);
				f >> str2;
				f >> stuname;
				s.SetName(stuname);
				f >> str2;
				f >> y >> m >> d;
				s.SetBirthday(new Date(y, m, d));
				while (s.getCourseCount())s.removeCourse(1);
				f >> str2;
				d = 0;
				while (f >> str2) {
					d++;
					f >> name;
					f >> str2;
					f >> y;
					f >> str2;
					f >> m;
					f >> type;
					// >> str2 >> y >> str2 >> m >> str2;
					//cout << name << y<<m << type << endl;
					if (type == "必修课") {
						course = new ObligatoryCourse(name, y);
						s.addCourse(course);
						s.setScore(d, m);
					}
					if (type == "选修课") {
						course = new ElectiveCourse(name, y);
						s.addCourse(course);
						switch (m) {
						case 95:
							score = 'A';
							break;
						case 85:
							score = 'B';
							break;
						case 75:
							score = 'C';
							break;
						case 65:
							score = 'D';
							break;
						case 55:
							score = 'E';
							break;
						default:
							score = 'F';
							break;
						}
						s.setScore(d, score);
					}
				}



				cout << "从student.txt恢复成功" << endl;
				f.close();
				break;
			case 0:
				return 0;
			default:
				cout << "非法输入" << endl;
				throw MyException();
				break;
			}
		}
		catch (MyException e) {
			cout << e << endl;
			cin.clear();
			cin.ignore();

		}

	}




}