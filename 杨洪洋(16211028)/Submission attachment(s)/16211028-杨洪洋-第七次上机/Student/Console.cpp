//
//  Console.cpp
//  Student
//
//  Created by apple on 2017/5/2.
//  Copyright © 2017年 apple. All rights reserved.
//

#include "Console.hpp"
#include <iostream>
#include<typeinfo>
#include<fstream>
#include<iomanip>
#include<strstream>
#include "MyException.hpp"
using namespace std;
Console::Console()
{
    ocNum=0;
    ecNum=0;
    tempecNum=0;
    tempocNum=0;
}
int Console::displayMenu()
{
        for(int i=0;i<ocNum;i++)
        {
            cout<<"ObligatoryCourse  "<<" ";
            cout<<"Sequence Number: "<<i+1<<" ";
            cout<<*oc[i];
            
        }
        for(int i=0;i<ecNum;i++)
        {
            cout<<"ElectiveCourse    "<<" ";
            cout<<"Sequence Number: "<<i+ocNum+1<<" ";
            cout<<*ec[i];
            
        }
    return 1;
}
Console& Console::buildStudent()
{
    char s[50];
    int y,m,d;
    cout<<"Please enter the student's name: "<<endl;
    cin>>s;
    cout<<"Please enter the student's birthday: (format: year month day)"<<endl;
    cin>>y>>m>>d;
    this->student=new Student(s);
    bool flag=this->student->setBirthday(y, m, d);
    while(!flag)
    {
        try {
            MyException myexc(y,m,d);
            throw &myexc;
        } catch (MyException *myexc) {
            cout<<"A wrong message!!!"<<endl;
            myexc->getErrordate();
            cout<<endl;
        }
        cerr<<"Please enter again! (format: year month day)"<<endl;
        cin>>y>>m>>d;
        flag=this->student->setBirthday(y, m, d);
    }
    return *this;
}//构造学生对象
Course* Console::selectCourse(int op)
{    //选课，参数:op=1:必修，op=2：选修
    if(op>=1&&op<=ocNum)
    {
        this->student->addCourse(this->oc[op-1]);
    }
    else if(op>ocNum&&op<=ocNum+ecNum)
    {
        this->student->addCourse(ec[op-ocNum-1]);
    }
    return this->student->getCourse(student->getCourseNumber());
}
bool Console::setCourseScore()
{
    int scores;
    char grade[100];
    if(typeid(ObligatoryCourse)==typeid(*student->getCourse(student->getCourseNumber())))
    {
        Course *obtemp=student->getCourse(student->getCourseNumber());
        ObligatoryCourse *ob1=&dynamic_cast<ObligatoryCourse&>(*obtemp);
        cout<<"Please enter the score: "<<endl;
        cin>>scores;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cerr<<"You must enter an integer!"<<endl;
            cin>>scores;
        }
        if(scores>=0&&scores<=100)
        {
            ob1->setMark(scores);
        }
        else
        {
            bool flag=0;
            while(!flag)
            {
                try {
                    MyException myexc(scores,'1');
                    throw &myexc;
                } catch (MyException *myexc) {
                    cout<<"A wrong message!!!"<<endl;
                    myexc->geterrorscore();
                    cout<<endl;
                }
                cout<<"You have entered an inaprropriate score! Please enter again!"<<endl;
                cin>>scores;
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cerr<<"You must enter an integer!"<<endl;
                    cin>>scores;
                }
                if(scores>=0&&scores<=100)
                {
                    flag=1;
                    ob1->setMark(scores);
                }
                else
                    flag=0;
            }
        }
        tempocNum++;
    }
    else if(typeid(ElectiveCourse)==typeid(*student->getCourse(student->getCourseNumber())))
    {
        Course *ectemp=student->getCourse(student->getCourseNumber());
        ElectiveCourse *ec1=&dynamic_cast<ElectiveCourse&>(*ectemp);
        cout<<"Please enter the grade: "<<endl;
        cin>>grade;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cerr<<"You must enter the grade!"<<endl;
            cin>>grade;
        }
        if(grade[0]>='A'&&grade[0]<='E')
            ec1->setgrade(grade[0]);
        else
        {
            bool flag=0;
            while(!flag)
            {
                try {
                    MyException myexc(grade);
                    throw &myexc;
                } catch (MyException *myexc) {
                    cout<<"A wrong message!!!"<<endl;
                    myexc->geterrorgrade();
                    cout<<endl;
                }
                cout<<"You have enter an inappropriate grade,Please enter again!"<<endl;
                cin>>grade;
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cerr<<"You must enter the grade!"<<endl;
                    cin>>grade;
                }
                if(grade[0]>='A'&&grade[0]<='E')
                {
                    flag=1;
                    ec1->setgrade(grade[0]);
                }
                else
                    flag=0;
            }
        }
        tempecNum++;
    }
    return 1;
}//设置所有的课程成绩
Console& Console::buildCourse()
{
    readSequentialFile("/Users/apple/yhy2017/projectsforoop/Student/Student/test1.txt");
    return *this;
}//构造所有的可选课程（包括必修和选修课）
int Console::askScore()
{
    cout<<"How many course's grade do you want to check?"<<endl;
    int num;
    cin>>num;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore();
        cerr<<"You must enter the amount of courses you want to check!"<<endl;
        cin>>num;
    }
    for(int i=0;i<num;i++)
    {
        cout<<"Please enter the sequence name of course: "<<endl;
        string  a;
        cin>>a;
        while((a[0]-'0'>=0&&a[0]-'0'<=9))
        {
            try {
                MyException myexc(a[0]-'0','1');
                throw &myexc;
            } catch (MyException *myexc) {
                cout<<"A wrong message!!!"<<endl;
                cout<<myexc->getErrorid()<<endl;
                cout<<"You must enter the sequence name!!!"<<endl;
                cin>>a;
            }
        }
        bool flag=0;
        for(int j=0;j<student->getCourseNumber();j++)
        {
            if(a==(student->getCourseList(j))->getname())
            {
                cout<<student->getCourseList(j)->getScore()<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0)
            cerr<<"You haven't chosen the course!"<<endl;
    }
    return 1;
}
int Console::askJidianScore()
{
    return student->calcCredit();
}
bool Console::readSequentialFile(const char *fileName)
{
    ifstream inClientFile(fileName,ios::in);
    if(!inClientFile)
        return false;
    int account;
    string kindofcourse;
    char name[30];
    double Credits;
    int i=0;
    int j=0;
    while(inClientFile>>kindofcourse>>account>>name>>Credits)
    {
        if(kindofcourse=="ObligatoryCourse")
        {
            oc[i++]=new ObligatoryCourse(name,Credits);
            ocNum++;

        }
        else if(kindofcourse=="ElectiveCourse")
        {
            ec[j++]=new ElectiveCourse(name,Credits);
            ecNum++;
        }
    }
    return true;
}
int Console::run()
{
    string courseName,Courss,k,CourseNames,realname,credit,grade;
    string Number;
    int op;
    buildStudent();//构造学生对象
    buildCourse();//构造所有的可选课程（包括必修和选修课）
    displayMenu();
    cout<<"Please enter the sequence number of the course, enter '-1' to exit: "<<endl;
    cin>>op;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore();
        cerr<<"You must enter the sequence number of the course!"<<endl;
        cin>>op;
    }
    while (op!=-1) {
        if(op!=-1)
        {
            if(op>=1&&op<=ocNum)
            {
                if(student->check(this->oc[op-1]))
                {
                    selectCourse(op);
                    setCourseScore();//设置所有的课程成绩
                    cout<<"Please enter the sequence number of the course, enter '-1' to exit: "<<endl;
                }
                else
                    cout<<"Please select again!"<<endl;
            }
            else if(op>ocNum&&op<=ocNum+ecNum)
            {
                if(student->check(ec[op-ocNum-1]))
                {
                    selectCourse(op);
                    setCourseScore();
                    cout<<"Please enter the sequence number of the course, enter '-1' to exit: "<<endl;
                }
                else
                    cerr<<"Please select again!"<<endl;
            }
            else
            {
                try {
                    MyException myexc(op);
                    throw &myexc;
                } catch (MyException *myexc) {
                    cout<<"A wrong message!!!"<<endl;
                    cout<<myexc->getErrorid()<<endl;
                }
                cerr<<"The course doesn't exist at all! Please select again!"<<endl;
            }
        }
        else
            break;
        cin>>op;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cerr<<"You must enter the sequence number of the course!"<<endl;
            cin>>op;
        }
    }
    
    cout<<"Do you want to quit some courses? Y/N"<<endl;
    char judge;
    cin>>judge;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore();
        cerr<<"You must enter 'Y' or 'N'!"<<endl;
        cin>>judge;
    }
    while(judge)
    {
        if(judge=='Y')
        {
            cout<<"Enter the sequence number of the course you want to quit: "<<endl;
            int a;
            cin>>a;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cerr<<"You must enter the sequence number of the course!"<<endl;
                cin>>a;
            }
            if(a>0&&a<=ocNum)
            {
                int counter=student->removeCourse(a, oc[a-1]->getname());
                if(counter==0)
                {
                    try {
                        MyException myexc(a);
                        throw &myexc;
                    } catch (MyException *myexc) {
                        cout<<"A wrong message!!!"<<endl;
                        cout<<myexc->getErrorid()<<endl;
                        cerr<<"You can't delete the course because you have chose no courses!"<<endl;

                    }

                }
                else if(counter==-2)
                {
                    try {
                        MyException myexc(a);
                        throw &myexc;
                    } catch (MyException *myexc) {
                        cout<<"A wrong message!!!"<<endl;
                        cout<<myexc->getErrorid()<<endl;
                        cerr<<"You can't delete the course becase you have not chose the course!"<<endl;
                    }
                }
                    
                else
                    tempocNum--;
            }
            else if(a>ocNum&&a<=ocNum+ecNum)
            {
                int counter=student->removeCourse(a, ec[a-ocNum-1]->getname());
                if(counter==0)
                {
                    try {
                        MyException myexc(counter);
                        throw &myexc;
                    } catch (MyException *myexc) {
                        cout<<"A wrong message!!!"<<endl;
                        cout<<myexc->getErrorid();
                        cerr<<"You can't delete the course because you have chose no courses!"<<endl;
                    }
                }
                else if(counter==-2)
                {
                    try {
                        MyException myexc(a);
                        throw &myexc;
                    } catch (MyException *myexc) {
                        cout<<"A wrong message!!!"<<endl;
                        cout<<myexc->getErrorid()<<endl;
                    }
                    cerr<<"You can't delete the course becase you have not chose the course!"<<endl;
                }
                else
                    tempecNum--;
            }
            else
            {
                cerr<<"It doesn't exist!"<<endl;
            }
            cout<<"Do you still want to quit some courses? Y/N"<<endl;
        }
        else if(judge=='N')
        {
            break;
        }
        else
        {
            cout<<"Please enter 'Y' or 'N'!"<<endl;
        }
        cin>>judge;
    }
    cout<<*(this->student);
    this->student->createSequentialFile("/Users/apple/yhy2017/projectsforoop/Student/Student/test2.txt");
    if(tempocNum!=1&&tempocNum!=0)
    {
        cout<<"You have selected "<<tempocNum<<" obligatory courses, ";
    }
    else
        cout<<"You have selected "<<tempocNum<<" obligatory courses, ";
    if(tempecNum!=1&&tempecNum!=0)
        cout<<tempecNum<<" elective courses."<<endl;
    else
        cout<<""<<tempecNum<<" elective course."<<endl;
    cout<<"Do you want to check the grade? Y/N"<<endl;
    char judge1;
    cin>>judge1;
    while(judge1!='Y'&&judge1!='N')
    {
        cerr<<"Please enter 'Y' or 'N'!"<<endl;
        cin>>judge1;
    }
    if(judge1=='Y')
        askScore();
    cout<<"Do you want to check GPA? Y/N"<<endl;
    char judge2;
    cin>>judge2;
    while(judge2!='Y'&&judge2!='N')
    {
        cerr<<"Please enter 'Y' or 'N'!"<<endl;
        cin>>judge2;
    }
    if(judge2=='Y')
        askJidianScore();
    return 0;
}
Console::~Console()
{
    
}
