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
	cout << "请输入姓名: ";
	cin >> Name;
	cout << "请输入日期: ";
	
	DateException de;
	CourseException ce;
	ArrException ae;
	
    while(cin  >> Year >> Month >> Day)
    {
    	if(de.DateExceptionCheck(Year,Month,Day))
    	break;
	}
	
	
	Date date(Year, Month, Day);
	cout<<"测试重载运算符++和<<" <<endl; 
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
	cout<<"测试选两节课"<<endl;
	cout<<"请输入第一门课的种类（0为必修，1为选修）"<<endl;

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
					cout << "请输入你想要选择的必修课（0或1）：" << endl;
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
							cout << "选课成功！" <<endl;
							i=1;
							break;
						}
					}
					
				}
				else if(coursetype == 1)
				{
					cout << "请输入你想要选择的选修课（0或1）：" << endl;
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
							cout << "选课成功！" <<endl;
							i=1;
							break;
						}
					}
				} 
				
			}
			if(i==1)
			break;
		}
		
	
	cout<<"请输入第二门课的种类（1为必修，2为选修）"<<endl;
	
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
					cout << "请输入你想要选择的必修课（0或1）：" << endl;
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
							cout << "选课成功！" <<endl;
							i=1;
							break;
						}
					}
					
				}
				else if(coursetype == 1)
				{
					cout << "请输入你想要选择的选修课（0或1）：" << endl;
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
							cout << "选课成功！" <<endl;
							i=1;
							break;
						}
					}
				} 
				
			}
			if(i==1)
			break;
		}
		
	cout<<"测试设定成绩"<<endl;
	int mark;
	char grade;
	
	for(int i = 0; i < test.getcourseNumber() ; i++ )
	{
		if(typeid(ObligatoryCourse) == typeid(*test.courseList[i]))
		{
			cout << "请输入必修" << (*test.courseList[i]).getCourseName() << "的成绩(0 ~ 100)：";
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
					cout<<"\n设置成绩成功！"<<endl; 
					dynamic_cast <ObligatoryCourse &> (*test.courseList[i]).setmark(mark);
					break;
				}
			}
		
		}
		else if (typeid(ElectiveCourse) == typeid(*test.courseList[i])) 
		{
			cout << "请输入选修" << (*test.courseList[i]).getCourseName() << "的成绩(A ~ E)：";
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
					cout<<"\n设置成绩成功！"<<endl;
					dynamic_cast <ElectiveCourse &> (*test.courseList[i]).setgrade(grade);
					break;
				}
			}
		}
	}
	cout << test <<endl; 
	

	
	
	cout<<"测试退选课"<<endl;
	cout << "请输入退选的课程序号：";
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
				cout <<"退选成功！" <<endl;
				break;
			}
		}
	}
	cout << test <<endl;
	
	cout << "正在将学生信息输出到文件中" <<endl;
	ofstream out("student_information.txt");
	out<<test;
	cout << "完成" <<endl;
	out.close();
}




