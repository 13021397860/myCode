#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>

#include"Date.h"
#include "Student.h"
#include"Console.h"

using namespace std;

int main() {
/*	Date birthday(2002, 5, 15);
	Student stu1("InJuly", birthday);
	Student stu2(stu1);
	stu1.print();
	const char *name = stu2.getname();
	cout << "test name : " << name << endl;
	//cout << x << endl;
	stu2.setname("sylar");
	stu2.print();
	Date tmp(stu1.getbirthDate());
	tmp.setDate(1971, 5, 12);
	stu2.setbirthDate(tmp);
	stu2.print();
	int x = stu2.getcount();
	cout << "size is :" << x << "\n";

	Date tmp(birthday);
	int day = tmp.getDay();
	int month = tmp.getMonth();
	int year = tmp.getDay();
	//cout << year << ' ' << month << ' ' << day << ' ' << endl;
	cout << birthday << endl;
	birthday.nextDay();
	cout << "The next day is :";
	birthday.print();
	cout << ++birthday << ' ' << birthday << endl;
	cout << birthday++ << ' ' << birthday << endl;
	cout << endl;
	birthday.setYear(2004);
	birthday.print();
	birthday.isLeapYear() ? cout << "LeapYear\n" : cout << "Not LeapYear\n";
	system("pause");

	char *name = new char[20];
	int y, m, d;
	cin >> name >> y >> m >> d;
	Student stu1(name, y, m, d);
	stu1.addCourse("Math", 4);
	stu1.addCourse("C++", 4);

	Student stu2("ROTK", 1966, 6, 6);
	stu2.addCourse("python", 3);
	stu2.addCourse(new Course("Math", 4));

	Student *stu3 = new Student("Burning", 1999, 9, 9);
	stu3->addCourse("Physics", 4);
	stu3->addCourse("Politics", 2);
	*/
	/*
	char *name = new char[30];
	int y, m, d, ty, cnt = 0;
	cout << "If you want to add student infomation, please input a 1, or input 0\n";
	Student *stu[100];
	while (cin >> ty && ty == 1)
	{
		cout << "Please Input four student Infomation name birthdate\n";
		cin >> name >> y >> m >> d;
		stu[cnt] = new Student(name, y, m, d);
		if (cnt & 1) {
			stu[cnt]->addCourse("Physics", 4, 0);
			stu[cnt]->addCourse("Politics", 2, 1);
		}
		else {
			stu[cnt]->addCourse("python", 3, 0);
			stu[cnt]->addCourse(new Course("近世数学基础", 5), 1);
			stu[cnt]->addCourse("C++", 4, 1);
		}
		cnt++;
		cout << "If you want to add student infomation, please input a 1, or input 0\n";
	}
	cout << "Student number is " << Student::getcount() << endl;
	for (int i = 0; i < cnt; i++)
	{
		cout << *stu[i] << '\n';
	}

	system("pause");
	return 0;
	*/
	Console control;
	cout << control.run() << endl;
	//control.run();
	return 0;
}