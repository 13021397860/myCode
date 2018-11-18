#include "Console.h"
#include <iostream>
#include <cstring>
#include "Date.h"
#include "student.h"
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#include "windows.h"
#include <fstream>
#include <iomanip>
using namespace std;
Console::Console()
{
	student s1;
	MyException myException;
}
void Console::run()
{
	Console c;
	c.FileClear();
	c.displayMenu1();
	int chose;
	chose=c.CinCheck();

	while (chose!=4)
	{
		if (chose==1)
		{
			c.buildStudent();
			c.PrintStudent();
			c.displayMenu1();
			chose=c.CinCheck();
		}
		else if (chose==2)
		{
			
			int chose2;
			c.showCourseFile();
			c.displayMenu2();
			c.writeStudentFile();
			chose2=c.CinCheck2();
			while (chose2!=5)
			{
				c.selectCourse(chose2);
				c.displayMenu2();
				chose2=c.CinCheck2();
			}
			c.PrintCourse();
			c.displayMenu1();
			chose=c.CinCheck();
			
		}
		else if (chose==3)
		{
			break;
		}
	}
	
}
void Console::displayMenu1()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
	cout<<"***********************************************欢迎来到学生信息管理平台*****************************************"<<endl;
	cout<<"**********************1, 初始化学生信息****************************"<<endl;
	cout<<"**********************2，添加课程**********************************"<<endl;
	cout<<"**********************3, 退出学生信息管理系统**********************"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	cout<<"请输入您想执行的功能："<<endl;
}
void Console::displayMenu2()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
		cout<<"*******1，添加选修课程*******"<<endl;
	 	cout<<"*******2, 添加必修课程*******"<<endl; 
	 	cout<<"*******3, 退选课操作*********"<<endl; 
	 	cout<<"*******4,查询积点成绩********"<<endl; 
	 	cout<<"*******5, 退出选课系统*******"<<endl; 
	 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		cout<<"请输入您想执行的功能："<<endl;
}
void Console::buildStudent()
{
		char* name=new char [20];
		cout<<"学生名称："; 
		cin>>name;
		s1.setname(name);
		cout<<"请输入该同学的出生年月日：";
		int yr,mh,dy;
		cin>>yr>>mh>>dy;
		bool ss=s1.setdate(yr,mh,dy);
		while(!ss)
		{
			myException.catchDate(ss);
			cin>>yr>>mh>>dy;
			ss=s1.setdate(yr,mh,dy);
		}
		
		
		ofstream outFile("StudentData.txt",ios::app);
		
		if (!outFile)
		{
			cerr<<"文件不能打开"<<endl;
			exit(1);
		}
		
		outFile<<s1.getname()<<" "<<s1.getDate()<<endl<<endl;
		outFile.close();
		
		
}
void Console::PrintStudent()
{
		cout<<"姓名：";cout<<s1.getname()<<endl;
		cout<<"生日: "; cout<<s1.getDate()<<endl;
}
void Console::PrintCourse()
{
		cout<<"您一共选了"<<s1.getCourseNumber()<<"门课"<<endl;
		cout<<endl;
	 	for (int i=0;i<s1.getCourseNumber();i++)
	 	{
	 		cout<<*s1.getCourse(i);
	 		cout<<"成绩："<<s1.getmark(i)<<endl;
	 		cout<<endl;
		 } 
}
void Console::getRTTI()
{
	cout<<s1.calcCredit()<<endl;
}
void Console::selectCourse(int op)
{
	if(op==1)
	{
				string str;
		 		int hour;
		 		int mark;
		 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
			 	cout<<"请输入课程名称：";
				cin>>str;
				cout<<"请输入课程学分：";
				cin>>hour; 
				cout<<"请为该课程设定成绩(分数)：";
				
				cin>>mark;
				while(!myException.catchObGrade(mark))
				{
					cin>>mark;
				}
				
				Course *c=new ObligatoryCourse (str,hour,mark);                                           
				s1.addCourse(c);
				s1.setJudgeCourse(op);
				
				ofstream outFile("StudentData.txt",ios::app);
				
				if (!outFile)
				{
					cerr<<"文件不能打开"<<endl;
					exit(1);
				}
				int i=s1.getCourseNumber()-1;
				outFile<<*s1.getCourse(i)<<setw(10)<<right<<s1.getmark(i)<<endl;
				
				outFile.close();
	}
	else if(op==2)
	{
				string str;
			 	int hour;
			 	char mark;
			 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
				cout<<"请输入课程名称：";
				cin>>str;
				cout<<"请输入课程学分：";
				cin>>hour;
				cout<<"请为该课程设定成绩（等级）："; 
				cin>>mark;
				while(!myException.catchElGrade(mark))
				{
					cin>>mark;
				}
				
				Course *c=new ElectiveCourse (str,hour,mark);                                        
				s1.addCourse(c);
				s1.setJudgeCourse(op);
				ofstream outFile("StudentData.txt",ios::app);
				
				if (!outFile)
				{
					cerr<<"文件不能打开"<<endl;
					exit(1);
				}
				
				int i=s1.getCourseNumber()-1;
				outFile<<*s1.getCourse(i)<<setw(10)<<right<<s1.getmark(i)<<endl;
				
				outFile.close();
	}
	else if (op==3)
	{
		int x=s1.getCourseNumber();
			 	if(s1.removeCourse(x))
			 		cout<<"退选课成功"<<endl;
			 	else
			 		cout<<"退选课失败"<<endl;
	}
	else if (op==4)
	{
		cout<<"您的积点成绩是："<<s1.calcCredit()<<endl;
		
		ofstream outFile("StudentData.txt",ios::app);
				
				if (!outFile)
				{
					cerr<<"文件不能打开"<<endl;
					exit(1);
				}
				
				outFile<<"积点成绩："<<s1.calcCredit()<<endl;
				
				outFile.close();
	}
 } 
void Console::showCourseFile()
{
	ifstream inFile("CourseData.txt",ios::in);
	
	if (!inFile)
	{
		cerr<<"文件不能打开"<<endl;
		exit(1);
	 } 
	 
	 string name;
	 int count;
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	 cout<<setw(18)<<"课程"<<setw(13)<<"学分"<<endl;
	 while (inFile>>name>>count)
	 {
	 	cout<<setw(18)<<name<<setw(13)<<count<<endl;
	 }
	 cout<<endl;
}
void Console::writeStudentFile()
{
	ofstream outFile("StudentData.txt",ios::app);
				
				if (!outFile)
				{
					cerr<<"文件不能打开"<<endl;
					exit(1);
				}
	outFile<<left<<setw(18)<<"课程"<<setw(10)<<"学分"<<setw(10)<<right<<"成绩"<<endl;
	outFile.close();
}
int Console::CinCheck()
{
	int chose;
	while (true)
	{
		
		cin>>chose;
		if(cin.good() && getchar() =='\n'&&chose>=1&&chose<=3) { //input an real number also is not allowed1: getchar() != '.'
            break;
        }
        else { 
            cout<<"输入错误，请重新输入"<<endl;
			cin.clear();
  
            cin.ignore(1024, '\n' ); 
        }    
	}
	return chose;
}
int Console::CinCheck2()
{
	int chose;
	while (true)
	{
		
		cin>>chose;
		if(cin.good() && getchar() =='\n'&&chose>=1&&chose<=5) { //input an real number also is not allowed1: getchar() != '.'
            break;
        }
        else { 
            cout<<"输入错误,请重新输入"<<endl;
			cin.clear();
  
            cin.ignore( 1024, '\n' ); 
        }    
	}
	return chose;
	return chose;
}
void Console::FileClear()
{
	ofstream outClear("StudentData.txt",ios::out);
	outClear.close();
}
