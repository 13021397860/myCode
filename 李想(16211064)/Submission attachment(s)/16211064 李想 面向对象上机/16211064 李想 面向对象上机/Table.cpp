#include "Table.h"
#include "Date.h"
#include "Course.h"

#include "Student.h"
#include<bits/stdc++.h>
#include<typeinfo>
#include "MyException.h"
using namespace std;
Table::Table()
{
    /*ObligatoryCourseList[0]=new ObligatoryCourse("CPP",4);
    ObligatoryCourseList[1]=new ObligatoryCourse("English",2);
    ObligatoryCourseList[2]=new ObligatoryCourse("Dispersed MATH",2);
    ElectiveCourseList[0]=new ElectiveCourse("higher mathematics",4);
    ElectiveCourseList[1]=new ElectiveCourse("mathematical analysis",5);
    ElectiveCourseList[2]=new ElectiveCourse("Computer Science",2);*/
}

Table::~Table()
{

    for(int i=0; i<3; i++)
    {
        if(ObligatoryCourseList[i])
            delete ObligatoryCourseList[i];
    }
    for(int i=0; i<3; i++)
    {
        if(ElectiveCourseList[i])
            delete ElectiveCourseList[i];
    }
}

void Table::Beginning()
{
    cout<<"输入0退出选课系统"<<endl;
    cout<<"输入1选择必修类课程"<<endl;
    cout<<"输入2选择选修类课程"<<endl;
    cout<<"输入3退选已选课程"<<endl;
    cout<<"输入4以管理员模式进入系统，并设置成绩"<<endl;
    cout<<"输入5计算绩点"<<endl;
    cout<<"输入6查看成绩"<<endl;
    cout<<"输入7保存学生信息至文件"<<endl;
}

void Table::Build()
{
    char name[100];
    int y, m, d;
    cout<<"请输入学生姓名："<<endl;
    cin>>name;
    cout<<"请输入学生的生日："<<endl;
    cout<<"备注：若您输入的日期非法，\n您在控制台接下来输入的数字将直接修改您上次输入非法的变量。\n若有多个变量非法，则按顺序修改。"<<endl;
    cin>>y>>m>>d;
    st=new Student(name,y,m,d);
}

void Table::run()
{
    int n;
    Build();
    Beginning();
    while(true)
    {
        cin>>n;
        while(cin.fail())
        {
            cin.clear();
            while(cin.get()!='\n')
                continue;
            cerr<<"输入类型错误，请重新输入。"<<endl;
            cin.ignore();
            cin>>n;
        }
        while(n<0||n>7)
        {
            cout<<"注意输入的数据范围应该是从0~7。请重新输入！"<<endl;
            cin>>n;
            while(cin.fail())
            {
                cin.clear();
                while(cin.get()!='\n')
                continue;
                cerr<<"输入类型错误，请重新输入。"<<endl;
                cin.ignore();
                cin>>n;
            }
        }
        if(n==0) break;
        if(n==1||n==2)
        {
            Course *temp=choose(n);
            st->addCourse(temp);
        }
        if(n==3) withdrawCourse();
        if(n==4)
            SetCourseScore();
        if(n==5)
            cout<<"绩点："<<st->calcCredit()<<endl;
        if(n==6)
            cout<<*st<<endl;
        if(n==7)
        {
            ofstream outfile("1.txt",ios::out);
            outfile<<*st;
        }
        Beginning();
    }

}

Course* Table::choose(int n)
{
    int choice;
    if(n==1)
    {
        ifstream inOCFile("OC.txt",ios::in);
        if(!inOCFile)
        {
            cerr<<"File could not be opened!"<<endl;
            exit(1);
        }
        else
        {
            string Course_Name;
            int Course_Hour;
            for(int i=0;i<3;i++)
            {
                inOCFile>>Course_Name>>Course_Hour;
                ObligatoryCourseList[i]=new ObligatoryCourse(Course_Name,Course_Hour);
                cout<<i+1<<" "<<Course_Name<<"学分："<<Course_Hour<<endl;
            }
            cin>>choice;
            while(cin.fail())
            {
                cin.clear();
                while(cin.get()!='\n')
                continue;
                cerr<<"输入类型错误，请重新输入。注意输入为1~3的数字。"<<endl;
                cin.ignore();
                cin>>choice;
            }
            /*while(choice<1||choice>3)
            {
                 cout<<"注意输入的数据范围应该是从1~3。请重新输入！"<<endl;
                 cin>>choice;
                while(cin.fail())
                {
                    cin.clear();
                    while(cin.get()!='\n')
                    continue;
                    cerr<<"输入类型错误，请重新输入。"<<endl;
                    cin.ignore();
                    cin>>choice;
                }
            }*/
            while(true)
            {
                try
                {
                    if(choice<1||choice>3) throw MyException();
                    break;
                }
                catch(MyException CE)
                {
                    cout<<CE.CourseError()<<endl;
                    cin>>choice;
                }

            }
            return ObligatoryCourseList[choice-1];
        }

    }
    if(n==2)
    {
        ifstream inECFile("EC.txt",ios::in);
        if(!inECFile)
        {
            cerr<<"File could not be opened!"<<endl;
            exit(1);
        }
        else
        {
            string Course_Name;
            int Course_Hour;
            for(int i=0;i<3;i++)
            {
                inECFile>>Course_Name>>Course_Hour;
                ElectiveCourseList[i]=new ElectiveCourse(Course_Name,Course_Hour);
                cout<<i+1<<" "<<Course_Name<<"学分："<<Course_Hour<<endl;
            }
            cin>>choice;
            while(cin.fail())
            {
                cin.clear();
                while(cin.get()!='\n')
                continue;
                cerr<<"输入类型错误，请重新输入。注意输入为1~3的数字。"<<endl;
                cin.ignore();
                cin>>choice;
            }
            /*while(choice<1||choice>3)
            {
                 cout<<"注意输入的数据范围应该是从1~3。请重新输入！"<<endl;
                 cin>>choice;
                while(cin.fail())
                {
                    cin.clear();
                    while(cin.get()!='\n')
                    continue;
                    cerr<<"输入类型错误，请重新输入。"<<endl;
                    cin.ignore();
                    cin>>choice;
                }
            }*/
            while(true)
            {
                try
                {
                    if(choice<1||choice>3) throw MyException();
                    break;
                }
                catch(MyException CE)
                {
                    cout<<CE.CourseError()<<endl;
                    cin>>choice;
                }
            }
            return ElectiveCourseList[choice-1];
        }
    }
}

void Table::withdrawCourse()
{
    int _choice;
    for(int i=0;i<st->GetCourseNumber();i++)
    {
        cout<<i+1<<*(st->courseList[i])<<endl;
    }
    cout<<"请输入想要退选课程的编号（确保您已经选了这门课程）:"<<endl;
    cin>>_choice;
    st->removeCourse(_choice);
    cout<<"您已经退选该课程！"<<endl;
}

void Table::SetCourseScore()
{
    char _grade;
    int _mark;
    for(int i=0;i<st->GetCourseNumber();i++)
    {
        if( typeid(ObligatoryCourse)==typeid((*st)[i]) )
        {
            cout<<"请输入必修课："<<(*st)[i].getname()<<" 的成绩（0-100）：";
            cin>>_mark;
            while(cin.fail())
            {
                cin.clear();
                while(cin.get()!='\n')
                continue;
                cerr<<"异常处理机制朝你抛了一个媚眼：你输入了错误的成绩类型！"<<endl;
                cin.ignore();
                cin>>_mark;
            }
            dynamic_cast<ObligatoryCourse&>((*st)[i]).setmark(_mark);
        }
        else
        {
            cout<<"请输入选修课："<<(*st)[i].getname()<<" 的成绩（A-E）：";
            cin>>_grade;
            while(cin.fail())
            {
                cin.clear();
                while(cin.get()!='\n')
                continue;
                cerr<<"异常处理机制朝你抛了一个媚眼：你输入了错误的成绩类型！"<<endl;
                cin.ignore();
                cin>>_grade;
            }
            dynamic_cast<ElectiveCourse&>((*st)[i]).setgrade(_grade);
        }
    }
}

