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
    /*o[0]=new ObligatoryCourse("���ݽṹ", 3);
    o[1]=new ObligatoryCourse("������ѧ����", 5);
    o[2]=new ObligatoryCourse("��ѧ����", 4);
    e[0]=new ElectiveCourse("ѡ��", 2);
    e[1]=new ElectiveCourse("Ӣ��",2);*/

}

Control &Control::buildStudent(char *n, int a,int b,int c)
{
    student=new Student( n,a,b,c);
}

int Control::display()const
{
	int choice=0;
	cout<<"ѧ��ѡ��ϵͳ\n"
		<<"1. ѡ���޿γ�\n"
		<<"2. ѡѡ�޿γ�\n"
		<<"3. �鿴ѡ�����\n"
		<<"4. ���ÿγ̳ɼ�\n"
		<<"5. �鿴����\n"
		<<"6. �鿴�ɼ�\n"
		<<"0. �˳�\n";
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
        cout<<ec.what()<<"���մ�������������"<<endl;
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
	cout<<"��ѡ��һ�ſγ�:\n";
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
    cout<<"�������óɼ������"<<endl;
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
    cout<<"����Ϊ�γ̼��ɼ�"<<endl;
    cout<<*student;
    return true;
}

void Control::refer()
{
    cout<<"����Ϊ��"<<student->calcCredit()<<endl;
}

