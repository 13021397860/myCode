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
    std::cout<<"������2017-5-16"<<std::endl;
    Date DateTest(2017,5,16);
    std::cout<<DateTest<<std::endl;
    std::cout<<DateTest++<<std::endl;
    std::cout<<DateTest<<std::endl;
    std::cout<<++DateTest<<std::endl;
    std::cout<<DateTest<<std::endl;
}
void Console::create()
{
    std::cout<<"�뽨��һ���˻������������������գ�:"<<std::endl;
    std::cin>>c;
    std::cin>>y>>m>>d;
    Date a(y,m,d);
    temp=new Student(c,a);
}
void Console::choose()
{
    std::cout<<"��Ҫѡ�����ֿγ̣�"<<std::endl;
    std::cout<<"��1ѡ����޿γ�;"<<std::endl;
    std::cout<<"��2ѡ��ѡ�޿γ�;"<<std::endl;
    int e;
    std::cin>>e;
    if(e==1)
    {
        std::cout<<"������γ����Լ�ѧʱ:"<<std::endl;
        std::cin>>x>>credit;
        ObligatoryCourse *ob=new ObligatoryCourse(x,credit);
        temp->addCourse(ob);
    }
    else if(e==2)
    {
        std::cout<<"������γ����Լ�ѧʱ:"<<std::endl;
        std::cin>>x>>credit;
        ElectiveCourse *ob=new ElectiveCourse(x,credit);
        temp->addCourse(ob);
    }
    else
    {
        std::cout<<"��������!"<<std::endl;
    }
}
void Console::setScore()
{
    for(int j=0;j<temp->getCourseNumber();j++) 
		temp->getList(j)->printClass();
    std::cout<<"����Ҫ�����ſγ�����ѧ�֣�"<<std::endl;
    int i;
    std::cin>>i;
    if(i>temp->getCourseNumber()||i<0) 
		std::cout<<"��������"<<std::endl;
    else
    {
        std::cout<<"����Ҫ���ö��ٷ֣�"<<std::endl;
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
    std::cout<<"����ʲô������"<<std::endl;
    std::cout<<"��1���ӿγ�;"<<std::endl;
    std::cout<<"��2�Ƴ��γ�;"<<std::endl;
    std::cout<<"��3����ѧ��;"<<std::endl;
    std::cout<<"��4��ӡ������Ϣ;"<<std::endl;
    std::cout<<"��5�����������Ӳ���;"<<std::endl;
    std::cout<<"��6��ѯ�γ�Ȩ��;"<<std::endl;
    std::cout<<"��7�˳�;"<<std::endl;
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
        std::cout<<"����Ҫ�Ƴ����ſγ̣�"<<std::endl;
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
        std::cout<<"�ѽ�����"<<std::endl;
        return false;
    }
    else
    {
        std::cout<<"��������"<<std::endl;
        return false;
    }
}
