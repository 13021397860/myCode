#include<iostream>
#include<string.h>
#include<iomanip>
#include<cstdlib>
#include<fstream>
#include"Student.h"
#include"Date.h"
#include"course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include<typeinfo>
#include"WrongGrade.h"
using namespace std;
int Student::cnt=0;
/*void Student::setBirthDate(const Date &date1)
{
    birthDate(date1);
}*/

Student::Student()
:birthDate(1,1,1)
{
    courseNumber=0;
    cnt++;
    name="Mary";
    jidian=0;
}

Student::Student(int y,int m,int d,const char *str1)
:birthDate(y,m,d)//**
{
    courseNumber=0;
    cnt++;
    name=new char[strlen(str1)+1];
    setName(str1);
    jidian=0;
}

Student::Student(const Student &s1)
:birthDate(s1.birthDate)//用在函数中的初始化构造器；
{
    cnt++;
    name =new char[strlen(s1.name)+1];
    strcpy(name,s1.name);
    jidian=0;
}

Student::~Student()
{
    delete[]name;
    for(int i=0;i<=courseNumber-1;i++)
    {
        delete courseList[i];//指针数组必须一个个delete；如果是单纯数组，参照name；
    }
    cout<<"Student is destroyed"<<endl;
}

void Student::setName(const char *str1)
{
    strcpy(name,str1);
}

/*void Student::setBirthDate(int y,int m,int d)
{
    birthDate.setDate(y,m,d);
}*/

char *Student::getName() const
{
    return name;
}

Date Student::getBirthDate() const
{
    return birthDate;
}

void Student::printStu() const
{
    cout<<name<<" ";
    cout<<birthDate;
    cout<<"coursenumber:"<<courseNumber<<endl;
    for(int i=0;i<=courseNumber-1;i++)  courseList[i]->print();//根据子类对象的类型选择print类型；
}
void  Student::printCnt()
{
    cout<<cnt<<endl;
}

Student& Student::addCourse1(const string& courseNa,int creditH,int m)
{
    if(courseNumber<Max_size)
    {
        courseList[courseNumber++]=new ObligatoryCourse(courseNa,creditH,m);//新建一个course对象，并保存他的地址；
    }
    return *this;
}

Student& Student::addCourse2(const string& courseNa,int creditH,char g)
{
    if(courseNumber<Max_size)
    {
        courseList[courseNumber++]=new ElectiveCourse(courseNa,creditH,g);//新建一个course对象，并保存他的地址；
    }
    return *this;
}

Student& Student::addCourse3(course *course_)
{
    if(courseNumber<Max_size)   courseList[courseNumber++]=course_;//
    //cout<<"IN ADD BEFORE CALC"<<endl;
    //calcCredit();
    return *this;
}

int Student::getJidian() const
{
    return jidian;
}

ostream &operator<<(ostream &output,const Student&stu)
{
    ofstream outFile_("stuInfo.dat",ios::out);
    ofstream outFile("stuInfo.dat",ios::app);
    if(!outFile_)
    {
        cerr<<"file couldn't be opened"<<endl;
        exit(1);
    }
    if(!outFile)
    {
        cerr<<"file couldn't be opened"<<endl;
        exit(1);
    }
    cout<<endl;
    output<<stu.name<<"      "<<stu.birthDate;
    outFile_<<stu.name;
    outFile<<' '<<stu.birthDate.getYear()<<' '<<stu.birthDate.getMonth()<<' '<<stu.birthDate.getDay()<<endl;
    /*
    while(oNum--)
    {
        outFile<<courseName<<' '<<credit<<' '<<mark<<endl;
    }
    while(eNum--)
    {
        cin>>courseName>>credit>>grade;
        outFile<<courseName<<' '<<credit<<' '<<grade<<endl;
    }*/

    int i;
    for(i=0;i<=stu.courseNumber-1;i++)
    {
        (stu.courseList[i])->print();//记住course是另一个类，这里已经属于调用用cout而非output
        //outFile<<stu.courseList[i].courseName<<' '<<credit<<' '<<mark<<endl;
        outFile<<stu.courseList[i]->name<<' '<<stu.courseList[i]->creditHour<<' '<<stu.courseList[i]->getScore()<<endl;
    }
    return output;
    outFile.close();
    outFile_.close();
}

bool Student::removeCourse(int id)
{
    for(int i=id;i<=courseNumber-2;i++)
    {
        courseList[i]=courseList[i+1];
    }
    delete courseList[courseNumber-1];
    courseNumber--;
    //qianyi;

}

int Student::GradeOc(int g)
{
    if(g<0||g>100)  throw WrongGrade();
    return g;
}

char Student::GradeEc(char c)
{
    if(c<'A'||c>'F'||(c>'a'&&c<'z'))    throw WrongGrade();
    return c;
}

void  Student::WriteCJ()//不能输出成绩；
{
    /*for(int i=0;i<=courseNumber-1;i++)
    {
        if(name_==courseList[i]->name)
        {
             courseList[i]->creditHour=ch;
             return 1;
        }
    }
   cout<<"can't find course to be rewrite credithour"<<endl;    return 0;*/
   char c;
   int g;
   ObligatoryCourse o;ElectiveCourse e;
   for(int i=0;i<=courseNumber-1;i++)
    {
        if(typeid(*(courseList[i]))==typeid(o))
        {
            cout<<"int"<<endl;
            while(cin>>g)
            {
                try
                {
                    int result=GradeOc(g);
                    cout<<"the set grade is"<<result<<endl;
                    courseList[i]->setChengji(g,'A');
                    break;
                }
                catch(WrongGrade& wrongGrade )
                {
                    cout<<"exception occured"<<wrongGrade.what()<<endl;
                }
            }
        }
        else if(typeid(*(courseList[i]))==typeid(e))
        {
            cout<<"char"<<endl;
            while(cin>>c)
            {
                try
                {
                    char result=GradeEc(c);
                    cout<<"the set grade is"<<result<<endl;
                    courseList[i]->setChengji(100,c);
                    break;
                }
                catch(WrongGrade& wrongGrade )
                {
                    cout<<"exception ec occured"<<wrongGrade.what()<<endl;
                }
            }
        }
    }
    cout<<"out WriteCJ"<<endl;
}

void Student::setJidian(int j)
{
    jidian=j;
}

void   Student::calcCredit()
{
    ObligatoryCourse o;ElectiveCourse e;
    int oTotal=0,eTotal=0;
    int oTC=0,eTN=0;
    for(int i=0;i<=courseNumber-1;i++)
    {
        if(typeid(*(courseList[i]))==typeid(o))
        {
            oTotal+=(courseList[i]->creditHour)*(courseList[i]->getScore());
            oTC+=courseList[i]->creditHour;
        }
        else if(typeid(*(courseList[i]))==typeid(e))
        {
            eTotal+=courseList[i]->getScore();
            eTN++;
        }
    }
    setJidian  (0.6*(oTotal/oTC)+0.4*(eTotal/eTN));////为何一定要const？？？？？？？
}

//
