#include "Fun.h"
#include"Date.h"
#include"Student.h"
#include"Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include"MyException.h"
#include<iostream>
#include<cstring>
#include<iomanip>
#include<fstream>
#include<strstream>
#include<typeinfo>
using namespace std;

Fun::Fun()
{
    //ctor
}

Fun::~Fun()
{
    //dtorgetList(j)
    delete temp;
}

/*bool Fun::createSequentialFile(const char *fileName)//写入数据
{
	ofstream outClientFile(fileName, ios::out);
	if  (!outClientFile) 	return false;
	int account; char name[ 30 ]; double balance;
	cout << " Account\tName\tBalance"<<"? "<<endl;
	while(cin>>account>>name>>balance)
	{
		outClientFile << account <<' '<< name <<' '<< balance << "\n";
		cout << " Account\tName\tBalance"<<"? "<<endl;
	}
	return true;
}*/

bool Fun::readSequentialFile(const char *fileName)//读取数据
{
   ifstream inClientFile( fileName, ios::in );
   if ( !inClientFile )  return false;
   int account; char name[ 30 ];
   cout <<"Course\tScore\n";
   while (inClientFile>>name>>account)
   {
   		cout<<name<<"\t"<<account<<endl;
   }
   inClientFile.close();
   return true;
}

bool Fun::chooseCourse(const char *fileName,int kk)
{
   ifstream inClientFile( fileName, ios::in );
   if ( !inClientFile )  return false;
   for(int i=0;i<kk;i++)
   {
       inClientFile>>x>>credit;
   }
   inClientFile.close();
   return true;
}


void Fun::writeSFile(Student &x)
{
    ofstream outfile("student.txt", ios::out);
    outfile<<x;
    outfile.close();
    return;
}

void Fun::PPtest()
{
    cout<<"Now is 2017-2-6"<<endl;
    Date DateTest(2017,2,6);
    cout<<DateTest<<endl;
    cout<<DateTest++<<endl;
    cout<<DateTest<<endl;
    cout<<++DateTest<<endl;
    cout<<DateTest<<endl;
}

void Fun::create()
{
    cout<<"Please create a student(include name,birthday):"<<endl;
    cin>>c;
    cin>>y>>m>>d;
    Date a(y,m,d);
    try
    {
        temp=new Student(c,a);
    }
    catch(MyException D)
    {
        cout<<"Exception: "<<D.whatD()<<endl;
        Fun::create();
    }
}

void Fun::choose()
{
    cout<<"which kind of class do you want to choose?"<<endl;
    cout<<"choose 1 for ObligatoryCourse;"<<endl;
    cout<<"choose 2 for ElectiveCourse;"<<endl;
    int cho;
    cin>>cho;
    if(cho==1)
    {
        if(readSequentialFile("ObligatoryCourse.txt"))
        {
            cout<<"Please choose a course:"<<endl;
            //cin>>x>>credit;
            cin>>num;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout<<"error! please choose again!"<<endl;
                cin>>num;
            }
            while(num>5||num<1)
            {
                cout<<"error! please choose again!"<<endl;
                cin>>num;
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout<<"error! please choose again!"<<endl;
                    cin>>num;
                }
            }
            chooseCourse("ObligatoryCourse.txt",num);
            ObligatoryCourse *ob=new ObligatoryCourse(x,credit);
            temp->addCourse(ob);
        }
        else cout<<"Error!"<<endl;
    }
    else if(cho==2)
    {
        if(readSequentialFile("ElectiveCourse.txt"))
        {
            cout<<"Please choose a course:"<<endl;
            //cin>>x>>credit;
            cin>>num;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout<<"error! please choose again!"<<endl;
                cin>>num;
            }
            while(num>3||num<1)
            {
                cout<<"error! please choose again!"<<endl;
                cin>>num;
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout<<"error! please choose again!"<<endl;
                    cin>>num;
                }
            }
            chooseCourse("ElectiveCourse.txt",num);
            ElectiveCourse *ob=new ElectiveCourse(x,credit);
            temp->addCourse(ob);
        }
        else cout<<"Error!"<<endl;
    }
    else
    {
        cout<<"Error!"<<endl;
    }
}

void Fun::setScore()
{
    for(int j=0;j<temp->getCourseNumber();j++) temp->getList(j)->printClass();
    cout<<"which course do you want to set score?"<<endl;
    int i;
    cin>>i;
    if(i>temp->getCourseNumber()||i<0)
    {
        throw MyException();
    }
    else
    {
        cout<<"which grade do you want to set?"<<endl;
        try
        {
            temp->getList(i)->setGrade();
        }
        catch(MyException S)
        {
            cout<<"Exception: "<<S.whatS()<<endl;
        }
        /*
        //此种方法应该是用iypeid判断类型之后读入一个int/char变量，然后传参进去。
        //像这样在函数内部输入数据，则不需要这样判断，用虚函数即可
        if(typeid(ObligatoryCourse)==typeid(*(temp->getList(i))))
        {
            temp->getList(i)->setGrade();
        }
        else
        {
            temp->getList(i)->setGrade();
        }*/
    }
}

bool Fun::control()
{
    cout<<"What do you want to do?"<<endl;
    cout<<"Choose 1 to add course;"<<endl;
    cout<<"Choose 2 to remove course;"<<endl;
    cout<<"Choose 3 to set score;"<<endl;
    cout<<"Choose 4 to print all information;"<<endl;
    cout<<"Choose 5 to test ++;"<<endl;
    cout<<"Choose 6 to know your calc;"<<endl;
    cout<<"Choose 7 to write down the information;"<<endl;
    cout<<"Choose 8 to quit;"<<endl;
    int i;
    cin>>i;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout<<"error! please choose again!"<<endl;
        cin>>i;
    }
    if(i==1)
    {
        choose();
        return true;
    }
    else if(i==2)
    {
        int j;
        for(int j=0;j<temp->getCourseNumber();j++) temp->getList(j)->printClass();
        cout<<"which course do you want to remove?"<<endl;
        cin>>j;
        try
        {
            temp->removeCourse(j);
        }
        catch(MyException C)
        {
            cout<<"Exception: "<<C.whatC()<<endl;
        }
        return true;
    }
    else if(i==3)
    {
        try
        {
            setScore();
        }
        catch(MyException C)
        {
            cout<<"Exception: "<<C.whatC()<<endl;
        }
        return true;
    }
    else if(i==4)
    {
        cout<<*temp<<endl;
        return true;
    }
    else if(i==5)
    {
        PPtest();
        return true;
    }
    else if(i==6)
    {
        cout<<temp->calcCredit()<<endl;
        return true;
    }
    else if(i==7)
    {
        writeSFile(*temp);
        cout<<"Finish!"<<endl;
        return true;
    }
    else if(i==8)
    {
        cout<<"Finish"<<endl;
        return false;
    }
    else
    {
        cout<<"Error! please choose again!"<<endl;
        return true;
    }
}
