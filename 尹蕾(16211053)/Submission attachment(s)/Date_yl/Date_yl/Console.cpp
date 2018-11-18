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
    cout<<"请输入学生姓名：";
    cin>>a;
    cout<<"请输入学生生日（年月日用空格分开）：";
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
            cout<<"出现异常："<<ex.what()<<"\n";
            cout<<"请重新输入学生生日（年月日用空格分开）：";
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
        cout<<"请从下列必修课程中选择一门课程：\n";
        while((choice>obnum)||(choice<0))
        {
            for(i=0; i<obnum; i++)
                cout<<"     "<<i+1<<"."<<*oblC[i];
            cout<<"     0.取消本次选课\n";
            cout<<"您要选的必修课程序号是：";
            cin>>choice;
        }
        if(choice!=0) return oblC[choice-1];
        break;
    case 2:
        cout<<"请从下列选修课程中选择一门课程：\n";
        while((choice>elnum)||(choice<0))
        {
            for(i=0; i<elnum; i++)
                cout<<"     "<<i+1<<"."<<*eleC[i];
            cout<<"     0.取消本次选课\n";
            cout<<"您要选的选修课程序号是：";
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
    cout<<"已选课程列表如下："<<endl;
    for(int i=0; i<student->getCountNumber(); i++)
        cout<<*(student->courseList[i]);
    cout<<"请输入你要删除课程的序号：\n";
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
            cout<<"出现异常："<<ex.what()<<"\n";
            cout<<"请重新输入你要删除课程的序号：\n";
        }
    }
}

int Console::displayMenu()
{
    int choice=0;
    cout<<"**********学生选课系统-主菜单**********\n"
        <<"\t1. 选必修课程\n"
        <<"\t2. 选选修课程\n"
        <<"\t3. 查看选课情况\n"
        <<"\t4. 设置课程成绩\n"
        <<"\t5. 查看学生积点成绩\n"
        <<"\t6. 保存学生成绩到文件\n"
        <<"\t7. 退课\n"
        <<"\t0. 退出系统\n"
        <<"请选择所需的操作(0~7)：";
    cin>>choice;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout<<"输入数据格式错误，请重新选择(0~7)：";
        cin>>choice;
    }
    while(choice<0 || choice>7)
    {
        cout<<"必须选择0~7之间的数，请重新选择：";
        cin>>choice;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1024,'\n');
            cout<<"输入数据格式错误，请重新选择(0~7)：";
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
        case 1: //选必修课
        case 2: //选选修课
            student->addCourse(selectCourse(choice));
            break;
        case 3: //输出学生选课信息（暂时不包括成绩）
            cout<<"已选课程列表如下："<<endl;
            for(int i=0; i<student->getCountNumber(); i++)
                cout<<*(student->courseList[i]);
            break;
        case 4: //设置学生成绩
            setCourseScore();
            break;
        case 5: //查看学生积点成绩
            cout<<"积点成绩为："<<endl;
            cout<<student->calcAchievement()<<endl;
            break;
        case 6://保存学生成绩到文件
            cout<<"请输入需要保存的文件名（包含文件类型）：";
            cin>>fileName;
            ofile=new ofstream(fileName);
            if(!ofile)
            {
                cerr<<"无法创建文件！\n";
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
            cout<<"必修课程“"<<(student->courseList[i])->getName()<<"”的成绩（0~100）：";
            cin>>mark;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(1024,'\n');
                cout<<"输入有误，请重新输入：\n";
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
                    cout<<"出现异常："<<ex.what()<<"\n";
                    cout<<"必修课程“"<<(student->courseList[i])->getName()<<"”的成绩(0-100)：";
                    cin>>mark;
                }
            }
        }
        else if(typeid(ElectiveCourse&)==typeid(*(student->courseList[i])))
        {
            cout<<"选修课程“"<<(student->courseList[i])->getName()<<"”的成绩（A~E）：";
            cin>>grade;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(1024,'\n');
                cout<<"输入有误，请重新输入：\n";
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
                    cout<<"出现异常："<<ex.what()<<"\n";
                    cout<<"选修课程“"<<(student->courseList[i])->getName()<<"”的成绩（A~E）：";
                    cin>>grade;
                }
            }
        }
        else
            return false;
    }
    return true;
}
