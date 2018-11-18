#include "Console.h"
#include<typeinfo>
#include"Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include"MyException.h"
#include<fstream>

Console::Console()
{
    //ctor
}

Console::~Console()
{
    //dtor
}

Console::Console(const Console& other)
{
    //copy ctor
}

void Console::Run()
{
    ifstream In_Obli("ObligatoryCourse.txt",ios::in);
    if(!In_Obli)
    {
        cout<<"�ļ�\"ObligatoryCourse.txt\"��ʧ��\n";
        return;
    }
    ifstream In_Elec("ElectiveCourse.txt",ios::in);
    if(!In_Elec)
    {
        cout<<"�ļ�\"ElectiveCourse.txt\"��ʧ��\n";
        return;
    }
    string CourseName;
    int CreditHour;
    int CourseNum=0;
    while(In_Obli>>CourseName>>CreditHour)
    {
        ss1[++CourseNum].setName(CourseName);
        ss1[CourseNum].setcreditHour(CreditHour);
    }
    CourseNum=0;
    while(In_Elec>>CourseName>>CreditHour)
    {
        ss2[++CourseNum].setName(CourseName);
        ss2[CourseNum].setcreditHour(CreditHour);
    }
    cout<<"���ڿɴ���ѧ����\n";
    Student s;
    s=CreateStudent();
    while(1)
    {
        DispMenu();
        int k;
        cin>>k;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout<<"��Ч�����룬����������ָ����ţ�0-4��\n\n";
            continue;
        }
        if(!k)
        {
            break;
        }
        switch(k)
        {
        case 0:
            break;
        case 1:
            SelectCourse(s);
            break;
        case 2:
            RemoveCourse(s);
            break;
        case 3:
        {
            cout<<"��ѡ�γ���Ŀ��"<<s.getCourseNumber()<<"\n";
            if(s.getCourseNumber()==0)
            {
                cout<<"�޿γ̿����óɼ�\n";
                break;
            }
            int p;
            cout<<"����Ҫ���óɼ��Ŀγ���ţ�\n";
            bool NumInvalidation=false;
            while(!NumInvalidation)
            {
                try
                {
                    cin>>p;
                    s.getCourse(p);
                }
                catch(MyException ex)
                {
                    cout<<"Error: "<<ex.what()<<endl;
                    NumInvalidation=false;
                    cout<<"��������Ҫ���óɼ��Ŀγ���ţ�\n";
                    continue;
                }
                NumInvalidation=true;
            }
            bool MarkInvalidation=false;
            while(!MarkInvalidation)
            {
                try
                {
                    s.getCourse(p)->SetMark();
                }
                catch(MyException ex)
                {
                    cout<<"Error: "<<ex.what()<<endl;
                    MarkInvalidation=false;
                    cout<<"����������ɼ�\n";
                    continue;
                }
                MarkInvalidation=true;
            }
            break;
        }
        case 4:
            cout<<s<<endl;
            cout<<"ƽ������: "<<s.calcCredit()<<endl<<endl;
            break;
        default:
            cout<<"��Ч�����룬����������ָ����ţ�0-4��\n\n";
        }
    }
    In_Obli.close();
    In_Elec.close();
    ofstream Out("StudentInfo.txt",ios::out);
    Out<<s;
    Out.close();
}


void Console::DispMenu()
{
    cout<<"----------------------------------------\n";
    cout<<"��ɽ������²������������1-4������0�Խ�����\n";
    cout<<"1.ѡ��γ̣�\n";//exception
    cout<<"2.�Ƴ��γ̣�\n";
    cout<<"3.���óɼ���\n";
    cout<<"4.���ѧ���ɼ���\n";
    cout<<"----------------------------------------\n";
}



Student Console::CreateStudent()
{
    Student student1;
    char *p=new char [255];
    cout<<"������ѧ��������\n";
    cin>>p;
    student1.setName(p);
    int y,m,d;
    cout<<"������ѧ�����գ���ʽ��2000-10-20����\n";
    char a;
    bool DateInvalidtion=false;
    while(!DateInvalidtion)
    {
        cin>>y>>a>>m>>a>>d;
        try
        {
            student1.setbirthDate(y,m,d);
        }
        catch(MyException ex)
        {
            cout<<"Error: "<<ex.what()<<endl;
            cout<<"������������ȷ��ѧ�����գ���ʽ��2000-10-20����\n";
            DateInvalidtion=false;
            continue;
        }
        DateInvalidtion=true;
        cout<<"ѧ���������óɹ�\n";
    }
    return student1;
}

int Console::RemoveCourse(Student& s)
{
    int num,order;
    try
    {
        cout<<"������ѡ�γ���Ŀ: "<<s.getCourseNumber()<<endl;
        if(s.getCourseNumber()==0)
        {
            throw -1;
        }
    }
    catch(int i)
    {
        cout<<"�޿γ̿����óɼ�\n";
        return 0;
    }
    cout<<"���ڿ��Ƴ��γ̣��������Ƴ��γ���Ŀ(����0���˳�)\n";
    cin>>num;
    if(num==0)
    {
        return 0;
    }
    else
    {
        while(num--)
        {
            cout<<"������Ҫ�Ƴ��Ŀγ����\n";
            bool RangeInvalidation=false;
            while(!RangeInvalidation)
            {
                try
                {
                    cin>>order;
                    s.removeCourse(order);
                }
                catch(MyException ex)
                {
                    cout<<"Error: "<<ex.what()<<endl;
                    cout<<"����������������Ҫ�Ƴ��Ŀγ����\n";
                    RangeInvalidation=false;
                    continue;
                }
                RangeInvalidation=true;
            }
        }
    }
    return 0;
}

void Console::SelectCourse(Student& s)
{
    cout<<"���ڿ�ʼѡ��\n";
    cout<<"��ѡ���޿Σ���������޿���Ŀ(1-5)\n";
    int course_num;
    cin>>course_num;
    cout<<"��ѡ���޿Σ���������޿α�ţ�1-5��\n";
    int i;
    while(course_num--)
    {
        bool NumInvalidation=false;
        while(!NumInvalidation)
        {
            try
            {
                cin>>i;
                if(i<1||i>5)
                {
                    throw -1;
                }
                s.addCourse(&ss1[i]);
            }
            catch(int i)
            {
                cout<<"Error: ѡ�γ�����Χ������������"<<endl;
                NumInvalidation=false;
                continue;
            }
            NumInvalidation=true;
        }
    }
    cout<<"��ѡѡ�޿Σ�������ѡ�޿���Ŀ(1-5)\n";
    cin>>course_num;
    cout<<"��ѡѡ�޿Σ�������ѡ�޿α�ţ�1-5��\n";
    while(course_num--)
    {
        bool NumInvalidation=false;
        while(!NumInvalidation)
        {
            try
            {
                cin>>i;
                if(i<1||i>5)
                {
                    throw -1;
                }
                s.addCourse(&ss2[i]);
            }
            catch(int i)
            {
                cout<<"Error: ѡ�γ�����Χ������������"<<endl;
                NumInvalidation=false;
                continue;
            }
            NumInvalidation=true;
        }
    }
}


