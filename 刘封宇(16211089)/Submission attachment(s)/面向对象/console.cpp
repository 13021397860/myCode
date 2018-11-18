#include "console.h"
#include "student.h"
#include "obligatoryCourse.h"
#include "electiveCourse.h"
#include "dateException.h"
#include "courseException.h"
#include "arrException.h"
#include "date.h"
#include <typeinfo>
#include <iostream>
#include <fstream>
#define maxnum 3
using namespace std;
Console::Console(){;} 
 
void Console::setCourseGrade(Student &stud)
{
	CourseException ce; //---------3 
	int mark = 0;
	char grade[10] ;
	grade[0] = 'E' ;
	 
	for(int i = 0; i < stud.getcourseNumber() ; i++ )
	{
		if(typeid(ObligatoryCourse) == typeid(*(stud.courseList[i])))
		{
			cout << "\n请输入必修课程“" << (*(stud.courseList[i])).getCourseName() << "”的成绩(0 ~ 100)：";
			while(1)
			{
				cin >> mark;
				if (cin.fail())
				{
         		cin.clear();
				cin.ignore();
				mark=-1;
      			}
				if(ce.CourseExceptionCheck(mark))
				{
					cout<<"\n设置成绩成功！"<<endl; 
					dynamic_cast <ObligatoryCourse &> (*(stud.courseList[i])).setMark(mark);
					break;
				}
			}
			
		}
		else if (typeid(ElectiveCourse) == typeid(*(stud.courseList[i]))) 
		{
			cout << "\n请输入选修课程“" << (*(stud.courseList[i])).getCourseName() << "”的成绩(A ~ E)：";
			while(1)
			{
				cin >> grade;
				if(ce.CourseExceptionCheck(grade[0]))
				{
					cout<<"\n设置成绩成功！"<<endl;
					dynamic_cast <ElectiveCourse &> (*(stud.courseList[i])).setGrade(grade[0]);
					break;
				}
			}
			
		}
	}	
}

int Console::run()
{
	char Name[99];
	int Year, Month, Day,courseType,num,number;
	
	DateException de;//-------1
	
	cout << "请输入姓名: ";
	cin >> Name;
	cout << "\n请输入日期: ";
	while(cin >> Year >>Month >>Day)
	{
		if(de.DateExceptionCheck(Year,Month,Day))
		break;
	}
	Date date(Year, Month, Day);
	
	cout << "\n测试 ++ 运算符: "<<endl;
	cout<<date<<endl;
	cout<<date++<<endl;
	cout<<++date<<endl;
	
	Student Test(Name, Year, Month, Day);
	
	ifstream file("course.txt", ios::in);
	if(!file)
	{
		cerr<<"error"<<endl;
	}
	char a[20],b[20],c[20],d[20];
   	file.getline(a,20,'\n');
   	file.getline(b,20,'\n');
	file.getline(c,20,'\n');
	file.getline(d,20,'\n');
	file.close();
	
	ArrException ae;//--------2
 
	bool numobl[maxnum];
	bool numele[maxnum];
	for(int i=0;i<maxnum;i++)
	{
		numobl[i]=1;
		numele[i]=1;
	}
	
	obligatoryCourse[1]	= new ObligatoryCourse(a, 1, 0);
	obligatoryCourse[2]	= new ObligatoryCourse(b, 2, 0);
	electiveCourse[1] = new ElectiveCourse(c, 3, 'E');
	electiveCourse[2] = new ElectiveCourse(d, 4, 'E');
		 
	while(1)
	{
		cout << "\n请选择: " <<endl
		 << "1-------选课" <<endl
		 << "2-------退课" <<endl
		 << "3-------设置成绩" <<endl 
		 << "4-------查看绩点" <<endl
		 << "5-------打印信息" <<endl 
		 << "0-------退出" <<endl;
		cin >> number;
		if (cin.fail())
		{
         	cin.clear();
			cin.ignore();
			number=-1;
      	}  
		if(number==0)
		{
			break;
		}
			
		if(ae.ArrExceptionCheck(number,5,1))
		{
			if(number==1)
			{
				while(1)
			{
				cout << "\n请选择: " <<endl
			 	<< "1-------必修课" <<endl
			 	<< "2-------选修课" <<endl
			 	<< "0-------退出" <<endl;
				 cin>>courseType;
				 if (cin.fail())
				{
         			cin.clear();
					cin.ignore();
					courseType = -1; 
      			}
      			if(courseType==0)
				{
					break;
				}
      			
      			
      			else if(ae.ArrExceptionCheck(courseType,2,1))
      			{
				  if(courseType == 1)
				{
					cout << "\n请输入你想要选择的必修课：" << endl;
					if(numobl[1])
					cout <<"1."<< a <<endl;
					if(numobl[2])
					cout <<"2."<< b <<endl; 
					cin>> num;
					if(ae.ArrExceptionCheck(num,maxnum-1,numobl[num]))
					{
						numobl[num]=0;
						Course *str1 = obligatoryCourse[num];
						Test.addCourse(str1);
						cout << "\n选课成功！" <<endl;
					}
					
				}
					else if(courseType==2)
				{
					cout << "\n请输入你想要选择的选修课：" << endl;
					if(numele[1])
					cout <<"1."<< c <<endl;
					if(numele[2])
					cout <<"2."<< d <<endl;
					cin>> num;
					if(ae.ArrExceptionCheck(num,maxnum-1,numobl[num]))
					{
						numele[num]=0;
						Course *str2 = electiveCourse[ num ];
						Test.addCourse(str2);
						cout << "\n选课成功！" <<endl;
					} 
				}
				} 
				
			}
			
			
			
		}
		else if(number==2)
		{
			while(1)
			{
			cout<<Test<<endl;
			cout << "\n请输入要删除的课程序号,输入-1退出：" <<endl;
			cin>>courseType;
			if (cin.fail())
			{
         		cin.clear();
				cin.ignore();
      		}
			if(courseType!=-1)
			{
				if(courseType==0)
				cout<<"\n退课失败！"<<endl;
				else if(Test.removeCourse(courseType))
				cout<<"\n退课成功！"<<endl; 
				else
				cout<<"\n退课失败！"<<endl;
			}
			else
			break;
			}
			
		}
		else if(number==3)
		{
			cout<<"\n请设置成绩：" <<endl;
			setCourseGrade(Test);
		}
		
		else if(number==4)
		{
			double x=Test.calcCredit();
			cout<<"\n该同学的绩点为  "<<x<<endl;
		}
		else if(number==5)
		{
			ofstream outfile("student.txt", ios::out);
			if(!file)
			{
				cerr<<"error"<<endl;
				break;
			}
			outfile<<Test;
			outfile.close();
			cout<<"\n打印成功！"<<endl; 
		}
			
			
		}
		
		
		
		
		
	}
	cout<<Test;

		                                                                                                                                                         
	return 0;
	
}



Console::~Console()
{
	
}

