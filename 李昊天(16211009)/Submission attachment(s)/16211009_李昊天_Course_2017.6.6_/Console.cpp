#include "Console.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;
Console::Console()
{
    //ctor
}

Console::~Console()
{
    //dtor
}

int Console::run()
{
    ifstream cindata("data.txt",ios::in);
    ofstream coutdata1("info.txt",ios::out);
    ofstream coutdata2("info&score.txt",ios::out);
    Student s("ABC",1970,1,1);
    string CourseName;int creditHour;char grade;int mark;char *na;na=new char[1000];int y,m,d;
    string Score;
    while(1)
    {
        cout<<"Welcome to the system"<<endl;
        cout<<"Please press the number to achieve the function"<<endl;
        cout<<"1.Check the last student information\n"
            <<"2.Create a student and import student's information\n"
            <<"3.Add courses\n"
            <<"4.Add courses from files\n"
            <<"5.Drop the Course\n"
            <<"6.Change scores\n"
            <<"7.Save student's information to files\n"
            <<"8.Save student's information and courses information to files\n"
            <<"9.Exit\n";
        string n1,n3;
        int n2;
        while(cin>>n1)
        {
            if(n1=="1")
            {
                cout<<s<<endl;
                cout<<endl;
                cout<<"If you need more service, please press 1 to get back, if not press 2 to quit the procedure"<<endl;
                cin>>n3;
                cout<<endl;
                if(n3=="1")break;
                else if(n3=="2") return 0;
                else{
                    cout<<"!Please press the right number! System will back to the main menu."<<endl;
                    system("pause");
                    break;
                }
            }
            else if(n1=="2")
            {
                cout<<"Enter the student's name and Birthday(For example:Ronnie O'Sullivan 1975 12 5)\n"
                    <<"Warning: If you enter the illegal information, system will set an default information for you\n"
                    <<"Length of name should less than 20\n";
                cin>>na>>y>>m>>d;
                s.setNameBirthday(na,y,m,d);
                if(s.getda())
                cout<<"Succeed!\n"
                    <<"The system will get back and you may enter more information.\n\n\n";
                system("pause");
                break;
            }
            else if(n1=="3")
            {
                cout<<"1.Add Obligatory Course\n2.Add Elective Course\n"<<endl;
                cin>>n3;
                if(n3=="1"){
                    Course *cPtr1 = new ObligatoryCourse();
                    cPtr1->setCourseType("ObligatoryCourse");
                    cout<<"Please enter the information according to the request\n Course name:"<<endl;
                    cin>>CourseName;
                    cPtr1->setName(CourseName);
                    cout<<"Course Credit Hour:\n";
                    cin>>creditHour;
                    cPtr1->setCreditHour(creditHour);
                    cout<<"Course Mark:\n";
                    cin>>mark;
                    try{
                            cPtr1->setMark(mark);
                    }
                    catch (MyException me)
                    {
                        cout<<me.what()<<endl;
                    }
                    //cout<<cPtr1->getScore()<<endl;
                    s.addCourse(cPtr1);
                    cout<<"If you need more service, please press 1 to get back, if not press 2 to quit the procedure"<<endl;
                    cin>>n3;
                    cout<<endl;
                    if(n3=="1")break;
                    else if(n3=="2") return 0;
                    else{
                        cout<<"!Please press the right number! System will back to the main menu."<<endl;
                        system("pause");
                        break;
                    }
                }
                else if(n3=="2"){
                    Course *cPtr0 = new ElectiveCourse();
                    cPtr0->setCourseType("ElectiveCourse");
                    cout<<"Please enter the information according to the request\n Course name:"<<endl;
                    cin>>CourseName;
                    cPtr0->setName(CourseName);
                    cout<<"Course Credit Hour:\n";
                    cin>>creditHour;
                    cPtr0->setCreditHour(creditHour);
                    cout<<"Course Grade(A/B/C/D/E):\n";
                    cin>>grade;
                    try{
                            cPtr0->setGrade(grade);
                    }
                    catch(MyException me)
                    {
                        cout<<me.what()<<endl;
                    }
                    s.addCourse(cPtr0);
                    cout<<"If you need more service, please press 1 to get back, if not press 2 to quit the procedure"<<endl;
                    cin>>n3;
                    cout<<endl;
                    if(n3=="1")break;
                    else if(n3=="2") return 0;
                    else{
                        cout<<"!Please press the right number! System will back to the main menu."<<endl;
                        system("pause");
                        break;
                    }
                }
                else{
                    cout<<"!Please press the right number! System will back to the main menu."<<endl;
                    system("pause");
                    break;
                }
            }
            else if(n1=="4")
            {
                while(cindata>>n3>>CourseName>>creditHour>>Score){
                    if(n3=="1"){
                        Course *cPtr1 = new ObligatoryCourse();
                        cPtr1->setCourseType("ObligatoryCourse");
                        cPtr1->setName(CourseName);
                        cPtr1->setCreditHour(creditHour);
                        stringstream SScore(Score);
                        SScore >> mark;
                        try{
                            cPtr1->setMark(mark);
                        }
                        catch (MyException me)
                        {
                            cout<<me.what()<<endl;
                        }
                        //cout<<cPtr1->getScore()<<endl;
                        s.addCourse(cPtr1);
                    }
                    else if(n3=="2"){
                        Course *cPtr0 = new ElectiveCourse();
                        cPtr0->setCourseType("ElectiveCourse");
                        cPtr0->setName(CourseName);
                        cPtr0->setCreditHour(creditHour);
                        grade=Score[0];
                        try{
                            cPtr0->setGrade(grade);
                        }
                        catch(MyException me)
                        {
                            cout<<me.what()<<endl;
                        }
                        s.addCourse(cPtr0);
                        }
                    }
                    cout<<"If you need more service, please press 1 to get back, if not press 2 to quit the procedure"<<endl;
                    cin>>n3;
                    cout<<endl;
                    if(n3=="1")break;
                    else if(n3=="2") return 0;
                    else{
                        cout<<"!Please press the right number! System will back to the main menu."<<endl;
                        system("pause");
                        break;
                    }
            }
            else if(n1=="5")
            {
                if(s.getCourseNumber()==0){
                    cout<<"You haven't chosen any course, system will back to the main menu.\n";
                    break;
                }
                else{
                    cout<<"The following items are your information\n";
                    cout<<s<<endl;
                    cout<<"Please enter the Number of your course that you want to drop out.\n";
                    cin>>n2;
                    try{
                        if(s.removeCourse(n2))cout<<"Succeed!"<<endl;
                        else cout<<"Failed!"<<endl;
                    }
                    catch(MyException me){
                        cout<<me.what()<<endl;
                    }
                    cout<<"If you need more service, please press 1 to get back, if not press 2 to quit the procedure"<<endl;
                    cin>>n3;
                    cout<<endl;
                    if(n3=="1")break;
                    else if(n3=="2") return 0;
                    else{
                        cout<<"!Please press the right number! System will back to the main menu."<<endl;
                        system("pause");
                        break;
                    }
                }
            }
            else if(n1=="6"){
                if(s.getCourseNumber()==0){
                    cout<<"You haven't chosen any course, system will back to the main menu.\n";
                    system("pause");
                    break;
                }
                else{
                    cout<<"The following items are your information\n";
                    cout<<s<<endl;
                    cout<<"Please enter the Number of your course that you want to change.\n";
                    cin>>n2;
                    if(s.getCourse(n2)->getCourseType()=="ObligatoryCourse"){
                        cout<<"Please enter new Mark\n";
                        cin>>mark;
                        s.getCourse(n2)->setMark(mark);
                    }
                    else{
                        cout<<"Please enter new Grade(A/B/C/D/E)\n";
                        cin>>grade;
                        s.getCourse(n2)->setGrade(grade);
                    }
                    s.calcCourseType();
                    s.calcCredit();
                    cout<<"Succeed!\n";
                    cout<<"If you need more service, please press 1 to get back, if not press 2 to quit the procedure"<<endl;
                    cin>>n3;
                    cout<<endl;
                    if(n3=="1")break;
                    else if(n3=="2") return 0;
                    else{
                        cout<<"!Please press the right number! System will back to the main menu."<<endl<<endl;
                        system("pause");
                        break;
                    }
                }
            }
            else if(n1=="7")
            {
                coutdata1<<"Name:"<<s.getName();
                coutdata1<<"   Birthday:"<<s.getBirthDateyear()<<"-"
                                         <<setfill('0')<<setw(2)<<s.getBirthDatemonth()<<"-"
                                         <<setfill('0')<<setw(2)<<s.getBirthDateday()<<endl;
                cout<<endl;
                cout<<"If you need more service, please press 1 to get back, if not press 2 to quit the procedure"<<endl;
                cin>>n3;
                cout<<endl;
                if(n3=="1")break;
                else if(n3=="2") return 0;
                else{
                    cout<<"!Please press the right number! System will back to the main menu."<<endl<<endl;
                    system("pause");
                    break;
                }
            }
            else if(n1=="8")
            {
                coutdata2<<s<<endl;
                cout<<endl;
                cout<<"If you need more service, please press 1 to get back, if not press 2 to quit the procedure"<<endl;
                cin>>n3;
                cout<<endl;
                if(n3=="1")break;
                else if(n3=="2") return 0;
                else{
                    cout<<"!Please press the right number! System will back to the main menu."<<endl<<endl;
                    system("pause");
                    break;
                }
            }
            else if(n1=="9")
            {
                return 0;
            }
            else
            {
                cout<<"!Please press the right number! System will back to the main menu."<<endl<<endl;
                system("pause");
                break;
            }
        }
    }
}
