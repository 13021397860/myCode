#include "Console.h"
#include <fstream>
#include <typeinfo>
#include <iostream>
#include "Exception.h"
using namespace std;

Console::Console()
{
    obnum=0;
    elnum=0;
    //ctor
}

Console::~Console()
{
    if(student!=NULL)
        delete student;
    int i;
    for(i=0; i<obnum; i++)
        delete oblC[i];
    for(i=0; i<elnum; i++)
        delete eleC[i];
    //dtor
}

Console& Console::buildStudent()
{
    char a[50];
    int y,m,d;
    Date birthdate;
    cout<<"������ѧ��������";
    cin>>a;
    cout<<"������ѧ�����գ��������ÿո�ֿ�����";
    while(1)
    {
        try
        {
            cin>>y>>m>>d;
            birthdate.setDate(y,m,d);
            break;
        }
        catch(Exception ex)
        {
            cout<<"�����쳣��"<<ex.what()<<"\n";
            cout<<"����������ѧ�����գ��������ÿո�ֿ�����";
        }
    }
    student=new Student(a,y,m,d);
    return *this;
}

Console& Console::buildCourse()
{
    char fileName[]="allcourselist.txt";
    ifstream file(fileName);
    int c, credit;
    string name;
    obnum=elnum=0;
    if (!file)
    {
        return *this;
    }
    while(file>>c>>name>>credit)
    {
        switch (c)
        {
        case 1:
            oblC[obnum++]=new ObligatoryCourse(name, credit);
            break;
        case 2:
            eleC[elnum++]=new ElectiveCourse(name, credit);
            break;
        }
    }
    file.close();

    return *this;
}

Course* Console::selectCourse(int op)
{
    int i,choice=-1;
    switch(op)
    {
    case 1:
        cout<<"������б��޿γ���ѡ��һ�ſγ̣�\n";
        while((choice>obnum)||(choice<0))
        {
            for(i=0; i<obnum; i++)
                cout<<"     "<<i+1<<"."<<*oblC[i];
            cout<<"     0.ȡ������ѡ��\n";
            cout<<"��Ҫѡ�ı��޿γ�����ǣ�";
            cin>>choice;
        }
        if(choice!=0) return oblC[choice-1];
        break;
    case 2:
        cout<<"�������ѡ�޿γ���ѡ��һ�ſγ̣�\n";
        while((choice>elnum)||(choice<0))
        {
            for(i=0; i<elnum; i++)
                cout<<"     "<<i+1<<"."<<*eleC[i];
            cout<<"     0.ȡ������ѡ��\n";
            cout<<"��Ҫѡ��ѡ�޿γ�����ǣ�";
            cin>>choice;
        }
        if(choice!=0) return eleC[choice-1];
        break;
    }
    return NULL;
}

bool Console::removeCCourse()
{
    int choice;
    cout<<"��ѡ�γ��б����£�"<<endl;
    for(int i=0; i<student->getCountNumber(); i++)
        cout<<*(student->courseList[i]);
    cout<<"��������Ҫɾ���γ̵���ţ�\n";
    while(1)
    {
        try
        {
            cin>>choice;
            student->removeCourse(choice);
            break;
        }
        catch(Exception ex)
        {
            cout<<"�����쳣��"<<ex.what()<<"\n";
            cout<<"������������Ҫɾ���γ̵���ţ�\n";
        }
    }
}

int Console::displayMenu()
{
    int choice=0;
    cout<<"**********ѧ��ѡ��ϵͳ-���˵�**********\n"
        <<"\t1. ѡ���޿γ�\n"
        <<"\t2. ѡѡ�޿γ�\n"
        <<"\t3. �鿴ѡ�����\n"
        <<"\t4. ���ÿγ̳ɼ�\n"
        <<"\t5. �鿴ѧ������ɼ�\n"
        <<"\t6. ����ѧ���ɼ����ļ�\n"
        <<"\t7. �˿�\n"
        <<"\t0. �˳�ϵͳ\n"
        <<"��ѡ������Ĳ���(0~7)��";
    cin>>choice;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout<<"�������ݸ�ʽ����������ѡ��(0~7)��";
        cin>>choice;
    }
    while(choice<0 || choice>7)
    {
        cout<<"����ѡ��0~7֮�������������ѡ��";
        cin>>choice;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1024,'\n');
            cout<<"�������ݸ�ʽ����������ѡ��(0~7)��";
            cin>>choice;
        }
    }
    return choice;
}

int Console::run()
{
    char fileName[256];
    ofstream *ofile;

    buildCourse();
    buildStudent();
    int choice=displayMenu();
    while(choice!=0)
    {
        switch (choice)
        {
        case 1: //ѡ���޿�
        case 2: //ѡѡ�޿�
            student->addCourse(selectCourse(choice));
            break;
        case 3: //���ѧ��ѡ����Ϣ����ʱ�������ɼ���
            cout<<"��ѡ�γ��б����£�"<<endl;
            for(int i=0; i<student->getCountNumber(); i++)
                cout<<*(student->courseList[i]);
            break;
        case 4: //����ѧ���ɼ�
            setCourseScore();
            break;
        case 5: //�鿴ѧ������ɼ�
            cout<<"����ɼ�Ϊ��"<<endl;
            cout<<student->calcAchievement()<<endl;
            break;
        case 6://����ѧ���ɼ����ļ�
            cout<<"��������Ҫ������ļ����������ļ����ͣ���";
            cin>>fileName;
            ofile=new ofstream(fileName);
            if(!ofile)
            {
                cerr<<"�޷������ļ���\n";
                break;
            }
            (*ofile)<<*student;
            ofile->close();
            delete ofile;
            break;
        case 7:
            removeCCourse();
            break;
        }

        choice=displayMenu();
    }
    return 0;
}

bool Console::setCourseScore()
{
    int mark=0;
    char grade='\0';
    for(int i=0; i<(student->getCountNumber()); i++)
    {
        if(typeid(ObligatoryCourse&)==typeid(*(student->courseList[i])))
        {
            cout<<"���޿γ̡�"<<(student->courseList[i])->getName()<<"���ĳɼ���0~100����";
            cin>>mark;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(1024,'\n');
                cout<<"�����������������룺\n";
                cin>>mark;
            }
            while(1)
            {
                try
                {
                    dynamic_cast<ObligatoryCourse*>(student->courseList[i])->setMark(mark);
                    break;
                }
                catch(Exception ex)
                {
                    cout<<"�����쳣��"<<ex.what()<<"\n";
                    cout<<"���޿γ̡�"<<(student->courseList[i])->getName()<<"���ĳɼ�(0-100)��";
                    cin>>mark;
                }
            }
        }
        else if(typeid(ElectiveCourse&)==typeid(*(student->courseList[i])))
        {
            cout<<"ѡ�޿γ̡�"<<(student->courseList[i])->getName()<<"���ĳɼ���A~E����";
            cin>>grade;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(1024,'\n');
                cout<<"�����������������룺\n";
                cin>>grade;
            }
            while(1)
            {
                try
                {
                    dynamic_cast<ElectiveCourse*>(student->courseList[i])->setGrade(grade);
                    break;
                }
                catch(Exception ex)
                {
                    cout<<"�����쳣��"<<ex.what()<<"\n";
                    cout<<"ѡ�޿γ̡�"<<(student->courseList[i])->getName()<<"���ĳɼ���A~E����";
                    cin>>grade;
                }
            }
        }
        else
            return false;
    }
    return true;
}
