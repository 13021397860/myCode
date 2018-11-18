#include "UserInterface.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "MyException.h"
#include"Stu.h"
#include <typeinfo>
using namespace std;
UserInterface::UserInterface()
{
    //ctor
}

UserInterface::~UserInterface()
{
    //dtor
}

void UserInterface::FirstMenu(Stu& stu1)
{
    cout<<"1.Create a student manually\n2.Create a student from student.txt\n\nInput number to choose\n";
    int n;
    InputChoiceEx(n,1,2);
    system("cls");
    if(n == 1)
    {
        SetInformation(stu1);
    }
    else
    {
        Inputfromfile(stu1);
    }
}

void UserInterface::Inputfromfile(Stu& stu1)
{
    ifstream read("student.txt",ios::in);
    char name[20];
    char* name1 = name;
    int m,d,y;
    Course* courselistfile[MAX_SIZE];
    read>>name>>m>>d>>y;
    int i=0;
    float num;
    string str1;
    string str2;
    stu1.setname(name1);
    stu1.setdate(m,d,y);
    while(read>>str1>>str2>>num)
    {
        if(str2 == "E")
        {
            courselistfile[i] = new ElectiveCourse;
            courselistfile[i]->setName(str1);
            courselistfile[i]->setHour(num);
        }
        else if(str2 == "O")
        {
            courselistfile[i] = new ObligatoryCourse;
            courselistfile[i]->setName(str1);
            courselistfile[i]->setHour(num);
        }
        i++;
    }
    for(int j=0;j<i;j++)
    {
        stu1.addCourse(courselistfile[j]);
    }
}

bool UserInterface::InputChoiceEx(int& i,int l,int r)
{
    try{InputChoice(i,l,r);}
    catch(MyException ex){
        cout<<ex.what()<<endl;
        InputChoiceEx(i,l,r);
        return false;
    }
    return true;
}

bool UserInterface::InputChoice(int& i,int l,int r)
{
    while(!(cin>>i))
    {
        cin.clear();
        while(cin.get()!='\n')
        {
            continue;
        }
        throw MyException(1);
    }
    while(i<l||i>r)
    {
        throw MyException(2);
        //cout<<"Invalid choice, try again : ";
        while(!(cin>>i))
        {
            cin.clear();
            while(cin.get()!='\n')
            {
                continue;
            }
            throw MyException(1);
        }
        if(cin.fail())
        {
            cin.clear();
            cin.ignore();
        }
    }
    return true;
}

bool UserInterface::InputChoiceChar(char& i,char l,char r)
{
    string s;
    cin>>s;
    while(s[0]<l||s[0]>r||s.size()>1)
    {
        cout<<"Invalid choice, try again : ";
        cin>>s;
    }
    i = s[0];
    return true;
}

void UserInterface::SetInformation(Stu &stu1)
{
    char* s;
    char ss[20];
    s = &ss[0];
    cout<<"Input the name of the student:"<<endl;
    cin>>ss;
    stu1.setname(s);
    cout<<"Input the birthdate of the student: month day year"<<endl;
    int m,d,y;
    cin>>m>>d>>y;
    stu1.setdate(m,d,y);
    while(!stu1.judgedate())
    {
        cin>>m>>d>>y;
        stu1.setdate(m,d,y);
    }

}

void UserInterface::FunctionList(Stu &stu1)
{
    cout<<"input number to continue"<<endl;
    cout<<"1.Add course"<<endl;
    cout<<"2.Remove Course"<<endl;
    cout<<"3.Set Course Grade"<<endl;
    cout<<"4.Show information (including all scores and calcCredit)"<<endl;
    cout<<"5.Test Function"<<endl;
    cout<<"6.Output Student Information to File \"studentInformation.txt\""<<endl;
    cout<<"7.Exit"<<endl;
    int i;
    InputChoiceEx(i,1,7);
    if(i == 1)
    {
        AddCourse(stu1);
    }
    else if(i == 2)
    {
        RemoveCourse(stu1);
    }
    else if(i == 3)
    {
        SetCourseGrade(stu1);
    }
    else if(i == 4)
    {
        ShowInformation(stu1);
    }
    else if(i == 5)
    {
        TestFunction(stu1);
    }
    else if(i == 7)
    {
        Exit();
    }
    else if(i == 6)
    {
        Output(stu1);
    }
}

void UserInterface::Output(Stu& stu1)
{
    ofstream outfile("studentInformation.txt", ios::out);
    outfile<<stu1;
    cout<<"File has been created! Input anything to continue";
    int n;
    cin>>n;
}

void UserInterface::AddCourse(Stu& stu1)
{
        int j;
        system("cls");
        cout<<"1.Add ObligatoryCourse\n2.Add ElectiveCourse\n3.Select courses from courselist.txt\n4.Go Back"<<endl;
        InputChoiceEx(j,1,4);
        if(j == 1)
        {
            system("cls");
            ObligatoryCourse* cPtr0 = new ObligatoryCourse();
            cout<<"Input course name"<<endl;
            string o;
            cin>>o;
            cPtr0->setName(o);
            cout<<"Input course creditHour"<<endl;
            int c;
            InputChoiceEx(c,0,MAX_SIZE);
            cPtr0->setHour(c);
            stu1.addCourse(cPtr0);
            system("cls");
        }
        else if(j == 2)
        {
            system("cls");
            ElectiveCourse* cPtr1 = new ElectiveCourse();
            cout<<"Input course name"<<endl;
            string o;
            cin>>o;
            cPtr1->setName(o);
            cout<<"Input course creditHour"<<endl;
            int c;
            InputChoiceEx(c,0,MAX_SIZE);
            cPtr1->setHour(c);
            stu1.addCourse(cPtr1);
            system("cls");
        }
        else if(j == 3)
        {
            system("cls");
            Course* courselistfile[MAX_SIZE];
            ifstream tfile("courselist.txt",ios::in);
            float num;
            string str1;
            string str2;
            int i=0;
            while(tfile>>str1>>str2>>num)
            {
                if(str2 == "E")
                {
                    courselistfile[i] = new ElectiveCourse;
                    courselistfile[i]->setName(str1);
                    courselistfile[i]->setHour(num);
                }
                else if(str2 == "O")
                {
                    courselistfile[i] = new ObligatoryCourse;
                    courselistfile[i]->setName(str1);
                    courselistfile[i]->setHour(num);
                }
                i++;
            }
            for(int k=0;k<i;k++)
            {
                cout<<k+1<<" : ";
                if(typeid(*courselistfile[k]) == typeid(ObligatoryCourse))
                {
                    cout<<"Obligatory ";
                }
                else
                {
                    cout<<"Elective   ";
                }
                cout<<*courselistfile[k];
            }
            cout<<"\nInput course number to select and add course || Input 0 to go back\n";
            int k;
            InputChoiceEx(k,0,i);
            if(k == 0)
            {
                ;
            }
            else
            {
                stu1.addCourse(courselistfile[k-1]);
                cout<<"Course has been added.\nInput any number to select course || Input 0 to go back\n";
                int m;
                while(InputChoiceEx(m,0,i))
                {
                    if(m == 0)
                        break;
                    else
                    {
                        stu1.addCourse(courselistfile[m-1]);
                        cout<<"Course has been added.\nInput any number to select course || Input 0 to go back\n";
                    }
                }
            }
        }
        else {
            ;
        }
}

void UserInterface::Exit()
{
    exit(0);
}

void UserInterface::RemoveCourse(Stu& stu1)
{
    system("cls");
    if(stu1.getCoursenumber()==0)
    {
        cout<<"No Course Has Been Added!"<<endl;
        cout<<"\nInput any number to go back !"<<endl;
        int m;
        cin>>m;
    }
    else
    {
       for(int n = 0;n<stu1.getCoursenumber();n++)
    {
        cout<<n+1<<". "<<*stu1.getcourselist(n);
    }
    cout<<"\nInput course id to remove course || Input 0 to go back !"<<endl;
        int m;
        InputChoiceEx(m,0,stu1.getCoursenumber());
        if(m==0)
        {
            ;
        }
        else {
            stu1.removeCourse(m);
        cout<<"\nInput any number to go back !"<<endl;
        cin>>m;
        }
    }
}

void UserInterface::ShowInformation(Stu& stu1)
{
        system("cls");
        cout<<stu1<<endl;
        int m;
        cout<<"Input any number to continue"<<endl;
        cin>>m;
        system("cls");
}

void UserInterface::TestFunction(Stu& stu1)
{
    system("cls");
    cout<<"1.date++\n2.++date\n\nInput ID to test function\n";
    int n;
    InputChoiceEx(n,1,2);
    if(n == 1)
    {
        cout<<stu1.getdate()++<<endl;
        cout<<stu1.getdate()<<endl;
        int m;
        cout<<"input any number to continue\n";
        cin>>m;
        system("cls");
    }
    else
    {
        cout<<++stu1.getdate()<<endl;
        cout<<stu1.getdate()<<endl;
        int m;
        cout<<"input any number to continue\n";
        cin>>m;
        system("cls");
    }
}

void UserInterface::SetCourseGrade(Stu& stu1)
{
    system("cls");
    if(stu1.getCoursenumber()==0)
    {
        cout<<"No Course Has Been Added!"<<endl;
        cout<<"\nInput any number to go back !"<<endl;
        int m;
        cin>>m;
    }
    else
    {
        for(int n = 0;n<stu1.getCoursenumber();n++)
        {
            cout<<n+1<<". "<<*stu1.getcourselist(n);
        }
        cout<<"\n1)Set single course grade\n2)Set all courses' grade\n3)Go back\n"<<endl;
        cout<<"Choose a function\n";
        int m;
        InputChoiceEx(m,1,3);
        if(m==3)
        {
            ;
        }
        else if(m == 1)
        {
            cout<<"\nInput course id to set grade || Input 0 to go back !"<<endl;
            InputChoiceEx(m,0,stu1.getCoursenumber());
            if(m==0)
            {
                ;
            }
            else
            {
                int mark;
                char grade;
                if(typeid(ObligatoryCourse)==typeid(*stu1.getcourselist(m-1))){
                    cout<<"ObligatoryCourse: "<<stu1.getcourselist(m-1)->getName()<<"\nMark(0-100): ";
                    InputChoiceEx(mark,0,100);
                    dynamic_cast<ObligatoryCourse*>(stu1.getcourselist(m-1))->setScore(mark);
                }
                else if(typeid(ElectiveCourse)==typeid(*stu1.getcourselist(m-1))){
                    cout<<"ElectiveCourse: "<<stu1.getcourselist(m-1)->getName()<<"\nGrade(A-E): ";
                    InputChoiceChar(grade,'A','E');
                    dynamic_cast<ElectiveCourse*>(stu1.getcourselist(m-1))->setScore(grade);
                }
                cout<<"\nInput any number except 0 to set Score || 0 to go back !"<<endl;
                cin>>m;
                if(m == 0)
                {
                    ;
                }
                else
                {
                    system("cls");
                    SetCourseGrade(stu1);
                }
            }
        }
        else if(m == 2)
        {
            system("cls");
            stu1.setCourseScore(stu1);
        }
    }
}
