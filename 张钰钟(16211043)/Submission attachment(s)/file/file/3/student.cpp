#include "student.h"
#include<iostream>
#include "date.h"
#include<cstring>
using namespace std;
Student::Student()
{
    int courseNumber=0;
    count++;
    //ctor
}

Student::Student(const Student& student)
{
    setStudentName(student.name);
    birthDate=student.birthDate;
    count++;
}



Student::~Student()
{
    count--;
    delete []name;

    //dtor
}

void Student::setStudentBirthDate(int y,int m,int d)
{
    birthDate.setDate(y,m,d);
}


void Student::setStudentName(const char* nam)
{
    delete []name;
    name=new char[strlen(nam)+1];
    strcpy(name,nam);
}

int Student::getStudentBirthYear()
{
    return birthDate.getDateYear();
}

int Student::getStudentBirthMonth()
{
    return birthDate.getDateMonth();
}

int Student::getStudentBirthDay()
{
    return birthDate.getDateDay();
}


char* Student::getStudentName()
{
    return name;
}

int Student::count=0;

int Student::getCount()
{
    return count;
}

void Student::printBirthDate()
{
    cout<<getStudentBirthYear()<<"-"<<getStudentBirthMonth()<<"-"<<getStudentBirthDay()<<endl;
}

Student& Student::addCourse(Course *course)
{
    courseList[courseNumber]=course;
    courseNumber++;
}


void Student::print()
{
    cout<<"name: "<<getStudentName()<<endl;
    cout<<"birthday: ";printBirthDate();
    cout<<"the course: "<<endl;
    for(int i=0;i<courseNumber;i++)
    {cout<<"name :"<<courseList[i]->getName()<<endl;cout<<"creditHour :"<<courseList[i]->getCreditHour()<<endl;}
}

/*Student Student::operator<<(int)
{
    cout<<"姓名: "<<getStudentName()<<"出生日期: ";printBirthDate();cout<<",选课信息如下:"<<endl;
    for(int i=0;i<courseNumber;i++)
    {
        cout<<"课程名: "<<courseList[i]->getName()<<"学分: "<<courseList[i]->getCreditHour()<<endl;
    }
}
*/

bool Student::removeCourse(int i)
{
    if(courseList[i-1]==NULL)
        return false;
    else
    {
        delete courseList[i-1];
        for(int t=i-1;t<courseNumber-1;t++)
        {
            courseList[t]=courseList[t+1];
        }
        courseList[courseNumber-1]=NULL;
        return true;
    }
}


void Student::fen(string tarname,int* fen)
{
    for(int i=1;i<=courseNumber;++i)
    {
        if(tarname==courseList[i]->getName())
        {
//            printf("!!!\n");
            courseList[i]->setGrade(*fen);
        }
    }
}
void Student::fen(string tarname,char* fen)
{
    for(int i=1;i<=courseNumber;++i)
    {
        if(tarname==courseList[i]->getName())
        {
//            printf("!!!\n");
            courseList[i]->setGrade(*fen);
        }
    }
}

double Student::calcCredit()
{
    double sum1=0;double sum2=0;int xf=0;
    for(int i=0;i<obno;i++)
    {
        xf+=courseList[i]->getCreditHour();
    }
    for(int i=0;i<obno;i++)
    {
        sum1+=courseList[i]->getScore()*(courseList[i]->getCreditHour()/xf);
    }
    xf=courseNumber-obno;
    for(int i=obno;i<courseNumber;i++)
    {
        sum2+=courseList[i]->getScore()/xf;
    }
    return(0.6*sum1+0.4*sum2);
}



