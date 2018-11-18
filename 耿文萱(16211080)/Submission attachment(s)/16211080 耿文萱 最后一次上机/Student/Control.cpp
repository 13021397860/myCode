#include "Control.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Course.h"
#include <fstream>
#include "Student.h"
#include <typeinfo>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "MyException.h"
using namespace std;

Control::Control()
{
    //file= new fstream;
    //ctor
}

Control::~Control()
{
    //dtor
}

Control &Control::buildCourse()
{
    oNum=3;
    eNum=2;
    string h;
    int l;
    ifstream infile(".\\couo.txt", ios::in );
    if(!infile)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    for(int i=0;i<3;i++)
    {
        infile>>h>>l;
        //cout<<h<<l<<endl;
        o[i]=new ObligatoryCourse(h,l);
    }
    infile.close();
    ifstream infil(".\\coue.txt", ios::in );
    if(!infil)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    for(int i=0;i<2;i++)
    {
        infil>>h>>l;
        //cout<<h<<l<<endl;
        e[i]=new ElectiveCourse(h,l);
    }
    infil.close();
    /*o[0]=new ObligatoryCourse("数据结构", 3);
    o[1]=new ObligatoryCourse("工科数学分析", 5);
    o[2]=new ObligatoryCourse("大学物理", 4);
    e[0]=new ElectiveCourse("选修", 2);
    e[1]=new ElectiveCourse("英语",2);*/

}

Control &Control::buildStudent(char *n, int a,int b,int c)
{
    student=new Student( n,a,b,c);
}

int Control::display()const
{
	int choice=0;
	cout<<"学生选课系统\n"
		<<"1. 选必修课程\n"
		<<"2. 选选修课程\n"
		<<"3. 查看选课情况\n"
		<<"4. 设置课程成绩\n"
		<<"5. 查看绩点\n"
		<<"6. 查看成绩\n"
		<<"0. 退出\n";
	cin>>choice;
	while(choice<0||choice>6||cin.fail())
    {
        cout<<"try again!"<<endl;
        cin.clear();
        cin.ignore();
        cin>>choice;
    }
	return choice;
}


int Control::run()
{
    cout<<"Set a student."<<endl;
    int a,b,c;
    char *m;
    cin>>m;
    bool h=true;
    cin>>a>>b>>c;
    buildCourse();
    try
    {
        buildStudent(m,a,b,c);
        if(a<=0)
        {
            throw MyException();
        }
        if(b<=0||b>12)
        {

            throw MyException();
        }
        if(c<=0||c>student->birthDate.monthday())
        {

            throw MyException();
        }
    }
    catch (MyException ec)
    {
        //h=false;
        cout<<ec.what()<<"生日错误，请重新运行"<<endl;
        return 0;
    }
    int choice=display();
    while (choice!=0)
    {
        switch (choice)
        {
            case 1:
            case 2:
                student->addCourse(selectCourse(choice));
                break;
            case 3:
                cout<<*student;
                break;
            case 4:
                setScore();
                break;
            case 5:
                refer();
                break;
            case 6:
                get();
                break;
        }
        choice=display();
    }
    cout<<*student;
    ofstream outfile(".\\stu.txt", ios::out);
    if(!outfile)
    {
        cerr<<"open error!"<<endl;
        exit(1);
    }
    outfile<<*student;
    outfile.close();
    return 0;
}

Course* Control::selectCourse(int y)
{
	cout<<"请选择一门课程:\n";
	if(y==1)
	{
	    for(int i=0;i<oNum;i++)
        {
            cout<<i+1<<"."<<*o[i];
        }
        int c;
        bool hh=false;
        while(hh==false){
        cin>>c;
        /*while(c<0||c>oNum||cin.fail())
        {
        cout<<"try again!"<<endl;
        cin.clear();
        cin.ignore();
        cin>>c;
        }*/
        try{
        if(c<0||c>oNum)
        {
            throw MyException();
        }}
        catch (MyException ec)
        {
            cout<<ec.what()<<endl;
            continue;
        }
        return o[c-1];}
	}
	if(y==2)
	{
	    for(int i=0;i<eNum;i++)
        {
            cout<<i+1<<"."<<*e[i];
        }
        int c;
        while(1){
        cin>>c;
        try{
        if(c<0||c>eNum)
        {
            throw MyException();
        }}
         catch (MyException ec)
        {
            cout<<ec.what()<<endl;
            continue;
        }
        return e[c-1];}
	}
}

bool Control::setScore()
{
    cout<<"输入设置成绩的序号"<<endl;
    cout<<*student;
    int i;
    cin>>i;
    try{
    if(i>(student->courseNumber)||i<=0)
    {
        throw MyException();
    }
    }
    catch (MyException ec)
    {
        cout<<ec.what()<<endl;
        return false;
    }
    if(typeid(*(student->courseList[i-1])).name()==typeid(*o[0]).name())
    {
        int y;
        cin>>y;
        try{
        if(y<0||y>100)
        {
            throw MyException();
        }}
        catch (MyException ex)
        {
        cout<<ex.what()<<endl;
        return false;
        }
        student->courseList[i-1]->setGrade(y,'0');
    }
    if(typeid(*(student->courseList[i-1])).name()==typeid(*e[0]).name())
    {
        char y1;
        cin>>y1;
        try{
        if(y1<'A'||y1>'E')
        {
            throw MyException();
        }}
        catch (MyException ex)
        {
        cout<<ex.what()<<endl;
        return false;
        }
        student->courseList[i-1]->setGrade(0,y1);
    }
    return true;
}

bool Control::get()
{
    cout<<"以下为课程及成绩"<<endl;
    cout<<*student;
    return true;
}

void Control::refer()
{
    cout<<"绩点为："<<student->calcCredit()<<endl;
}

