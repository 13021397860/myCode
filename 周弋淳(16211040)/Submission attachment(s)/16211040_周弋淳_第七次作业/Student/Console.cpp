#include "Console.h"
#include "Date.h"
#include "Student.h"
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#include "MyException.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>

Console::Console()
{
     //dtor
}

Console& Console::buildStudent()
{
    char name[100];
    int y,m,d;
    cout<<"������ѧ��������";cin>>name;
    cout<<endl;
    while(1)
    {
        try{
            cout<<"������ѧ������������(��ʽΪ���� �� �ա�)��";
            cin>>y>>m>>d;
            cout<<endl;
            s1=new Student(name,y,m,d);
            break;
        }catch(MyException ex){
            cout<<"�����쳣��"<<ex.what()<<endl;
            cout<<endl;
        }
    }
    cout<<s1->getName()<<"   ";
    cout<<s1->getBirthDate()<<endl;
    cout<<"��һ���ǣ�"<<++s1->getBirthDate()<<endl;
    return *this;
}

Console& Console::bulidCourse()
{
    ifstream inFile("Coursedata.txt");
    /*ifstream inFile;
      inFile.open("Coursedata.txt");*/
    char str[100];
    int OC,EC,c;
    OC=EC=ocNum=ecNum=0;
    while(inFile&&!inFile.eof())
    {
        inFile>>str;
        /*inFile.getline(str,100);*/
        if(!strcmp(str,"ObligatoryCourse"))
        {
            OC=1;
            EC=0;
        }
        else if(!strcmp(str,"ElectiveCourse"))
        {
            OC=0;
            EC=1;
        }
        else
        {
            inFile>>c;
            if(OC==1&&EC==0)
            {
                oc[++ocNum]=new ObligatoryCourse(str,c);
            }
            else if(OC==0&&EC==1)
            {
                ec[++ecNum]=new ElectiveCourse(str,c);
            }
        }
    }
    inFile.close();
    return *this;
}

void Console::saveStudentDate() const
{
    ofstream outFile("StudentDate.txt");
    /*ofstream outFile;
      outFile.open("StudentDate.txt");*/
    if(outFile)
        outFile<<*s1<<endl;
    outFile.close();
}

void Console::selectCourse(int op)
{
    if(op==1)
    {
        cout<<"��ӿ�ѡ�γ���ѡ��һ�ű��޿γ̣�\n";
        for(int i=1;i<=ocNum;i++)
        {
            cout<<"              "<<i<<"."<<*oc[i]<<endl;
        }
        cout<<"              0.ȡ�����β���\n";
        cout<<"��Ҫѡ�Ŀγ��ǣ�0~"<<ocNum<<"����";
        cin>>kc;
        /*while(cin.fail()||kc<0||kc>ocNum)
        {
            cout<<"\n���������ڣ�����������:";
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
            }
            cin>>kc;
        }
        cout<<endl;
        cout<<endl;*/
        if(cin.fail()||kc<0||kc>ocNum)
            throw MyException("����Ŀγ�ѡ�");
        if(kc!=0)
        {
            if(s1->ifCourseAdded(*oc[kc]))
            {
                 cout<<"�ÿγ���ѡ�������ظ�������\n";
                 cout<<endl;
                 cout<<endl;
                 kc=0;
            }
            else
            {
                cout<<endl;
                s1->addCourse(&*oc[kc]);
                kc=0;
            }
        }
    }
    else if(op==2)
    {
        cout<<"��ӿ�ѡ�γ���ѡ��һ��ѡ�޿γ̣�\n";
        for(int i=1;i<=ecNum;i++)
        {
            cout<<"              "<<i<<"."<<*ec[i]<<endl;
        }
        cout<<"              0.ȡ�����β���\n";
        cout<<"��Ҫѡ�Ŀγ��ǣ�0~"<<ecNum<<"����";
        cin>>kc;
        /*while(cin.fail()||kc<0||kc>ecNum)
        {
            cout<<"\n���������ڣ�����������:";
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
            }
            cin>>kc;
        }
        cout<<endl;
        cout<<endl;*/
        if(cin.fail()||kc<0||kc>ecNum)
            throw MyException("����Ŀγ�ѡ�");
        if(kc!=0)
        {
            if(s1->ifCourseAdded(*ec[kc]))
            {
                cout<<"�ÿγ���ѡ�������ظ�������\n";
                cout<<endl;
                cout<<endl;
                kc=0;
            }
            else
            {
                cout<<endl;
                s1->addCourse(&*ec[kc]);
                kc=0;
            }
        }
    }
}

void Console::setCourseScore()
{
    cout<<"�����ѡ�γ���ѡ��Ҫ���óɼ��Ŀγ̣�\n";
    s1->courseListPrint();
    cout<<"              0.ȡ�����β���\n";
    cout<<"��Ҫ���óɼ��Ŀγ��ǣ�0~"<<s1->getCourseNumber()<<"����";
    cin>>kc;
    /*while(cin.fail()||kc<0||kc>s1->getCourseNumber())
    {
        cout<<"\n���������ڣ�����������:";
        if(cin.fail())
        {
            cin.clear();
            cin.ignore();
        }
        cin>>kc;
    }*/
    if(cin.fail()||kc<0||kc>s1->getCourseNumber())
            throw MyException("����Ŀγ�ѡ�");
    if(kc!=0)
    {
        while(1)
        {
            try{
                s1->setCourseGrade(kc);
                break;
            }catch(MyException ex){
                cout<<"�����쳣��"<<ex.what()<<endl;
                cout<<endl;
            }
        }
        kc=0;
    }
    cout<<endl;
    cout<<endl;
}

void Console::cancelCourse()
{
    cout<<"�����ѡ�γ���ѡ��Ҫ��ѡ�Ŀγ̣�\n";
    s1->courseListPrint();
    cout<<"              0.ȡ�����β���\n";
    cout<<"��Ҫ��ѡ�Ŀγ��ǣ�0~"<<s1->getCourseNumber()<<"����";
    cin>>kc;
    /*while(cin.fail()||kc<0||kc>s1->getCourseNumber())
    {
        cout<<"\n���������ڣ�����������:";
        if(cin.fail())
        {
            cin.clear();
            cin.ignore();
        }
        cin>>kc;
    }*/
    if(cin.fail()||kc<0||kc>s1->getCourseNumber())
            throw MyException("����Ŀγ�ѡ�");
    if(kc!=0)
    {
        s1->removeCourse(kc);
        kc=0;
    }
    cout<<endl;
    cout<<endl;
}

int Console::displayMenu()
{
    kc=0;
    while(kc==0)
    {
        cout<<"---------------ѧ��ѡ��ϵͳ���˵�----------------\n";
        cout<<"              1.����ѡ��\n";
        cout<<"              2.ѡ��ѡ��\n";
        cout<<"              3.�鿴ѡ�����\n";
        cout<<"              4.���ÿγ̳ɼ�\n";
        cout<<"              5.�˿�\n";
        cout<<"              6.��ѯ�ɼ�\n";
        cout<<"              7.��ѯ����ɼ�\n";
        cout<<"              8.�洢��Ϣ\n";
        cout<<"              0.�˳�ϵͳ\n";
        cout<<"���������������0~8����";
        cin>>cz;
        while(cin.fail()||cz<0||cz>8)
        {
            cout<<"\n���������ڣ�����������:";
            if(cin.fail())
            {
                cin.clear();
                cin.ignore();
            }
            cin>>cz;
        }
        cout<<endl;
        if(cz==1||cz==2)
        {
            while(1)
            {
                try{
                    this->selectCourse(cz);
                    break;
                }catch(MyException ex){
                    cout<<"�����쳣��"<<ex.what()<<endl;
                    cout<<endl;
                }
            }
            kc=0;
        }
        else if(cz==3)
        {
            //s1.courseListPrint();
            cout<<*s1;
            cout<<endl;
            cout<<endl;
        }
        else if(cz==4)
        {
            while(1)
            {
                try{
                    this->setCourseScore();
                    break;
                }catch(MyException ex){
                    cout<<"�����쳣��"<<ex.what()<<endl;
                    cout<<endl;
                }
            }
            kc=0;
        }
        else if(cz==5)
        {
            while(1)
            {
                try{
                    this->cancelCourse();
                    break;
                }catch(MyException ex){
                    cout<<"�����쳣��"<<ex.what()<<endl;
                    cout<<endl;
                }
            }
            kc=0;
        }
        else if(cz==6)
        {
            cout<<*s1;
            cout<<endl;
            cout<<endl;
        }
        else if(cz==7)
        {
            cout<<"�㵱ǰ�ļ���Ϊ��"<<fixed<<setprecision(4)<<s1->calcCredit();
            cout<<endl;
            cout<<endl;
        }
        else if(cz==8)
        {
            this->saveStudentDate();
        }
        else if(cz==0)
        {
            cout<<"ѡ�ν�����\n";
            return 0;
        }
    }
    return 0;
}

void Console::run()
{
    this->buildStudent();
    this->bulidCourse();
    this->displayMenu();
}

Console::~Console()
{
    //dtor
}
