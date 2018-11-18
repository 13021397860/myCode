#ifndef COURSE_H
#define COURSE_H
#include<string>
#include<iostream>
#include<iomanip>
#include <typeinfo>
using namespace std;

class Course
{
public:
    Course();
    Course(const string, const int);
    Course(const Course &);
    virtual ~Course();
    const string& getName() const;
    void getCreditHour(int &) const;
    int getCreditHour() const{return creditHour;}
    void setName(string);
    void setCreditHour(int);
    virtual const int getScore() const = 0;
    virtual void getScore(int &) const = 0;
    //virtual const int getScore(int &) const = 0;
    friend ostream& operator <<(ostream &os, const Course& c);
protected:
    string name;
    int creditHour; //бЇЗж
private:
};

#endif // COURSE_H
