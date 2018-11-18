#include "Students.h"
#include <iostream>
#include <cstring>
#include "Time.h"
#include <typeinfo>
#include "MyException.h"
using namespace std;
int Students::counter=0;
Students::Students(char *a, const Date &b):birthDate(b)
{
    name=new char[strlen(a)+1];
    strcpy(name, a);
    counter++;
    courseNumber=0;
}
Students::Students(const Students &a):birthDate(a.birthDate)
{
    name=new char[strlen(a.name)+1];
    strcpy(name ,a.name);
}
void Students::getName(char *s)
{
    strcpy(s, name);
}
Date Students::getBirthDate()
{
    return birthDate;
}
int Students::getCounter()
{
    return counter;
}
void Students::print()const
{
    cout<<"他的名字是"<<name<<endl;
    cout<<"他生于"<<birthDate.getYear()<<"年 ";
    cout<<birthDate.getMonth()<<"月 ";
    cout<<birthDate.getDay()<<"日 \n";
}
Students& Students::addCourse(Course *course)//这里的参数也可是子类对象，且子类对象在传入的过程中类型不变 
{
	if(courseNumber<MAX_SIZE) 
	{
		courseList[courseNumber++]=course;
	}
	return (*this);
}
Students& Students::addElectiveCourse(char grade, const string &courseName, int creditHour )
{
	if(courseNumber<MAX_SIZE)
	{
		courseList[courseNumber++]=new ElectiveCourse(grade, courseName, creditHour);//new 后面应该接子类对象，不然 
	}                                                                                //之后的操作中无法正确调用虚函 
	return (*this);																	//数		
}
Students& Students::addObligatoryCourse(int score, const string &courseName, int creditHour )
{
	if(courseNumber<MAX_SIZE)
	{
		courseList[courseNumber++]=new ObligatoryCourse(score, courseName, creditHour);
	}
	return (*this);
}
int Students::getCourseNumber()const
{
	return courseNumber;
}
Course* Students::getCourseList(int i)//调用私有成员：courseList数组 
{
	return courseList[i];
}
bool Students::removeCourse(int i)//i为第几门课 
{
	if(i>courseNumber||i<1)
	{
	 	cout<<"你想退选的科目不存在！" <<endl;
		return false;
	}
	else
	{
		cout<<"你所退选的课程为：\n"; 
		cout<<courseList[i-1]<<endl;
		Course *c=courseList[i-1];
		delete c;//删除指针所指向的东西，此时c也为空 
		for(int j=i-1;j<courseNumber-1;j++)
		{
			courseList[j]=courseList[j+1];	
		}
		courseNumber--;
		return true;
	}
}
void Students::SetCourseGrade(MyException &MyEx)
{
	cout<<"必修课请输入0-100，选修课请输入A-E\n";
	for(int i=0;i<getCourseNumber();i++)
	{
		if(typeid(*courseList[i])==typeid(ObligatoryCourse))//通过typeid来判断数据类型 
		{                                                   //头文件：<typeinfo> 
			int mark;
			while(cin>>mark)
			{
				try
				{
					if(cin.fail()||mark<0||mark>100)
					{
						cin.clear();
           				cin.ignore();
           				throw mark;
					}
				}catch(int )
				{
					cout<<"您输入的成绩不合法！请重新输入！"<<endl;
					MyEx.MyExceptionOfOCS(mark);
					continue;
				}
				
				break;		
			}
			((ObligatoryCourse*)courseList[i])->setMark(mark);//courseList数组类型是Course 
		}                                                     //需要转化成相对应的 课程类型
		else                                                  //才能调用相对应的set函数 
		{
			char grade;
			while(cin>>grade)
			{
				try
				{
					if(grade!='A'&&grade!='B'&&grade!='C'&&grade!='D'&&grade!='E')
						throw grade;
				}catch(char grade)
				{
					cout<<"您输入的成绩不合法！请重新输入！"<<endl;
					MyEx.MyExceptionOfOES(grade);
					continue; 
				}
				break;
			}
			((ElectiveCourse*)courseList[i])->setGrade(grade);
		}
	 }
}
int Students::calcCredit()
{
	int totalOfOCC=0, numberOfECC=0;//选修课的总课数 
	double GPA=0;
	for(int i=0;i<courseNumber;i++)
	{
		if(typeid(*courseList[i])==typeid(ObligatoryCourse))//计算选修和必修课的总学分 
			totalOfOCC+=courseList[i]->getCreditHour();
		else
			numberOfECC++;		
	} 
	for(int i=0;i<courseNumber;i++)
	{
		if(typeid(*courseList[i])==typeid(ObligatoryCourse))
			GPA+=0.6*(courseList[i]->getScore()*(static_cast<double>(courseList[i]->getCreditHour())/totalOfOCC));		
		else
			GPA+=0.4*(static_cast<double>(courseList[i]->getScore())/numberOfECC);//强制转换！！！ 
	} 
	return GPA;
}
Students::~Students()
{
    delete []name;
    for(int i=0;i<courseNumber;i++)//释放指针空间 
    {
    	delete courseList[i];
	} 
    counter--;
    cout<<"程序已经完成"<<endl;
}

