#include "Student.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "MyException.h"
#include <windows.h>
#include <typeinfo>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
int Student::count=0;
Student::Student()
{
    name=NULL;
    courseNumber=0;
    count++;
    //ctor
}
Student::Student(const Student &S):birthDate(S.birthDate){
    int len=strlen(S.name);
    name=(char*)malloc(len+1);
    strcpy(name,S.name);
    puts("Copying Student~~~");
    courseNumber=0;
    count++;
    //ctor
}
Student::Student(const char *_name)
{
    int len=strlen(_name);
    name=(char*)malloc(len+1);
    strcpy(name,_name);
    courseNumber=0;
    count++;
    //ctor
}
Student::Student(const char *_name,const Date &_birthDate):birthDate(_birthDate){
    int len=strlen(_name);
    name=(char*)malloc(len+1);
    strcpy(name,_name);
    courseNumber=0;
    count++;
    //ctor
}
bool Student::setName(const char *_name)
{
    if (name!=NULL){
        printf("%s Changes His/Her Name~~  ",name);
        delete[](name);
        puts("Changing name......");
    }
    int len=strlen(_name);
    if (len==0) return 1;
    name=(char*)malloc(len+1);
    strcpy(name,_name);
    return 0;
    //ctor
}
char* Student::getName(){
    char *s;
    s=(char*)malloc(strlen(name));
    strcpy(s,name);
    return s;
}
bool Student::getName(char *const pos){
    if (name==NULL) return 1;
    strcpy(pos,name);
    return 0;
}
Date Student::getBirthday()const{
    return birthDate;
}
int Student::getStudentNum(){
    return count;
}
void Student::printStudentNum(){
    printf("There are %d students\n",count);
}
bool Student::printName()const{
    if (name==NULL) return 1;
    printf("%s",name);
    puts("");
    return 0;
}
void Student::printBirthday()const{
    cout<<birthDate<<"\n";
}
void Student::print()const{
    printf("%s's Birthday is ",name);
    cout<<birthDate<<"\n";
    puts("He/She chooses:");
    if (courseNumber==0) puts("Nothing!");
    for (int i=0;i<courseNumber;i++){
//        cout<<*courseList[i];
        courseList[i]->printCourse();
        puts("");
    }
}
int Student::getCourseScore(int i)const throw(MyException){
    if (i<=0||i>courseNumber) throw RANGE_ERROR;
    if (courseList[i-1]->getScore()==-1) return -1;
    return courseList[i-1]->getScore();
}
double Student::calcCredit()const {
    if (courseNumber==0) return 0;
    double ret,retO,retE;int allO,allE;
    ret=retO=retE=allO=allE=0;
    for (int i=0;i<courseNumber;i++)
    {
        if (courseList[i]->getScore()==-1) continue;
        if (typeid(*courseList[i])==typeid(ObligatoryCourse))
            retO+=courseList[i]->getScore()*courseList[i]->getCreditHour(),
            allO+=courseList[i]->getCreditHour();
        else
            retE+=courseList[i]->getScore(),
            allE++;
    }
    if (allO) ret+=0.6*retO/allO;
    if (allE) ret+=0.4*retE/allE;
    return ret;
}
ostream &operator<<(ostream &out,const Student &A)
{
     out<<"姓名:"<<A.name
        <<"   出生日期:"<<A.birthDate
        <<"   选课信息如下:\n";
    if (A.courseNumber==0) out<<"没选课!\n";
    else
    {
        for (int i=0;i<A.courseNumber;i++)
            out<<*A.courseList[i]<<"\n";
    }
     out<<"积点: "<<A.calcCredit()<<"\n";
    return out;
}
Student& Student::addCourse(Course *course)
{
    if (courseNumber==MAX_SIZE) puts("已满");
    else{
        for (int i=0;i<courseNumber;i++)
            if (courseList[i]->getName()==course->getName()) return (*this);
        courseList[courseNumber++]=course;
    }
    return (*this);
}
/*
Student& Student::addCourse(const string &courseName, int creditHour)
{
    if (courseNumber==MAX_SIZE) puts("wrong");
    else{
        Course*course=new Course(courseName,creditHour);
        courseList[courseNumber++]=course;
    }
    return (*this);
};
*/
bool Student::removeCourse(int i)
{
    if (i<=0||i>courseNumber||courseNumber==0) return 0;
    free(courseList[--i]);
    while (++i<courseNumber) courseList[i-1]=courseList[i];
    courseNumber--;
    return 1;
};
bool Student::setCourseScore(int i) throw(MyException)
{
    if (i<=0||i>courseNumber) throw RANGE_ERROR;
    i--;
    if (typeid(*courseList[i])==typeid(ElectiveCourse)){
        cout<<"请输入一个字符:\n";
        char grade;cin>>grade;
        while (cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"输入数据格式错误，请重新输入\n";
            cin>>grade;
        }
        ((ElectiveCourse*)courseList[i])->setGrade(grade);
    }
    else{
        cout<<"请输入一个数字:\n";
        int mark;cin>>mark;
        while (cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"输入数据格式错误，请重新输入\n";
            cin>>mark;
        }
        ((ObligatoryCourse*)courseList[i])->setMark(mark);
    }
    return 1;
};
Student::~Student()
{
    printf("%s dead!",name);
    delete[]name;
    for (int i=0;i<courseNumber;i++) free(courseList[i]);
    count--;
    puts("");
    //dtor
}
