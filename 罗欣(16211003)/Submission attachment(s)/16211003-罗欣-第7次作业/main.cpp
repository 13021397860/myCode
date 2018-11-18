#include <iostream>
#include<iomanip>
#include "Date.h"
#include"Student.h"
#include"Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include"Console.h"
#include<cstring>
using namespace std;

int main()
{
/*
    Course *cPtr0=new ObligatoryCourse();
    cPtr0->setmark(90);
    cout<<cPtr0->getScore()<<endl;

    Course *cPtr1=new ElectiveCourse();
    cPtr1->setmark(85);
    cout<<cPtr1->getScore()<<endl;

    Date birth;
    string str="NoName";
    birth.SetDate(1990,1,1);
    char *p=new char[str.length()+1];
    strcpy(p,str.data());
    Student s(p);
    s.SetName(p);
    s.SetBirthday(&birth);
    cPtr0->setcreditHour(48);
    cPtr0->setname("math");
    cPtr1->setcreditHour(36);
    cPtr1->setname("m");
    s.addCourse(cPtr0);
    s.addCourse(cPtr1);
    s.addCourse(NULL);
    s.PrintStu();
    s.GetBirthday().PrintDate();
    s.printcourselist();

    Date birth;
    string str;
    int y,m,d;
    cout<<"student's name: ";
    cin>>str;
    cout<<"birthday; ";
    cin>>y>>m>>d;
    birth.SetDate(y,m,d);
    char *p=new char[str.length()+1];
    strcpy(p,str.data());
    Student s(p);
    s.SetBirthday(&birth);

    int instruction;
    cout<<"3 Types Of Instructions"<<endl
    <<"  \"1\" To Show The Student's Information"<<endl
    <<"  \"2\" To Add A Course"<<endl
    <<"  \"3\" To End."<<endl;
    while(cin>>instruction)
    {
        Course *cptr0=new ObligatoryCourse();
        Course *cptr1=new ElectiveCourse();
        switch(instruction)
        {
        case 1:
            s.PrintStu();
            cout<<"Birthday:";
            cout<<s.GetBirthday();
            s.GetBirthday().PrintDate();
            s.printcourselist();
            cout<<"!"<<endl;
            cout<<s<<endl;
            break;
        case 2:
            cout<<"Enter \"1\" To Add An Obligatory Course"<<endl<<"   or \"2\" To Add An Elective Course:"<<endl;
            int classtype;
            cin>>classtype;
            if(classtype==1)
            {
                int coMark;
                int coCredit;
                string coName;
                cout<<"Enter a course name: ";
                cin>>coName;
                cout<<"Enter the credit: ";
                cin>>coCredit;
                cout<<"Enter the grade: ";
                cin>>coMark;
                cptr0->setmark(coMark);
                cptr0->setcreditHour(coCredit);
                cptr0->setname(coName);
                s.addCourse(cptr0);
            }
            else if(classtype==2)
            {
                int coMark;
                int coCredit;
                string coName;
                cout<<"Enter a course name: ";
                cin>>coName;
                cout<<"Enter the credit: ";
                cin>>coCredit;
                cout<<"Enter the grade: ";
                cin>>coMark;
                cptr1->setmark(coMark);
                cptr1->setcreditHour(coCredit);
                cptr1->setname(coName);
                s.addCourse(cptr1);
            }
            else
            {
                cout<<"bi xiu shu 1 xuan xiu shu 2 mei you "<<classtype<<endl<<"chong tou lai yi ci xie xie"<<endl;
            }
            break;
        case 3:
            cout<<"Enter the number of the course you want to quit: ";
            int no;
            cin>>no;
            s.quitCourse(no);
            break;
        case 4:
            return 0;
        default:
            cout<<"Wrong Instruction."<<endl;
        }
    }
*/
    Console con;
    con.run();
}
