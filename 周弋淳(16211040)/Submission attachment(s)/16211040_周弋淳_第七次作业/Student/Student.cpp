#include "Student.h"
#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "MyException.h"
#include<iostream>
#include<cstring>
#include<typeinfo>

using namespace std;

int Student::count = 0;

Student::Student(const char *n,const int y,const int m,const int d):birthDate(y,m,d)
{
    name = NULL;
    Student::setName(n);
    count++;
    courseNumber=0;
}

Student::Student(const Student &n):birthDate(n.birthDate)
{
    length = n.length;
    name=NULL;
    Student::setName(n.name);
    count++;
    courseNumber=n.courseNumber;
}

Student& Student::setName(const char *const n)
{
    if(name)
        delete []name;
    length = strlen(n);
    name = new char[length+1];
    strcpy(name,n);
    return *this;
}

char* Student::getName() const
{
    return name;
}

Date Student::getBirthDate() const
{
    return birthDate;
}

Student& Student::addCourse(Course *course)
{
    if(courseNumber < MAX_SIZE)
    {
        if(dynamic_cast<ObligatoryCourse*>(course))
            courseList[courseNumber] = new ObligatoryCourse;
        else if(dynamic_cast<ElectiveCourse*>(course))
            courseList[courseNumber] = new ElectiveCourse;
        *courseList[courseNumber]=*course;
        //courseList[courseNumber]=course;
        courseList[courseNumber]->setIfCourseAdded(1);
        courseNumber++;
        return *this;
    }
}

/*Student& Student::addCourse(const string &courseName,int creditHour)
{
    if(courseNumber < MAX_SIZE)
    {
        courseList[courseNumber] = new Course;
        courseList[courseNumber]->setName(courseName);
        courseList[courseNumber]->setCreditHour(creditHour);
        courseNumber++;
        return *this;
    }
}*/

void Student::courseListPrint() const
{
    for(int i=0;i<courseNumber;i++)
    {
        cout<<"              已选课程"<<i+1<<"："<<courseList[i]->getName()<<"   学分："<<courseList[i]->getCreditHour()<<"\n";
    }
}

int Student::getCount()
{
    return count;
}

ostream& operator<<(ostream& output, const Student& s)
{
    output<<"姓名："<<s.name<<"  出生日期："<<s.birthDate<<"  选课信息如下：\n";
    for(int i=0;i<s.courseNumber;i++)
    {
        output<<"          "<<*s.courseList[i]<<"\n";
    }
    return output;
}

bool Student::removeCourse(const int i)
{
    if(i<=courseNumber)
    {
        for(int j=i-1;j<courseNumber-1;j++)
        {
            courseList[j]=courseList[j+1];
        }
        courseNumber--;
        return 1;
    }
    else
        return 0;
}

bool Student::ifCourseAdded(const Course &c) const
{
    for(int i=0;i<=courseNumber-1;i++)
    {
        if(c.getName()==courseList[i]->getName())
            return 1;
    }
    return 0;
}

void Student::setCourseGrade(const int i)
{
    if(i<=courseNumber)
    {
        if(typeid(ObligatoryCourse)==typeid(*courseList[i-1]))
        {
            cout<<"请输入成绩(0~100):";
            int m;
            cin>>m;
            if(m<0||m>100)
                throw MyException("错误的成绩数据！");
            dynamic_cast<ObligatoryCourse*>(courseList[i-1])->setMark(m);
        }
        else if(typeid(ElectiveCourse)==typeid(*courseList[i-1]))
        {
            cout<<"请输入成绩等级(A~E):";
            char g;
            cin>>g;
            if(g<'A'||g>'E')
                throw MyException("错误的成绩数据！");
            dynamic_cast<ElectiveCourse*>(courseList[i-1])->setGrade(g);
        }
        courseList[i-1]->setIfCourseScoreSet(1);
    }
}

double Student::calcCredit() const
{
    int sum1,sum2,num1,num2;
    double sum;
    sum1=sum2=num1=num2=sum=0;
    for(int i=0;i<=courseNumber-1;i++)
    {
        if(courseList[i]->getIfCourseScoreSet()==1&&typeid(ObligatoryCourse)==typeid(*courseList[i]))
        {
            sum1+=courseList[i]->getScore()*courseList[i]->getCreditHour();
            num1+=courseList[i]->getCreditHour();
        }
        else if(courseList[i]->getIfCourseScoreSet()==1&&typeid(ElectiveCourse)==typeid(*courseList[i]))
        {
            sum2+=courseList[i]->getScore();
            num2++;
        }
    }
    if(num1!=0&&num2!=0)
        sum=0.6*((double)sum1/(double)num1)+0.4*((double)sum2/(double)num2);
    else if(num1==0&&num2!=0)
        sum=0.4*((double)sum2/(double)num2);
    else if(num1!=0&&num2==0)
        sum=0.6*((double)sum1/(double)num1);
    return sum;
}

int Student::getCourseNumber() const
{
    return courseNumber;
}

Student::~Student()
{
    for(int i=0;i<courseNumber;i++)
        delete courseList[i];
    count--;
    delete []name;
}
