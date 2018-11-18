#include<iostream>
#include<iomanip>
#include "student.h"
#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include<cstring>
#include <typeinfo>
#include <fstream>
using namespace std;

int student::count=0;

student ::student ()
{
    courseNumber=0;

    //ctor
}

void student::setName(char *a)
{
    count++;
    delete name;
    if(a==NULL)
    {
        name=new char[20];
        a="xxxxx?";
        strcpy(name,a);
    }
    else
    {
        name=new char[strlen(a)+1];
        strcpy(name,a);
    }
}
student::~student()
{
    count--;
    delete []name;
}
student::student(const student &t )
{
    count++;
    name=new char[strlen(t.name)+1];
    strcpy(name,t.name);
    birthday=t.birthday;
}
student::student(char *p,int x,int y,int z)
{
    setName(p);
    count++;
    setBirthday(x,y,z);
}
void student::setBirthday(int y,int m,int d)
{
    year=(y>0)?y:1949;
    month=(m>0 && m<=12)?m:1;
    day=(d>0 && d<=31)?d:1;

    birthday.cheakDate();
}
void student::cheakName()
{
    int p=strlen(name);
    if(p>20 || p==0)
    {
        name="xxxxx?";
    }

}

char * student::getName() const
{
    return name;
}
Date student::getBirthday() const
{
    return birthday;
}
void student::printName()
{
    cout<<name<<endl;
}
void student::printBirthday()
{
    birthday.print();
}
student& student::addCourse(Course *course){
    if(course){

        courseList[courseNumber]=NULL;
        courseList[courseNumber++]=course;

    }
    return *this;
}
/*student& student::addCourse(const string &courseName,int creditHour){

    return *this;
}*/
int student::getnum(){
    return courseNumber;
}
void student::printcourseList(int k){
    cout<<courseList[k]->getcoursename()<<endl;
    cout<<courseList[k]->getScore()<<endl;
}
ostream & operator << (ostream & os, const student & st1){
    os<<"姓名："<<st1.getName()<<"    "<<"出生日期："<<st1.getBirthday()<<"选课信息如下："<<endl;
    if(st1.courseNumber==0)
        os<<"该学生未选课！"<<endl;
    else
    for(int i=0;i<st1.courseNumber;i++){
        os<<*(st1.courseList[i])<<endl;

    }
    return os;

}

bool student::savefile1(student& S)
{
    ofstream outfile("studentdata.txt",ios::out);
    if(!outfile) {cout<<"Save fail"<<endl;return false;}
    outfile<<S;
    outfile.close();
    return true;
}
bool student::readfiile1(student &S){
    ifstream infile("information.txt",ios::in);
    if(!infile){cout<<"Read fail"<<endl; return false;}
    char *CName;
    CName=new char[100];
    int credithour;int score;
    cout <<"coursename credithour score:"<<endl;
    while(infile >>CName >>credithour>>score)
    cout<<CName<<" "<<credithour<<" "<<score<<endl;
    return true;

}
bool student::removeCourse( int x){
    if(x<= 0 || x>courseNumber)
        return false;
    else
        delete courseList[x-1];
        for(int i=x-1;i<courseNumber-1;i++){
            courseList[i]=courseList[i+1];
        }
        courseNumber --;
        return true;
}

float student::calcCredit(){
    float fmnum1=0,fmnum2=0,fznum1=0,fznum2=0,whole;
    float totalobcre,totalelcre,obkey=0.6,elkey=0.4;
    ObligatoryCourse *strob=new ObligatoryCourse();
    ElectiveCourse *strel= new ElectiveCourse();
    Course *strcourse;
    for(int i=0;i<getnum();i++){
        strcourse=courseList[i];
        if(typeid (*strcourse).name()==typeid (*strob).name()){
            fznum1+=strcourse->getScore()*strcourse->getcredithour();
            fmnum1+=strcourse->getcredithour();

        }
        else if(typeid (*strcourse).name()==typeid (*strel).name()){
            fznum2+=strcourse->getScore();
            fmnum2++;
        }
    }
        float midnum1=0,midnum2=0;
        if(fmnum1!=0)
            midnum1=obkey*fznum1/fmnum1;
        if(fmnum2!=0)
            midnum2=elkey*fznum2/fmnum2;
        whole=midnum1+midnum2;
        delete strob;
        delete strel;
        strob=NULL;
        strel=NULL;
        return whole;


}
