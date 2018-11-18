#include "Student.h"
#include "Date.h"
#include "ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include<iostream>
#include<cstring>
#include<typeinfo>
using namespace std;

int Student::count=0;

Student::Student(const char*const n,const Date &d)
    :birthDate(d)
{
    name=NULL;
    setName(n);
    count++;
    courseNumber=0;
}

Student::Student(const char*const n,int y,int m,int d)
    :birthDate(y,m,d)
{
    name=NULL;
    setName(n);
    count++;
    courseNumber=0;
}

Student::~Student()
{

    int i=courseNumber-1;
	while(i>0)
    {
		if (removeCourse(i))
            i--;
	}
    delete[]name;
    count--;
}

bool Student::removeCourse(int i)
{
	if(i<courseNumber)
    {
		for(int j=i;j<courseNumber-1;j++)
		{
			courseList[j]=courseList[j+1];
		}
		courseNumber--;
		return true;
	}
	else
		return false;
}

bool Student::removeCourse(const string& courseName)
{
    int i;
	for(i=0;i<courseNumber;i++)
    {
		if(courseName==courseList[i]->getname())
            break;
	}
	if(i<courseNumber)
    {
		return removeCourse(i);
	}
	else
		return false;
}

Student::Student(const Student &s)
    :birthDate(s.birthDate)
{
    name=NULL;
    setName(s.name);
    count++;
    courseNumber=0;
}

Student& Student::setName(const char *const n)
{
    if(name)
        delete[]name;
    name=new char[strlen(n)+1];
    strcpy(name,n);
    return *this;
}

/*void Student::print() const
{
	cout<<"Name:"<<name<<"\nBirthday:";
	birthDate.print();
	cout<<"\n";
}*/

ostream& operator<<(ostream& output,const Student& s)
{
	output<<"姓名："<<s.name<<"   出生日期："<<s.birthDate<<"绩点成绩："<<s.calcCredit()<<"     选课信息如下：\n";
	for(int i=0;i<s.courseNumber;i++)
    {
		output<<(*s.courseList[i])<<"\n";
	}
	return output;
}

Course& Student::operator[](int i)const
{
    if(i<0||i>=courseNumber)
    {
        throw MyException(student);
    }
	return (*courseList[i]);
}


/*Student& Student::addCourse(const string &courseName,int creditHour)
{
    if(courseNumber<MAXSIZE)
    {
        courseList[courseNumber++]=new Course(courseName,creditHour);
    }
    return *this;
}*/

Student& Student::addCourse(Course *course)
{
    if(courseNumber<MAXSIZE)
        courseList[courseNumber++]=course;
    return *this;
}

double Student::calcCredit()const
{
    int ocsum=0,ecsum=0,credit=0,num=0;
    for(int i=0;i<(*this).courseNumber;i++)
    {
        if(typeid(ObligatoryCourse)==typeid((*this)[i]))
        {
            ocsum=ocsum+((*this)[i].getScore())*((*this)[i].getcreditHour());
            credit=credit+((*this)[i]).getcreditHour();
        }
        else if(typeid(ElectiveCourse)==typeid((*this)[i]))
        {
            ecsum+=((*this)[i]).getScore();
            num++;
        }
    }
    if(credit==0&&num!=0)
        return 0.4*(ecsum/num);
    else if(credit!=0&&num==0)
        return 0.6*(ocsum/credit);
    else if(credit!=0&&num!=0)
        return 0.6*(ocsum/credit)+0.4*(ecsum/num);
    else
        return 0;
}
