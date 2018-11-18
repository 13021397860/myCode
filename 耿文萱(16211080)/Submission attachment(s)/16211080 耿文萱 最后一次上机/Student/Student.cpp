#include "Student.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Date.h"
#include <typeinfo>
#include <iostream>
#include <string.h>
#include "MyException.h"
using namespace std;

int Student::count=0;

Student::Student(const char* const n,int a, int b,int c)
:birthDate(a, b, c)
{
    name=NULL;
    setName(n);
    courseNumber=0;
    count++;
     //ctor
}

Student::~Student()
{
    int i=courseNumber-1;
	while(i>0)
    {
		if (reCourse(i))
		i--;
	}
	delete[] name;
	count--;//dtor
}

double Student::calcCredit()const
{
    int ocredit=co();
    int enu=ce();
    //cout<<ocredit<<" "<<enu<<endl;
    int oa=0;
    int ea=0;
    for(int i=0; i<courseNumber;i++)
    {
        if(typeid(ObligatoryCourse)==typeid((*courseList[i])))
            oa+=courseList[i]->getScore()*(courseList[i]->getCreditHour());
        if(typeid(ElectiveCourse)==typeid((*courseList[i])))
            ea+=courseList[i]->getScore();
    }
    //cout<<oa<<endl;
    //cout<<ea<<endl;
    double result=0;
    if(ocredit>0)
        result+=0.6*oa/ocredit;
    if(enu>0)
        result+=0.4*ea/enu;
    return result;

}

int Student::co() const
{
	int totalCredit=0;
	for(int i=0;i<courseNumber;i++){
		totalCredit+=courseList[i]->getO();
	}
	return totalCredit;
}

int Student::ce() const
{
	int number=0;
	for(int i=0;i<courseNumber;i++)
    {
		number+=courseList[i]->getE();
	}
	return number;
}


/*Student& Student::addCourse(const string &courseName,int creditHour)
{
    if(courseNumber<MAX_SIZE)
    {
        courseList[courseNumber++]=new Course(courseName, creditHour);
    }
    return courseList;
}*/

Student& Student::addCourse(Course *course)
{
	if(courseNumber<MAX_SIZE)
    {
		courseList[courseNumber++]=course;
	}
	cout<<courseNumber<<endl;
	return (*this);
}


Student::Student(const Student& d)
:birthDate(d.birthDate)
{
    name=NULL;
    setName(d.name);
    count++;
}

/*void Student::print()
{
    cout<<name<<endl;
    cout<<birthDate<<endl;
   for(int i=0;i<courseNumber;i++)
    {
        cout<<*courseList[i];
        courseList[i]->print1();
    }
}*/

ostream& operator << (ostream& out,const Student& d)
{
   out<<"姓名："<<d.name<<"出生日期："<<d.birthDate<<"选课信息如下\n";
   for(int i=0;i<d.courseNumber;i++)
    {
        out<<i+1<<" "<<*d.courseList[i];
        //courseList[i]->print1();
    }
   return out;
}

void Student::setName(const char *n)
{
    if (name) delete[] name;
    name=new char[strlen(n)+1];
    strcpy(name, n);
}

bool Student::reCourse(int x)
{
    if(x<courseNumber)
    {
        delete courseList[x];
        for(int i=x;i<courseNumber-1;i++)
        {
            courseList[i]=courseList[i+1];
        }
        courseNumber-=1;
        return true;
    }
    else
    {
        return false;
    }
}


char* Student::getname()
{
    return name;
}

int Student::getcount()
{
    return count;
}

int Student::gety()
{
    int y;
    y=birthDate.getDate1();
    return y;
}
