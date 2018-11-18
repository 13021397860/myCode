#include "student.h"
#include "Date.h"
#include "Course.h"
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include <typeinfo>
using namespace std;
int student::counter=0;
student::student()
{
    courseNumber=0;
    counter++;
    birthDate=Date(1,1,1);
    name=new char[100];
}
student::student(const char* const x)
{
    courseNumber=0;
    counter++;
    birthDate=Date(1,1,1);
    name=new char[100>strlen(x)+1?100:strlen(x)+1];
    strcpy(name,x);
}

student::~student()
{
    counter--;
    delete []name;
//    int x=courseNumber;
//    while(x--)
//        *this.removeCourse(1);
    delete []courseList;
    printf("student类析构函数被调用\n");
}
student::student(const student& x)
{
    name=new char[strlen(x.name)+1];
    strcpy(name,x.name);
    birthDate=x.birthDate;
}
void student::setname(const char * const x)
{
    if(strlen(x)>100)
        name=new char[strlen(x)+1];
    strcpy(name,x);
}
char *student::getname()const
{
    return name;
}

void student::setBirthDate(const Date &x)
{
    birthDate=Date(x);
}
const Date student::getBirthDate()const
{
    return birthDate;
}
int student::getCounter()
{
    return counter;
}
student& student::addCourse(Course *course)
{
    if(courseNumber<MAX_SIZE-1)
    {
        printf("选课成功\n");
        courseList[++courseNumber]=course;
    }
    else
    {
        printf("选课失败\n");
    }
    return *this;
}
student& student::addCourse(const string &courseName, int creditHour,int st)
{
    if(courseNumber<MAX_SIZE-1)
    {
        printf("success\n");
        Course *tem;
//        tem=new(Course);
        if(st)
            tem=new(ObligatoryCourse);
        else
            tem=new(ElectiveCourse);
        (*tem).setName(courseName);
        (*tem).setCreditHour(creditHour);
        courseList[++courseNumber]=tem;
    }
    else
    {
        printf("fail\n");
    }
    return *this;
}
void student::printCourse()
{
    for(int i=1;i<=courseNumber;i++)
    {
            cout<<(courseList[i]);
    }
}
int student::getcn()
{
    return courseNumber;
}
bool student::removeCourse(int i)
{
//    try{
        if(i>0&&i<=courseNumber)
    {
        delete courseList[i];
        for(int j=i;j<courseNumber;++j)
            courseList[j]=courseList[j+1];
        --courseNumber;return true;
    }
//        else throw
//            Course_Existent_Exception()
//    }
//    catch(Exception &x)
//
//    {
//        cout<<x.what()<<endl;
//    }
    return false;
}
void student::fen(string tarname,int* fen)
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
void student::fen(string tarname,char* fen)
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
int student::getfen(string tarname)
{
    for(int i=1;i<=courseNumber;++i)
    {
        if(tarname==courseList[i]->getName())
        {
//            printf("!!!\n");
            return courseList[i]->getScore();
        }
    }
}
double student::calcCredit()
{
//    printf("!!!!\n");
    double bisum=0,bizhi=0,xuanzhi=0;
    int xuansum=0;
//    ObligatoryCourse tem;
//    char oh[40];
//    strcpy(oh,typeid(tem).name());
//    cout<<oh<<endl;
    for(int i=1;i<=courseNumber;++i)
    {
//        printf("%d\n",i);
//        printf("%d\n",i);
//        cout<<typeid(courseList[i]).name()<<endl;
//        if(strcmp(typeid(courseList[i]).name(),oh)==0)
//            printf("000\n");
        if(courseList[i]->who()==2)
            {
                if(courseList[i]->getScore()==-1)
                    continue;
                bisum+=courseList[i]->getCreditHour();
                bizhi+=courseList[i]->getScore()*courseList[i]->getCreditHour();
            }
        else
            {
                if(courseList[i]->getScore()==-1)
                    continue;
                ++xuansum;
                xuanzhi+=courseList[i]->getScore();
            }
    }
    double re=0;
    if(bisum>=1.00)
        re+=0.6*(double)bizhi/(double)bisum;
    if(xuansum>=1.000)
        re+=0.4*(double)xuanzhi/(double)xuansum;
    return re;
}
