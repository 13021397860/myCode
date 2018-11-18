#include<iostream>
#include<cstring>
#include<cstdlib>
#include "stu.h"
#include"myexception.h"
#define Max 1000
using namespace std;
int Stu::count=0;
Stu::Stu()
{
	name=new char[21];
	strcpy(name,"xxx");
	count++;
	courseNumber=0;
	OzongCredit=0;
	Ezong=0;
}
Stu::Stu(char *p)
{
	if(p==NULL)
	{
		name=new char[21];
		strcpy(name,"xxx");
	}
	else
	{
		char * s=static_cast<char*>(p);
		if(strlen(s)>20)
		{
			name=new char[21];
			strcpy(name,"xxx");
		}
		else
		{
			name=new char[21];
			strcpy(name,s);
		}
	}
	count++;
	courseNumber=0;
	OzongCredit=0;
	Ezong=0;
}
Stu::Stu(const Stu &S)
{
	name=new char[21];
	strcpy(name,S.name);
	birthDate.datecpy(S.birthDate);
	count++;
	courseNumber=S.courseNumber;
	for(int i=0;i<courseNumber;i++)
	{
		if(dynamic_cast<ElectiveCourse*>(courseList[i])==NULL)
		{ 
			courseList[i]=new ObligatoryCourse(S.courseList[i]->getName(),S.courseList[i]->getCredit());
		}
		else
		{
			courseList[i]=new ElectiveCourse(S.courseList[i]->getName(),S.courseList[i]->getCredit());
		}
	}
	OzongCredit=S.OzongCredit;
	Ezong=S.Ezong;
}
Stu::~Stu()
{
	delete[] name;
	count--;
	for(int i=0;i<courseNumber;i++)//释放内存 释放内存
	{
		//cout<<courseList[i]->getName()<<endl;
		//cout<<"shi fang"<<endl;
		delete courseList[i];
	}
}
bool Stu::setName(char * a)
{
	if(strlen(a)>20)
	{
		cout<<"The name is too long!"<<endl;
		return 0;
	}
	else
	{
		strcpy(name,a);
		return 1;
	}
}
bool Stu::setBirth(int y,int m,int d)
{
	bool x=birthDate.setAll(y,m,d);
	if(x)return 1;
	else return 0;
}
Stu & Stu::addCourse(Course * course)
{
	if(course==NULL)return *this;
	courseList[courseNumber]=course;
	courseNumber++;
	if(dynamic_cast<ElectiveCourse*>(course)==NULL)
	OzongCredit+=course->getCredit();
	else Ezong++;
	
	return *this;
}
double Stu::calcCredit()
{
	double ans=0;
	for(int i=0;i<courseNumber;i++)
	{
		if(dynamic_cast<ElectiveCourse*>(courseList[i])==NULL)
		{
			/*cout<<"OOO: ";
			cout<<Oweight*(double)courseList[i]->getScore()*(double)courseList[i]->getCredit()/(double)OzongCredit<<endl;*/
			ans+=Oweight*(double)courseList[i]->getScore()*(double)courseList[i]->getCredit()/(double)OzongCredit;
			
		}
		
		else 
		{
		/*cout<<"EEE: ";
			cout<<Eweight*(double)courseList[i]->getScore()/(double)Ezong<<endl;*/
			ans+=Eweight*(double)courseList[i]->getScore()/(double)Ezong;
		}
		
	}
	return ans;
} 
bool Stu::removeCoourse(int i)
{
	if(i<courseNumber)
	{
		if(dynamic_cast<ElectiveCourse*>(courseList[i])==NULL)
		OzongCredit-=courseList[i]->getCredit();
		else Ezong--;
		delete courseList[i];
		for(int k=i;k<courseNumber-1;k++)
		{
			courseList[k]=courseList[k+1];
		}
		courseList[courseNumber-1]=NULL;
		courseNumber--;
		cout<<"退课成功"<<endl;
	}
	else cout<<"退课失败"<<endl;
}
void Stu::vaCourse(int i)
{
	if(i<courseNumber)
	{
		try{
		if(dynamic_cast<ElectiveCourse*>(courseList[i])==NULL)
		{
			cout<<"#请输入成绩(0-100):";
			int x;
			cin>>x;
			while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cin>>x;
				}
			if(x<0||x>100)
			{
				throw myexception("the mark is invaild!!!");
			}
			courseList[i]->setScore(x);
			cout<<"#打分成功"<<endl;
		}
		else
		{
			cout<<"#请输入成绩(A-E):";
			char x;
			cin>>x;
			while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cin>>x;
				}
			if(x<65||x>69)
			{
				throw myexception("the mark is invaild!!!");
			}
			courseList[i]->setScore(x);
			cout<<"#打分成功"<<endl;
		}
	}catch(myexception ex)
	{
		cout<<ex.getmessage()<<endl;
	}
	}
	else cout<<"无此课程"<<endl;
}
