#include<iostream>
#include<fstream>
#include<cstring>
#include <typeinfo>
#include"date.h"
#include"student.h"
#include"Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include"console.h"
#include"DateException.h"
#include"CourseException.h"
#include"MyException.h"
#include"ArrException.h"
using namespace std;

void Console::go()
{
	char Name[15];
	int Year, Month, Day, coursetype ,number;
	cout << "����������: ";
	cin >> Name;
	cout << "����������: ";
	
	DateException de;
	CourseException ce;
	ArrException ae;
	
    while(cin  >> Year >> Month >> Day)
    {
    	if(de.DateExceptionCheck(Year,Month,Day))
    	break;
	}
	
	
	Date date(Year, Month, Day);
	cout<<"�������������++��<<" <<endl; 
	cout<<date<<endl;
	cout<<date++<<endl;
	cout<<++date<<endl;
	
	Student test(Name, Year, Month, Day);
	
	
	ifstream in("source.txt", ios::in);
	char a[20],b[20],c[20],d[20];
   	in.getline(a,20,'\n');
   	in.getline(b,20,'\n');
	in.getline(c,20,'\n');
	in.getline(d,20,'\n');
	in.close();
	
	
	obligatoryCourse[0]	= new ObligatoryCourse(a, 1, 0);
	obligatoryCourse[1]	= new ObligatoryCourse(b, 2, 0);
	electiveCourse[0] = new ElectiveCourse(c, 3, 'E');
	electiveCourse[1] = new ElectiveCourse(d, 4, 'E');	 
	cout<<"����ѡ���ڿ�"<<endl;
	cout<<"�������һ�ſε����ࣨ0Ϊ���ޣ�1Ϊѡ�ޣ�"<<endl;

		while(1)
		{
			int i=0;
			cin>>coursetype;
			if(cin.fail())
			{
				cin.clear();
				cin.ignore();
				coursetype=-1;
			}
			if(ae.ArrExceptionCheck(coursetype,2))
			{
				if(coursetype == 0)
				{
					cout << "����������Ҫѡ��ı��޿Σ�0��1����" << endl;
					while(1)
					{
						cin>> number;
						if(cin.fail())
						{
							cin.clear();
							cin.ignore();
							number = -1;
						}
				      	if(ae.ArrExceptionCheck(number,2))
				      	{
							Course *str1 = obligatoryCourse[ number];
							test.addCourse(str1);
							cout << "ѡ�γɹ���" <<endl;
							i=1;
							break;
						}
					}
					
				}
				else if(coursetype == 1)
				{
					cout << "����������Ҫѡ���ѡ�޿Σ�0��1����" << endl;
					while(1)
					{
						cin>> number;
						if(cin.fail())
						{
							cin.clear();
							cin.ignore();
							number = -1;
						}
				      	if(ae.ArrExceptionCheck(number,2))
				      	{
							Course *str2 = electiveCourse[ number ];
							test.addCourse(str2);	
							cout << "ѡ�γɹ���" <<endl;
							i=1;
							break;
						}
					}
				} 
				
			}
			if(i==1)
			break;
		}
		
	
	cout<<"������ڶ��ſε����ࣨ1Ϊ���ޣ�2Ϊѡ�ޣ�"<<endl;
	
		while(1)
		{
			int i=0;
			cin>>coursetype;
			if(cin.fail())
			{
				cin.clear();
				cin.ignore();
				coursetype=-1;
			}
			if(ae.ArrExceptionCheck(coursetype,2))
			{
				if(coursetype == 0)
				{
					cout << "����������Ҫѡ��ı��޿Σ�0��1����" << endl;
					while(1)
					{
						cin>> number;
						if(cin.fail())
						{
							cin.clear();
							cin.ignore();
							number = -1;
						}
				      	if(ae.ArrExceptionCheck(number,2))
				      	{
							Course *str1 = obligatoryCourse[ number];
							test.addCourse(str1);
							cout << "ѡ�γɹ���" <<endl;
							i=1;
							break;
						}
					}
					
				}
				else if(coursetype == 1)
				{
					cout << "����������Ҫѡ���ѡ�޿Σ�0��1����" << endl;
					while(1)
					{
						cin>> number;
						if(cin.fail())
						{
							cin.clear();
							cin.ignore();
							number = -1;
						}
				      	if(ae.ArrExceptionCheck(number,2))
				      	{
							Course *str2 = electiveCourse[ number ];
							test.addCourse(str2);	
							cout << "ѡ�γɹ���" <<endl;
							i=1;
							break;
						}
					}
				} 
				
			}
			if(i==1)
			break;
		}
		
	cout<<"�����趨�ɼ�"<<endl;
	int mark;
	char grade;
	
	for(int i = 0; i < test.getcourseNumber() ; i++ )
	{
		if(typeid(ObligatoryCourse) == typeid(*test.courseList[i]))
		{
			cout << "���������" << (*test.courseList[i]).getCourseName() << "�ĳɼ�(0 ~ 100)��";
			while(1)
			{
				cin >> mark;
				if(cin.fail())
				{
					cin.clear();
					cin.ignore();
					mark = -1;
				}
				if(ce.CourseException_check_1(mark))
				{
					cout<<"\n���óɼ��ɹ���"<<endl; 
					dynamic_cast <ObligatoryCourse &> (*test.courseList[i]).setmark(mark);
					break;
				}
			}
		
		}
		else if (typeid(ElectiveCourse) == typeid(*test.courseList[i])) 
		{
			cout << "������ѡ��" << (*test.courseList[i]).getCourseName() << "�ĳɼ�(A ~ E)��";
			while(1)
			{
				cin >> grade;
				if(cin.fail())
				{
					cin.clear();
					cin.ignore();
					grade = 'G';
				}
				if(ce.CourseException_check_2(grade))
				{
					cout<<"\n���óɼ��ɹ���"<<endl;
					dynamic_cast <ElectiveCourse &> (*test.courseList[i]).setgrade(grade);
					break;
				}
			}
		}
	}
	cout << test <<endl; 
	

	
	
	cout<<"������ѡ��"<<endl;
	cout << "��������ѡ�Ŀγ���ţ�";
	int i;
	while(1)
	{
		cin >> i;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore();
			i = 1;
		}
		if(ae.ArrExceptionCheck(i-1,2))
		{
			if(test.removeCourse(i))
			{
				cout <<"��ѡ�ɹ���" <<endl;
				break;
			}
		}
	}
	cout << test <<endl;
	
	cout << "���ڽ�ѧ����Ϣ������ļ���" <<endl;
	ofstream out("student_information.txt");
	out<<test;
	cout << "���" <<endl;
	out.close();
}




