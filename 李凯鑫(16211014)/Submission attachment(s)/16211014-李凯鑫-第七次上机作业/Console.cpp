#include "Console.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<sstream>
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Student.h"
#include "MyException.h"
using namespace std;

Console::Console()
{
    //ctor
}

Console::~Console()
{
    //dtor
}

void Console::option()
{
    cout<<endl;
    cout<<"1.Check Student's Information\n"
        <<"2.Add Course  (course number <=10)\n"
        <<"  1.Add ObligatoryCourse\n"
        <<"  2.Add ElectiveCourse\n"
        <<"3.Add Course From File (Include The Mark) \n"
        <<"4.Drop Course\n"
        <<"5.Change Course Mark\n"
        <<"6.Add Student And Course Information To The File\n"
        <<"7.Add Student Information To The File\n"
        <<"8.Exit"<<endl;
    cout<<endl;
}

int Console::run()
{
    cout<<"Add Student  (name    birthday)"<<endl;
    Student s("ABC",1,1,1);
    char name[21];
    int y,m,d;
    cin>>name>>y>>m>>d;
    try
    {
        s.setStudent(name,y,m,d);
    }
    catch(MyException ex)
    {
        cout<<"出现异常："<<ex.what()<<"\n";
    }
    option();
    string operation;
    while(cin>>operation)
    {
        if(operation=="1")
        {
            s.calcCredit();
            cout<<s;
            cout<<"Credit: "<<s.getCredit()<<endl;
            option();
        }
        else if(operation=="2")
        {
            string cs;
            int k=1;
            while(k==1)
            {
                cout<<"Choose course type: 1.ObligatoryCourse   2.ElectiveCourse"<<endl;
                cin>>cs;
                stringstream ss;
                try
                {
                    if(cs=="1")
                    {
                        cout<<"Add course name, credit hour"<<endl;
                        string n1;
                        int hour1;
                        int mark=0;
                        cin>>n1>>hour1;
                        Course* c1= new ObligatoryCourse(n1,hour1,mark);
                        s.addCourse(c1,"ObligatoryCourse");
                        k=0;
                        option();
                    }
                    else if(cs=="2")
                    {
                        cout<<"Add course name, credit hour"<<endl;
                        string n2;
                        int hour2;
                        string grade="0";
                        cin>>n2>>hour2;
                        Course* c2=new ElectiveCourse(n2,hour2,grade);
                        s.addCourse(c2,"ElectiveCourse");
                        k=0;
                        option();
                    }
                    else
                        cout<<"Please Input Right Option\n"<<endl;
                }
                catch(MyException ex)
                {
                    cout<<"出现异常："<<ex.what()<<"\n";
                }
            }
        }
        else if(operation=="3")
        {
            ifstream inClientFile("test.txt", ios::in);
            if(!inClientFile)
            {
                cerr<<"File could no be opened"<<endl;
                exit(1);
            }
            string cs;
            int k1=0,k2=0;
            while(inClientFile>>cs)
            {
                if(cs=="1")
                {
                    string n1;
                    int hour1, mark;
                    inClientFile>>n1>>hour1>>mark;
                    Course* c1= new ObligatoryCourse(n1,hour1,mark);
                    s.addCourse(c1,"ObligatoryCourse");
                    k1=1;
                }
                else if(cs=="2")
                {
                    string n2;
                    int hour2;
                    string grade;
                    inClientFile>>n2>>hour2>>grade;
                    Course* c2=new ElectiveCourse(n2,hour2,grade);
                    s.addCourse(c2,"ElectiveCourse");
                    k2=1;
                }
            }
            if(k1==1&&k2==1)
                cout<<"Succeed"<<endl;
            else
                cout<<"Fail"<<endl;
            option();
        }
        else if(operation=="4")
        {
            cout<<"The number of the course you want to drop"<<endl;
            int ci;
            cin>>ci;
            try
            {
                if(s.removeCourse(ci))cout<<"Succeed"<<endl;
            }
            catch(MyException ex)
            {
                cout<<"出现异常："<<ex.what()<<"\n";
            }
            option();
        }
        else if(operation=="5")
        {
            cout<<"Input the number of course and mark you want to set"<<endl;
            int number;
            string mark;
            cin>>number>>mark;
            try
            {
                s.setMark(number,mark);
            }
            catch(MyException ex)
            {
                cout<<"出现异常："<<ex.what()<<"\n";
            }
            option();
        }
        else if(operation=="6")
        {
            ofstream outClientFile("reception.txt", ios::out);
            if(!outClientFile)
            {
                cerr<<"File could not be opened"<<endl;
                exit(1);
            }
            s.calcCredit();
            outClientFile<<s;
            outClientFile<<"Credit: "<<s.getCredit()<<endl;
            cout<<"Succeed"<<endl;
            option();
        }
        else if(operation=="7")
        {
            ofstream outClientFileStu("reception2.txt", ios::out);
            if(!outClientFileStu)
            {
                cerr<<"File could not be opened"<<endl;
                exit(1);
            }
            outClientFileStu<<"Name : "<<s.getName()<<"    Birthday : "<<s.getBirthDate()<<endl;
            outClientFileStu<<"Credit: "<<s.getCredit()<<endl;
            cout<<"Succeed"<<endl;
            option();
        }
        else if(operation=="8")
            break;
        else
        {
            cout<<"Please Input Right Option"<<endl;
            option();
        }
    }
    return 0;
}
