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
    cout<<"���н���"<<endl;
}

int selesub::run()
{
    cout<<"��¼��"<<endl<<"����������������";
    char*p;
    p=new char;
    cin>>p;
    cout<<"���������ĳ������ڣ��� �� �գ���";
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
    cout<<"��������������1���˳�������0"<<endl;
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
                cout<<"��ѡ����Ҫ�˵��ڼ��ſγ̣�";
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
                cout<<"���ļ���ɼ��ǣ�"<<s->getcalc()<<endl;break;
            case 7:
                s->print();break;
            default:
                cout<<"��������ȷ����"<<endl;
        }
        cout<<"��������������1���˳�������0"<<endl;
        cin>>x;
    }
    return 0;
}
void selesub::displaymenu()const
{
    cout<<"1.ѡ���޿�\n2.ѡѡ�޿�\n3.��ѧ����Ϣ�洢���ļ���\n4.���ÿγ̳ɼ�\n5.�˿�\n6.��ѯ����ɼ�\n7.չʾѧ����Ϣ\n��������ѡ��Ĳ�����Ӧ�ı��:";
}

void selesub::seleoc()
{
    for(int i=1;i<=ocnum;i++)
    {
        cout<<i<<"."<<oc[i]->getname()<<" "<<oc[i]->getcred()<<endl;
    }
    cout<<"��ѡ����Ӧ�Ŀγ̱�ţ�";
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
    cout<<"��ѡ����Ӧ�Ŀγ̱�ţ�";
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
            cout<<"���޿γ̣�"<<(s->getcourse(i)).getname()<<"�ĳɼ���0-100����";
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
            cout<<"ѡ�޿γ̣�"<<(s->getcourse(i)).getname()<<"�ĳɼ���A-E����";
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
