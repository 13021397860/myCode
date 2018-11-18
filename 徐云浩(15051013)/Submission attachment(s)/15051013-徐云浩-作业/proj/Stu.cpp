#include "Stu.h"
#include <string.h>
#include <iostream>
#include <typeinfo>
#include "UserInterface.h"
#include "MyException.h"
using namespace std;

#define ELEcoefficient 0.4
#define OBLcoefficient 0.6

int Stu::count = 0;
int Stu::courseNumber = 0;

Stu::Stu()
{
    name = NULL;
    ++count;
}

Stu::Stu(const char*s)
{
    name = NULL;
    setname(s);
    ++count;

}

Stu::Stu(const Stu &s)
{
    name = NULL;
    setname(s.name);
    ++count;
}

Stu::~Stu()
{
    this->courseNumber = 0;
    delete[]name;
    for(int i=0;i<getCoursenumber();i++)
    delete courseList[i];
    --count;
}

Stu& Stu::setname(const char*s){
    if(name)
        delete[]name;
    if(s == NULL)
    {
        cout<<"INPUT NULL"<<endl;
        return *this;
    }
    else {
    lenth = strlen(s);
    name = new char[lenth+1];
    strcpy(name,s);
    return *this;
    }
}

void Stu::printname(){
    if(name==NULL)
        cout<<"no name"<<endl;
    else
        cout<<name<<endl;
}

int Stu::getCount()
{
    return count;
}

int Stu::getCoursenumber(){
    return courseNumber;
}

Course * Stu::getcourselist(int i)
{
    return courseList[i];
}

void Stu::view()
{
    cout<<"count="<<count<<endl;
}

Stu& Stu::addCourse(Course *course)
{
    if(course == NULL)
    {
        cout<<"input null"<<endl;
    }
    else if(courseNumber>=MAX_SIZE)
    {
        cout<<"course number is full"<<endl;
    }
    else
    {
        courseList[courseNumber]=course;
        courseNumber++;
    }
    return *this;
}
bool Stu::removeCourse(int i)
{
    if(i<1||i>MAX_SIZE||i>courseNumber)
    {
        cout<<"Input a wrong course ID !"<<endl;
        return false;
    }
    else
    {
        Course *p;
        p = courseList[i-1];
        for(int j=i-1;j<courseNumber-1;j++)
        {
            courseList[j] = courseList[j+1];
        }
        courseNumber--;
        delete p;
        cout<<"Course No."<<i<<" is removed !"<<endl;
        return true;
    }
}

bool Stu::judgedate()
{
    try{birthdate.judgeInput();}
    catch(MyException ex){
        cout<<ex.what()<<endl;
        return false;
    }
    return true;
}

bool Stu::setCourseScore(Stu& stu1)
{
    int mark = 0;
    char grade = '\0';
    for(int i=0;i<stu1.getCoursenumber();i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*stu1.getcourselist(i))){
            cout<<"ObligatoryCourse: "<<stu1.getcourselist(i)->getName()<<"\nMark(0-100): ";
            UserInterface::InputChoice(mark,0,100);
            dynamic_cast<ObligatoryCourse*>(stu1.getcourselist(i))->setScore(mark);
        }
        else if(typeid(ElectiveCourse)==typeid(*stu1.getcourselist(i))){
            cout<<"ElectiveCourse: "<<stu1.getcourselist(i)->getName()<<"\nGrade(A-E): ";
            UserInterface::InputChoiceChar(grade,'A','E');
            dynamic_cast<ElectiveCourse*>(stu1.getcourselist(i))->setScore(grade);
        }else {return false;}
    }
    return true;
}
/*
static void printScore(Stu& c,int n)
{
    if(typeid(ObligatoryCourse)==typeid(*c.getcourselist(n)))
    {
        if(dynamic_cast<ObligatoryCourse*>(c.getcourselist(n))->getScore() == -1)
            cout<<"Score: N/A"<<endl;
        else
            cout<<"Score: "<<dynamic_cast<ObligatoryCourse*>(c.getcourselist(n))->getScore()<<endl;
    }
    else if(typeid(ElectiveCourse)==typeid(*c.getcourselist(n)))
    {
        if(dynamic_cast<ElectiveCourse*>(c.getcourselist(n))->getScore() == 0)
            cout<<"Score: N/A"<<endl;
        else
            cout<<"Score: "<<dynamic_cast<ElectiveCourse*>(c.getcourselist(n))->getScore()<<endl;
    }
}
*/
ostream& operator<<(ostream& out,Stu& c){
    out<<"name: ";
    if(c.getname()==NULL)
        out<<"no name"<<endl;
    else
        out<<c.getname()<<endl;
    out<<"birthdate: ";
    out<<c.birthdate<<endl;
    for(int n = 0;n<c.getCoursenumber();n++)
    {
        out<<*c.getcourselist(n);
    }
    if(c.calCredit() == 0)
    {
        out<<"积点成绩 : N/A"<<endl;
    }
    else
    {
        out<<"积点成绩 : "<<c.calCredit()<<endl;
    }
    return out;
}

float Stu::calCredit()
{
    float sum = 0;
    if(getCoursenumber() == 0)
    {
        return sum;
    }
    else
    {
        for(int i=0;i<getCoursenumber();i++)
        {
            if(getcourselist(i)->getScore()==-1)
            {
                return sum;
            }
        }
        float sumobl=0,sumele=0;
        float oblid=0,eleid=0;
        for(int i=0;i<getCoursenumber();i++)
        {
            if(typeid(*getcourselist(i))==typeid(ObligatoryCourse))
            {
                sumobl+=getcourselist(i)->getHour();
            }
            else
            {
                sumele+=getcourselist(i)->getHour();
            }
        }
        for(int i=0;i<getCoursenumber();i++)
        {
            if(typeid(*getcourselist(i))==typeid(ObligatoryCourse))
            {
                if(sumobl == 0)
                {
                    oblid = 0;
                }
                else
                oblid+=getcourselist(i)->getScore()*getcourselist(i)->getHour()/sumobl;
            }
            else
            {
                if(sumele == 0)
                    eleid = 0;
                else
                eleid+=getcourselist(i)->getScore()*getcourselist(i)->getHour()/sumele;
            }
        }
        sum = ELEcoefficient * eleid + OBLcoefficient * oblid ;
        return sum;
    }
}
