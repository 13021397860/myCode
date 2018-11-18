#include<iostream>
#include<cstring>
#include<typeinfo>
#include"Date.h"
#include"Student.h"
#include"Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
using namespace std;
int Student::count=0;
Student::Student()
{
	count++;
	count_1=0;
}
Student::Student(const char *const n,Date &t):birthday(t)
{
	sname= new char [strlen(n)+1];
	strcpy(sname,n);
	count++;
}
Student::Student(Student &t)
{
	birthday=t.birthday;
	sname=t.sname;
	count++;
}
Student::~Student()
{
	count--;
}
void Student::setName(char *n)
{
	sname= new char [strlen(n)+1];
	strcpy(sname,n);
}
void Student::setBirthday(const Date &d)
{
	birthday=d;
}
char Student::getName() const
{
	return *sname;
}
Date Student::getBirthday()
{
	cout<<birthday.get_month()<<"/"<<birthday.get_day()<<"/"<<birthday.get_year()<<endl;
}
void Student::printStudent()
{
	cout<<sname<<" ";
	cout<<birthday<<endl;	
}
int Student::getcount() const
{
	cout<<"count is "<<count<<endl;
}
Student& Student::addCourse(Course *c)
{
	count_1++;
	courseList[count_1]=c;
	string a;
	a=c->getCourseName();
	cout<<a<<" has been elected"<<endl;
	return *this;
}
ostream& operator << (ostream &output, Student &s)
{
	output<<"Name: "<<s.sname<<"    Birthday: "<<s.birthday<<", the chosen courses are:\n";
	for(int i=s.count_1;i>=1;i--){
		cout<<*(s.courseList[i])<<endl;
	}
	return output;
}
bool Student::removeCourse(int i)
{
	if(count_1==0){
		return 0;
	}
	else{
		count_1--;
		delete courseList[i];
		for(int j=i;j<=count_1;j++){
			courseList[j]=courseList[j+1];
		}
		return 1;
	}
} 
int Student::getCaleCredit()
{
	
}
int Student::getCourseNumber()
{
	return courseNumber;
}
Course *Student::outputList()
{
	for(int i=1;i<=courseNumber;i++){
		cout<<*(courseList[i])<<endl;
	}
}
Course *Student::getList(int n)
{
	return courseList[n];
}
