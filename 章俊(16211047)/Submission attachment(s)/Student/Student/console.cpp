#include "console.h"
#include "student.h"
#include "time.h"
#include <iostream>
#include <cstring>
#include "course.h"
#include <string>
#include <fstream>
#include "myexception.h"
#include "obligatorycourse.h"
#include "electivecourse.h"
#define MAX_SIZE 10
using namespace std;
using std::ostream;
using std::istream;

Console::Console()
{
    student1=new Student;
    //ctor
}
Console::~Console()
{
    if(!student1)
        delete student1;
    //dtor
}
int Console::run()
{
    cout<<"欢迎来到选课系统,提供学生的姓名、生日信息的录入与查询"<<endl;
    cout<<"还可以进行选课、退课"<<endl;
    cout<<"每人最多可选10门必修和10门选修课"<<endl;
    buildStudent();
    buildCourse();
    int choice;
    choice=displayMenu();
    while (choice!=0)
    {
        switch (choice)
        {
            case 1:
                selectObCourse();
                break;
            case 2:
                selectElCourse();
                break;
            case 3:
                //Student s=(*student);
                cout<<(*student1)<<endl;
                break;
            case 4:
                setCourseScore();
                break;
            case 5:
                removecourse();
                break;
            case 6:
                cout<<"积点为"<<(*student1).calAchievement()<<endl;;
                break;
            default:
                break;
        }
        choice=displayMenu();
    }
    save();
    return 0;
}

int Console::displayMenu()const
{
    cout<<endl;
    cout<<"按1 选必修课"<<endl;
    cout<<"按2 选选修课"<<endl;
    cout<<"按3 输出学生选课信息"<<endl;
    cout<<"按4 设置学生成绩"<<endl;
    cout<<"按5 退课"<<endl;
    cout<<"按6 查看积点"<<endl;
    cout<<"按0 退出系统"<<endl;
    cout<<endl;
    int choice;
    cin>>choice;
    while(cin.fail() || choice>=7 || choice<0)
    {
        cout<<"请重新输入\n";
        cin.clear();
        cin.ignore(1024, '\n');
        cin>>choice;
    }
    return choice;
}
void Console::selectObCourse()
{
    cout<<"必修课有高数、大物"<<endl;
    cout<<"按1 选择高数"<<endl;
    cout<<"按2 选择大物"<<endl;
    cout<<endl;
    int j;
    cin>>j;
    if(j==1)
    {
        student1->addCourse(ob[0]);
    }
    else if(j==2){
        student1->addCourse(ob[1]);
    }
}
void Console::selectElCourse()
{
    cout<<"选修课有音乐鉴赏、体育"<<endl;
    cout<<"按1 选择音乐鉴赏"<<endl;
    cout<<"按2 选择体育"<<endl;
    cout<<endl;
    int j;
    cin>>j;

    if(j==1)
    {
        student1->addCourse(el[0]);
    }
    else if(j==2)
    {
        student1->addCourse(el[1]);
    }
}
void Console::removecourse()
{
    cout<<"最先输出的为地1门课，依次递增"<<endl;
    cout<<(*student1)<<endl;
    cout<<"输入退到第几门课"<<endl;
    cout<<endl;
    int i;
    while(1)
    {
        cin>>i;
        try{
                while(cin.fail())
                {
                    cout<<"请重新输入\n";
                    cin.clear();
                    cin.ignore(1024, '\n');
                    cin>>i;
                }
                Course *a=(*student1)[i];
                student1->removeCourse(i);
                break;
        }catch(MyException ex)
        {
            cout<<"课程下标超出，系统异常："<<ex.what()<<"\n";
            cout<<"输入";
        }
    }

}
bool Console::setCourseScore()
{
    while(1)
    {
        try{
            student1->setCourseScore();
            break;
        }
        catch(MyException ex)
        {
            cout<<"系统异常："<<ex.what()<<"\n";
            cout<<"请重新输入成绩";
        }
    }

}
void Console::buildStudent()
{
    cout<<"输入同学的姓名"<<endl;
    char *na= new char [20];
    cin>>na;
    student1->setname(na);
    cout<<"输入同学的生日"<<endl;
    cout<<endl;
    int y,m,d;
    while(1)
    {
        try{
            cout<<"请输入出生年份"<<endl;
            cin>>y;
            cout<<"请输入出生月份"<<endl;
            cin>>m;
            cout<<"请输入出生日份"<<endl;
            cin>>d;
            Time t(y,m,d);
            student1->setbirthDate(t);
            break;
        }
        catch(MyException ex)
        {
            cout<<"系统异常："<<ex.what()<<"\n";
            cout<<"请重新输入学生生日"<<endl<<endl;
        }
    }
    //student1=new Student(na,y,m,d);
}
void Console::buildCourse()
{
    /*ob[0]=new ObligatoryCourse("gaoshu",2);
    ob[1]=new ObligatoryCourse("wuli",2);
    el[0]=new ElectiveCourse("xuexi",1);
    el[1]=new ElectiveCourse("yinyue",1);*/
    int i,j=0,k=0;
    string s;
    ifstream ifile1,ifile2;
    ifile1.open("a.txt");
    ifile2.open("b.txt");
    if(ifile1)
    {
        //cout<<"coursename\tcoursehour\n"
        while(ifile1>>s>>i)
        {
            ob[j]=new ObligatoryCourse(s,i);
            j++;
        }
    }
    if(ifile2)
    {
        //cout<<"coursename\tcoursehour\n"
        while(ifile2>>s>>i)
        {
            el[k]=new ElectiveCourse(s,i);
            k++;
        }
    }
    else{
        cout<<"error/n";
    }
    ifile1.close();
    ifile2.close();
}
bool Console::save()
{
     ofstream out;
     out.open("save.txt",ios::app);
     if(!out)
        return 0;
     if(student1==NULL)
     {
         cout<<"error\t";
     }
     out<<(*student1);
     out.close();
}
