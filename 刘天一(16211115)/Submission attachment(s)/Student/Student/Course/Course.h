#ifndef STUDENT_COURSE_H
#define STUDENT_COURSE_H

#include <string>
#include <iostream>
#include "../Exception/MyException.h"
using namespace std;

class Course
{
    friend ostream& operator<<(ostream &,const Course&);
public:
    Course();
    Course(Course &c){setName(c.getName());setCreditHour(c.getCreditHour());}
    Course(const std::string n,const int c){setName(n);setCreditHour(c);}
    virtual ~Course();
    void setName(const std::string n){name=n;}
    void setCreditHour(const int c){creditHour=c;}
    std::string getName()const{return name;}
    int getCreditHour()const{return creditHour;}
    virtual void print(){};
    virtual int getScore()const=0;
protected:
    std::string name;
    int creditHour;
private:

};

#endif //STUDENT_COURSE_H
