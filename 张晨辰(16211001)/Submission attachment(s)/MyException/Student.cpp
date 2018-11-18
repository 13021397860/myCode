#include<iostream>
#include<cstring>
#include<typeinfo>
#include "Student.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Date.h"
#include "MyException.h"
using namespace std;

int Student::count=0;

Student::Student(char *name,const Date birth)
:birthDate(birth)
{
    if(name==NULL)
    {
        cout<<"\nname is illegal!\nthe date has been corrected to: Bob\n";
        name="Bob";
        setName(name);
    }
    else
        setName(name);
    count++;
}
Student::Student(Student &s)
:birthDate(s.birthDate)
{
    setName(s.name);
}
void Student::setName(char *na)
{
    if(name!=NULL)//防止内存泄露，改名字（开辟一块新内存）之前把上一个名字占用的内存释放掉
        delete []name;
    name=new char[11];//深拷贝：改名字之前开辟一块新内存，而不是在原来的内存上直接改
    if(strlen(na)>10||na==NULL)
    {
        cout<<"name is illegal!\nthe date has been corrected to: Bob\n";
        strcpy(name,"Bob");//字符串拷贝
    }
    else
        strcpy(name,na);
}
char *Student::getName()const
{
    return name;
}
void Student::getCount()
{
    cout<<"number of students right now: "<<count<<endl;
}
int Student::addCourse(Course *course)
{
    if(i<MAX_SIZE)
    {
        courseList[i]=course;
        i++;
        return 1;
    }
    return 0;
}
bool Student::removeCourse(int j)
{
    if(j>i||j<=0)
        return 0;
    for(int temp=j-1;temp<i-1;temp++)
        courseList[temp]=courseList[temp+1];
    i--;
    return 1;
}
int Student::getCourseNumber()const
{
    return i;
}
bool Student::setCourseScore ()
{
    int mark=0;
    char grade='\0';
    for(int j=0;j<getCourseNumber();j++)
    {
        if(typeid(ObligatoryCourse)==typeid(*(courseList[j])))
        {
            cout<<"Obligatory Course: <"<<courseList[j]->getName()<<"> score: ";
            while(cin>>mark)
            {
                try
                {
                    dynamic_cast<ObligatoryCourse&>(*(courseList[j])).setScore(mark);
                    break;
                }catch(MyException &myException)
                {
                    cout<<myException.what()<<endl;
                }
                cout<<"Obligatory Course: <"<<courseList[j]->getName()<<"> score: ";
            }
        }
        else if(typeid(ElectiveCourse)==typeid(*(courseList[j])))
        {
            cout<<"Elective Course: <"<<courseList[j]->getName()<<"> score: ";
            while(cin>>grade)
            {
                try
                {
                    dynamic_cast<ElectiveCourse&>(*(courseList[j])).setScore(grade);
                    break;
                }catch(MyException &myException)
                {
                    cout<<myException.what()<<endl;
                }
                cout<<"Elective Course: <"<<courseList[j]->getName()<<"> score: ";
            }
        }
        else
            return false;
    }
    return true;
}
double Student::calcCredit()const
{
    double OSum=0.0,ESum=0.0;
    int AllOCredit=0;//所选必修课总学分
    int AllENum=0;//所选选修课总门数
    for(int j=0;j<i;j++)
    {
        if(typeid(ObligatoryCourse)==typeid(*(courseList[j])))
        {
            OSum+=courseList[j]->getScore()*courseList[j]->getCreditHour();
            AllOCredit+=courseList[j]->getCreditHour();
        }
        else if(typeid(ElectiveCourse)==typeid(*(courseList[j])))
        {
            ESum+=courseList[j]->getScore();
            AllENum++;
        }
    }
    return OWeight*OSum/AllOCredit+EWeight*ESum/AllENum;
}
Student::~Student()
{
    if(name!=NULL)
        delete []name;
    for(--i;i>=0&&courseList[i]!=NULL;i--)
        delete courseList[i];
}
