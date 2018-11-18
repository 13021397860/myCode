#include "student.h"
#include"date.h"
#include<string.h> 
#include<stdlib.h> 
#include<iostream>
using namespace std;

int Student::count=0;

Student::Student()
{
    name=NULL;
    CourseNumber=0;
}

Student::Student(const char *tname)
{
    name=(char*)malloc(strlen(tname)+1);
 	strcpy(name,tname);
 	count++;
 	CourseNumber=0;
}

Student::Student(const char *tname,const Date &d):birthday(d)
{
 	name=(char*)malloc(strlen(tname)+1);
 	strcpy(name,tname);
 	
 	count++;
 	CourseNumber=0;
}

Student::Student(const Student &S):birthday(S.birthday)
{
	
    name=(char*)malloc(strlen(S.name)+1);
    strcpy(name,S.name);
    count++; 
    CourseNumber=0;
}

void Student::setName(char *tname)
{
	delete name;
	name=(char*)malloc(strlen(tname)+1);
	strcpy(name,tname);
}

char* Student::getName()const
{
	char* s;
    s=(char*)malloc(strlen(name));
    strcpy(s,name);
    return s;
} 
Date Student::getBirthday()const
{
	return birthday;
}
void Student::PrintName()const
{ 
	printf("名字是:%s\n",name);
}

void Student::PrintBirthday()const
{
	printf("生日是:"); 
	cout<<birthday;
}

int Student::getCount()
{
	return count;
}
int Student::getCourseNumber()const
{
	return CourseNumber;
}

int Student::calcCredit()
{
	double Credit=0,OblitaryCredit=0,ElectiveCredit=0;
	for(int i=1;i<=CourseNumber;i++)
	{
		if( typeid(*this->CourseList[i])==typeid (OblitaryCourse) )
		{
			OblitaryCredit+=CourseList[i]->getCreditHour();
		} 
		if( typeid(*this->CourseList[i])==typeid (ElectiveCourse) )
		{
			ElectiveCredit+=1;
		} 
	}
	for(int i=1;i<=CourseNumber;i++)
	{
		if( typeid(*this->CourseList[i])==typeid (OblitaryCourse) )
		{
			Credit+=(CourseList[i]->getScore()*CourseList[i]->getCreditHour() / OblitaryCredit)*0.6;
		} 
		if( typeid(*this->CourseList[i])==typeid (ElectiveCourse) )
		{
			Credit+=(CourseList[i]->getScore() / ElectiveCredit)*0.4;
		} 
	}
	return Credit;
}
Student& Student::addCourse(Course *Course)
{
	if(CourseNumber<MAX_SIZE)
		{
			CourseList[++CourseNumber]=Course;
		} 
	else
		printf("%s的课程已满\n",name); 
}
//Student& Student::addCourse(const string &courseName,int creditHour)
//{
//	if(CourseNumber<MAX_SIZE)
//	{
//		Course *_course=new Course(courseName,creditHour);
//		CourseList[++CourseNumber]=_course;
//	}
//	else
//		printf("%s的课程已满\n",name);
//}

bool Student::removeCourse(int i)
{
	if(0<i&&i<=CourseNumber)
	{
		int k=i;
		
		delete(CourseList[k]);//先free掉这个点 
		
		while(k<=CourseNumber-1)
		{CourseList[k]=CourseList[k+1];k++;}

		CourseNumber--;
		return 1;
	}
	else return 0;
}

ostream &operator <<(ostream&out,const Student &S)
{
	string _name=S.getName();
	Date _birthday=S.birthday;
	int _CourseNumber=S.getCourseNumber();
	
	out<<_name<<" "<<_birthday<<",选课信息如下"<<endl; 
	for(int i=1;i<=_CourseNumber;i++)
	{
//		string _coursename=S.CourseList[i]->getName();
//		int  _creditHour=S.CourseList[i]->getCreditHour();
//		out<<"课程名:"<<_coursename<<"  "<<"学分:"<<_creditHour<<endl; 
		S.CourseList[i]->printCourse();
	} 
}
Student::~Student()
{
	for(int i=1;i<=CourseNumber;i++) 
	{
		free(CourseList[i]);
	}
	printf("%s 被析构了\n",name);
	delete[] name;
	count--;
}
