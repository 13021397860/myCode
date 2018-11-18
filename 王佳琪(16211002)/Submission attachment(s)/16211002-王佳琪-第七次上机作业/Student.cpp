#include "Student.h"
#include<iostream>
#include<cstring>
#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"

using namespace std;

void Student::calcCredit()
{
	r1 = 0; r2 = 0;
	qz1 = 0.6;
	qz2 = 0.4;
	int cre1 = 0,cre2 = 0;
	for(int i = 1;i <= courseNumber;i++)
	{
		if(dynamic_cast<ObligatoryCourse*>(courseList[i]))
		{
			r1 +=  courseList[i]->getCreditHour() * courseList[i]->getScore();
			cre1 += courseList[i]->getCreditHour();//必修课总学分 
			//cout<<"r1"<<r1<<' '<<"cre1"<<cre1<<endl;
		}
		else
		{
			r2 +=  courseList[i]->getScore();//选修课总成绩 
			cre2 ++;//选修课门数 
			//cout<<"r2"<<r2<<" "<<"cre2"<<cre2<<endl;
		}
	} 
	if(cre1 == 0) r1 = 0;
		else{
			r1 = qz1 *(r1/cre1);
			//cout<<" "<<r1<<endl;
		}
		if(cre2 == 0) r2 = 0;
		else{
			r2 = qz2 *(r2/cre2);
			//cout<<" "<<r2<<endl;
		}
}

ostream& operator<< (ostream& os, Student& s)
{
	os<<"姓名："<<s.name<<"   "
	<<"出生日期：" <<s.birthDay->getYear()<<"-"<<s.birthDay->getMonth()<<"-"<<s.birthDay->getDay()<<endl;
	for(int i = 1;i<=s.courseNumber;i++)
	{
		os<<"课程名 : "<<s.courseList[i]->getName()<<"   "<<"学分 : "<<s.courseList[i]->getCreditHour()
		<<"   "<<"成绩 ："<<s.courseList[i]->getScore()<<endl;
	}
	s.calcCredit(); 
	os<<"绩点成绩："<<s.r1+s.r2<<endl;
	return os;
}

Student::Student(const char *n/*, const Date *dt */)
{
    if(n != NULL)
    {
        name = new char[strlen(n)+1];
        strcpy(name,n);
    }
    else{
        name = new char[1];
        name[0] = '\0';
    }
    birthDay = NULL;

    /*if(dt != NULL)
    {
    	birthDay = new Date;

	}*/

	birthDay = new Date;
    count++;
    courseNumber = 0;
}

Student::~Student(){
	delete [] name;
	name = NULL;
	delete birthDay;
	birthDay = NULL;
	count--;
	delete [] courseList;
    cout<<"The class is destroyed."<<endl;
}

Student::Student(const Student &student)
{
	count++;
	name = new char[strlen(student.name)+1];
    strcpy(name,student.name);
    if(birthDay !=NULL)
	delete birthDay;
	birthDay = new Date;
	Date *bd = student.birthDay;
    birthDay->setDate(bd->getYear(), bd->getMonth(), bd->getDay());
}

void Student::SetName(const char *n)
{
	if(name != NULL)
	delete [] name;
    if(n == NULL)
    {
        name = new char[1];
        name[0] = '\0';
    }
    else{
        name = new char[strlen(n)+1];
        strcpy(name,n);
    }
}

void Student::SetBirthday(Date *bd)
{
	if(birthDay !=NULL)
	delete birthDay;
	birthDay = new Date;
    birthDay->setDate(bd->getYear(), bd->getMonth(), bd->getDay());
}

char* Student::GetName()
{
    return name;
}

Date &Student::GetBirthday()
{
    return *birthDay;
}

void Student::print()
{
    cout<<name<<endl;
}

int Student::count = 0;

bool Student::removeCourse(int a)
{
	if(a<=courseNumber && a>0)
	{
		for(int i = a;i<courseNumber;i++)
		{
			courseList[i] = courseList[i+1];
		}
		courseNumber--;
		
		return 1;
	}
	else return 0;
}

Student& Student::addCourse(Course *course)
{
	if(course != NULL)
	 {
	 	if(courseNumber == MAX_SIZE)
	 	{
	 		cout<<"Already Full!"<<endl;
		 }
		else{
			courseNumber++;
			courseList[courseNumber] = course;
		}
	 }
	return *this;
}

void Student::setScore(int num1,int score1)
{
		courseList[num1]->setScore(score1);
}


