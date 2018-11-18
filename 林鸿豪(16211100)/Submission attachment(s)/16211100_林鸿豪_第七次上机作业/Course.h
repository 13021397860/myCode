#include <iostream>
#include <string>
using namespace std;

#ifndef COURSE_H
#define COURSE_H
class Course
{
protected:
    string name;
    int creditHour;
public:
    string getName()const{return name;}
    int getcreditHour()const{return creditHour;}
    void setName(string n){name=n;}
    void setcreditHour(int c) {creditHour=c;}
    Course(string n="NoFound",int c=0){name=n,creditHour=c;}
    virtual ~Course(){}
    virtual void setMark(int m){}
    virtual void setMark(char m){}
    virtual int getScore()const=0;
    friend ostream& operator<<(ostream& os,Course &c){
        os<<"CourseName:"<<c.name<<" CreditHour:"<<c.creditHour<<" Mark:"<<c.getScore()<<endl;
    }
    virtual void CoursePrint()const{cout<<name<<"  "<<creditHour<<endl;}
};

#endif // COURSE_H
