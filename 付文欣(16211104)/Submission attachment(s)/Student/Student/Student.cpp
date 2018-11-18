#include <cstdio>
#include <cstring>
#include <fstream>
#include "Student.h"
const int nameSize=100;

int Student::stu_count=0;

void Student::setName(){
    cout<<"输入姓名：";
    cin>>name;
}

void Student::setName(const string &s){
    name=s;
}

const string &Student::getName()const{
    return name;
}

void Student::print_Name()const{
    ofstream FileName("information.txt",ios::out);
    FileName<<"姓名："<<name<<" ";
}

void Student::print_birthDate()const{
    printf("出生日期：");
    ofstream FileName;
    FileName.open("information.txt",ios::out);
    FileName<<birthDate;
    //birthDate.print();
}

Student& Student::addCourse(Course *course){
    if(!is_overflow())courseList[++courseNumber]=course;
    return (*this);
}

Student& Student::addCourse(const string &courseName,int creditHour){
    if(!is_overflow()){
        Course *Cc=new Course(courseName,creditHour);
        courseList[++courseNumber]=Cc;
    }
    return (*this);
}

void Student::setScore(int i,const int n){
    courseList[i]->setScore(n);
}

void Student::setScore(int i,const char n){
    courseList[i]->setScore(n);
}

ostream & operator<<(ostream & out,const Student &S){
    out<<"姓名:"<<S.name<<"\t出生日期:"<<S.birthDate;
    out<<"选课信息如下：\n";
    for(int i=1;i<=S.courseNumber;i++){
        out<<i<<(*S.courseList[i]);
        if(S.courseList[i]->is_haveScore()){
            out<<"   "<<(S.courseList[i]->getScore())<<endl;
        }
        else out<<"   无成绩"<<endl;
    }
    return out;
}

bool Student::removeCourse(int i){
    if(i>courseNumber) return false;
    Course *p=courseList[i];
    for(int j=i;j<courseNumber;j++) courseList[j]=courseList[j+1]; delete p;
    courseNumber--;
    return true;
}
