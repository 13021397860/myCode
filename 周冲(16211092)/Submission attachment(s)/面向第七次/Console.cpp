#include"Date.h"
#include"Student.h"
#include"Course.h"
#include "Console.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include<iostream>
#include<cstring>
#include<typeinfo>
Console::Console()
{
}
Console::~Console()
{
    delete temp;
}
void Console::PPtest()
{
    std::cout<<"今天是2017-5-16"<<std::endl;
    Date DateTest(2017,5,16);
    std::cout<<DateTest<<std::endl;
    std::cout<<DateTest++<<std::endl;
    std::cout<<DateTest<<std::endl;
    std::cout<<++DateTest<<std::endl;
    std::cout<<DateTest<<std::endl;
}
void Console::create()
{
    std::cout<<"请建立一个账户（姓名、出生年月日）:"<<std::endl;
    std::cin>>c;
    std::cin>>y>>m>>d;
    Date a(y,m,d);
    temp=new Student(c,a);
}
void Console::choose()
{
    std::cout<<"想要选择哪种课程？"<<std::endl;
    std::cout<<"按1选择必修课程;"<<std::endl;
    std::cout<<"按2选择选修课程;"<<std::endl;
    int e;
    std::cin>>e;
    if(e==1)
    {
        std::cout<<"请填入课程名以及学时:"<<std::endl;
        std::cin>>x>>credit;
        ObligatoryCourse *ob=new ObligatoryCourse(x,credit);
        temp->addCourse(ob);
    }
    else if(e==2)
    {
        std::cout<<"请填入课程名以及学时:"<<std::endl;
        std::cin>>x>>credit;
        ElectiveCourse *ob=new ElectiveCourse(x,credit);
        temp->addCourse(ob);
    }
    else
    {
        std::cout<<"发生错误!"<<std::endl;
    }
}
void Console::setScore()
{
    for(int j=0;j<temp->getCourseNumber();j++) 
		temp->getList(j)->printClass();
    std::cout<<"你想要给哪门课程设置学分？"<<std::endl;
    int i;
    std::cin>>i;
    if(i>temp->getCourseNumber()||i<0) 
		std::cout<<"发生错误！"<<std::endl;
    else
    {
        std::cout<<"你想要设置多少分？"<<std::endl;
        ObligatoryCourse middle;
        if(typeid(middle)==typeid(*(temp->getList(i))))
        {
            temp->getList(i)->setGrade();
        }
        else
        {
            temp->getList(i)->setGrade();
        }
    }
}
bool Console::control()
{
    std::cout<<"进行什么操作？"<<std::endl;
    std::cout<<"按1增加课程;"<<std::endl;
    std::cout<<"按2移除课程;"<<std::endl;
    std::cout<<"按3设置学分;"<<std::endl;
    std::cout<<"按4打印所有信息;"<<std::endl;
    std::cout<<"按5进行日期增加操作;"<<std::endl;
    std::cout<<"按6查询课程权重;"<<std::endl;
    std::cout<<"按7退出;"<<std::endl;
    int i;
    std::cin>>i;
    if(i==1)
    {
        choose();
        return true;
    }
    else if(i==2)
    {
        int j;
        for(int j=0;j<temp->getCourseNumber();j++) temp->getList(j)->printClass();
        std::cout<<"你想要移除哪门课程？"<<std::endl;
        std::cin>>j;
        temp->removeCourse(j);
        return true;
    }
    else if(i==3)
    {
        setScore();
        return true;
    }
    else if(i==4)
    {
        std::cout<<*temp<<std::endl;
        return true;
    }
    else if(i==5)
    {
        PPtest();
        return true;
    }
    else if(i==6)
    {
        std::cout<<temp->calcCredit()<<std::endl;
        return true;
    }
    else if(i==7)
    {
        std::cout<<"已结束！"<<std::endl;
        return false;
    }
    else
    {
        std::cout<<"发生错误"<<std::endl;
        return false;
    }
}
