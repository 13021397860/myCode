#include <iostream>
#include <typeinfo>
#include <string>
#include <fstream>
#include "Console.h"

using namespace std;

Console::Console()
{
}

Console::~Console()
{
	studentList.clear();
	OCList.clear();
	ECList.clear();
}

int Console::regist()
{
	try
	{
		do
		{
			cout << "�������������." << endl;
			char* studentName=new char[20];
			cin >> studentName;
			cout << "��������ĳ��������գ�ÿ�������ÿո����." << endl;
			int year,month,day;
			cin >> year >> month >> day;
			Student student(studentName,year,month,day);
			for(int i=0;i<studentList.size();i++)
			{
				Date x=student.get_date();
				Date y=studentList[i].get_date();
				string a=student.get_name();
				string b=studentList[i].get_name();
				if(a==b&&x==y)
				{
					cout << "�˻��Ѵ��ڣ�" << endl << endl;
					continue;
				}
			}
			studentList.push_back(student);
			return studentList.size()-1;
		}while(1);
	}
	catch(MyException &myException)
	{
		cout<<myException.what()<<endl;
		return -1;
	}
}

int Console::login()
{
	do
	{
		cout << "�������������." << endl;
		char* studentName=new char[20];
		cin >> studentName;
		cout << "��������ĳ��������գ�ÿ�������ÿո����." << endl;
		int year,month,day;
		cin >> year >> month >> day;
		Student student(studentName,year,month,day);
		for(int i=0;i<studentList.size();i++)
		{
			Date x=student.get_date();
			Date y=studentList[i].get_date();
			string a=student.get_name();
			string b=studentList[i].get_name();
			if(a==b&&x==y)
				return i;
		}
		cout << "�˻������ڻ�����Ϣ�������" << endl << endl;
	}while(1);
}

void Console::createOC()
{
	ifstream OCin("OC.txt");
	char* courseName;
	int creditHour;
	courseName=new char[100];
	while(OCin >> courseName)
	{
		OCin >> creditHour;
		ObligatoryCourse *OC=new ObligatoryCourse(courseName,creditHour,0);
		OCList.push_back(*OC);
	}
	delete[] courseName;
}

void Console::createEC()
{
	ifstream ECin("EC.txt");
	char* courseName;
	int creditHour;
	courseName=new char[100];
	while(ECin >> courseName)
	{
		ECin >> creditHour;
		ElectiveCourse *EC=new ElectiveCourse(courseName,creditHour,'E');
		ECList.push_back(*EC);
	}
	delete[] courseName;
}

void Console::chooseCourse(Student &student)
{
	try
	{
		int order;
		do
		{
			cout << "��ѡ����ı��޿�." << endl;
			for(int i=0;i<OCList.size();i++) 
				cout << "�γ�"<<i+1<<":" << OCList[i].getName() << " ѧ��:" << OCList[i].getCreditHour() << endl;
			cout << "��������ѡ��Ŀγ̵ı��."<<endl;
			int courseNumber;
			cin >> courseNumber;
			//Course* res=&OCList[courseNumber-1];
			if(courseNumber>OCList.size()||courseNumber<1)
				throw MyException();
			student.addCourse(&OCList[courseNumber-1]);
			cout<<"���Ƿ�Ҫѡ�������γ�?"<<endl<<"�ǣ�������1����������0."<<endl;
			cin >>order;
		}
		while(order);
		
		do
		{
			cout << "��ѡ�����ѡ�޿�." << endl;
			for(int i=0;i<ECList.size();i++) 
				cout << "�γ�"<<i+1 << ":" << ECList[i].getName() << " ѧ��:" << ECList[i].getCreditHour() << endl;
			cout << "��������ѡ��Ŀγ̵ı��."<<endl;
			int courseNumber;
			cin >> courseNumber;
			if(courseNumber>OCList.size()||courseNumber<1)
				throw MyException();
			//Course* res=&ECList[courseNumber-1];
			student.addCourse(&ECList[courseNumber-1]);
			cout<<"���Ƿ�Ҫѡ�������γ�?"<<endl<<"�ǣ�������1����������0."<<endl;
			cin >>order;
		}
		while(order);
	}
	catch(MyException &myException)
	{
		cout<<myException.what()<<endl;
	} 
}

void Console::showCL(Student &student)
{
	cout<<"��Ŀγ̱�����."<<endl;
	for(int i=0;i<student.getCourseCounter();i++)
		cout<<"�γ�"<<i+1<<":"<<student.getCourse(i)->getName()<<" ѧ��:"<<student.getCourse(i)->getCreditHour()<<endl;
}

void Console::showGrade(Student &student)
{
	cout<<"��Ŀγ̳ɼ�����."<<endl;
	for(int i=0;i<student.getCourseCounter();i++)
		cout << *(student.getCourse(i)) << endl;
	/*{
		cout<<"�γ�"<<i+1<<":"<<student.getCourse(i)->getName()<<" ѧ��:"<< student.getCourse(i)->getCreditHour();
		if(student.checkOC(i))
			cout << " �ɼ�:" << dynamic_cast<ObligatoryCourse*>(student.getCourse(i))->getScore()<<endl;
		else
			cout << " �ɼ�:" << dynamic_cast<ElectiveCourse*>(student.getCourse(i))->getScore()<<endl;
	}*/
}

void Console::removeCourse(Student &student)
{
	try
	{
		int order;
		cout<< "�Ƿ���Ҫ�˿Σ��ǣ�������1����������0." << endl;
		cin >> order;
		if(order)
			do
			{ 
				this->showCL(student);
				cout << "��������Ҫ�˵Ŀγ̵ı��."<<endl;
				int courseNumber;
				cin >> courseNumber;
				student.removeCourse(courseNumber);
				cout<<"���Ƿ�Ҫ��ѡ�����γ�?"<<endl<<"�ǣ�������1����������0."<<endl;
				cin >>order;
			}
			while(order); 
	}
	catch(MyException &myException)
	{
		cout<<myException.what()<<endl;
	} 
}

void Console::setGrade(Student &student)
{
	try
	{
		int order;
		cout<< "�Ƿ���ҪΪ��Ŀγ����óɼ����ǣ�������1����������0." << endl;
		cin >> order;
		if(order)
			do
			{ 
				this->showCL(student);
				cout << "��������Ҫ���óɼ��Ŀγ̵ı��."<<endl;
				int courseNumber;
				cin >> courseNumber;
				if(student.checkOC(courseNumber-1))
				{
					cout << "��������Ҫ���õĳɼ�."<<endl;
					int grade;
					cin >> grade;
					if(grade<0||grade>100)
						throw MyException();
					dynamic_cast<ObligatoryCourse*>(student.getCourse(courseNumber-1))->setMark(grade);
				}
				else
				{
					cout << "��������Ҫ���õĵȵ�."<<endl;
					char grade;
					cin >> grade;
					if(grade!='A'&&grade!='B'&&grade!='C'&&grade!='D'&&grade!='E')
						throw MyException();
					dynamic_cast<ElectiveCourse*>(student.getCourse(courseNumber-1))->setGrade(grade);
				}
				cout<<"���Ƿ�Ҫ���������γ̵ĳɼ�?"<<endl<<"�ǣ�������1����������0."<<endl;
				cin >>order;
			}
			while(order); 
	}
	catch(MyException &myException)
	{
		cout<<myException.what()<<endl;
	} 
}

void Console::showGPA(Student& student)
{
	cout<<"��ļ���ɼ�Ϊ��"<<student.calcGrade()<<endl;
}

void Console::createStudentList()
{
	ifstream Sin("student.txt");
	char* studentName;
	int day,month,year,n,creditHour,type,grade;
	char* courseName;
	studentName=new char[20];
	courseName=new char[100];
	while(Sin >> studentName)
	{
		Sin >> year >> month >> day >> n;
		Student student(studentName,year,month,day);
		studentList.push_back(student);
		for(int i=1;i<=n;i++)
		{
			Sin >> type;
			if(type==1)
			{ 	
				Sin >> courseName >> creditHour >> grade;
				ObligatoryCourse *course;
				course=new ObligatoryCourse(courseName,creditHour,grade);
				studentList[studentList.size()-1].addCourse(course); 
			}
			else
			{ 	
				int level;
				Sin >> courseName >> creditHour >> grade;
				if(grade==95)
					level='A';
				if(grade==85)
					level='B';
				if(grade==75)
					level='C';
				if(grade==65)
					level='D';
				if(grade==55)
					level='E';
				ElectiveCourse *course;
				course=new ElectiveCourse(courseName,creditHour,level); 
				studentList[studentList.size()-1].addCourse(course); 
			}
		}
	}
	delete[] courseName;
	delete[] studentName;
}

void Console::saveStudentList()
{
	ofstream Sout("student.txt");
	for(int i=0;i<studentList.size();i++)
	{
		string a=studentList[i].get_name();
		Date b=studentList[i].get_date();
		Sout << a << endl;
		Sout << b << endl;
		Sout << studentList[i].getCourseCounter() << endl;
		for(int j=0;j<studentList[i].getCourseCounter();j++)
		{
			if(studentList[i].checkOC(j))
				Sout << "1 ";
			else
				Sout << "2 ";
			Sout << studentList[i].getCourse(j)->getName() << " " << 
			studentList[i].getCourse(j)->getCreditHour() << " ";
			if(studentList[i].checkOC(j)) 
				Sout << dynamic_cast<ObligatoryCourse*>(studentList[i].getCourse(j))->getScore() << endl;
			else
				Sout << dynamic_cast<ElectiveCourse*>(studentList[i].getCourse(j))->getScore() << endl;
		}
	}
}

void Console::menu()
{
	this->createOC();
	this->createEC();
	this->createStudentList();
	int order;
	int studentID;
	do
	{
		while(1)
		{
			cout << "���Խ��еĲ�����" << endl;
			cout << "1.��¼" << endl;
			cout << "2.ע��" << endl;
			cout << "3.�˳�" << endl;
			cout << "������������еĲ����ı��" << endl;
			cin >> order;
			if(order>3||order<1)
			{
				cout << "�������" << endl;
				continue;
			}
			break;
		}
		if(order==2)
			studentID=Console::regist();
		if(order==1)
			studentID=Console::login();
		if(order==3)
			return;
	}while(studentID==-1);
	while(1)
	{
		cout << "���Խ��еĲ�����" << endl;
		cout << "1.ѡ��" << endl;
		cout << "2.�˿�" << endl;
		cout << "3.���óɼ�" << endl;
		cout << "4.��ѯ�α�" << endl;
		cout << "5.��ѯ�ɼ�" << endl;
		cout << "6.��ѯ����ɼ�" << endl;
		cout << "7.�˳�" << endl;
		cout << "������������еĲ����ı��" << endl;
		cin >> order;
		if(order>7||order<1)
		{
			cout << "�������" << endl;
			continue; 
		}
		if(order==1)
			Console::chooseCourse(studentList[studentID]);
		if(order==2)
			Console::removeCourse(studentList[studentID]);
		if(order==3)
			Console::setGrade(studentList[studentID]);
		if(order==4)
			Console::showCL(studentList[studentID]);
		if(order==5)
			Console::showGrade(studentList[studentID]);
		if(order==6)
			Console::showGPA(studentList[studentID]);
		this->saveStudentList(); 
		cout << endl;
		if(order==7)
			break;
	}
}


