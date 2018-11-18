#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include "date.h"
#include "student.h"
#include "course.h"
#include "obligatorycourse.h"
#include "electivecourse.h"
#include "console.h"
#include "myexception.h"
using namespace std;
Console::Console()
{
    //ctor
}
void displayorder()
{
    cout<<"����1��ѡ�����пγ�"<<endl;
    cout<<"����2���鿴��ѡ�γ�"<<endl;
    cout<<"����3��Ϊ��ѡ�γ���ӳɼ�"<<endl;
    cout<<"����4����ѡ�γ�"<<endl;
    cout<<"����0���˳�ϵͳ"<<endl;
    cout<<"********************"<<endl;
}

void Console::run()
{
    char* s=(char *)malloc(10*sizeof(char));

    int y,m,d;
    cout<<"����������:";
    cin>>s;
    cout<<"�������������:";
    cin>>y;
    while(1)
    {
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                cout<<"���ʹ���"<<endl;
                     cout<<"********************"<<endl;
                    cin>>y;
                }
                cin>>m;
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                cout<<"���ʹ���"<<endl;
                     cout<<"********************"<<endl;
                    cin>>m;
                }
                cin>>d;
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                cout<<"���ʹ���"<<endl;
                     cout<<"********************"<<endl;
                    cin>>d;
                }

                try
                {
                    if(!(y>0&&m>0&&m<13&&d>0&&d<daysOfMonth(y,m)+1))
                    {
                    MyException e(1);
                    throw e;
                    }

                    break;

                }
                catch(MyException& error)
                {
                error.what();
                cin>>y;
                }

    }
    Student b(s,y,m,d);


    Course *a[20];


    int x;
    readSequentialFile("�½��ı��ĵ�.txt",a);
    displayorder();

    while(cin>>x&&x)
    {
        cout<<"********************"<<endl;
        while(1)
        {

        while(cin.fail())
        {
                    cin.clear();
                    cin.ignore();
                    cout<<"����ʧ�ܣ�����ѡ��"<<endl;
                     cout<<"********************"<<endl;
                    cin>>x;
            }
                if(x<0||x>4)
                {
                     cout<<"����ʧ�ܣ�����ѡ��"<<endl;
                     cout<<"********************"<<endl;
                    cin>>x;
        }
                else break;

        }

        if(x==1)
        {
            int y;
            cout<<"��ѡ�Σ�"<<endl;

            cout<<left<<setfill(' ')<<"No."<<setw(3)<<"1"<<*a[0]<<endl;
            cout<<left<<setfill(' ')<<"No."<<setw(3)<<"2"<<*a[1]<<endl;
            cout<<"********************"<<endl;
            cin>>y;
            while(1)
            {
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                cout<<"ѡ��ʧ�ܣ���������ѡ�γ�!����ѡ��"<<endl;
                     cout<<"********************"<<endl;
                    cin>>y;
                }
                try
                {
                    if(y<0||y>2)
                    {
                    MyException e(2);
                    throw e;
                    }
                    b.addCourse(a[y-1]);
                    break;

                }
                catch(MyException& error)
                {
                error.what();
                cin>>y;
                }

            }



        }
        else if(x==3)
        {
            int p;
            cout<<b;
            cout<<"��������Ҫ��ӳɼ��Ŀγ̱�ţ�"<<endl;
            cin>>p;
            b.setScore(p);
            cout<<"********************"<<endl;
        }
        else if(x==2)
        {
            cout<<b;
            cout<<"********************"<<endl;
        }
        else if(x==4)
        {
            int p;
            cout<<b;
            cout<<"��������Ҫ��ѡ�Ŀγ̱�ţ�"<<endl;
            cin>>p;
             while(1)
            {
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout<<"�˿�ʧ�ܣ������ڿγ�!����ѡ��"<<endl;
                     cout<<"********************"<<endl;
                    cin>>p;
                }
                try
                {
                    if(p<0||p>b.getcoursenumber())
                    {
                    MyException e(2);
                    throw e;
                    }
                    b.removeCourse(p);
                    break;

                }
                catch(MyException& error)
                {
                error.what();
                cin>>p;
                }


            }

        }
        else if(x==0) break;

         displayorder();

    }
    c=&b;
    createSequentialFile("Student.txt");
}

void Console::daytest()
{
    Date a(1998,10,4);


    cout<<a<<endl;
    cout<<a++<<endl;
    cout<<++a<<endl;
}

bool Console::createSequentialFile(const char *fileName){
	ofstream outClientFile(fileName, ios::out);
	if (!outClientFile) 	return false;

		outClientFile << *c;

    outClientFile.close();
	return true;
}

bool Console::readSequentialFile(const char *fileName,Course* course[]){
   ifstream inClientFile;
   inClientFile.open( fileName, ios::in );
   if ( !inClientFile )  return false;

   int account; char name[30]; double balance;

    int i=0;
   while (inClientFile>>account >>name>>balance)
   {
       //outputLine( account, name, balance );
        if(account==1)
        {
            *(course+i)=new ElectiveCourse(name,balance);
            i++;
        }
        else if(account==2)
        {
            *(course+i)=new ObligatoryCourse(name,balance);
            i++;
        }

   }
    inClientFile.close();
   return true;
}
int Console::daysOfMonth(int y,int m) const
{
    if(m==2){
        if((y%4==0&&y%100!=0)||y%400==0){
            return 29;
        }
   else{
            return 28;
      }
}
    else if(m==4||m==6||m==9||m==11){
            return 30;
    }
    else{
            return 31;
    }
}
Console::~Console()
{
    //dtor
}
