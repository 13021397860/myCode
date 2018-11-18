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
    cout<<"����0�˳�ѡ��ϵͳ"<<endl;
    cout<<"����1ѡ�������γ�"<<endl;
    cout<<"����2ѡ��ѡ����γ�"<<endl;
    cout<<"����3��ѡ��ѡ�γ�"<<endl;
    cout<<"����4�Թ���Աģʽ����ϵͳ�������óɼ�"<<endl;
    cout<<"����5���㼨��"<<endl;
    cout<<"����6�鿴�ɼ�"<<endl;
    cout<<"����7����ѧ����Ϣ���ļ�"<<endl;
}

void Table::Build()
{
    char name[100];
    int y, m, d;
    cout<<"������ѧ��������"<<endl;
    cin>>name;
    cout<<"������ѧ�������գ�"<<endl;
    cout<<"��ע��������������ڷǷ���\n���ڿ���̨��������������ֽ�ֱ���޸����ϴ�����Ƿ��ı�����\n���ж�������Ƿ�����˳���޸ġ�"<<endl;
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
            cerr<<"�������ʹ������������롣"<<endl;
            cin.ignore();
            cin>>n;
        }
        while(n<0||n>7)
        {
            cout<<"ע����������ݷ�ΧӦ���Ǵ�0~7�����������룡"<<endl;
            cin>>n;
            while(cin.fail())
            {
                cin.clear();
                while(cin.get()!='\n')
                continue;
                cerr<<"�������ʹ������������롣"<<endl;
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
            cout<<"���㣺"<<st->calcCredit()<<endl;
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
                cout<<i+1<<" "<<Course_Name<<"ѧ�֣�"<<Course_Hour<<endl;
            }
            cin>>choice;
            while(cin.fail())
            {
                cin.clear();
                while(cin.get()!='\n')
                continue;
                cerr<<"�������ʹ������������롣ע������Ϊ1~3�����֡�"<<endl;
                cin.ignore();
                cin>>choice;
            }
            /*while(choice<1||choice>3)
            {
                 cout<<"ע����������ݷ�ΧӦ���Ǵ�1~3�����������룡"<<endl;
                 cin>>choice;
                while(cin.fail())
                {
                    cin.clear();
                    while(cin.get()!='\n')
                    continue;
                    cerr<<"�������ʹ������������롣"<<endl;
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
                cout<<i+1<<" "<<Course_Name<<"ѧ�֣�"<<Course_Hour<<endl;
            }
            cin>>choice;
            while(cin.fail())
            {
                cin.clear();
                while(cin.get()!='\n')
                continue;
                cerr<<"�������ʹ������������롣ע������Ϊ1~3�����֡�"<<endl;
                cin.ignore();
                cin>>choice;
            }
            /*while(choice<1||choice>3)
            {
                 cout<<"ע����������ݷ�ΧӦ���Ǵ�1~3�����������룡"<<endl;
                 cin>>choice;
                while(cin.fail())
                {
                    cin.clear();
                    while(cin.get()!='\n')
                    continue;
                    cerr<<"�������ʹ������������롣"<<endl;
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
    cout<<"��������Ҫ��ѡ�γ̵ı�ţ�ȷ�����Ѿ�ѡ�����ſγ̣�:"<<endl;
    cin>>_choice;
    st->removeCourse(_choice);
    cout<<"���Ѿ���ѡ�ÿγ̣�"<<endl;
}

void Table::SetCourseScore()
{
    char _grade;
    int _mark;
    for(int i=0;i<st->GetCourseNumber();i++)
    {
        if( typeid(ObligatoryCourse)==typeid((*st)[i]) )
        {
            cout<<"��������޿Σ�"<<(*st)[i].getname()<<" �ĳɼ���0-100����";
            cin>>_mark;
            while(cin.fail())
            {
                cin.clear();
                while(cin.get()!='\n')
                continue;
                cerr<<"�쳣������Ƴ�������һ�����ۣ��������˴���ĳɼ����ͣ�"<<endl;
                cin.ignore();
                cin>>_mark;
            }
            dynamic_cast<ObligatoryCourse&>((*st)[i]).setmark(_mark);
        }
        else
        {
            cout<<"������ѡ�޿Σ�"<<(*st)[i].getname()<<" �ĳɼ���A-E����";
            cin>>_grade;
            while(cin.fail())
            {
                cin.clear();
                while(cin.get()!='\n')
                continue;
                cerr<<"�쳣������Ƴ�������һ�����ۣ��������˴���ĳɼ����ͣ�"<<endl;
                cin.ignore();
                cin>>_grade;
            }
            dynamic_cast<ElectiveCourse&>((*st)[i]).setgrade(_grade);
        }
    }
}

