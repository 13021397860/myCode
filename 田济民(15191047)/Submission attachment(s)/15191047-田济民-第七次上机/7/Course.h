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
    virtual void setCreditHour(int );//����ѧ��
    virtual int getCreditHour();
    virtual bool setName(string);
    bool showName();
    string getName();
    friend ostream& operator<<(ostream& os,const Course& p)
    {
        os<<" �γ�����"<<p.name<<" ѧ��: "<<p.creditHour<<"\n";
        return os;
    }

protected:

private:
    string name;//�γ�����
    int creditHour;//ѧ��
};

#endif // COURSE_H
