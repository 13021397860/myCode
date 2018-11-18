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
        cout<<"#名字输入有误，名字变为xiaoming\n";
        //cout<<"#名字输入有误，名字变为xiaoming!\n";
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
        cout<<"#名字输入有误，名字变为xiaoming!\n";
        //cout<<"#名字输入有误，名字变为xiaoming!\n";
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
        printf("#传入空课程，此操作无效！\n");
        //printf("#传入空课程，此操作无效！\n");
    }
    else if(courseNumber>=MAX_SIZE)
    {
        printf("#你的课程已满，请下个学期再选！\n");
        //printf("#你的课程已满，请下个学期再选！\n");
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
            printf("#退课成功！\n");
            //printf("#退课成功！\n");
        }
        else
        {
            for(int j=i;j<courseNumber;j++)
                courseList[j-1]=courseList[j];
            courseNumber--;
            printf("#退课成功！\n");
            //printf("#退课成功！\n");
        }
    }catch(MyException ex){
        cout<<"#出现异常："<<ex.what2()<<"\n";
        cout<<"#没有此课程，退课失败！\n";
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
            printf("#未有已设置成绩的科目,积点成绩为0！\n");
            return 0;
        }
        else
        {
            printf("#因为只有选修课拥有成绩，所以选修课权重为1！\n");
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
            printf("#因为只有必修课拥有成绩，所以必修课权重为1！\n");
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
            printf("#因为既有必修拥有成绩，又有选修课拥有成绩，所以必修课权重为0.6，选修课权重为0.4！\n");
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
