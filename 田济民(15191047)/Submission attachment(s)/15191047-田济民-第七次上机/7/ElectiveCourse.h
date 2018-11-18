#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include"Course.h"
#include<string>
using namespace std;
class ElectiveCourse:public Course
{
public:
    ElectiveCourse();
    ElectiveCourse(string,int);
    virtual ~ElectiveCourse();
    void setScore(int s);
    int getScore();
    bool setName(string a)
    {
        name=a;
        return true;
    }
    void setCreditHour(int i)
    {
        gred=i;
    }
    int getCreditHour()
    {
        return gred;
    }
    friend ostream& operator<<(ostream& os,const ElectiveCourse& p)
    {
        os<<" ElectiveCourse :"<<p.name<<'|'<<" creditHour: "<<p.gred<<"\n";
        return os;
    }
protected:

private:
    char grade;
    string name;
    int gred;
};

#endif // ELECTIVECOURSE_H
