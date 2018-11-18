#include "Student.h"
#include "Date.h"
#include "Date.h"
#include "MyException.h"
#include<iostream>
#include<string.h>
#include <typeinfo>
using namespace std;
int Student::count=0;

Student::Student(const char* const n,int y,int m,int d)
{ 
	Name=new char[strlen(n)+1];
	strcpy(Name,n);
	Birthdate.setDate(y,m,d);
	count++;
	cout<<count<<endl;
	courseNumber=0;
}
Student::Student(const Student &n)
{
	Name=new char[strlen(n.Name)+1];
	strcpy(Name,n.Name);
	Birthdate=n.Birthdate;
	count++;
	cout<<count<<endl;
}
Student& Student::addCourse(Course* course)
{
	courseList[courseNumber++]=course;
}
Student::~Student()
{
	int i=courseNumber-1;
	while (i>0)
	{
		if (removeCourse(i)) i--;
	}
	delete []Name;
	count--;
}
void Student::setName(const char* const n)
{
	if (Name) delete []Name;
	Name=new char[strlen(n)+1];
	strcpy(Name,n);
}
char* Student::getName()
{
	return Name;
}
Date Student::setBirthdate(int y,int m,int d)
{
	Birthdate.setDate(y,m,d);
	return Birthdate;
}
Date Student::getBirthdate()
{
	return Birthdate;
}
int Student::getCourseNumber()
{
	return courseNumber;
}
ostream& operator<<(ostream& output,Student& p){
	output<<"姓名："<<p.getName()<<"    出生日期："<<p.getBirthdate()<<"，    选课信息如下："<<endl;
	for (int i=0;i<=p.courseNumber-1;i++)
	{
		output<<*(p.courseList[i]);
	}
    return output;
}
Course& Student::operator[](int i){
	if (i<0||i>=courseNumber)
	{
		cerr<<"下标越界："<<i<<endl;
		exit(1);
		throw MyException(RANGE_ERROR);
	}
	return (*courseList[i]);
}
bool Student::removeCourse(int i){
	if (i<courseNumber)
	{
		delete courseList[i];
		for (int j=i;j<courseNumber-1;j++)
		{
			courseList[j]=courseList[j+1];
		}
		courseNumber--;
		return true;
	}
	else return false;
} 
double Student::calcCredit(){
	double ocsum1=0.0,ocsum2=0.0,ecsum1=0.0,ecsum2=0.0,sum=0.0;
	for(int i=0;i<=courseNumber-1;i++)
	{
		if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
		{
			ocsum1+=(double)((*courseList[i]).getCreditHour());
		}
		else if (typeid(ElectiveCourse)==typeid(*courseList[i]))
		{
			ecsum1++;
		}
	}
	for(int i=0;i<=courseNumber-1;i++)
	{
		if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
		{
			ocsum2+=0.6*((double)(*courseList[i]).getScore())*((double)(*courseList[i]).getCreditHour())/ocsum1;
		}
		else if (typeid(ElectiveCourse)==typeid(*courseList[i]))
		{
			ecsum2+=0.4*((double)(*courseList[i]).getScore())/ecsum1;
		}
	}
	sum=ocsum2+ecsum2;
	return sum;
}
