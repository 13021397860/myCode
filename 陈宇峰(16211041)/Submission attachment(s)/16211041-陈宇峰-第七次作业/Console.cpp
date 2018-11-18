#include "Console.h"
#include "Student.h"
#include "Myexception.h"
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

string obcoursename[5];
string elcoursename[5];
int obcoursecH[5];
int elcoursecH[5];
ObligatoryCourse obcourse[5];
ElectiveCourse elcourse[5];

Console::Console()
{
    //ctor
}

Console::~Console()
{
    //dtor
}

void Console::if_cin_wrong(int &i)
{
    cin>>i;
    while (cin.fail()||i<1||i>6)
    {
        cout<<"\nInvalid choice,try again:";
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
        }
        cin>>i;
    }
}

void Console::displaymenu()
{
    cout<<"Your operation is:"<<endl;//cout<<"您要进行的操作是："<<endl;
    cout<<"1.Selecting obligatoryCourse"<<endl;//cout<<"1.必修选课"<<endl;
    cout<<"2.Selecting electiveCourse"<<endl;//cout<<"2.选修选课"<<endl;
    cout<<"3.Dropping class"<<endl;//cout<<"3.退选课"<<endl;
    cout<<"4.Query student's information"<<endl;//cout<<"4.查询学生信息"<<endl;
    cout<<"5.Setting grades"<<endl;//cout<<"5.设置成绩"<<endl;
    cout<<"6.Logging out"<<endl;//cout<<"6.退出系统"<<endl;
    cout<<"Please enter the operation you want to do (1~6):";//cout<<"请输入您要进行的操作（1~6）：";
}

Console& Console::buildCourse()
{
    string str;
    int num;
    fstream file("content.txt");
    for (int i=0;i<5;i++)
    {
        file>>str>>num;
        obcourse[i].setname(str);
        obcoursename[i]=str;
        obcourse[i].setcreditHour(num);
        obcoursecH[i]=num;
    }

    for (int i=0;i<5;i++)
    {
        file>>str>>num;
        elcourse[i].setname(str);
        elcoursename[i]=str;
        elcourse[i].setcreditHour(num);
        elcoursecH[i]=num;
    }
    file.close();
}

Console& Console::buildStudent()
{
    char name[10];
    int d,m,y;
    cout<<endl;
    cout<<"------------------------Welcome to the education system------------------------"<<endl;
    cout<<endl;
    cout<<"Please enter the student's name :";
    cin>>name;
    cout<<endl;
    cout<<"Please enter the student's birthday :";
    while (1)
    {
    try{
        cin>>y>>m>>d;
        student=new Student(name,m,d,y);
        break;
    }catch(MyException ex)
    {
        cout<<"\nWRONG:"<<ex.what()<<endl;
        cout<<"please set the birthday again:";
    }
    }
    cout<<"-------------------------------------------------------------------------------"<<endl;
}

int Console::run()
{
    buildCourse();
    buildStudent();
    int operation,choose;
    while (1)
    {
        displaymenu();
        if_cin_wrong(operation);
        switch (operation)
        {
        case 1:
            cout<<"\nThere are the obligatory courses you can choose"<<endl;
            for (int i=0;i<5;i++)
            {
                cout<<"  "<<i+1<<"."<<setw(36)<<left<<obcoursename[i]<<"  "<<obcoursecH[i]<<" credit hour"<<endl;
            }
            cout<<"  6.Don't choose"<<endl;
            cout<<"Please enter the code of the course you want to choose : ";
            if_cin_wrong(choose);
            //cin>>choose;
            if (choose<6)
            {
                cout<<"\nYou choose the course: "<<obcoursename[choose-1]<<"\n";
                student->addCourse(&obcourse[choose-1]);
                cout<<endl;
            }
            cout<<endl;
            break;

        case 2:
            cout<<"\nThere are the elective courses you can choose"<<endl;
            for (int i=0;i<5;i++)
            {
                cout<<"  "<<i+1<<"."<<setw(36)<<left<<elcoursename[i]<<"  "<<elcoursecH[i]<<" credit hour"<<endl;
            }
            cout<<"  6.Don't choose"<<endl;
            cout<<"Please enter the code of the course you want to choose : ";
            if_cin_wrong(choose);
            //cin>>choose;
            if (choose<6)
            {
                cout<<"\nYou choose the course: "<<elcoursename[choose-1]<<"\n";
                student->addCourse(&elcourse[choose-1]);
                cout<<endl;
            }
            cout<<endl;
            break;

        case 3:
            cout<<endl;
            cout<<"0.Do nothing"<<endl;
            student->printcourselist();
            cout<<"The course that you want to drop is : ";
            while (1)
            {
                try{
                    cin>>choose;
                    if (choose!=0)
                    {
                        student->removeCourse(choose-1);
                    }
                    break;
                }catch (MyException ex)
                {
                    cout<<"\nWRONG:"<<ex.what()<<endl;
                    cout<<"please input your choice again:";
                }
            }
            cout<<endl;
            break;

        case 4:
            {
            fstream file("information.txt");
            file<<*student;
            file.close();
            cout<<"\n"<<*student;
            cout<<endl;
            break;
            }

        case 5:
            cout<<endl;
            if (!student->setCourseScore())
                cout<<"Fail to set"<<endl;
            cout<<endl;
            break;

        case 6:
            cout<<"\nLog out successfully"<<endl;
            break;
        }
        if (operation==6) break;
    }
    return 0;
}
