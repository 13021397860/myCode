#include "run.h"
#include <typeinfo>
#include"TextStudentClass.h"
#include<iostream>
using namespace std;


string E[22];

string O[22];

int EN=0;
int ON=0;

run::run()
{
    //ctor
}

run::run(int)
{

}

run::~run()
{
    //dtor
}

void run::loadElectiveclass()//ѡ��
{
    ifstream infile("ѡ�޿γ�.txt",ios::in);
    if(!infile)
    {
        cerr<<"��ȡѡ�޿�ʧ��"<<endl;
        exit(1);
    }
    for(int i=1;i<=20;i++)
    {
        E[i]="empty";
    }
    for(int i=1;i<20;i++)
    {
        infile>>E[i];
        if(E[i]=="empty")
        {
            break;
        }
        EN++;
    }
    infile.close();
}

void run::loadObligatoryclass()//����
{
    ifstream infile("���޿γ�.txt",ios::in);
    if(!infile)
    {
        cerr<<"��ȡѡ�޿�ʧ��"<<endl;
        exit(1);
    }
    for(int i=1;i<=20;i++)
    {
        O[i]="empty";
    }
    for(int i=1;i<20;i++)
    {
        infile>>O[i];
        if(O[i]=="empty")
        {
            break;
        }
        ON++;
    }
    infile.close();
}


void run::saveinf(TextStudentClass *a)
{
    ofstream outfile("ѧ����Ϣ.txt",ios::out);
    if(!outfile)
    {
        cerr<<"����ʧ��"<<endl;
        exit(1);
    }
    outfile<<"����"<<" "<<"��������"<<endl;
    outfile<<a->Getname()<<" "<<a->Getbirth()<<endl;
    outfile.close();
}

void run::saveclass(TextStudentClass *a)
{
    Course *temp;
    ofstream outfile("ѧ����Ϣ.txt",ios::app);
    if(!outfile)
    {
        cerr<<"����ʧ��"<<endl;
        exit(1);
    }
    outfile<<"��ѡ�γ�: "<<endl;
    for(int i=1;i<=a->getcoursenumber();i++)
    {
        a->getcourseList(i,temp);
        outfile<<*temp;
    }
}


void run::bixiu(TextStudentClass *a)
{
    int k=1;
    loadObligatoryclass();
    while(k)
    {

        cout<<"����Щ�γ̹���ѡ��"<<endl;
        for(int i=1;i<=ON;i++)
        {
            cout<<i<<'.'<<O[i]<<" ";
        }
        cout<<endl;
        cout<<"������Ҫѡ��Ŀγ����"<<endl;
       int cou;
       cin>>cou;
       if(cin.fail())
       {
           cin.clear();
           cin.ignore();
           cout<<"��������ȷ���"<<endl;
           continue;
       }
       while(!(cou<=ON&&cou>=1))
       {
           cout<<"��������ȷ���"<<endl;
           cin>>cou;
           if(cin.fail())
           {
               cin.clear();
               cin.ignore();
               continue;
           }
       }
        a->addCourse(O[cou],4,0);
        cout<<"�����������ּ���ѡ�Σ�������0�˳�"<<endl;
        cin>>k;
    }
}

void run::xuanxiu(TextStudentClass *a)
{
    int k=1;
    loadElectiveclass();
    while(k)
    {

        cout<<"����Щ�γ̹���ѡ��"<<endl;
        for(int i=1;i<=EN;i++)
        {
            cout<<i<<'.'<<E[i]<<" ";
        }
        cout<<endl;
        cout<<"������Ҫѡ��Ŀγ����"<<endl;
        int cou;
        try
        {
             cin>>cou;
             if(cin.fail())
             {
                 throw MyException();
             }
        }
        catch(MyException x)
        {
               cout<<"�����쳣:"<<x.Seceterror()<<endl;
               cin.clear();
               cin.ignore();
               continue;
        }
       //if(cin.fail())
       //{
       //    cin.clear();
       //    cin.ignore();
        //   cout<<"��������ȷ���"<<endl;
        //   continue;
      // }
       while(!(cou<=EN&&cou>=1))
       {
           cout<<"��������ȷ���"<<endl;
           //cin>>cou;
           try
           {
            cin>>cou;
            if(cin.fail())
            {
                throw MyException();
            // cin.clear();
               //cin.ignore();
               //continue;
            }
           }
           catch(MyException x)
           {
               cin.clear();
               cin.ignore();
               continue;
           }
       }
       try
       {
          a->addCourse(E[cou],1,'G');
          cout<<"�����������ּ���ѡ�Σ�������0�˳�"<<endl;
          cin>>k;
       }
       catch(MyException x)
       {
          cout<<"ѡ���쳣:"<<x.Courserror()<<endl;
            k=0;
            cout<<"�ѷ���������"<<endl;
       }

    }
}

void run::xuanke(TextStudentClass *a)
{
    cout<<"********************************************************************************"<<endl;
    cout<<"1ѡ��                           2����                                      0�˳�"<<endl;
    cout<<"********************************************************************************"<<endl;
    int i;
    cin>>i;
    switch(i)
    {
        case 1:xuanxiu(a);break;
        case 2:bixiu(a);break;
        case 0:leave();break;
        default:cout<<"�밴��ʾ����"<<endl;
                menu();
                break;
    }
}

TextStudentClass* run::info()
{
    char N[20];
    cout<<"������ѧ������"<<endl;
    cin>>N;
    int year,month,day;
    cout<<"������ѧ���ĳ�������"<<endl;
    try
    {
        cin>>year>>month>>day;
        Date birth(year,month,day);
    }
    catch(MyException k)
    {
        cout<<"�쳣����: "<<k.Daterror()<<endl;
        if(day<=0)
        {
            day=1;
        }
        if(month<=0)
        {
            month=1;
        }
        if(year<=0)
        {
            year=1;
        }
        cout<<"�ѽ������������Ϊ1"<<endl;
    }
    Date birth(year,month,day);
    TextStudentClass *student1=new TextStudentClass(N,birth);
    cout<<*student1;
    return student1;
}

void run::leave()
{
    exit(1);
}

void run::chengji(TextStudentClass *a)
{
    int score;
    char s;

    cout<<"��������Ҫ���óɼ��Ŀγ�"<<endl;
    for(int i=1;i<=a->getcoursenumber();i++)
    {
        cout<<*a->getcourse(i)<<endl;
        Course *p=a->getcourse(i);
        if (typeid(*p)==typeid(ObligatoryCourse))
        {
            cout<<"����1-100"<<endl;
            cin>>score;
            try
            {
                a->getcourse(i) ->SetMark(score);
            }
            catch(MyException x)
            {
                cout<<"����ɼ��쳣: "<<x.Scorerror()<<endl;
                score=60;
                cout<<"�ѽ��ɼ�����Ϊ����(60)"<<endl;
                a->getcourse(i) ->SetMark(score);
            }
        }
        else
        {
            cout<<"����A-E"<<endl;
            cin>>s;
            try
            {
                 a->getcourse(i)->SetGrade(s);
            }
            catch(MyException x)
            {
                cout<<"����ɼ��쳣: "<<x.Scorerror()<<endl;
                s='D';
                cout<<"�ѽ��ɼ�����Ϊ����(60)"<<endl;
                a->getcourse(i)->SetGrade(s);
            }
        }
    }
    cout<<*a;
}
void run::jidian(TextStudentClass *a)
{
    a->calcCredit();
}

void run::SAVE(TextStudentClass *a)
{
    saveinf(a);
    saveclass(a);
}

/*void run::searchcourse(TextStudentClass *a)
{
}
*/
void run::tuike(TextStudentClass *a)
{
    Course *temp;
    cout<<"����ѡ�Ŀγ��У�"<<endl;
    for(int i=1;i<=a->getcoursenumber();i++)
    {
        a->getcourseList(i,temp);
        cout<<i<<'.'<<*temp;
    }
    cout<<"��������Ҫ�˵��Ŀγ����"<<endl;
    int i;
    try
    {
     cin>>i;
     if(i>a->getcoursenumber())
     {
         throw MyException();
     }
     a->removeCourse(i);
     cout<<"�˿γɹ����ѷ������˵�"<<endl;
    }
    catch(MyException x)
    {
        cout<<"�����쳣��"<<x.Removerror()<<endl;
        cout<<"�ѷ������˵�"<<endl;

    }
}


void run::menu()
{
     int i=1;
     TextStudentClass *student1;
     cout<<"                    ��ӭʹ��ѧ���γ̹���ϵͳ���밴��ʾ������                             "<<endl;
     cout<<"************************************************************************************************************************"<<endl;
     cout<<"1¼��ѧ����Ϣ        2ѧ��ѡ��        3���ÿγ̳ɼ�       4��ѯѧ������      5������Ϣ     6�˿�         0�˳�"<<endl;
     cout<<"**********************************************************************************************************************"<<endl;
     while(i){
     cin>>i;
     switch(i)
     {
         case 1:student1=info();break;
         case 2:xuanke(student1);break;
         case 3:chengji(student1);break;
         case 4:jidian(student1);break;
         case 5:SAVE(student1);break;
         case 6:tuike(student1);break;
         case 0:leave();break;
         default:cout<<"�밴����ʾ����"<<endl;
                 menu();
                 break;
     }
     }
}
