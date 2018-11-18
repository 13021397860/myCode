#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<cstdlib>
#include<conio.h>
#include<fstream>
#define MAX_SIZE 12
#include "../Course.h"
#include "../Stu.h"
#include "../Time.h"
#include "Console.h"
#include"MyException.h"
using namespace std;


Console::Console()
{
    s= NULL;
    ocNum = 0;
    ecNum = 0;
}

Console::~Console()
{
    delete s;
    for(int i = 0; i < ocNum; i++)
        delete oc[i];
    for(int i = 0; i < ecNum; i++)
        delete ec[i];
}

Console& Console::buildStudent()

{

    int y, m, d;
    char n[20];
    cout<<"enter name year month day"<<endl;
    cin >> n >> y >> m >> d;
    try
    {
        s= new Stu(n,y,m,d);
    }
    catch(MyException et)
    {
        cout<<et.what()<<endl;
    }

    return *this;

}

Console& Console::file_buildStudent(const char *fileName)
{
    ifstream inClientFile(fileName,ios::in);
    char n[20];
    int y,m,d;
    while(1)
    {
        try
        {
            inClientFile >>n >>y>>m>>d;
                s= new Stu(n,y,m,d);
            break;
        }catch(MyException ex)
        {
            cout<<"data error"<<ex.what()<<endl;
            cout<<"please enter again"<<endl;
        }
    }


    inClientFile.close();
    delete inClientFile;
    return *this;

}


Console& Console::file_buildcourse(int j,string name,int credithour)
{
    if(j==0)
    {
        oc[ocNum] = new ObligatoryCourse(name,credithour);
        ocNum++;
    }
    if(j==1)
    {
        ec[ecNum] = new ElectiveCourse(name,credithour);
        ecNum++;
    }
    return *this;
}

bool Console::infile(const char *fileName)
{
   ifstream inClientFile(fileName,ios::in);
   if ( !inClientFile )  return false;
   int j;
   string name;
   int credithour;
   while (inClientFile >>j >>name>>credithour)
      file_buildcourse( j, name, credithour );
    inClientFile.close();
    delete inClientFile;
   return true;
}



bool Console::file_outstudent(const char* filename, Stu* s)
{
    ofstream *outfile;
    Stu* pstudent;
    pstudent=s;
    outfile=new ofstream(filename, ios::app);
    *outfile<<*pstudent;
    //delete pstudent;
    outfile->close();
    delete outfile;
    return true;

}



Console& Console::buildCourse()
{
    oc[0] = new ObligatoryCourse("English", 4);
    oc[1] = new ObligatoryCourse("Linear Algebra", 3);
    oc[2] = new ObligatoryCourse("Physics", 4);
    oc[3] = new ObligatoryCourse("Calculus", 4);
    ocNum = 4;
    ec[0] = new ElectiveCourse("Data Structure", 4);
    ec[1] = new ElectiveCourse("HTML5", 2);
    ec[2] = new ElectiveCourse("JAVA", 3);
    ecNum = 3;
    return *this;

}

Course* Console::selectCourse()
{
    int h, mid, id, judge;
    string t;

    cout << "ObligatoryCourse:"<<endl;
    for(int i = 0; i < ocNum; i++)
    {
         cout << "id:" << i+1 << " "<< *oc[i] << endl;
    }
    cout << "ElectiveCourse:"<<endl;
    for(int i = 0; i < ecNum; i++)
    {
        cout << "id:" << i+1 << " " << *ec[i] << endl;
    }
    cout<<"Input [0] to exit select course"<<endl
        <<"input [1] and [id] to select obligatory course"<<endl
        <<"input [2] and [id] to select elective course "<<endl
        <<"Input [3] to set score"<<endl;
    while(1)
    {
        cin>>mid;
        switch(mid)
        {
            case 0: judge = 1;
                break;
            case 1:
                cout<<"You have entered [1]! Choose the id of courses!"<<endl;
                try
                {
                    cin >> id;
                    if(id > ocNum || id < 1)
                        {
                        	throw MyException(RANGE_ERROR);
						}

                        else
                            s->addCourse(oc[id-1]);
                        break;
                }catch(MyException et)
                {
                    cout<<et.what()<<endl;
                }
            case 2:
                cout<<"You have entered [2]! Choose the id of courses!"<<endl;
                try
                {
                    cin >> id;
                    if(id > ecNum || id < 1)
                        {
                        	throw MyException(RANGE_ERROR);
						}

                        else
                            s->addCourse(ec[id-1]);
                        break;
                }
                catch(MyException et)
                {
                    cout<<et.what()<<endl;
                }
            case 3:
                try
                {
                    s->setScore();
                } catch(MyException et)
                {
                    cout<<et.what()<<endl;
                }
                break;
            }
    }


            cout <<*s<<endl;
            if(judge == 1)
                cout <<*s<<endl;
            cout<<"Input [0] to exit select course"<<endl;
}






int Console::displayMenu() const
{
    cout<<"-----------------Welcome!--------------------"<<endl<<endl;


}

bool Console::setCourseScore()
{
    s->setScore();
    return true;
}

int Console::run()
{

    infile("course.txt");
    file_buildStudent("Student_name.txt");
    //buildStudent();
    //buildCourse();
    int n=13;
    displayMenu();
    while(n=13)
    {


        selectCourse();
        cout<<"Press enter to continue..."<<endl;
        n=getch();

        if(n!=13)
        {
            break;
        }

    }
        cout<<"calculate credit: "<<s->calCredit()<<endl;
        file_outstudent("student.txt",s);


}
