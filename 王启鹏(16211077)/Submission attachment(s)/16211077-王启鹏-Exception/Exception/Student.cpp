#include "Student.h"
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int Student::Count=0;
Student::Student(const char * const c, const int y, const int m, const int d)
    :birthDate(y, m, d)
{
    //ctor
    setName(c);
    courseNumber=0;
    for(int i=0; i<MAX_SIZE; i++)
        courseList[i]=NULL;
}

Student::~Student()
{
    //dtor
    Count--;
    delete[] name;
    for(int i=0; i<MAX_SIZE; i++){
        if(courseList[i])
            delete courseList[i];
    }
}

Student::Student(const Student &s)
    :birthDate(s.birthDate)
{
    Count++;
    name=new char[100];
    strcpy(name,s.name);
    courseNumber=s.courseNumber;
}

void Student::setName(const char *c)
{
    Count++;
    name=new char[100];
    strcpy(name, c);
    return ;
}

char * Student::getName()
{
    return name;
}

void Student::print()
{
    cout<<"name:"<<getName()<<"\t birthday:";
    birthDate.print();
    cout<<"已选课程：\n";
    for(int i=0; i<MAX_SIZE; i++)
        if(courseList[i])
            cout<<"课程："<<courseList[i]->getName()<<"\t学分："<<courseList[i]->getCreditHour()<<endl;

    return ;
}

Date Student::getBirthDate() const
{
    return birthDate;
}

Student& Student::addCourse(Course *course)
{
    int i;
    for(i=0; i<MAX_SIZE; i++)
        if(courseList[i]==NULL)
            break;
    if(i<MAX_SIZE){
        courseList[i]=course;
        courseNumber++;
    }
    return (*this);
}

/*
Student& Student::addCourse(const string &courseName, int creditHour)
{
    Course *newCourse=new Course(courseName, creditHour);
    int i;
    for(i=0; i<MAX_SIZE; i++)
        if(courseList[i]==NULL)
            break;
    if(i<MAX_SIZE){
        courseList[i]=newCourse;
        courseNumber++;
    }
    return (*this);
}
*/

bool Student::removeCourse(int num)
{
    if(num<1 || num>courseNumber){
        MyException except("range");
        throw except;
        return false;
    }
    if(courseList[num-1]==NULL)
        return false;
    Course *tmp=courseList[num-1];
    for(int i=num-1; i<MAX_SIZE-1; i++)
        courseList[i]=courseList[i+1];
    courseList[courseNumber-1]=NULL;
    courseNumber--;
    return true;
}

ostream& operator<<(ostream &output, const Student &s)
{
    output<<"姓名："<<s.name<<"   "<<"出生日期："<<s.birthDate<<","<<"选课信息如下："<<endl;
    for(int i=0; i<MAX_SIZE; i++){
        if(s.courseList[i])
            output<<i+1<<"、"<<(*s.courseList[i])<<endl;
    }
    return output;
}

const Course& Student::operator[](int subject)const
{
    if(subject>=0 && subject<courseNumber)
        return (*courseList[subject]);
    else{
        MyException except("range");
        throw except;
    }
}

Course& Student::operator[](int subject)
{
    if(subject>=0 && subject<courseNumber)
        return (*courseList[subject]);
    else{
        MyException except("range");
        throw except;
    }
}

double Student::calcCredit() const
{
    double ans=0;
    for(int i=0; i<courseNumber; i++){
        ans=ans+(*this)[i].getWeight() * (*this)[i].getScore() * (*this)[i].getCreditHour()/ GetOcCredit();
        //必修正常，选修getCreditHour()==0不计算
        ans=ans+(*this)[i].getWeight() * (*this)[i].getScore() * (*this)[i].getNumber()/ GetEcNumber();
        //选修正常，必修getTotal()==0不计算
        /*
            下面简单利用RTTI感觉反而简单了OTZ
            getCreditHour()不用virtual，就是正常返回学分，virtual有点乱的感觉
            getNumber()不用写
            getWeight()也不用写了，直接就是0.6和0.4
        */
        /*
            if(typeid(ObligatoryCourse&)==typeid((*this)[i]))
                ans=ans+0.6 * (*this)[i].getScore() * (*this)[i].getCreditHour()/ GetOcCredit();
            else
                ans=ans+0.4 * (*this)[i].getScore() / GetEcNumber();
        */
    }
    return ans;
}

double Student::GetOcCredit() const
{
    //RTTI计算必修的学分
    double num=0;
    for(int i=0; i<courseNumber; i++)
        if(typeid(ObligatoryCourse&)==typeid((*this)[i]))
            num=num+(*this)[i].getCreditHour();
    return num;
}

double Student::GetEcNumber() const
{
    double num=0;
    for(int i=0; i<courseNumber; i++)
        if(typeid(ObligatoryCourse&)==typeid((*this)[i]))
            num++;
    return num;
}
