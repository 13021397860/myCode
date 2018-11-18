#include "interface.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "Date.h"
#include "Student.h"
#include "obligatorycourse.h"
#include "electivecourse.h"
using namespace std;

//ObligatoryCourse math("Math",4),English("English",4),software("Software",4);
//ElectiveCourse website("Website",1),searching("Searching",1),Linux("Linux",1);

//ObligatoryCourse OCourse0[3]={math,English,software};
//ElectiveCourse ECourse0[3]={website,searching,Linux};

vector<ObligatoryCourse> OCourse;
vector<ElectiveCourse> ECourse;

int a[4],aa=0;
int b[4],bb=0;

interface::interface()
{
    //ctor
}

interface::~interface()
{
    //dtor
}

void interface::fileText()
{
    /*ofstream OC("OC.txt",ios::out);
    ofstream EC("EC.txt",ios::out);
    for(int i=0;i<3;i++)
    {
        OC<<OCourse0[i].getName()<<" "<<OCourse0[i].getCreditHour()<<endl;
        EC<<ECourse0[i].getName()<<" "<<ECourse0[i].getCreditHour()<<endl;
    }*/

    ifstream OC2("OC.txt",ios::in);
    ifstream EC2("EC.txt",ios::in);

    if(!OC2||!EC2)
    {
        cerr<<"File could not be opened" <<endl;
        exit(1);
    }

    /*string s1((istreambuf_iterator<char>(OC2)),istreambuf_iterator<char>());
    string s2((istreambuf_iterator<char>(EC2)),istreambuf_iterator<char>());
    cout<<"ObligatoryCourses:\n"<<s1<<endl;
    cout<<"ElectiveCourses:\n"<<s2<<endl;*/

    string str;
    int x;

    while(OC2>>str>>x)
    {
        ObligatoryCourse tmp(str,x);
        OCourse.push_back(tmp);
    }

    while(EC2>>str>>x)
    {
        ElectiveCourse tmp(str,x);
        ECourse.push_back(tmp);
    }
}

void interface::dateTest()
{
    cout<<"Date operator test:\n";
    Date da;
    cout<<"date: "<<da<<endl;
    cout<<"date++: "<<da++<<endl;
    cout<<"++date: "<<++da<<endl;
    cout<<"date+number: "<<endl;
    cout<<"Please input the number: ";
    int num;cin>>num;
    cout<<"answer: "<<da+num<<endl<<endl<<endl;
}

Student interface::createStudent()
{
    for(int i=1;i<=3;i++)a[i]=b[i]=i;
    char* p = new char;
    cout<<"Please input the student's name: \n";
    cin>>p;
    cout<<endl;

    Date da;
    cout<<"Please input the birthdate(year-month-day): \n";
    cin>>da;
    cout<<endl;

    Student stu( p, &da );
    return stu;
}

void interface::CZ( Student& stu )
{
    while(1)
    {
        cout<<"*************************************************"<<endl<<endl;

        cout<<"Input 1 to add an obligatorycourse\n";
        cout<<"Input 2 to add an electivecourse\n";
        cout<<"Input 3 to check the courselist\n";
        cout<<"Input 4 to remove a course\n";
        cout<<"Input 5 to set grade\n";
        cout<<"Input 6 to calculate the calecredit\n";
        cout<<"Input 7 to save the student's information into the file\n";
        cout<<"Input 8 to visit a course in the courselist\n";
        cout<<"Input 0 to quit\n";

        int cz;cin>>cz;cout<<endl;

        while(cin.fail())
        {
            cout<<"Wrong Input. Please input again:\n";
            cin.clear();
            cin.ignore();
            cin>>cz;
        }

        if(cz==0) break;

        else if(cz==1)
        {
            if(aa==3)cout<<"You have select all the oblidatorycourses\n\n";
            else
            {
                int x;
                cout<<"Iuput the number of the oblidatorycourse\n";
                if(a[1]!=0)cout<<"1. Math     4\n";
                if(a[2]!=0)cout<<"2. English  4\n";
                if(a[3]!=0)cout<<"3. Software 4\n";

                cin>>x;

                while(cin.fail())
                {
                    cout<<"Wrong Input. Please input again:\n";
                    cin.clear();
                    cin.ignore();
                    cin>>x;
                }

                if(x==1&&a[1]!=0)stu.addCourse(&OCourse[0]);
                else if(x==2&&a[2]!=0)stu.addCourse(&OCourse[1]);
                else if(x==3&&a[3]!=0)stu.addCourse(&OCourse[2]);
                else cout<<"Wrong Input\n";

                cout<<endl;
                a[x]=0;aa++;
            }
        }

        else if(cz==2)
        {
            if(bb==3)cout<<"You have select all the electivecourses\n\n";
            else
            {
                int x;
                cout<<"Iuput the number of the electivecourse\n";
                if(b[1]!=0)cout<<"1. Website   1\n";
                if(b[2]!=0)cout<<"2. Searching 1\n";
                if(b[3]!=0)cout<<"3. Linux     1\n";

                cin>>x;

                while(cin.fail())
                {
                    cout<<"Wrong Input. Please input again:\n";
                    cin.clear();
                    cin.ignore();
                    cin>>x;
                }

            if(x==1&&b[1]!=0)stu.addCourse(&ECourse[0]);
            else if(x==2&&b[2]!=0)stu.addCourse(&ECourse[1]);
            else if(x==3&&b[3]!=0)stu.addCourse(&ECourse[2]);
            else cout<<"Wrong Input\n";

            cout<<endl;
            b[x]=0;bb++;
            }
        }

        else if(cz==3)
        {
            cout<<stu;
            cout<<endl;
        }

        else if(cz==4)
        {
            cout<<stu;
            cout<<"Please input the number of course you want to remove:\n";
            int x;cin>>x;

            while(cin.fail())
            {
                cout<<"Wrong Input. Please input again:\n";
                cin.clear();
                cin.ignore();
                cin>>x;
            }

            string str;
            if(stu.courseExist(x,str))
            {
                for(int i=0;i<3;i++)
                {
                    if(OCourse[i].getName()==str){aa--;a[i+1]=1;}
                    if(ECourse[i].getName()==str){bb--;b[i+1]=1;}
                }
            }
            if(stu.removeCourse(x))
                cout<<"Remove Success\n";

            cout<<endl;
        }

        else if(cz==5)
        {
            cout<<stu;
            cout<<"Please input the number of course you want to set grade:\n";
            int x;cin>>x;

            while(cin.fail())
            {
                cout<<"Wrong Input. Please input again:\n";
                cin.clear();
                cin.ignore();
                cin>>x;
            }

            if(x<1||x>stu.getCourseNumber()||!stu.getCourseNumber())
                cout<<"Wrong Input\n";
            else stu.setGrade(x);
            cout<<endl;
        }

        else if(cz==6)
        {
            cout<<"Your calecredit is: "<<stu.caleCredit()<<endl;
        }

        else if(cz==7)
        {
            ofstream outfile("student.txt",ios::out);

            if(!outfile)
            {
                 cerr<<"File could not be opened" <<endl;
                 exit(1);
            }

            outfile<<stu;
            cout<<"Save succeed\n\n";
        }

        else if(cz==8)
        {
            cout<<stu;
            int x;cin>>x;
            while(cin.fail())
            {
                cout<<"Wrong Input. Please input again:\n";
                cin.clear();
                cin.ignore();
                cin>>x;
            }
            stu.VisitCourseList(x);
        }

    }
    cout<<"Thanks for using.\n";
}


