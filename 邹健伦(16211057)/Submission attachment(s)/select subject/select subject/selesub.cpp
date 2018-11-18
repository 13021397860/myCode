#include "selesub.h"
#include<typeinfo>
#include<fstream>
#include<string>
#include<cstdlib>
#include"Myexception.h"
/*selesub::selesub()
{
    ocnum=5;
    oc[1]=new obligatorycourse("physics",4);
    oc[2]=new obligatorycourse("introduction to computer",3);
    oc[3]=new obligatorycourse("Data structure",5);
    oc[4]=new obligatorycourse("senior mathematics",4);
    oc[5]=new obligatorycourse("P.E.",3);
    ecnum=4;
    ec[1]=new electivecourse("philosophy",3);
    ec[2]=new electivecourse("geography",4);
    ec[3]=new electivecourse("biology",2);
    ec[4]=new electivecourse("literature",1);
}*/
selesub::selesub()
{
    string s;
    int cred;
    ifstream infile("course information.txt",ios::in);
    if(!infile)
    {
        cerr<<"file could not be opened"<<endl;
        exit(1);
    }
    infile>>ocnum;
    for(int i=1;i<=ocnum;i++)
    {
        infile>>s>>cred;
        oc[i]=new obligatorycourse(s,cred);
    }
    infile>>ecnum;
    for(int i=1;i<=ecnum;i++)
    {
        infile>>s>>cred;
        ec[i]=new electivecourse(s,cred);
    }
}
selesub::~selesub()
{
    cout<<"运行结束"<<endl;
}

int selesub::run()
{
    cout<<"登录："<<endl<<"请输入您的姓名：";
    char*p;
    p=new char;
    cin>>p;
    cout<<"请输入您的出生日期（年 月 日）：";
    int y,m,d;
    s=new student(p,1900,1,1);
    cin>>y>>m>>d;
    try
    {
        s->setdate(y,m,d);
    }
    catch(Myexception ex)
    {
        ex.datewrong(s);
    }
    cout<<"继续操作请输入1，退出请输入0"<<endl;
    bool x;
    cin>>x;
    while(x)
    {
        displaymenu();
        int k;
        cin>>k;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cin>>k;
        }
        switch(k)
        {
            case 1:
                seleoc();break;
            case 2:
                seleec();break;
            case 3:
                displaycourse();break;
            case 4:
                setcoursescore();break;
            case 5:
                displaycourse();
                cout<<"请选择您要退掉第几门课程：";
                int q;
                while(1)
                {
                    try
                    {
                        cin>>q;
                        q--;
                        s->removecourse(q);
                        break;
                    }
                    catch(Myexception ex)
                    {
                        cout<<"system has wrong"<<endl;
                        ex.counumwrong();
                    }
                }
                break;
            case 6:
                cout<<"您的绩点成绩是："<<s->getcalc()<<endl;break;
            case 7:
                s->print();break;
            default:
                cout<<"请输入正确参数"<<endl;
        }
        cout<<"继续操作请输入1，退出请输入0"<<endl;
        cin>>x;
    }
    return 0;
}
void selesub::displaymenu()const
{
    cout<<"1.选必修课\n2.选选修课\n3.将学生信息存储到文件中\n4.设置课程成绩\n5.退课\n6.查询绩点成绩\n7.展示学生信息\n请输入您选择的操作对应的编号:";
}

void selesub::seleoc()
{
    for(int i=1;i<=ocnum;i++)
    {
        cout<<i<<"."<<oc[i]->getname()<<" "<<oc[i]->getcred()<<endl;
    }
    cout<<"请选择相应的课程编号：";
    int j;
    cin>>j;
    s->addcourse(oc[j]);
    obligatorycourse *a;
    a=oc[j];
    oc[j]=oc[ocnum];
    oc[ocnum]=a;
    ocnum--;
}
void selesub::seleec()
{
    for(int i=1;i<=ecnum;i++)
    {
         cout<<i<<"."<<ec[i]->getname()<<" "<<ec[i]->getcred()<<endl;
    }
    cout<<"请选择相应的课程编号：";
    int j;
    cin>>j;
    s->addcourse(ec[j]);
    electivecourse *a;
    a=ec[j];
    ec[j]=ec[ocnum];
    ec[ocnum]=a;
    ecnum--;
}
void selesub::displaycourse()const
{
    cout<<*s;
}
bool selesub::setcoursescore()
{
    int mark;
    char grade;
    for(int i=0;i<s->getcoursenumber();i++)
    {
        if(typeid(obligatorycourse)==typeid(s->getcourse(i)))
        {
            cout<<"必修课程："<<(s->getcourse(i)).getname()<<"的成绩（0-100）：";
            while(1)
            {
                try
                {
                    cin>>mark;
                    dynamic_cast<obligatorycourse&>(s->getcourse(i)).setmark(mark);
                    break;
                }
                catch(Myexception ex)
                {
                    cout<<"system has mistake"<<endl;
                    ex.setgradewrong();
                }
            }
        }
        else if(typeid(electivecourse)==typeid(s->getcourse(i)))
        {
            cout<<"选修课程："<<(s->getcourse(i)).getname()<<"的成绩（A-E）：";
            while(1)
            {
                try
                {
                    cin>>grade;
                    dynamic_cast<electivecourse&>(s->getcourse(i)).setgrade(grade);
                    break;
                }
                catch(Myexception ex)
                {
                    cout<<"system has mistake"<<endl;
                    ex.setgradewrong();
                }
            }
        }
        else
        {
            return false;
        }
    }
}
