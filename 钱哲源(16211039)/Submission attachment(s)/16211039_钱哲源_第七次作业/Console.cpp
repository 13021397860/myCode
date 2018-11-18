#include "Console.h"
#include "Student.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Date.h"
#include "MyException.h"
#include<iostream>
#include<typeinfo>
#include<fstream>
using namespace std;


int Console::start()
{
    buildCourse();
    buildStudent();
    int x=displayMenu();
    while (x!=0)
    {
        switch (x)
        {
            case 1:
                while (1)
                {
                    try {
                        selectCourse1();
                        break;
                    }catch (MyException et)
                    {
                        cout<<"no course match.\n";
                    }
                }

                break;
            case 2:
                while (1)
                {
                    try {
                        selectCourse2();
                        break;
                    }catch (MyException et)
                    {
                        cout<<"no course match.\n";
                    }
                }
                break;
            case 3:
                cout<<(*student);
                break;
            case 4:
                cout<<(*student);
                cout<<"choose a class:";
                while (1)
                {
                    try {
                        student->setCourseScore();
                        break;
                    }catch (MyException et)
                    {
                        cout<<"error score.\n";
                    }
                }
                break;
            case 5:
                {
                    ofstream outfile("student.txt", ios::out);
                    outfile<<(*student);
                }
                break;

        }
        x=displayMenu();
    }
    return 0;
}



Console& Console::buildCourse()
{
    ifstream coursefile("course.txt",ios::in);
    string na;
    int ch;
    for (int i=0;i<3;i++)
    {
        coursefile>>na>>ch;
        oc[i]=new ObligatoryCourse(na,ch);
    }
    for (int i=0;i<3;i++)
    {
        coursefile>>na>>ch;
        ec[i]=new ElectiveCourse(na,ch);
    }
}

Console& Console::buildStudent()
{
    cout<<"������������";
    char na[12];
    cin>>na;
    cout<<"���������գ�";
    int ye,mo,da;
    while(cin>>ye>>mo>>da)
    {
        try{
            Date Birthdate(ye,mo,da);
            break;
        }catch (MyException et){
            cout<<et.what()<<"\n";
        }
    }

    student=new Student(na,ye,mo,da);
}

int Console::displayMenu() const
{
	int a=0;
	cout<<"  ѧ��ѡ��\n"<<"1.���޿γ�\n"<<"2.ѡ�޿γ�\n"<<"3.�鿴��ѡ�γ̳ɼ���GPA\n"<<"4.���ÿγ̳ɼ�\n"<<"5.������ļ�\n"<<"0.�˳�\n";
	cin>>a;
	while (a < 0 || a > 5 || cin.fail())
    {
        cout << "Invalid choice, try again:";

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
        }
        cin >> a;
    }
	return a;
}

void Console::selectCourse1()
{
    cout<<"��ѡ���޿γ�\n";
    for (int i=0;i<3;i++)
    {
        cout<<i+1<<"."<<oc[i]->getName()<<" "<<oc[i]->getHour()<<"\n";
    }
    cout<<"0.�˳�\n";
    cout<<"��ѡ��\n";
    int u;
    cin>>u;
    while (cin.fail())
    {
        cout << "Invalid choice, try again:";

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
        }
        cin >> u;
    }
    if(u)
    {
        if (u<1 || u>3) throw MyException("wrong course.\n");
        student->addCourse(oc[u-1]);
    }
}

void Console::selectCourse2()
{
    cout<<"��ѡѡ�޿γ�\n";
    for (int i=0;i<3;i++)
    {
        cout<<i+1<<"."<<ec[i]->getName()<<" "<<ec[i]->getHour()<<"\n";
    }
    cout<<"0.�˳�\n";
    cout<<"��ѡ��\n";
    int v;
                cin>>v;
                while (cin.fail())
                {
                    cout << "Invalid choice, try again:";

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                    }
                    cin >> v;
                }
                if(v)
                {
                    if (v<1 || v>3) throw MyException("wrong course.\n");

                    student->addCourse(ec[v-1]);
                }
}
Console::Console()
{

}

Console::~Console()
{
    delete student;
}
