#ifndef COURSE_H
#define COURSE_H
#include<string>
#include<iostream>
using std::string;
using std::ostream;
class Course
{
public:
    Course();
    Course(string n,int creditHour);
    virtual ~Course();
    virtual int getScore()=0;
    virtual void setScore(int s) {}
    virtual void setCreditHour(int );//设置学分
    virtual int getCreditHour();
    virtual bool setName(string);
    bool showName();
    string getName();
    friend ostream& operator<<(ostream& os,const Course& p)
    {
        os<<" 课程名："<<p.name<<" 学分: "<<p.creditHour<<"\n";
        return os;
    }

protected:

private:
    string name;//课程名称
    int creditHour;//学分
};

#endif // COURSE_H
