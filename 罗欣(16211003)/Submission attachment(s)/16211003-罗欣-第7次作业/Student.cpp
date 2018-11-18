#include "Student.h"
#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "MyException.h"
#include<iostream>
#include<cstring>
using namespace std;

ostream& operator<<(ostream& cout,Student& s)
{
    cout<<"Name: "<<s.name<<"   Birthday: ";
    cout<<s.birthday.GetYear()<<'-'<<s.birthday.GetMonth()<<'-'<<s.birthday.GetDay()<<endl;
    if(s.courseNumber>0)
    {
        for(int i=1;i<=s.courseNumber;i++)
        {
            cout<<*s.courseList[i];
        }
        s.calcCredit();
        cout<<"Point: "<<s.point<<endl;
    }
    else
        cout<<"No Course."<<endl;
    return cout;
}

int Student::Count=0;
Student::Student()
{
    courseNumber=0;
}
Student::Student(const char *pName)
{
    Count++;
    if(pName==NULL)
    {
        name=new char [1];
        name[0]='\0';
    }
    else
    {
        name=new char[strlen(pName)+1];
        strcpy(name,pName);
    }
    courseNumber=0;
    point=0;
    //ctor
}

Student::Student(const Student& data)
{
    Count++;
    if(name != NULL)
        delete [] name;
    name=new char[strlen(data.name)+1];
    name=data.name;
    Date bd=data.birthday;
    /*
    if(birthday!=NULL)
    {
        delete birthday;
    }
    birthday=new Date;
    */
    birthday.SetDate(bd.GetYear(),bd.GetMonth(),bd.GetDay());
}

Student::~Student()
{
    delete[] name;
    //delete birthday;
    delete[] courseList;
    Count--;
    //dtor
}

void Student::SetName(char *pName)
{
    if(name!=NULL)
    {
        delete[]name;
    }
    if(!pName)
    {
        name=new char[1];
        name[0]='\0';
    }
    else
    {
        name=new char[strlen(pName)+1];
        strcpy(name,pName);
    }
}

void Student::SetBirthday(Date d)
{
    birthday.SetDate(d.GetYear(),d.GetMonth(),d.GetDay());
}

Date& Student::GetBirthday()
{
    return birthday;
}

char* Student::GetName()
{
    return name;
}

void Student::PrintStu()
{
    cout<<"Name: "<<name<<"."<<endl;
}

int Student::GetCount()
{
    return Student::Count;
}


Student &Student::addCourse(Course *course)
{
    if(course!=NULL)
    {
        if(courseNumber<MAX_SIZE)
        {
            courseNumber++;
            courseList[courseNumber]=course;
        }
    }

    return *this;
}

void Student::printcourselist()
{
    if(courseNumber>0)
    {
        for(int i=1;i<=courseNumber;i++)
        {
            cout<<*courseList[i];
        }

    }
    else
        cout<<"No Course."<<endl;

}

void Student::quitCourse(int &n)
{
    if(removeCourse(n))
    {
        for(int i=n;i<courseNumber;i++)
            courseList[i]=courseList[i+1];
        courseNumber--;
    }
    else
        cout<<"Wrong Course."<<endl;
}

bool Student::removeCourse(int &n)
{
    if(n<=courseNumber and n>0)
        return 1;
    else
        return 0;
}

void Student::setscore(int &no)
{
    int m;
    cout<<"enter the grade: ";
    while(cin>>m)
    {
        try
        {
            MyException Exception(2);
            Exception.GradeException(m);
            courseList[no]->setmark(m);
            break;
        }
        catch(int &num)
        {
            cout<<"illegal grade"<<endl<<"input again: ";
        }
    }


}

void Student::calcCredit()
{
    int i=1;
    int iE=0;
    double ObligatoryCredit=0;
    double ElectiveCredit=0;
    double ObligatoryHour=0;
    double wO=0.6;
    double wE=0.4;
    point=0;
    while(removeCourse(i))
    {
        if(dynamic_cast<ObligatoryCourse*>(courseList[i]))
        {
            ObligatoryHour+=courseList[i]->getcreditHour();
            ObligatoryCredit+=(courseList[i]->getScore()*courseList[i]->getcreditHour());
        }
        else if(dynamic_cast<ElectiveCourse*>(courseList[i]))
        {
            ElectiveCredit+=courseList[i]->getScore();
            iE++;
        }
        i++;
    }
    if(ObligatoryHour)
    {
        point+=(ObligatoryCredit*wO)/ObligatoryHour;
    }
    if(iE)
    {
        point+=(ElectiveCredit*wE)/iE;
    }
}
