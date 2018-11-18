#include "Console.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "Date.h"
#include "Student.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"

using namespace std;

ofstream ofile("client.txt",ios::out);
ifstream ifile("courselist.txt",ios::in);

Console::Console()
{
}

Console::~Console()
{
}

int Console::run()//运行控制台
{
	buildStudent();
	displayMenu();
	
	for(int i = 1;i<=6;i++)
	{
		if(i<=3)
		{
			ifile>>str>>hour;
			//cout<<i<<" "<<str<<' '<<hour;
			obl[i].setName(str);
			obl[i].setCreditHour(hour);
		}
		else
		{
			ifile>>str>>hour;
			//cout<<i<<" "<<str<<' '<<hour;
			ele[i-3].setName(str);
			ele[i-3].setCreditHour(hour);
		}
	}
	
	while(cin>>num)
  {
	if(num == 1) 
	{
		if(!ofile)
		{
			cout<<"Failed"<<endl;
			exit(0);
		}
		else
		{
			ofile<<*student<<endl;
			cout<<*student<<endl;
		}
	}
	else if(num == 2)
	{
	 	cout<<"Please choose your courses :"<<endl;
	 	cout<<"Input 1 for obligatory courses , input 2 for elective courses :"<<endl;
		while(cin>>num1)
		{
			if(num1 == 1||num1 == 2)
			{
				selectCourse(num1);
				break;
			}
			else cout<<"Please input again."<<endl<<"Input 1 for obligatory courses , input 2 for elective courses :"<<endl;
		}
	}
	else if(num == 3)
	{
		cout<<"Type in the course you want to quit :"<<endl;
		cin>>num1;
		if(student->removeCourse(num1)) cout<<"Successed!"<<endl;
		else cout<<"Failed!"<<endl;
	}
	else if(num == 4) 
	{
		cout<<"Please set scores of the courses : "<<endl;
		setCourseScore();
	}
	else 
	{
		cout<<"Failed!"<<endl
			<<"Please input again."<<endl; 
	}
  }
}
		 
void Console::displayMenu() const //显示系统主菜单
{
	cout<<"Input 1 to check your personal information ."<<endl
	<<"Input 2 to elect courses ."<<endl
	<<"input 3 to quit courses ."<<endl
	<<"input 4 to set score ."<<endl;
	
}
		
Course* Console::selectCourse(int op) //选课 返回课程地址 op = 1 必修 op = 2 选修
{
	      if(op == 1)
			{
				Course *c1=new ObligatoryCourse();
				cout<<"Please input the num of the obligatorycourse :"<<endl;
				
				while(cin>>courseNum)
				{
					try
					{
						MyException my;
						my.CourseException(courseNum);
						c1->setCourse(obl[courseNum].getCreditHour(),obl[courseNum].getName());
						student->addCourse(c1);
						return c1;
					}
					catch(int courseNum)
					{
						cout<<"Exception occurred: course number error."<<endl
							<<"Please input course number again."<<endl;	
					}
				}
				
			}
			else if(op == 2)
			{
				Course *c2=new ElectiveCourse(); 
				cout<<"Please input the num of the electivecourse :"<<endl;
				
				while(cin>>courseNum)
				{
					try
					{
						MyException my;
						my.CourseException(courseNum);
						c2->setCourse(ele[courseNum].getCreditHour(),ele[courseNum].getName());
						student->addCourse(c2);
						return c2;
					}
					catch(int courseNum)
					{
						cout<<"Exception occurred: course number error."<<endl
							<<"Please input course number again."<<endl;	
					}
				}
			}
}
		
void Console::setCourseScore() //设置某一课程成绩
{
	int num1,score1;
	cin>>num1;
	while(cin>>score1)
	{
		try
		{
			MyException my;
			my.GradeException(score1);
			student->setScore(num1,score1);
			break;
		}
		catch(int score1)
		{
			cout<<"Exception occurred: grade error."<<endl
			    <<"Please input again."<<endl;
		}
	}
	
}
		
void Console::buildStudent() //构造学生对象
{
    cout<<"Please put in a name shorter than 10 characters :"<<endl;
    while(cin>>str)//控制名字长度 
    {
        if(str.length()>40)
        cout<<"Put in again."<<endl;
        else break;
    }
	
    n = new char[str.length()+1];
    strcpy(n,str.data());
    
    //if(student!=NULL) delete student;  
    
    student = new Student;
    student->SetName(n);
     
    cout<<"Please put in a date :"<<endl;
    while(cin>>y>>m>>d)
    {
    	try
    	{
    		MyException my;
    		date.wrongDate(y,m,d);
    		my.DateException(date);
    		student->SetBirthday(&date);
    		break;
		}
		catch(Date &date)
		{
			cout<<"Exception occurred: date error."<<endl
			    <<"Please input again."<<endl;
		}
	}
}

Console& Console::buildcourse() //设置所有可选课程
{
	
}
