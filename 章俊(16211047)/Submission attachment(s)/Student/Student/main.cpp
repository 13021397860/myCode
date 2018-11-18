#include "student.h"
#include "time.h"
#include <iostream>
#include <cstring>
#include "course.h"
#include <string>
#include "obligatorycourse.h"
#include "electivecourse.h"
#include "console.h"
#include <fstream>


#define MAX_SIZE 10
using namespace std;
int main()
{
    /*ObligatoryCourse *ob[MAX_SIZE];
    ElectiveCourse *el[MAX_SIZE];
    int i,j=0,k=0;
    string s;
    ifstream ifile1,ifile2;
    ifile1.open("a.txt",ios::in);
    ifile2.open("b.txt",ios::in);
    if(ifile1)
    {
        while(ifile1>>s>>i)
        {
            ob[j]=new ObligatoryCourse(s,i);
            j++;
            cout<<s<<" "<<i<<endl;
        }
    }
    else if(ifile2)
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
    }*/
    //ifile1.close("a.txt");
    //ifile2.close("b.txt");
    //cout<<ob[0]<<"\t122"<<el[1];
    Console console;
    console.run();
    return 0;
    //测试重载student<<
    /*ObligatoryCourse *ob[MAX_SIZE];
    ElectiveCourse *el[MAX_SIZE];
    ob[0]=new ObligatoryCourse("gaoshu",1);
    ob[1]=new ObligatoryCourse("gaoshu2",1);
    el[0]=new ElectiveCourse("tiyu1",2);
    el[1]=new ElectiveCourse("tiyu2",2);
    Student s1("Jack",1999,3,21);
    s1.addCourse(ob[0]);
    s1.addCourse(ob[1]);
    s1.addCourse(el[0]);
    s1.addCourse(el[1]);
    cout<<s1<<endl;
    s1.removeCourse(2);
    cout<<s1<<endl;
    /*重载Time<<
    Time (1999,3,21);
    //t.print();
    cout<<t<<endl;
    //t++;
    cout<<t++<<endl;
    cout<<t<<endl;
    cout<<++t<<endl;
    cout<<t<<endl;
    Time d;
    cin>>d;
    cout<<d;
    //t.print();
    //++t;
    //t.print();*/
    return 0;
}
/*第三次上机
    ObligatoryCourse *ob[MAX_SIZE];
    ElectiveCourse *el[MAX_SIZE];
    cout<<"欢迎来到选课系统,提供学生的姓名、生日，选课的课程名称与学分等信息的录入与查询"<<endl;
    cout<<"每人最多可选10门课"<<endl;
    ob[0]=new ObligatoryCourse("gaoshu",1);
    ob[1]=new ObligatoryCourse("gaoshu2",1);
    el[0]=new ElectiveCourse("tiyu1",2);
    el[1]=new ElectiveCourse("tiyu2",2);
    Student s1;
    int b=1;
    while(b!=0)
    {
        cout<<endl;
        cout<<"输入1 可以录入新同学的姓名"<<endl;
        cout<<"输入2 可以录入新同学的生日"<<endl;
        cout<<"输入3 自动选课"<<endl;
        cout<<"输入4 可以查看选课信息"<<endl;
        cout<<"输入0 退出系统"<<endl;
        cout<<endl;
        cin>>b;
        if(b==1)
        {
            char *na= new char [20];
            cin>>na;
            s1.setname(na);
        }
        else if(b==2)
        {
            int y,m,d;
            cout<<"请输入出生年份"<<endl;
            cin>>y;
            cout<<"请输入出生月份"<<endl;
            cin>>m;
            cout<<"请输入出生日份"<<endl;
            cin>>d;
            Time t(y,m,d);
            s1.setbirthDate(t);
        }
        else if(b==3)
        {
            cout<<"由于某种原因，系统自动帮你选好课程了"<<endl;
            s1.addCourse(ob[0]);
            s1.addCourse(ob[1]);
            s1.addCourse(el[0]);
            s1.addCourse(el[1]);
        }
        else if(b==4)
        {
            s1.printstudent();
            cout<<"已选课程"<<endl;
            s1.printcourseList();
            cout<<endl;
        }
        else if(b==0)
        {
            return 0;
        }
    }*/
