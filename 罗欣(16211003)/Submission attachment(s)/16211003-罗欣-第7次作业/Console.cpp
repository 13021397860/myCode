#include "Console.h"
#include "Student.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include"Course.h"
#include"MyException.h"
using namespace std;

ofstream outClientFile("client.dat",ios::out);
ifstream inClientFile("courses.dat",ios::in);

Console::Console()
{
    //ctor
}

Console::~Console()
{
    //dtor
}

Console& Console::buildStudent()
{
    cout<<"Student's name: ";
    cin>>str;
    cout<<"Birthday: ";

    char *p=new char[str.length()+1];
    strcpy(p,str.data());
    Student s(p);
    while(cin>>y>>m>>d)
    {
        birth.SetDate(y,m,d);
        try
        {
            if(!birth.isLeapyear())
            {
                MyException Exception(0);
                Exception.DateException(birth);
            }
            break;
        }
        catch(Date&)
        {
            cout<<"Wrong date"<<endl<<"input again: ";
        }

    }

    student=new Student;
    student->SetName(s.GetName());
    student->SetBirthday(birth);

    return *this;
}


void Console::displayMenue()const
{
    cout<<"5 Types Of Instructions"<<endl
    <<"  \"1\" to show the student's Information"<<endl
    <<"  \"2\" to add a course"<<endl
    <<"  \"3\" to quit a course"<<endl
    <<"  \"4\" to set score for a course"<<endl
    <<"  \"5\" to end."<<endl;
    cout<<"Some courses you can choose: "<<endl;
}

Console& Console::buildCourse()
{
    {
        cout<<"Obligatory Course:"<<endl;
        for(int i=1;i<=2;i++)
        {
            inClientFile>>cn>>cc;
            cout<<"name: "<<cn;
            cout<<" Credict Hour("<<cc;
            cout<<")"<<endl;
            ObligatoryCourse *cp=new ObligatoryCourse();
            cp->setname(cn);
            cp->setcreditHour(cc);
            cp->setmark(60);
            oc[i]=cp;
        }
        cout<<"Elective Course: "<<endl;
        for(int i=1;i<=2;i++)
        {
            inClientFile>>cn>>cc;
            cout<<"name: "<<cn;
            cout<<" Credict Hour("<<cc;
            cout<<")"<<endl;
            ElectiveCourse *cp=new ElectiveCourse();
            cp->setname(cn);
            cp->setcreditHour(cc);
            cp->setmark(0);
            ec[i]=cp;
        }

    }

    return *this;
}

Console& Console::chooseObligatoryCourse(int op)
{
    while(op!=1 && op!=2)
    {
        cout<<"Failed"<<endl;
        cin>>op;
    }
    if(op<=2 && op>0)
    {
        cptr0->setcreditHour(oc[op]->getcreditHour());
        cptr0->setname(oc[op]->getname());
        cptr0->setmark(60);
        student->addCourse(cptr0);
    }
    else
        cout<<"no such a course"<<endl;
    return *this;
}

Console& Console::chooseElectiveCourse(int op)
{
    while(op!=1 && op!=2)
    {
        cout<<"Failed"<<endl;
        cin>>op;
    }
    if(op<=2 && op>0)
    {
        cptr1->setcreditHour(ec[op]->getcreditHour());
        cptr1->setname(ec[op]->getname());
        cptr1->setmark(60);
        student->addCourse(cptr1);
    }
    return *this;
}


Course* Console::seletCourse(int op)
{
    while(op!=1 && op!=2)
    {
        cout<<"Failed"<<endl;
        cin>>op;
    }
    if(op==1)
    {
        cptr0=new ObligatoryCourse();
        cout<<"Choose a course from the format below(enter its number): "<<endl
        <<"1."<<oc[1]->getname()<<' '<<oc[1]->getcreditHour()<<endl
        <<"2."<<oc[2]->getname()<<' '<<oc[2]->getcreditHour()<<endl;
        int no;
        cin>>no;
        chooseObligatoryCourse(no);
    }
    else if(op==2)
    {
        cptr1=new ElectiveCourse();
        cout<<"Choose a course from the format below(enter its number): "<<endl
        <<"1."<<ec[1]->getname()<<' '<<ec[1]->getcreditHour()<<endl
        <<"2."<<ec[2]->getname()<<' '<<ec[2]->getcreditHour()<<endl;
        int no;
        cin>>no;
        chooseElectiveCourse(no);
    }
}
void Console::setCourseScore()
{
    cout<<"Set score for one course and first choose a course (enter its number): ";
    int no;
    while(cin>>no)
    {
        try
        {
            MyException Exception(1);
            Exception.CourseNumException(no,student);
            student->setscore(no);
            break;
        }
        catch(int &num)
        {
            cout<<"wrong course"<<endl<<"input again: ";
        }
    }
}

void Console::run()
{
    buildStudent();
    displayMenue();
    buildCourse();
    char instruction;
    int flag=1;
    while(cin>>instruction)
    {
        switch(instruction)
        {
        case '1':
            if(!outClientFile)
            {
                cout<<"file could not be opened"<<endl;
                exit(0);
            }
            else
            {
                cout<<*student<<endl;
                outClientFile<<*student<<endl;
            }
            //cout<<student.birth.GetDay()<<endl;
            break;
        case '2':
            cout<<"Enter \"1\" To Add An Obligatory Course"<<endl<<"   or \"2\" To Add An Elective Course:"<<endl;
            int classtype;
            cin>>classtype;
            seletCourse(classtype);

            break;
        case '3':
            cout<<"Enter the number of the course you want to quit: ";
            int no;
            while(cin>>no)
            {
                try
                {
                    MyException Exception(1);
                    Exception.CourseNumException(no,student);
                    student->quitCourse(no);
                    break;
                }
                catch(int &num)
                {
                    cout<<"wrong course"<<endl<<"input again: ";
                }
            }
            break;
        case '4':
            setCourseScore();
            break;
        case '5':
            flag=0;
            break;
        default:
            cout<<"Wrong Instruction."<<endl;
        }
        if(!flag)
            break;
    }
}
