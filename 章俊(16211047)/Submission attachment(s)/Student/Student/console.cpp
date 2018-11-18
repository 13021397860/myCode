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
    cout<<"��ӭ����ѡ��ϵͳ,�ṩѧ����������������Ϣ��¼�����ѯ"<<endl;
    cout<<"�����Խ���ѡ�Ρ��˿�"<<endl;
    cout<<"ÿ������ѡ10�ű��޺�10��ѡ�޿�"<<endl;
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
                cout<<"����Ϊ"<<(*student1).calAchievement()<<endl;;
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
    cout<<"��1 ѡ���޿�"<<endl;
    cout<<"��2 ѡѡ�޿�"<<endl;
    cout<<"��3 ���ѧ��ѡ����Ϣ"<<endl;
    cout<<"��4 ����ѧ���ɼ�"<<endl;
    cout<<"��5 �˿�"<<endl;
    cout<<"��6 �鿴����"<<endl;
    cout<<"��0 �˳�ϵͳ"<<endl;
    cout<<endl;
    int choice;
    cin>>choice;
    while(cin.fail() || choice>=7 || choice<0)
    {
        cout<<"����������\n";
        cin.clear();
        cin.ignore(1024, '\n');
        cin>>choice;
    }
    return choice;
}
void Console::selectObCourse()
{
    cout<<"���޿��и���������"<<endl;
    cout<<"��1 ѡ�����"<<endl;
    cout<<"��2 ѡ�����"<<endl;
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
    cout<<"ѡ�޿������ּ��͡�����"<<endl;
    cout<<"��1 ѡ�����ּ���"<<endl;
    cout<<"��2 ѡ������"<<endl;
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
    cout<<"���������Ϊ��1�ſΣ����ε���"<<endl;
    cout<<(*student1)<<endl;
    cout<<"�����˵��ڼ��ſ�"<<endl;
    cout<<endl;
    int i;
    while(1)
    {
        cin>>i;
        try{
                while(cin.fail())
                {
                    cout<<"����������\n";
                    cin.clear();
                    cin.ignore(1024, '\n');
                    cin>>i;
                }
                Course *a=(*student1)[i];
                student1->removeCourse(i);
                break;
        }catch(MyException ex)
        {
            cout<<"�γ��±곬����ϵͳ�쳣��"<<ex.what()<<"\n";
            cout<<"����";
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
            cout<<"ϵͳ�쳣��"<<ex.what()<<"\n";
            cout<<"����������ɼ�";
        }
    }

}
void Console::buildStudent()
{
    cout<<"����ͬѧ������"<<endl;
    char *na= new char [20];
    cin>>na;
    student1->setname(na);
    cout<<"����ͬѧ������"<<endl;
    cout<<endl;
    int y,m,d;
    while(1)
    {
        try{
            cout<<"������������"<<endl;
            cin>>y;
            cout<<"����������·�"<<endl;
            cin>>m;
            cout<<"����������շ�"<<endl;
            cin>>d;
            Time t(y,m,d);
            student1->setbirthDate(t);
            break;
        }
        catch(MyException ex)
        {
            cout<<"ϵͳ�쳣��"<<ex.what()<<"\n";
            cout<<"����������ѧ������"<<endl<<endl;
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
