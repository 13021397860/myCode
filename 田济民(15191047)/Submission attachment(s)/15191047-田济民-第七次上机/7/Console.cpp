#include "Console.h"
#include"Student.h"
#include<iostream>
#include<string>
#include"ObligatoryCourse.h"
#include"Course.h"
#include"ElectiveCourse.h"
#include<typeinfo>
#include<fstream>
#include<cstdlib>
#include"MyException.h"
Course*courseListmain[10];
int xuan[10]= {0};
using namespace std;
Console::Console()
{
    //ctor
}
Console::~Console()
{
    //dtor
}
void choice(int &i,int l,int r)
{
    while(!(cin>>i))
    {
        cin.clear();
        while(cin.get()!='\n')
            continue;
        cout << "\nInvalid choice, try again:";
    }
    if(i<l||i>r)
    {
        cout << "\nInvalid choice, try again:";
        choice(i,l,r);
    }
    return;
}
void Console::run()
{
part1:
    cout<<"you should input some info to create a student\n";
    cout<<"please input name,year,month,day\n";
    string name;
    int y,m,d;
    cin>>name>>y>>m>>d;
    Date adate;
    try
    {
        adate=Date(y,m,d);
    }
    catch(MyException &ex)
    {
        cout<<ex.mymessages()<<endl;
        goto part1;
    }
    Student *stu1=new Student(adate,name);
    cout<<"a student was created\n";
    ifstream tFile("studentclass.txt", ios::in);
    int num;
    string str1;
    string str2;
    int i=0;
    while(tFile>>str1>>str2>>num)
    {
        if(str1=="ElectiveCourse")
        {
            courseListmain[i]=new ElectiveCourse();
            courseListmain[i]->setCreditHour(num);
            courseListmain[i]->setName(str2);
        }
        else if(str1=="ObligatoryCourse")
        {
            courseListmain[i]=new ObligatoryCourse();
            courseListmain[i]->setCreditHour(num);
            courseListmain[i]->setName(str2);
        }
        ++i;
    }
    cout<<"these course below can be chosen\n";
    int j;
    for( j=0; j<i; j++)
    {
        if(typeid(ObligatoryCourse)==typeid(*courseListmain[j]))
        {
            ObligatoryCourse*temp=dynamic_cast<ObligatoryCourse*>(courseListmain[j]);
            cout<<j<<" "<<*temp;
        }
        else if(typeid(ElectiveCourse)==typeid(*courseListmain[j]))
        {
            ElectiveCourse*temp1=dynamic_cast<ElectiveCourse*>(courseListmain[j]);
            cout<<j<<" "<<*temp1;
        }
    }
    while(true)
    {
        int ope;
        cout<<"**********************************\n";
        cout<<"1 select Course\n";
        cout<<"2 to removecourse\n";
        cout<<"3 to set score\n";
        cout<<"4 to show course score\n";
        cout<<"5 to exit\n";
        choice(ope,1,5);
        if(ope==1)
        {
            //select course
            cout<<"please input course number(in front of course name)\n";
            int temp1;
            choice(temp1,0,j);
            if(xuan[temp1]==0)
                stu1->addCourse(courseListmain[temp1]);
            else cout<<"the course has been chosen\n";
            xuan[temp1]=1;
        }

        else if(ope==2)//remove course
        {
            cout<<"please input course number(in front of course name)\n";
            int n;
            cin>>n;
            try
            {
                Course*temp=stu1->returncourse(n);
                if(!stu1->removeCourse(n))
                    cout<<"wrong input\n\n\n";
                else
                {
                    int x;
                    for(x=0; x<i; x++)
                    {
                        if(temp==courseListmain[x])
                            break;
                    }
                    cout<<"course was removed\n";
                    xuan[x]=0;
                }
            }
            catch(MyException ex2)
            {
                cout<<ex2.mymessages()<<endl;
                continue;
            }

        }
        else if(ope==3)
        {
            //set score;
            cout<<"please input the course number and score\n";
            int s,pos;
            cin>>pos>>s;
            try
            {
            //    cout<<145<<endl;
                stu1->setscore(s,pos);
              //  cout<<147<<endl;
            }
            catch(MyException ex3)
            {
                cout<<ex3.mymessages()<<endl;
            }
        }
        else if(ope==4)
        {
            //show course
            cout<<"please input the course number \n";
            int pos;
            cin>>pos;
            try
            {
                cout<<stu1->returncourse(pos)->getScore()<<endl;
            }
            catch(MyException ex4)
            {
                cout<<ex4.mymessages()<<endl;
            }
        }
        else if(ope==5)
        {

            break;
        }
        //  system("cls");
        cout<<"these course below can be chosen\n";
        for( j=0; j<i; j++)
        {
            if(typeid(ObligatoryCourse)==typeid(*courseListmain[j]))
            {
                ObligatoryCourse*temp=dynamic_cast<ObligatoryCourse*>(courseListmain[j]);
                cout<<j<<" "<<*temp;
            }
            else if(typeid(ElectiveCourse)==typeid(*courseListmain[j]))
            {
                ElectiveCourse*temp1=dynamic_cast<ElectiveCourse*>(courseListmain[j]);
                cout<<j<<" "<<*temp1;
            }
        }
        cout<<"*****";
        cout<<"student info ******\n";
        cout<<*stu1;
    }
    ofstream outfile("student.txt", ios::out);

    outfile<<*stu1;
    delete stu1;
}
