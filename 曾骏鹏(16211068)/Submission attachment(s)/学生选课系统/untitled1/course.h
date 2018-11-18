//
// Created by zjp on 2017/4/17.
//
#include <iostream>
#ifndef COURSE_H
#define COURSE_H
using namespace std;

class course
{
public:
    course(const string n,const int c)
    {
        name=n;
        creditHour=c;
    }
    virtual ~course();
    string getName() const;
    void setName(const string);
    int getCreditHour() const;
    void setCreditHour(const int);
    virtual int getScore() const = 0;
    friend ostream& operator << (ostream &os,const course &c);

private:
    string name;
    int creditHour;
};


#endif //COURSE_H
