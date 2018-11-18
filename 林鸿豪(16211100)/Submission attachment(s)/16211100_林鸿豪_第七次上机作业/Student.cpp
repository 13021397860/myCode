#include <iostream>
#include <string.h>
#include <typeinfo>
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "MyException.h"
#include "Student.h"
using namespace std;
int Student::counter=0;
Student::Student()
{
    courseNumber=0;
    StuName=new char[8];
    strcpy(StuName,"NOFOUND");
    birthDate=new Date(2017,1,1);
    counter++;
  //  cout<<"这是第"<<counter<<"个学生"<<endl;
}
void Student::setName(const char* name)
{
    len=strlen(name);
    len++;
    StuName=new char[len];
    strcpy(StuName,name);
}
Student::Student(const char* name, int y,int m,int d)
{
    courseNumber=0;
    counter++;
    setName(name);
    birthDate=new Date(y,m,d);
   // cout<<"这是第"<<counter<<"个学生"<<endl;
}
Student::Student(const Student &s)
{
    courseNumber=0;
    StuName=new char[8];
    strcpy(StuName,s.StuName);
    birthDate=new Date(s.birthDate->getYear(),s.birthDate->getMonth(),s.birthDate->getDay());
    counter++;
   // cout<<"这是第"<<counter<<"个学生"<<endl;
}
Student::~Student()
{
    delete StuName;
    delete birthDate;
    for (int i=0;i<courseNumber;i++)    delete courseList[i];//
   // delete [] courseList;//不需要
   /* for (int i=0;i<counter;i++)
    {
        counter--;
        cout<<"Student deleted\n";
        cout<<"还剩第"<<counter<<"个学生"<<endl;
    }*/
}

Student& Student::addCourse(Course *course)
{
    if (courseNumber>=MAX_SIZE)
        throw(MyException("FULL CLASS!"));
    else if (courseNumber<MAX_SIZE)
      {
          courseList[courseNumber++]=course;
      }
}

Student& Student::addCourse(const string &courseName, int creditHour)
{
    if (courseNumber<MAX_SIZE)
    {
      //  courseList[courseNumber++] = new Course(courseName,creditHour);
    }

}
/*
void Student::StuPrint() const
{
    StuNamePrint();
    StuDatePrint();
    if (courseNumber>0)
        for (int i=0;i<courseNumber;i++)
            courseList[i]->CoursePrint();
}*/
/*
fstream& operator<<(fstream& os,Student &s)
{
    os<<s.StuName<<" "<<*s.birthDate;
    if (s.courseNumber>0)
        for (int i=0;i<s.courseNumber;i++)
            os<<*s.courseList[i];
}*/

ostream& operator<<(ostream& os,Student &s)
{
    os<<"姓名："<<s.StuName<<"	出生日期："<<*s.birthDate;
    os<<"选课信息如下："<<endl;
    if (s.courseNumber>0)
        for (int i=0;i<s.courseNumber;i++)
            os<<*s.courseList[i];
    cout<<endl;
}

bool Student::removeCourse(int i)
{
    if (i>courseNumber||i<0)    throw(MyException("WRONG DELETE"));
    int j;
    delete courseList[i-1];
    for (j=i-1;j<courseNumber;j++)
        courseList[j]=courseList[j+1];
    courseNumber--;
    return 1;
}

void Student::setMark(int i)
{
    ObligatoryCourse c1;
    ElectiveCourse c2;
 /*   cout<<endl;
    cout<<typeid(*courseList[i-1]).name()<<endl;
    bool a=(typeid(*courseList[i-1])==typeid(c1));
    bool b=(typeid(*courseList[i-1])==typeid(c2));
    cout<<a<<" "<<b<<endl;*/
    if (typeid(*courseList[i-1])==typeid(c1))
    {
        int m;
        cin>>m;
        if (m<0||m>100) throw (MyException("WRONG MARK"));
        courseList[i-1]->setMark(m);
    }
    else if (typeid(*courseList[i-1])==typeid(ElectiveCourse))
    {
        char m;
        cin>>m;
        if (m>'E'||m<'A')   throw (MyException("WRONG MARK"));
        courseList[i-1]->setMark(m);
    }
}


 float Student::calCredit()const
 {
    ObligatoryCourse c1;
    ElectiveCourse c2;
    int markforO=0,markforE=0;
    int creditforO=0,numforE=0;
    for (int i=0;i<courseNumber;i++)
    {
        if (typeid(*courseList[i])==typeid(c1))
        {
            int mark=courseList[i]->getcreditHour()*courseList[i]->getScore();
            markforO+=mark;
            creditforO+=courseList[i]->getcreditHour();
        }
        else if (typeid(*courseList[i])==typeid(c2))
        {
            int mark=(courseList[i]->getScore());
            markforE+=mark;
            numforE++;
        }
    }
    int m1=markforO/creditforO,m2=markforE/numforE;
    float Credit=ObliWeight*m1+ElecWeight*m2;
    return Credit;
 }

 void Student::getCourseScore(int i)
{
    cout<<courseList[i-1]->getScore()<<endl;
}
