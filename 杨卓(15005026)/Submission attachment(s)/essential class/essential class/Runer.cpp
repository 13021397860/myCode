#include <iostream>
#include <cstdio>
#include "Date.h"
#include "student.h"
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#include <cstdlib>
#include "Runer.h"
#include <iomanip>
#include <fstream>
#include "MyException.h"
using namespace std;
Runer::Runer()
{
    //ctor
}



void Runer::start()
{






    Date date;
    student stu;
    ObligatoryCourse obl;
    ElectiveCourse ele;
    int y,m,d,year,month,day;
    cout<<"write the first student's name and brithday directly:";
    char *name1;
    name1=new char[100];
    cin>>name1;
    stu.setName(name1);
    cin>>y>>m>>d;
    while(cin.fail()){
        cin.clear();
        cin.ignore();
        cout<<"Erro, please rewrite it"<<endl;
        cin>>y>>m>>d;
    }
    stu.setBirthday(y,m,d);
    stu.cheakName();
    int k=1;
    Course *cptr1=new ElectiveCourse();
    Course *cptr2=new ObligatoryCourse();
    while(k)
    {
        int kk=1;
        cout<<"����1����ѡ��ϵͳ������2�˿Σ�����0�˳�ѡ��ϵͳ->";
        cin>>kk;
        while(cin.fail()){
        cin.clear();
        cin.ignore();
        cout<<"Erro, please rewrite it"<<endl;
        cin>>kk;
    }
    while(kk<0 || kk>2)
    {
        cout<<"����ѡ��0~2֮�������������ѡ��";
        cin>>kk;
        while (cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"�������ݸ�ʽ����������ѡ��(0~2)��";
            cin>>kk;
        }
    }

        if(kk==2)
        {
            cout<<"ɾ���ڼ��ſΣ�"<<endl;
            int jjj;
            cin>>jjj;
            stu.removeCourse(jjj);
        }
        else if(kk==0)
        {
            break;
        }
        else if(kk==1)
        {
            int kkk=0;
            cout<<"����1,ѡ����޿Σ�����2��ѡ��ѡ�޿�->";
            cin>>kkk;
            while(cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"Erro, please rewrite it"<<endl;
            cin>>kkk;
    }
            if(kkk==2)
            {
                Course *cptr1=new ElectiveCourse();
                cout<<"write the  electivecourse's name: ";
                char *course1;
                course1=new char[100];
                cin>>course1;
                cptr1->setcoursename(course1);
                cout<<"set the grade for this one: ";
                char grade1;
                cin>>grade1;
                while(grade1<'A' || (grade1>'X'&&grade1<'a') || grade1>'x'){
                    cin.clear();
                    cin.ignore();
                    cout<<"Erro, please rewrite it"<<endl;
                    cin>>grade1;
                   }

                cptr1->setgrade(grade1);
                cout<<"set the creditHour for this one:";
                int ch;
                cin>>ch;
                while(cin.fail()){
                cin.clear();
                cin.ignore();
                cout<<"Erro, please rewrite it"<<endl;
                cin>>ch;
                }
                cptr1->setcredithour(ch);
                cptr1->getScore();
                stu.addCourse(cptr1);
            }

            else
            {
                Course *cptr2=new ObligatoryCourse();
                cout<<"write the obligatorycourse's name: ";
                char *course2;
                course2=new char[100];
                cin>>course2;
                cptr2->setcoursename(course2);

                cout<<"set the mark for this one: ";
                int mmm;
                cin>>mmm;
                while(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout<<"Erro, please rewrite it"<<endl;
                    cin>>mmm;
                }

                cptr2->setmark(mmm);
                cptr2->getScore();
                cout<<"set the creditHour for this one:";
                int ch1;
                cin>>ch1;
                while(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout<<"Erro, please rewrite it"<<endl;
                    cin>>ch1;
                }

                cptr2->setcredithour(ch1);


                stu.addCourse(cptr2);
            }
        }
    }
    cout<<endl;
    cout<<"**************************************"<<endl;
    int ff=stu.getnum();
    if(ff!=0)
    cout<<"ѡ�γɹ���"<<endl;
    if(ff==0)
    cout<<"ѡ��ʧ�ܣ�"<<endl;
    cout<<endl;
    cout<<"**************************************"<<endl;
    cout<<endl;
    cout<<stu;
    stu.savefile1(stu);
    cout<<"**************************************"<<endl;
    cout<<"Show readfile:"<<endl;
    stu.readfiile1(stu);
    cout<<"**************************************"<<endl;
    cout<<endl;
    cout<<"����count�ǣ�"<<student::count<<endl;
    cout<<"the student's number of course is:"<<stu.getnum()<<endl;
    cout<<"the student's credit is:"<<stu.calcCredit()<<endl;

}

Runer::~Runer()
{
    //dtor

}
