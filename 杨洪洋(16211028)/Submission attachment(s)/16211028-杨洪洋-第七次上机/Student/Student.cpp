
#include "Student.hpp"
#include "Date.hpp"
#include "Course.hpp"
#include "ObligatoryCourse.hpp"
#include "ElectiveCourse.hpp"
#include<iostream>
#include<cstring>
#include<typeinfo>
#include<fstream>
using namespace std;
int Student::count=0;
Student::Student()
{
    //ctor
}
Student::Student(const char *const text)
{
    ++count;
    name=new char [strlen(text)+1];
    strcpy(name,text);
    courseNumber=0;
    jidian=0;
}
bool Student::setBirthday(int y,int m,int d)
{
    if(birthDate.setdate(y, m, d))
        return true;
    else
        return false;
}

Student::Student(const Student &s):birthDate(s.birthDate)
{
    ++count;
    cout<<"copy constructing:"<<s.name<<endl;
    name=new char[strlen(s.name)+1];
    strcpy(name,s.name);
    courseNumber=0;
    jidian=0;
    
}
Student::~Student()
{
    --count;
    delete []name;//dtor
    int i=courseNumber-1;
    while(i>0)
    {
        if(removeCourse(i,courseList[i]->getname()))
            removeCourse(i,courseList[i]->getname());
        i--;
    }
}
void Student::printstu()
{
    cout<<"the name is:"<<getName()<<endl;
    cout<<"the birthday is:"<<endl;
    //birthDate.print();
    cout<<birthDate;
}
char *Student::getName()
{
    return name;
}
void  Student::setName(char *s)
 {
     ++count;
     if(name)delete []name;
     name=new char [strlen(s)+1];
     strcpy(name,s);
 }
int Student::getCount()
{
    return count;
}
void Student ::printcount()
{
    cout<<"The count is:"<<count<<endl;
}
bool Student::check(Course *course)
{
    int i;
    bool flag=1;
    for(i=0;i<courseNumber;i++)
    {
        if(courseList[i]->getname()==course->getname())
        {
            flag=0;
            break;
        }
    }
    return flag;
}
Student& Student::addCourse(Course *course)
{
    if(this->courseNumber==0)
    {
        courseList[courseNumber]=(Course*)malloc(sizeof(course));
        courseList[courseNumber]=course;
        courseNumber++;
    }
    else if(courseNumber<MAX_SIZE)
    {
            courseList[courseNumber]=(Course*)malloc(sizeof(course));
            courseList[courseNumber]=course;
            courseNumber++;
    }
    else
        cout<<"You've already chosen 10 courses and you can't choose any more."<<endl;
       // throw 3;
    return (*this);
}
int Student::getCourseNumber()
{
    return courseNumber;
}

ostream &operator <<(ostream &output,Student &stu)
{
    output<<"Name: "<<stu.getName()<<" Birthday: "<<stu.birthDate<<", some information about the courses: "<<endl;
    for(int i=0;i<stu.courseNumber;i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*stu.courseList[i]))
        {
            output<<dynamic_cast<ObligatoryCourse&>(*stu.courseList[i])<<endl;
        }
        else if(typeid(*stu.courseList[i])==typeid(ElectiveCourse))
        {
            output<<dynamic_cast<ElectiveCourse&>(*stu.courseList[i])<<endl;
        }
    }
    return output;
}
int Student::removeCourse(int a,string name)
{
    if(courseNumber<=0)
        return 0;
    else
    {
        int flag=0;
        for(int i=0;i<courseNumber;i++)
        {
            if(this->courseList[i]->getname()==name)
            {
                delete this->courseList[i];
                for(int j=i;j<this->courseNumber-1;j++)
                {
                    this->courseList[j]=this->courseList[j+1];
                }
                flag=1;
            }
        }
        if(flag==1)
        {
            this->courseNumber--;
            return 1;

        }
        else
            return -2;
            
    }
}
Course* Student::getCourse(int i)
{
    if(i==getCourseNumber())
    {return this->courseList[getCourseNumber()-1];}
    else
        return this->courseList[i];
}
void Student::setCourseNumber()
{
    this->courseNumber=0;
}
double Student::calcCredit()
{
    double sumob=0.0;
    double sumec=0.0;
    int numob=0;
    int numec=0;
    for(int i=0;i<courseNumber;i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
        {
            numob+=courseList[i]->getCreditHour();
        }
        else if(typeid(*courseList[i])==typeid(ElectiveCourse))
        {
            numec++;
        }
    }
    for(int i=0;i<courseNumber;i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
        {
            sumob=courseList[i]->getScore()*courseList[i]->getCreditHour()/numob;
            jidian+=0.6*sumob;
        }
        else if(typeid(*courseList[i])==typeid(ElectiveCourse))
        {
            sumec=courseList[i]->getScore()/numec;
            jidian+=0.4*sumec;
        }
    }
    cout<<jidian<<endl;
    return 1;
}
Course* Student::getCourseList(int j)
{
    return courseList[j];
}
bool Student::createSequentialFile(const char *fileName)
{
    ofstream outClientFile(fileName,ios::out);
    if(!outClientFile)
        return false;
    outClientFile<<*this<<endl;
    return true;
}
