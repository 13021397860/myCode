#include "Student.h"
#include"Date.h"
#include<iostream>
#include<cstring>
#include<iomanip>
#include"Course.h"
#include<typeinfo>
using namespace std;
int Student::count = 0;

void Student::printName() const
{
    cout<<name;
}
Student::Student(const char* const &s, int &y, int &m, int &d):birthDate(y, m, d)
{
    name = NULL;
    setName(s);
    courseNumber = 0;
    count++;
}

Student::~Student()
{
    //for(int i = 0; i < courseNumber-1; i++) delete courseList[i];
    if(name != NULL)delete[] name;
    count--;
}
Student::Student(const Student &s):birthDate(s.birthDate)
{
    name=NULL;
    setName(s.name);
    count++;
}

void Student::setName(const char* const s)
{
    if(name) delete[] name;
    name = new char[strlen(s)+1];
    strcpy(name, s);
}
Student& Student::addCourse(Course *&course)
{
    if(courseNumber < MAX_SIZE) courseList[courseNumber++] = course;
    else
    {
        cout<<"课程数已满\n";
    }
    return *this;
}
/*Student& Student::addCourse(const string &courseName, int creditHour)
{
    if(courseNumber < MAX_SIZE)
    {
        courseList[courseNumber++] = new Course(courseName, creditHour);
    }
    else
    {
        cout<<"课程数已满\n";
    }
    return *this;
}*/
ostream& operator<<(ostream &Cout, const Student &stu)
{
    Cout<<stu.name<<"   "<<"出生日期："<<stu.birthDate<<", 选课信息如下：\n";
    for(int i = 0; i < stu.courseNumber; i++)
    {
        Cout<<*(stu.courseList[i]);
        Cout<<"成绩："<<stu.courseList[i]->getScore()<<endl;
    }
    return Cout;
}
bool Student::removeCourse(int i)
{
    if(i > courseNumber) return 0;
    else
    {
        for(int j = i; j < courseNumber-1; j++) courseList[j] = courseList[j+1];
        delete courseList[courseNumber-1];
        courseNumber--;
        return 1;
    }
}
Student::Student(const char* const n, const Date &date):birthDate(date)
{
    name=NULL;
    setName(n);
    count++;
    courseNumber=0;
}
double Student::calcCredit()
{
    double sumo = 0, sume = 0;//o表示必修课，e表示选修课， 总学分
    double gradeo = 0, gradee = 0;//成绩
    double credit = 0;
    for(int i = 0; i < courseNumber; i++)
    {
        if(typeid(ObligatoryCourse) == typeid(*(courseList[i])))
        {
            sumo += (double)(courseList[i]->getcreditHour());
            gradeo += (double)(courseList[i]->getScore()) * (double)(courseList[i]->getcreditHour());
        }
        else
        {
            sume += (double)(courseList[i]->getcreditHour());
            gradee += (double)(courseList[i]->getScore());
        }
    }
    credit = 0.6 * gradeo / sumo + 0.4 * gradee / sume;
    return credit;
}
int Student::getScore(int num)const
{
    cout<<courseList[num-1]->getScore()<<endl;
}
int Student::getCredit()
{
    cout<<calcCredit()<<endl;
}
