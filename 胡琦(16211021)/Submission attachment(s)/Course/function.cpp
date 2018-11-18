#include "function.h"
#include "Student.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include <iostream>
#include <cstdio>
#include <fstream>
#include "MyException.h"
using namespace std;
ofstream fout("out.txt");
ifstream fin("in.txt");
function::function()
{
    //ctor
}

function::~function()
{
    //dtor
}

Student function::BuildStudent()
{
    char name[50];
	date birthDate;

	cout<<"请输入学生姓名: ";
	cin>>name;
	cout<<"请输入学生生日";
	while(1)
    {
        cin>>birthDate;
        if(cin.fail())
        {
            cout<<"输入不合法，请重新输入"<<endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        try
        {
            Student s(name, birthDate);
            break;
        }
        catch(MyException ex)
        {
            cout<<"程序异常："<<ex.what()<<"，请重新输入"<<endl;
        }
    }
    Student s(name, birthDate);
    return s;
}
void function::displayMenu1() const
{
    cout<<"1.显示学生信息并存入文件\t";
    cout<<"2.添加课程\t";
    cout<<"3.退选课程\t";
    cout<<"4.退出程序"<<endl;
}

void function::displayMenu2() const
{
    cout<<endl;
    cout<<"1.添加必修课"<<"    ";
    cout<<"2.添加选修课"<<"\t"<<endl;
}

void function::selectCourse(Student &s, int op)
{
    int mark;
    string name;
    cout<<"请输入课程名："<<endl;
    cin>>name;
    cout<<"请输入学分："<<endl;
    cin>>mark;
    if(op==1)
    {
        Course *c=new ObligatoryCourse;
        c->setName(name);
        c->setCreditHour(mark);
        c->setKind(1);
        setCourseScore(s,c);
        s.addCourse(c);
    }
    else if(op==2)
    {
        Course *c=new ElectiveCourse;
        c->setName(name);
        c->setCreditHour(mark);
        c->setKind(2);
        setCourseScore(s,c);
        s.addCourse(c);
    }
    cout<<"添加课程成功！"<<endl<<endl;
}
void function::setCourseScore(Student &s,Course *&c)
{
    int grade;
    cout<<"请输入成绩："<<endl;
    while(1)
    {
        cin>>grade;
        try
        {
            c->setScore(grade);
            break;
        }
        catch(MyException ex)
        {
            cout<<"程序异常："<<ex.what()<<"，请重新输入"<<endl;
        }
    }
}

void function::RemoveCourse(Student& s)
{
    int n;
    cout<<"请输入要退的课程的编号："<<endl;
    while(1)
    {
        cin>>n;
        try
        {
            s.removeCourse(n);
            break;
        }
        catch(MyException ex)
        {
            cout<<"程序异常"<<ex.what()<<"，请重新输入"<<endl;
        }
    }
}
void function::run(Student &s)
{
    int x,op;
    //readSequentialFile("in.txt");
    while(1)
    {
        displayMenu1();
        cin>>x;
        if(cin.fail())
        {
            cout<<"输入不合法，请重新输入"<<endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        if(x==1)
        {
            fout<<s;
            fout.close();
            cout<<s<<endl;
        }
        else if(x==2)
        {
            displayMenu2();
            cin>>op;
            if(cin.fail())
            {
                cout<<"输入不合法，请重新输入"<<endl;
                cin.clear();
                cin.ignore();
                continue;
            }
            if(op!=1&&op!=2)
            {
                cout<<"输入不合法，请重新输入"<<endl<<endl;;
                cin.clear();
                cin.ignore();
                continue;
            }
            selectCourse(s,op);
        }
        else if(x==3)
            RemoveCourse(s);
        else if(x==4)
            break;
        else
        {
            cout<<"输入不合法，请重新输入"<<endl;
            cin.clear();
            cin.ignore();
        }
    }
}

bool function::createSequentialFile(const char *fileName)
{
	ofstream outClientFile(fileName, ios::out);
	if  (!outClientFile)
        return false;
	int count;
	char name[30];
	double hour;
	cout<<" count\tName\thour";
	cout<<"? ";
	while(cin>>count>>name>>hour)
    {
		outClientFile<<count<<' '<<name<<' '<<hour<<"\n";
		cout<<"? ";
	}
	return true;
}

bool function::readSequentialFile(const char *fileName)
{
    ifstream inClientFile(fileName,ios::in);
    if ( !inClientFile )
        return false;
    int count;
    char name[30],kind[30];
    double hour;
    cout<<"count\tName\tkind\t\thour"<<endl;
    while(inClientFile>>count>>name>>kind>>hour)
        cout<<count<<"\t"<<name<<"\t"<<kind<<"\t"<<hour<<endl;
    return true;
}
