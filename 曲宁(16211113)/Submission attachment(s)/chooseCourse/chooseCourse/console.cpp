#include "Student.h"
#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include <string>
#include <iostream>
#include "console.h"
#include <typeinfo>
#include <fstream>
#include <cstdlib>
#include "myexception.h"
using namespace std;

Console::Console()
{

}

int Console::run()
{
    char name[10];
    cout<<"Please enter the student's name: ";
    cin>>name;
    cout<<"\nPlease enter the student's birthday: ";
    int y1,m1,d1;
    while(cin>>y1>>m1>>d1)
    {
        try
        {
            if(y1<1990||y1>2017||m1>12||m1<=0||d1>31||d1<1)
                throw MyException();
            else
                break;
        }
        catch(MyException ex1)
        {
            ex1.getWrong(0);
            continue;
        }
    }
    /*/while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout<<"Your input is incorrect. Please re-enter it!(year)"<<endl;
        cin>>y1;
    };/*/


    /*/while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout<<"Your input is incorrect. Please re-enter it!(month)"<<endl;
        cin>>m1;
    };/*/

    /*/while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout<<"Your input is incorrect. Please re-enter it!(day)"<<endl;
        cin>>d1;
    };/*/
    Date birthDate1(y1,m1,d1);
    Student student1(name,birthDate1);

    string e[2]= {"Chinese","English"};
    char e1[10]="Chinese";
    char e2[10]="English";
    string o[4]= {"Math","c++","PE","Physical"};
    char o1[10]="Math";
    char o2[10]="c++";
    char o3[10]="PE";
    char o4[10]="Physical";

    ofstream infile("courseData.txt",ios::in);
    if(!infile)
    {
        cerr << "open error"<<endl;

        exit(1);
    }
    infile<<e1<<"\n"<<e2<<"\n"<<o1<<"\n"<<o2<<"\n"<<o3<<"\n"<<o4;
    infile.close();

    ifstream ifs("courseData.txt");

    cout<<"\nPlease choose your elective course!!!(End with #)\n";
    char courseH[10];
    for(int i=0; i<2; i++)
    {

        ifs.getline(courseH,8);
        cout<<i+1<<"."<<courseH<<endl;
    }
    char choice;
    int num=0;
    int course[6];
    while(cin>>choice)
    {
        try
        {
            if(choice=='#')
                break;
            else if(choice-48>2||choice-48<=0)
            {
                throw MyException();
            }
            else
            {
                course[num]=1;
                num++;
                Course *course1=new ElectiveCourse('A',e[(choice-48)-1],0.5);
                student1.addCourse(*&course1);
            }

        }
        catch(MyException ex4)
        {
            ex4.getWrong(1);
            continue;
        }
    }

    int xuanNumber=num;
    cout<<"Please choose your obligatory course!!!(End with #)\n";
    for(int i=0; i<4; i++)
    {
        ifs.getline(courseH,9);
        cout<<i+1<<"."<<courseH<<endl;
    }
    char choice2;
    ObligatoryCourse *course2;
    while(cin>>choice2)
    {
        try
        {
            if(choice2=='#')
                break;
            else if(choice2-48>4||choice2-48<=0)
            {
                throw MyException();
            }
            else
            {
                course[num]=2;
                num++;
                course2=new ObligatoryCourse(100,o[(choice2-48)-1],4);
                student1.addCourse(*&course2);
            }

        }
        catch(MyException ex5)
        {
            ex5.getWrong(1);
            continue;
        }
    }

    for(int i=0; i<num; i++)
    {
        cout<<"Please set grade/mark for the No."<<i+1<<endl;
        if(course[i]==1)
        {
            cout<<"It is an elective course.(char)\n";
            char a;
            while(cin>>a)
            {
                try
                {
                    if(a=='A'||a=='B'||a=='C'||a=='D')
                    {
                        student1.settheScore(course[i],0,a,i);
                        break;
                    }
                    else
                        throw MyException();
                }
                catch(MyException ex6)
                {
                    ex6.getWrong(2);
                    continue;
                }
            }
        }
        else
        {
            cout<<"It is an obligatory course.(int)\n";
            int b;
            while(cin>>b)
            {
                try
                {
                    if(b<=100&&b>=0)
                    {
                        student1.settheScore(course[i],b,'A',i);
                        break;
                    }
                    else
                        throw MyException();
                }
                catch(MyException ex7)
                {
                    ex7.getWrong(2);
                    continue;
                }
            }

        }
    }

    cout<<"The next operation:"<<endl;
    cout<<"1.Withdrawn course\n"<<"2.Check scores\n"<<"3.Search for points of view\n"<<"4.Exit system\n"<<"5.Store student information in a file\n";
    int caozuo;
    while(cin>>caozuo)
    {
        while (cin.fail()||caozuo>5)
        {
            cin.clear();
            cin.ignore();
            cout<<"Your input is incorrect. Please re-enter it!"<<endl;
            cin>>caozuo;
        };
        switch(caozuo)
        {
        case 1:
        {
            cout<<"Which course do you want to remove?(end with #)\n";
            char removenum;
            while(cin>>removenum)
            {
                if(removenum=='#')
                    break;
                else
                    student1.removeCourse((removenum-48)-1);
            }
            break;
        }
        case 2:
        {
            student1.printGrade();
            break;
        }
        case 3:
        {
            cout<<student1.calcCredit(xuanNumber,num-xuanNumber)<<endl;
            break;
        }
        case 4:
        {
            cout<<student1;
            break;
        }
        case 5:
        {
            ofstream ofs("Student.txt",ios::out);
            if(!infile)
            {
                cerr << "open error"<<endl;

                exit(1);
            }
            ofs<<student1;
            ofs.close();
            cout<<"Success"<<endl;
        }
        }
    }


}
Console::~Console()
{

}
