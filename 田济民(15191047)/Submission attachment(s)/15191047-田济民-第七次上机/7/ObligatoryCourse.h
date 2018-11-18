#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include"Course.h"
#include<string>
using namespace std;
class ObligatoryCourse:public Course
{
public:
    ObligatoryCourse();
    ObligatoryCourse(string,int);
    virtual ~ObligatoryCourse();
    bool setMark(int mk);
    int getMark();
    void setScore(int );
    int getScore();
    bool setName(string a)
    {
        name=a;
        return true;
    }
    void setCreditHour(int i)
    {
        grehour=i;
        return;
    }
    int getCreditHour()
    {
        return grehour;
    }
    friend ostream& operator<<(ostream& os,const ObligatoryCourse& p)
    {
        os<<" ObligatoryCourse : "<<p.name<<'|'<<" creditHour: "<<p.grehour<<"\n";
        return os;
    }
protected:

private:
    string name;
    int grehour;
    int mark;

//
};

#endif // OBLIGATORYCOURSE_H
