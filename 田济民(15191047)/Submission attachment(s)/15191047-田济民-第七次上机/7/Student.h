#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#include<string>
#include<iostream>
#include"Course.h"
#include<typeinfo>
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include"MyException.h"
#define MAX_SIZE 5
using std::cout;
class Student
{
public:
    Student();
    Student(string,int y,int m,int d);
    Student(Date birda,string nm);        //����
    const string getName();                 //ȡ������
    bool setName(string nm);                //��������
    Date& getBirthDate();                    //ȡ������
    bool setBirthDate(int y,int m,int d);   //��������
    virtual ~Student();                     //��������
    void showName();
    void showDate();
    Student& addCourse(Course *c);//ѡ��
                                                        /*  Student& addCourse(const string &courseName, int creditHour);*/
    friend ostream& operator<<(ostream& os,const Student& p)
    {
        os<<p.name<<" ��������: "<<p.birthDate<<" ѡ����Ϣ���£������û��˵��û�Σ�"<<"\n";
        for(int i=0; i<p.courseNumber; i++)
            if(typeid(ObligatoryCourse)==typeid(*p.courseList[i]))
            {
                ObligatoryCourse*temp=dynamic_cast<ObligatoryCourse*>(p.courseList[i]);
                os<<i<<" "<<*temp;
            }
            else if(typeid(ElectiveCourse)==typeid(*p.courseList[i]))
            {
                ElectiveCourse*temp1=dynamic_cast<ElectiveCourse*>(p.courseList[i]);
                os<<i<<" "<<*temp1;
            }
        return os;
    }
    double calcCredit();        //���㼨��
    static int getCOUNT();
    bool removeCourse(int i);
    bool setscore(int s,int pos);
    int  returnScore(int i)
    {
        return courseList[i]->getScore();
    }
    Course*returncourse(int pos)
    {
          if(pos>=courseNumber||pos<0)
        throw(MyException(2));
        return courseList[pos];
    }
protected:

private:
    Student(const Student &a);              //��ֹ��������
    string name;
    Date birthDate;
    static int COUNT;
    Course*courseList[MAX_SIZE];
    int courseNumber;
};
#endif // STUDENT_H

