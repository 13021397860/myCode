#include "Student.h"
#include "Course.h"
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

int Student::Count=0;

Student::Student()
{
    Count++;
    courseNum=0;
    name="unidentified";
    birthDate.setDate(1990,1,1);//ctor
}

Student::Student(const Student &student)
{
    name=student.name;
    birthDate=student.birthDate;
    Count++;
    courseNum=0;
}

Student::~Student()
{
    Count--;
    delete name;//dtor
    for(int i=0;i<courseNum;i++)
        delete courseList[i];
}

void Student::setStudentName(char *n)
{
    int sizeOfName=0;
    for(int i=0;i<=9;i++)
    {
        if(n[i]=='\0')
            break;
        sizeOfName++;
    }
    if(sizeOfName>8)
        n="unidentified";
    name=new char[8];
    strcpy(name,n);
}

void Student::setStudentBirth(int y,int m,int d)
{
    birthDate.setDate(y,m,d);
}

int Student::getStudentCount()
{
    return Count;
}

string Student::getStudentName()
{
    return name;
}

Date Student::getStudentBirthday()
{
    return birthDate;
}

Student &Student::addCourse(Course *course)
{
    courseList[courseNum++]=course;
    return *this;
}

bool Student::removeCourse(int i){
    i--;
    if(i<0||i+1>courseNum||courseNum==0)return false;
    for(int j=i;j<courseNum;j++)
        courseList[j]=courseList[j+1];
    courseNum--;
    return true;
}

string Student::getConsultCourseName(int i){
    i--;
    if(i<0||i>courseNum||courseNum==0)return "NULL";
    return courseList[i]->getCourseName();
}

double Student::consultCourse(int i){
    i--;
    if(i<0||i>courseNum||courseNum==0)return -1;
    return courseList[i]->getScore();
}

double Student::calcCredit(){
    double SumOfO_C=0;
    double SumOfO_C_C=0;
    double NumOfE_C=0;
    double SumOfE_C_S=0;
    for(int i=0;i<courseNum;i++){
        if(courseList[i]->getScore()==-1)continue;
        if(courseList[i]->Tag()==1){
            SumOfO_C=SumOfO_C+(courseList[i]->getScore()) * (courseList[i]->getCourseCredit());
            SumOfO_C_C+=courseList[i]->getCourseCredit();
        }
        else
        {
            SumOfE_C_S+=courseList[i]->getScore();
            NumOfE_C++;
        }
    }
    if(SumOfO_C_C==0&&NumOfE_C==0)
        return 0;
    else if(SumOfO_C_C==0)
        return 0.4*SumOfE_C_S/NumOfE_C;
    else if(NumOfE_C==0)
        return 0.6*SumOfO_C/SumOfO_C_C;
    else
        return 0.6*SumOfO_C/SumOfO_C_C+0.4*SumOfE_C_S/NumOfE_C;
}

int Student::getcourseNum(){
    return courseNum;
}

void Student::print()
{
    cout<<"name of student:"<<name<<endl;
    //birthDate.print();
    cout<<"date of birthday:"<<birthDate<<endl;
    cout<<"course:"<<endl;
    if(!courseNum)
        cout<<"    Haven't added course!"<<endl;
    else
    for(int i=0;i<courseNum;i++){
        cout<<i<<'.'<<*(courseList[i]);
    }
}

ostream& operator<<(ostream &out,Student &student)
{
    out<<"name of student:"<<student.getStudentName()<<endl<<"date of birthday:"<<student.getStudentBirthday()<<endl<<"course:"<<endl;
    if(!student.courseNum)
        out<<"    Haven't added course!"<<endl;
    else
    for(int i=0;i<student.courseNum;i++)
    {
        out<<i<<'.'<<*(student.courseList[i]);
    }
    return out;
}
