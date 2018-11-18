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
	cout<<"***********************************************��ӭ����ѧ����Ϣ����ƽ̨*****************************************"<<endl;
	cout<<"**********************1, ��ʼ��ѧ����Ϣ****************************"<<endl;
	cout<<"**********************2����ӿγ�**********************************"<<endl;
	cout<<"**********************3, �˳�ѧ����Ϣ����ϵͳ**********************"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	cout<<"����������ִ�еĹ��ܣ�"<<endl;
}
void Console::displayMenu2()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
		cout<<"*******1�����ѡ�޿γ�*******"<<endl;
	 	cout<<"*******2, ��ӱ��޿γ�*******"<<endl; 
	 	cout<<"*******3, ��ѡ�β���*********"<<endl; 
	 	cout<<"*******4,��ѯ����ɼ�********"<<endl; 
	 	cout<<"*******5, �˳�ѡ��ϵͳ*******"<<endl; 
	 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		cout<<"����������ִ�еĹ��ܣ�"<<endl;
}
void Console::buildStudent()
{
		char* name=new char [20];
		cout<<"ѧ�����ƣ�"; 
		cin>>name;
		s1.setname(name);
		cout<<"�������ͬѧ�ĳ��������գ�";
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
			cerr<<"�ļ����ܴ�"<<endl;
			exit(1);
		}
		
		outFile<<s1.getname()<<" "<<s1.getDate()<<endl<<endl;
		outFile.close();
		
		
}
void Console::PrintStudent()
{
		cout<<"������";cout<<s1.getname()<<endl;
		cout<<"����: "; cout<<s1.getDate()<<endl;
}
void Console::PrintCourse()
{
		cout<<"��һ��ѡ��"<<s1.getCourseNumber()<<"�ſ�"<<endl;
		cout<<endl;
	 	for (int i=0;i<s1.getCourseNumber();i++)
	 	{
	 		cout<<*s1.getCourse(i);
	 		cout<<"�ɼ���"<<s1.getmark(i)<<endl;
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
			 	cout<<"������γ����ƣ�";
				cin>>str;
				cout<<"������γ�ѧ�֣�";
				cin>>hour; 
				cout<<"��Ϊ�ÿγ��趨�ɼ�(����)��";
				
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
					cerr<<"�ļ����ܴ�"<<endl;
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
				cout<<"������γ����ƣ�";
				cin>>str;
				cout<<"������γ�ѧ�֣�";
				cin>>hour;
				cout<<"��Ϊ�ÿγ��趨�ɼ����ȼ�����"; 
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
					cerr<<"�ļ����ܴ�"<<endl;
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
			 		cout<<"��ѡ�γɹ�"<<endl;
			 	else
			 		cout<<"��ѡ��ʧ��"<<endl;
	}
	else if (op==4)
	{
		cout<<"���Ļ���ɼ��ǣ�"<<s1.calcCredit()<<endl;
		
		ofstream outFile("StudentData.txt",ios::app);
				
				if (!outFile)
				{
					cerr<<"�ļ����ܴ�"<<endl;
					exit(1);
				}
				
				outFile<<"����ɼ���"<<s1.calcCredit()<<endl;
				
				outFile.close();
	}
 } 
void Console::showCourseFile()
{
	ifstream inFile("CourseData.txt",ios::in);
	
	if (!inFile)
	{
		cerr<<"�ļ����ܴ�"<<endl;
		exit(1);
	 } 
	 
	 string name;
	 int count;
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	 cout<<setw(18)<<"�γ�"<<setw(13)<<"ѧ��"<<endl;
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
					cerr<<"�ļ����ܴ�"<<endl;
					exit(1);
				}
	outFile<<left<<setw(18)<<"�γ�"<<setw(10)<<"ѧ��"<<setw(10)<<right<<"�ɼ�"<<endl;
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
            cout<<"�����������������"<<endl;
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
            cout<<"�������,����������"<<endl;
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
