


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

	cout << "������ѧ������: " << endl;
	cin >> stuname;

	cout << "������ѧ�����������գ���: 2000 1 1��" << endl;
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
			//cout << "��[����]����ѧ�����������գ���: 2000 1 1��" << endl;
		}
	}

	Student s(stuname, new Date(y, m, d));
	fstream f;
	string str2, type;
	char score;

	while (true) {
		try {
			cout << "1.���ѧ����Ϣ 2.��ӱ�ѡ�γ� 3.ɾ����ѡ�γ� 4.ѡ�� 5.��ѡ 6.ָ���γ̳ɼ� 7.��ѯѧ���ܳɼ��뼨��" << endl << "8.���汸ѡ�γ̵��ļ� 9.���ļ��ָ���ѡ�γ�" << endl << "10.����ѧ����Ϣ���ļ� 11.���ļ��ָ�ѧ����Ϣ 0.�˳�����" << endl;
			cin >> op;
			if (cin.fail())throw MyException();
			switch (op)
			{
			case 1:
				cout << s << endl;
				break;
			case 2:
				cout << "1.���޿� 2.ѡ�޿�" << endl;
				cin >> op;
				if (cin.fail())throw MyException();
				cout << "�����룺�γ��� ѧ��" << endl;
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
					cout << "�Ƿ�����" << endl;
				}
				break;
			case 3:
				cout << "��ϣ��ɾ���ڼ��ű�ѡ�γ̣�" << endl;
				cin >> t;
				if (cin.fail())throw MyException();
				if (t > 0 && t <= coursenum) {
					for (int i = t; i < coursenum - 1; i++) {
						courseList[i] = courseList[i + 1];
					}
					coursenum--;
				}
				else {
					cout << "ɾ��ʧ�ܣ���ǰֻ��" << coursenum << "�ű�ѡ��!" << endl;
					throw MyException(MyException::EXPECTION_OVERFLOW);
				}

				break;
			case 4:
				cout << "��ѡ�γ����£�" << endl;
				for (int i = 1; i <= coursenum; i++) {
					cout << "�γ�" << i << ": " << *(courseList[i]) << endl;
				}
				cout << "����������ѡ�ڼ��ſγ̣�" << endl;
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
					cout << "ѡ�γɹ���" << endl;
				}
				else {
					cout << "ѡ��ʧ�ܣ���ǰֻ��" << coursenum << "�ű�ѡ��!" << endl;
					throw MyException(MyException::EXPECTION_OVERFLOW);
				}
				break;
			case 5:
				cout << "��������ɾ����ѡ�ĵڼ��ſγ̣�" << endl;
				cin >> t;
				if (cin.fail())throw MyException();
				if (s.removeCourse(t)) {
					cout << "ɾ���ɹ�!" << endl;
				}
				else {
					cout << "ɾ��ʧ�ܣ���ǰѧ��ֻ��" << s.getCourseCount() << "�ſ�!" << endl;
					throw MyException(MyException::EXPECTION_OVERFLOW);
				};
				break;
			case 6:
				cout << "������γ������ɼ�:������ ���޿�:1 100 ѡ�޿�:1 A��" << endl;

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
						cout << "���óɹ�" << endl;
					}
					else {
						cout << "����ʧ��! ��ȷ��: 1.�γ�����Ƿ���ȷ 2.���޿�ֻ��ʹ�����η�����ѡ�޿�ֻ��ʹ��A��B��C��D��E" << endl;
						throw MyException(MyException::EXPECTION_GRADE);
					}
				}
				else {
					if (s.setScore(y, str[str.length() - 1])) {
						cout << "���óɹ�" << endl;
					}
					else {
						cout << "����ʧ��! ��ȷ��: 1.�γ�����Ƿ���ȷ 2.���޿�ֻ��ʹ�����η�����ѡ�޿�ֻ��ʹ��A��B��C��D��E" << endl;
						throw MyException(MyException::EXPECTION_GRADE);
					}
				}

				break;
			case 7:
				cout << s << endl;
				cout << "����:" << s.calcCredit() << endl << endl;
				break;
			case 8:
				f.open("course.txt", ios::out);
				for (int i = 1; i <= coursenum; i++) {
					f << *(courseList[i]) << endl;
				}
				f.close();
				cout << "���浽course.txt�ɹ�" << endl;
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
					if (type == "���޿�") {
						course = new ObligatoryCourse(name, y);
						courseList[++coursenum] = course;
					}if (type == "ѡ�޿�") {
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
				cout << "���浽student.txt�ɹ�" << endl;
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
					if (type == "���޿�") {
						course = new ObligatoryCourse(name, y);
						s.addCourse(course);
						s.setScore(d, m);
					}
					if (type == "ѡ�޿�") {
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



				cout << "��student.txt�ָ��ɹ�" << endl;
				f.close();
				break;
			case 0:
				return 0;
			default:
				cout << "�Ƿ�����" << endl;
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