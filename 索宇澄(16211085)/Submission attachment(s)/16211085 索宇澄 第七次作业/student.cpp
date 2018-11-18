#include"student.h"
#include"date.h"
#include"ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include<iostream>
#include <string.h>
#include <typeinfo>
using namespace std;
int Student::counter=0;

ostream & operator<<(ostream & out, const Student & A)
{
    out <<"姓名："<< A.getName() <<"    出生日期："<< A.getBirthDate()<<"    积点成绩："<<A.calcCredit()<<", 选课信息如下："<<endl;
    for(int i=0;i<A.getcourseNumber();i++)
    {
    	out <<*(A.courseList[i])<<endl;
	}
    return out;
}


Student::Student()
{
	cout<<"ready"<<endl;
}

Student::Student(const char *Name, int y, int m, int d) :birthDate(y, m, d)
{
    name=NULL;
    setName(Name);
    counter++;
} 

Student::Student(const char *studentName, const Date &studentDate):birthDate(studentDate)
{
    name=NULL;
    setName(studentName);
	counter++;	
}

Student::Student(const Student &stud):birthDate(stud.birthDate)
{
    name=NULL;
    setName(stud.name);
    counter++;
}

bool Student::removeCourse(int i)
{
	if(i > courseNumber)
	return false;
	
	else
	{
        for(int k = i; k < courseNumber; k++)
        {
            courseList[ k - 1 ]=courseList[ k ];
        }
        
        courseNumber--;
		return true;
	}
}





double Student::calcCredit() const
{
    int a=0,b=0,c=0,d=0;
    double credit=0;
    for(int i=0; i<courseNumber; i++)
    {
        if(typeid(ObligatoryCourse)==typeid((*courseList[i])))
        {
            d+=courseList[i]->getCreditHour();
            a+=courseList[i]->getScore()*courseList[i]->getCreditHour();
        }
        else
        {
            c++;
            b+=courseList[i]->getScore();
        }
    }
    cout<<a<<" "<<d<<endl;
    if(c==0)
        credit=a/d;
    else if(d==0)
        credit=b/c;
    else
        credit=0.6*a/d+0.4*b/c;
    return credit;

}




Student &Student::setName(const char *studentName)
{
    if(studentName == NULL) delete[] studentName;
    name = new char[strlen(studentName)+1];
    strcpy(name, studentName);	
    return *this;
}

Student &Student::addCourse(Course *course)
{
    if(courseNumber >= MAX_SIZE)	cout<<"failed"<<endl;
    else
    {
        courseList[courseNumber] = course;
        courseNumber++;
    }
    return *this;	
}


void Student::printCourse() const
{
	for(int i = 0; i < courseNumber; i++)
    {
        cout<< "course : " << courseList[i] -> getCourseName() << endl
        	<< "credit hour ：" << courseList[i] -> getCreditHour() << endl
        	<<courseList[i] -> getScore()<<endl;
    }
}


Student::~Student()
{
	
	delete[] name;
	counter--; 
}
