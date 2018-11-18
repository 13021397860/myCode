#include "Console.h"
#include"Student.h"
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include"OtherOption.h"
#include"WrongOc.h"
#include"WrongEc.h"
using namespace std;
Console::Console()
{
    //ctor
}

Console::~Console()
{

    //dtor
}




int Console::quotient(int choice)
{
    if(choice<0||choice>6)  throw OtherOption();
    return choice;
}

int Console::displayMenu()
{
    int choice =0;
    cout<<" student course system-main menu:\n"<<"\t1.select obligatory course\n"<<"\t2.select elective course\n"<<"\t3.see course-selecting list\n"<<"\t4.set course grade:\n""\t5.remove course\n"<<"\t0.exit system\n"<<"\t6.calculate jidian"<<"please choose one"<<endl;
    cin>>choice;
    try
    {
        int result=quotient(choice);
        cout<<"the choice is"<<result<<endl;
        return choice;
    }
    catch(OtherOption& otherOption)
    {
        cout<<"exception course id occured"<<endl<<otherOption.what();
    }
    /*
    while (choice<0||choice>6)
    {
      cout << "\nInvalid choice, try again:\n";
      cin >> choice;
      if (cin.fail())
      {
         cin.clear();		//清除错误标记
        cin.ignore();	//移除错误字符
      };
   }
    return choice;*/


}

int Console::quotientOc(int id)
{
    if(id<0||id>2)throw WrongOc();
    return id;
}

int Console::quotientEc(int id)
{
    if(id<0||id>1)  throw WrongEc();
    return id;
}

course*  Console::selectCourse(int choice)
{
    if(choice ==1)
    {
       int id;
        while(cin>>id)
        {
            try
            {
                int result=quotientOc(id);
                cout<<"the id of oc is"<<result<<endl;
                return oc[id];
            }
            catch(WrongOc& wrongOc)
            {
                cout<<"exception occured"<<wrongOc.what()<<endl;
            }
        }

    }
    else if(choice ==2)
    {
        int id;
        while(cin>>id)
        {
            try
            {
                int result=quotientEc(id);
                cout<<"the id of ec is"<<result<<endl;
                return ec[id];
            }
            catch(WrongEc& wrongEc)
            {
                cout<<"exception  occured"<<wrongEc.what()<<endl;
            }
        }

    }
}

bool Console::setCourseScore()
{
    student->WriteCJ();
    cout<<"out SETCOURSESCORE"<<endl;
}

int Console::mxDay(int year,int month,int day)
{
    switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return 28;
    default:
        cout<<"mxDayError"<<endl;
    }
}


Console& Console::buildStudent()
{
    int year,month ,day ;
    char n[50];//
    while(cin>>year>>month>>day>>n)
    {
        try
        {
                if(year<=0||(month<=0||month>=13)||(day<=0||day>mxDay(year,month,day))) throw OtherOption();
                   student=new Student(year,month,day,n);
                   break;
        }
        catch(OtherOption& otherOption )
        {
                cout<<"exception stu occured"<<endl<<otherOption.what();
        }
    }



}

Console& Console::buildCourse()
{
    ofstream outFile("courseLib.dat",ios::out);
    if(!outFile)
    {
        cerr<<"file couldn't be opened"<<endl;
        exit(1);
    }
    int oNum=3,eNum=2;
    string courseName;int credit,mark;char grade;
    while(oNum--)
    {
        cin>>courseName>>credit>>mark;
        outFile<<courseName<<' '<<credit<<' '<<mark<<endl;
    }
    while(eNum--)
    {
        cin>>courseName>>credit>>grade;
        outFile<<courseName<<' '<<credit<<' '<<grade<<endl;
    }
    ifstream inFile("courseLib.dat",ios::in);
    int oNum_=3,eNum_=2;
    if(!inFile)
    {
        cerr<<"file couldn't be opened"<<endl;
        exit(1);
    }
    int id=0;
    while(oNum_--)
    {
        inFile>>courseName>>credit>>mark;
        oc[id]=new ObligatoryCourse(courseName,credit,mark );
        id++;
    }
    id=0;
    while(eNum_--)
    {
        inFile>>courseName>>credit>>grade;
        ec[id]=new ElectiveCourse(courseName,credit,grade );
        id++;
    }
    return *this;
    outFile.close();
}

void Console::outPutStuIfo()
{

}

/*int y,m,d;
    string str4;
        Student a(1998,8,20,"jack");
        a.addCourse3(new ObligatoryCourse("english",4,100));//吧一个oblicourse的指针传给student的courselist作为指针数组元素；
        a.addCourse2("cplusplus",4,'A');//在里面形成指针；
        cout<<a<<endl;
        cout<<"after writeCJ:"<<endl-;
        a.WriteCJ();
        cout<<a<<endl;
        cout<<"after remove cplusplus"<<endl;
        a.removeCourse(1);
        cout<<a;*/


Console& Console::removeCour(int id)
{
    student->removeCourse(id);
}

int Console::run()
{
    buildCourse();
    cout<<"end1"<<endl;
    buildStudent();
    cout<<"out"<<endl;
    int choice=displayMenu();
    while(choice!=0)
    {
        switch(choice)
        {
        case 1:
        case 2:
            student->addCourse3(selectCourse(choice));
            break;
        case 3:
            cout<<*student; outPutStuIfo(); break;
        case 4:
            setCourseScore();break;
        case 5:
            int id;
            cin>>id;
            removeCour(id);break;
        case 6:
            student->calcCredit();
            cout<<"jidian:"<<student->getJidian()<<endl;break;
        }
        choice=displayMenu();
    }
    return 0;
}
/*
cplusplus 4 0
english 4 0
math 3 0
pe 2 F
art 2 F
1998 8 20 jack







































































































































































































































































































































































































































































































































*/
