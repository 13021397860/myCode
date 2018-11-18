#include "Console.h"
#include <iostream>
#include "Course.h"
#include "Student.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#include "MyException.h"
#include <iostream>
#include <typeinfo>
#include <fstream>
#include <cstdlib>
using namespace std;
Course *oc[MAX_SIZE]={new ObligatoryCourse("TOBEWRITEN", -1,-1),new ObligatoryCourse("TOBEWRITEN", -1,-1)};
Course *ec[MAX_SIZE]={new ElectiveCourse("TOBEWRITEN", -1,-1),new ElectiveCourse("TOBEWRITEN", -1,-1),new ElectiveCourse("TOBEWRITEN",-1,-1)};

Console::Console()
{
    //ctor
}

void Console::run()
{
    //testdate();
    displaycourse();
    chooseandgive();
}

void Console::testdate()
{
    cout<<"testdate"<<endl;
    cout<<"type month date year in order"<<endl;
    int yue,ri,nian;
    cout<<"type the time you want to test"<<endl;
    int testnumber;
    cin>>testnumber;
    while(testnumber--)
    {
        cin>>yue>>ri>>nian;
        Date te(yue,ri,nian);
        cout<<te<<endl;
        cout<<te++<<endl;
        cout<<++te<<endl;
    }
}


void outputline(string name,int credit,int score)
{

    //cout<<name<<"  "<<credit<<"   "<<score<<endl;
}
void Console::displaycourse()
{
    ifstream infile;
    string name1;
    int credit1,score1;
    infile.open("coursetochoose.txt", ios::in);
    if(!infile)
    {
        cerr<<"Wrong file opeing"<<endl;
    }
    int i=0;
    while(infile>>name1>>credit1>>score1)
    {
        outputline(name1,credit1,score1);
        if(i<2)
        {
            oc[i]->name=name1;
            oc[i]->creditHour=credit1;
            oc[i]->myscore=score1;
        }
        if(i>=2)
        {
            ec[i-2]->name=name1;
            ec[i-2]->creditHour=credit1;
            ec[i-2]->myscore=score1;
        }
        i++;
    }
for(int i=0;i<2;i++)
    {
        cout<<i+1<<"   ";
        cout<<*oc[i]<<endl;
        //oc[i]->printcourseinfor();
    }
    for(int i=0;i<3;i++)
    {
        cout<<i+3<<"   ";
        cout<<*ec[i]<<endl;
    }
}

void Console::testinfor(Student test)
{
            cout<<"Ensure your information:"<<endl;
            test.printeve();
}

void Console::chooseandgive()
{
        int flag;
    char name[20];
    cout<<"type 1 to continue,0 to exit"<<endl;
    while(1)
    {
        cin>>flag;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cerr<<"Please type number"<<endl;
            cin>>flag;
        }
        if(flag!=1&&flag!=0)
        {
            cerr<<"Wrong command number has been typed"<<endl;
            cout<<"Type again"<<endl;
            cin>>flag;
        }
        else if(flag==1)
        {
            cout<<"type your name and birthday(month date year)"<<endl;
            cin>>name;
            while(cin.fail())
            {

                cin.clear();
                cin.ignore();
                cerr<<"Type reasonablle name"<<endl;
                cin>>name;
            }
            int yue,ri,nian;
            MyException except;
            try
            {
                cin>>yue>>ri>>nian;
                Date riqi(yue,ri,nian);
                riqi.printdate();
                except.testdate(riqi);
            }
            catch(Date riqi)
            {
                cout<<"Invaild date information!"<<endl;
                cout<<"Please type valid date!"<<endl;
                 cin>>yue>>ri>>nian;
            }
            cout<<endl;
            Student test(name,yue,ri,nian);
            testinfor(test);
            cout<<endl;

            cout<<"type the number of course you want to choose(less than 5)"<<endl;
            int number;
            cin>>number;

            while(number>5||number<=0)
            {
                cout<<endl;
                cerr<<"Please type the reasonable number(1-5),and type it again:"<<endl;
                cout<<"You number is:"<<endl;
                cin>>number;
            }
            cout<<endl;
            cout<<"Type the id of course you want to choose"<<endl;
            while(number--)
            {

                int temp;
                MyException number;
                try
            {
                cin>>temp;
                number.testunder(temp);
            }
            catch(int temp)
            {
                cout<<"Invalid id number of course"<<endl;
            }
            if(temp<0||temp>5)
            {
                cout<<"Not this id!"<<temp<<endl;
                cout<<"Type again!"<<endl;
                cin>>temp;
            }
                if(temp<=2)
                {

                    test.addCourse(oc[temp-1]);
                }
                else
                {
                    test.addCourse(ec[temp-3]);

                }
            }
            cout<<test<<endl;


            cout<<"please enter the score of each class"<<endl;
            test.shezhichengji(test);
            cout<<endl;
            cout<<endl;
            test.calcCredit();
            cout<<endl;
            cout<<"the result is:"<<endl;
            cout<<test<<endl;
            ofstream outfile("student.txt",ios::out);
            outfile<<test;

           cout<<endl;
           cout<<endl;

  }
        else if(flag==0)
        {
            break;
        }


           }
}




Console::~Console()
{
    //dtor
}
