//
// Created by zjp on 2017/4/17.
//
#include <iostream>
#include <iomanip>
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "student.h"
#include <typeinfo>
#include <fstream>
#include "myException.h"
using namespace std;

int student::count=0;

student::~student()
{
    int i=courseNumber-1;
    while(i>0)
        if(removeCourse(i))
            i--;
    delete[] name;
    count--;
}

student::student(const char *n,int y,int m,int d):birthDate(y,m,d)
{
    setName(n);
    courseNumber=0;
    count++;
}


student::student(const student &s):birthDate(s.birthDate)
{
    name=new char[strlen(s.name)+1];
    strcpy(name,s.name);
    courseNumber=s.courseNumber;
    count++;
}

void student::setName(const char * const n)
{
    name=new char[strlen(n)+1];
    strcpy(name,n);
}

const char* student::getName(void) const
{
    return name;
}

int student::getNumber() const
{
    return courseNumber;
}

void student::printName() const
{
    cout << name << "\n";
}


int student::getCount() const
{
    return count;
}

void student::printBirthDate(void) const
{
    cout << "The birday of the student \"" << name << "\" is " << birthDate.getDay() << '.' << birthDate.getMonth() << '.' << birthDate.getDay() << endl;
}

void student::printBasicInfo() const
{
    cout << setw(15) << left << "Name" << name << endl;
    cout << setw(15) << left << "Birthday";
    cout << birthDate.getYear() << '-' << birthDate.getMonth() << '-' << birthDate.getDay() << endl;
    cout << "\nSeleted Course:\n";
    cout << setw(15) << left << "course name" << "credithour" << "mark" << endl;
    for(int i=0;i<courseNumber;i++)
    {
        cout << setw(15) << left << courseList[i]->getName();
        cout << "     " <<courseList[i]->getCreditHour() << endl;
    }
    cout << "Information All Shown\n";
    for(int i=0;i<50;i++)
        cout << '*';
    cout << endl << endl;
}

student& student::addCourse(course *c)
{
    courseNumber++;
    course *temp=c;
    courseList[courseNumber-1]=temp;
    return *this;
}

/*student& student::addCourse(const string &cName,const int cHour)
{
    course *c=new course(cName,cHour);
    return addCourse(c);
}*/

bool student::removeCourse(const int i)
{
    if(i<=courseNumber)
    {
        delete  courseList[i];
        for(int j=i-1;j<courseNumber-1;j++)
            courseList[j]=courseList[j+1];
        courseNumber--;
        return true;
    }
    else
        return false;
}

bool student::setCourseScore()
{
    cout << "设置成绩：\n";
    if(typeid(ObligatoryCourse)==typeid(*courseList[courseNumber-1])) {
        cout << "请输入该必修课的成绩(范围：0~100)：";
        int mark;
        while(1) {
            cin >> mark;
            try {
                if(cin.fail() || mark<0 || mark>100)
                    throw myException(SCORE_INVALID);
            }
            catch(myException &exc1) {
                cin.clear();
                cin.ignore();
                cout << exc1.what();
                continue;
            }
            break;
        }
        dynamic_cast<ObligatoryCourse *>(courseList[courseNumber-1])->setMark(mark);
    }
    else if(typeid(ElectiveCourse)== typeid(*courseList[courseNumber-1])) {
        cout << "请输入该选修课的成绩(范围：A-E):";
        char grade;
        while(1) {
            cin >> grade;
            try {
                if(grade<'A' || grade>'E')
                    throw myException(SCORE_INVALID);
            }
            catch(myException &exc2) {
                cout << exc2.what();
                continue;
            }
            break;
        }
        dynamic_cast<ElectiveCourse *>(courseList[courseNumber-1])->setGrade(grade);
    }
    return 1;
}

double student::calcCredit() const
{
    int o_sum=0,e_sum=0;
    double credit=0;
    for(int i=0;i<courseNumber;i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
            o_sum+=courseList[i]->getCreditHour();
        else if(typeid(ElectiveCourse)== typeid(*courseList[i]))
            e_sum+=1;
    }
    for(int i=0;i<courseNumber;i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
            credit+=0.6*(courseList[i]->getScore())*((double)(courseList[i]->getCreditHour())/o_sum);
        else if(typeid(ElectiveCourse)== typeid(*courseList[i]))
            credit+=0.4*(courseList[i]->getScore())/(double)e_sum;
    }
    return credit;
}

void student::printInfo(student &s) const
{
    ofstream outfile("StudentInfo.txt",ios::out);
    outfile << s << endl;
}

ostream& operator << (ostream &os,const student &s)
{
    os << "姓名：" << s.getName() << " 出生日期：" << s.birthDate;
    if(!s.getNumber())
    {
        os << "，当前暂未选课\n";
    }
    else {
        os << "\n当前已选课程数为：" << s.getNumber();
        os << "，选课信息如下：\n";
        for (int i = 0, counter = 1; i < s.getNumber(); i++)
            os << "   " << counter++ << '.' << *(s.courseList[i]) << "\n";
    }
    return os;
}

student::student() {}
