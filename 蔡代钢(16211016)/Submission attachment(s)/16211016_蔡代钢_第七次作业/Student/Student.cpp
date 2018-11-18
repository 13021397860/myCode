#include "Student.h"
#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
int Student::count=0;
void outexception1(int k,int num1)
{
    if(k<=0||k>num1)
        throw MyException();
}
Student::Student()
{
}
Student::Student(char *names,int y1, int m1, int d1)
{
    name=NULL;
    setname(names);//ctor
    birthday.settime(y1,m1,d1);
    ++count;
}
Student::Student(const Student &t)
{
    name=NULL;
    setname(t.name);//ctor
    birthday=t.birthday;
    ++count;
}
bool Student::isLegal(const char *names)
{
    char a[1000]={0};
    strcpy(a, names);
    if(strlen(a)>20)
        return 0;
    else
        return 1;
}
Student& Student::setname(const char *names)
{
    if(names==NULL)
    {
        if (name) delete[] name;
        cout<<"#���������������ֱ�Ϊxiaoming\n";
        //cout<<"#���������������ֱ�Ϊxiaoming!\n";
        int length=8;
        name=new char [9];
        names="xiaoming";
        strcpy(name, names);
        return *this;
    }
    else if(isLegal(names))
    {
        if (name) delete[] name;
        int length=strlen(names);
        name=new char[length+1];
        strcpy(name, names);
        return *this;
    }
    else
    {
        if (name) delete[] name;
        cout<<"#���������������ֱ�Ϊxiaoming!\n";
        //cout<<"#���������������ֱ�Ϊxiaoming!\n";
        int length=8;
        name=new char [9];
        names="xiaoming";
        strcpy(name, names);
        return *this;
    }
}
Student& Student::addCourse(Course *course)
{
    if(course==NULL)
    {
        printf("#����տγ̣��˲�����Ч��\n");
        //printf("#����տγ̣��˲�����Ч��\n");
    }
    else if(courseNumber>=MAX_SIZE)
    {
        printf("#��Ŀγ����������¸�ѧ����ѡ��\n");
        //printf("#��Ŀγ����������¸�ѧ����ѡ��\n");
    }
    else
    {
        //courseList[courseNumber]=new course;
        courseList[courseNumber]=course;
        courseNumber++;
        return *this;
    }
}
bool Student::removeCourse(int i)
{
    try{
        outexception1(i,courseNumber);
        if(i==courseNumber)
        {
            courseNumber--;
            printf("#�˿γɹ���\n");
            //printf("#�˿γɹ���\n");
        }
        else
        {
            for(int j=i;j<courseNumber;j++)
                courseList[j-1]=courseList[j];
            courseNumber--;
            printf("#�˿γɹ���\n");
            //printf("#�˿γɹ���\n");
        }
    }catch(MyException ex){
        cout<<"#�����쳣��"<<ex.what2()<<"\n";
        cout<<"#û�д˿γ̣��˿�ʧ�ܣ�\n";
    }
}
void Student::setbirthday(int y1, int m1, int d1)
{
    birthday.settime(y1,m1,d1);
}
void Student::setmessage(const char *names,int y,int m,int d)
{
    setname(names);//ctor
    birthday.settime(y,m,d);
}
char * Student::getname()
{
    return name;
};
int Student::getcount()
{
    return count;
};
int Student::getcourseNumber()
{
    return courseNumber;
};
Course * Student::getcourseList(int i)
{
    return courseList[i-1];
};
Data Student::getbirthday()
{
    return birthday;
}
int Student::calcCredit(double &sum)
{
    double scoresum1=0,scoresum2=0;
    double creditHour1=0,coursenum2=0;
    for(int i=0;i<courseNumber;i++)
    {
        if(courseList[i]->getpd()==1&&courseList[i]->getScore()>=-0.05)
        {
            creditHour1+=courseList[i]->getcreditHour();
        }
        else if(courseList[i]->getpd()==2&&courseList[i]->getScore()>=-0.05)
        {
            coursenum2++;
        }
    }
    if(creditHour1>=-0.05&&creditHour1<=0.05)
    {
        if(coursenum2>=-0.05&&coursenum2<=0.05)
        {
            printf("#δ�������óɼ��Ŀ�Ŀ,����ɼ�Ϊ0��\n");
            return 0;
        }
        else
        {
            printf("#��Ϊֻ��ѡ�޿�ӵ�гɼ�������ѡ�޿�Ȩ��Ϊ1��\n");
            for(int i=0;i<courseNumber;i++)
            {
                if(courseList[i]->getpd()==2&&courseList[i]->getScore()>=-0.05)
                {
                    scoresum2+=courseList[i]->getScore();
                }
            }
            sum=scoresum2/coursenum2;
            return 1;
        }
    }
    else
    {
        if(coursenum2>=-0.05&&coursenum2<=0.05)
        {
            printf("#��Ϊֻ�б��޿�ӵ�гɼ������Ա��޿�Ȩ��Ϊ1��\n");
            for(int i=0;i<courseNumber;i++)
            {
                if(courseList[i]->getpd()==1&&courseList[i]->getScore()>=-0.05)
                {
                    scoresum1+=courseList[i]->getScore()*courseList[i]->getcreditHour();
                }
            }
            sum=scoresum1/creditHour1;
            return 1;
        }
        else
        {
            printf("#��Ϊ���б���ӵ�гɼ�������ѡ�޿�ӵ�гɼ������Ա��޿�Ȩ��Ϊ0.6��ѡ�޿�Ȩ��Ϊ0.4��\n");
            for(int i=0;i<courseNumber;i++)
            {
                if(courseList[i]->getpd()==1&&courseList[i]->getScore()>=-0.05)
                {
                    scoresum1+=courseList[i]->getScore()*courseList[i]->getcreditHour();
                }
                else if(courseList[i]->getpd()==2&&courseList[i]->getScore()>=-0.05)
                {
                    scoresum2+=courseList[i]->getScore();
                }
            }
            sum=0.6*scoresum1/creditHour1+0.4*scoresum2/coursenum2;
            return 1;
        }
    }
}
Student::~Student()
{
    delete[] name;
    if(courseNumber!=0)
        delete[] courseList;
    --count;
}
