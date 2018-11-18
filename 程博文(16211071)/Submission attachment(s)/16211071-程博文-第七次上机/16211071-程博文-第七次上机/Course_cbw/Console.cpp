#include "Console.h"
#include<typeinfo>
#include"Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include"MyException.h"
#include<fstream>

Console::Console()
{
    //ctor
}

Console::~Console()
{
    //dtor
}

Console::Console(const Console& other)
{
    //copy ctor
}

void Console::Run()
{
    ifstream In_Obli("ObligatoryCourse.txt",ios::in);
    if(!In_Obli)
    {
        cout<<"文件\"ObligatoryCourse.txt\"打开失败\n";
        return;
    }
    ifstream In_Elec("ElectiveCourse.txt",ios::in);
    if(!In_Elec)
    {
        cout<<"文件\"ElectiveCourse.txt\"打开失败\n";
        return;
    }
    string CourseName;
    int CreditHour;
    int CourseNum=0;
    while(In_Obli>>CourseName>>CreditHour)
    {
        ss1[++CourseNum].setName(CourseName);
        ss1[CourseNum].setcreditHour(CreditHour);
    }
    CourseNum=0;
    while(In_Elec>>CourseName>>CreditHour)
    {
        ss2[++CourseNum].setName(CourseName);
        ss2[CourseNum].setcreditHour(CreditHour);
    }
    cout<<"现在可创建学生：\n";
    Student s;
    s=CreateStudent();
    while(1)
    {
        DispMenu();
        int k;
        cin>>k;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout<<"无效的输入，请重新输入指令序号（0-4）\n\n";
            continue;
        }
        if(!k)
        {
            break;
        }
        switch(k)
        {
        case 0:
            break;
        case 1:
            SelectCourse(s);
            break;
        case 2:
            RemoveCourse(s);
            break;
        case 3:
        {
            cout<<"已选课程数目："<<s.getCourseNumber()<<"\n";
            if(s.getCourseNumber()==0)
            {
                cout<<"无课程可设置成绩\n";
                break;
            }
            int p;
            cout<<"输入要设置成绩的课程序号：\n";
            bool NumInvalidation=false;
            while(!NumInvalidation)
            {
                try
                {
                    cin>>p;
                    s.getCourse(p);
                }
                catch(MyException ex)
                {
                    cout<<"Error: "<<ex.what()<<endl;
                    NumInvalidation=false;
                    cout<<"重新输入要设置成绩的课程序号：\n";
                    continue;
                }
                NumInvalidation=true;
            }
            bool MarkInvalidation=false;
            while(!MarkInvalidation)
            {
                try
                {
                    s.getCourse(p)->SetMark();
                }
                catch(MyException ex)
                {
                    cout<<"Error: "<<ex.what()<<endl;
                    MarkInvalidation=false;
                    cout<<"请重新输入成绩\n";
                    continue;
                }
                MarkInvalidation=true;
            }
            break;
        }
        case 4:
            cout<<s<<endl;
            cout<<"平均分数: "<<s.calcCredit()<<endl<<endl;
            break;
        default:
            cout<<"无效的输入，请重新输入指令序号（0-4）\n\n";
        }
    }
    In_Obli.close();
    In_Elec.close();
    ofstream Out("StudentInfo.txt",ios::out);
    Out<<s;
    Out.close();
}


void Console::DispMenu()
{
    cout<<"----------------------------------------\n";
    cout<<"你可进行以下操作（输入序号1-4，输入0以结束）\n";
    cout<<"1.选择课程：\n";//exception
    cout<<"2.移除课程：\n";
    cout<<"3.设置成绩：\n";
    cout<<"4.输出学生成绩：\n";
    cout<<"----------------------------------------\n";
}



Student Console::CreateStudent()
{
    Student student1;
    char *p=new char [255];
    cout<<"请输入学生姓名：\n";
    cin>>p;
    student1.setName(p);
    int y,m,d;
    cout<<"请输入学生生日（格式：2000-10-20）：\n";
    char a;
    bool DateInvalidtion=false;
    while(!DateInvalidtion)
    {
        cin>>y>>a>>m>>a>>d;
        try
        {
            student1.setbirthDate(y,m,d);
        }
        catch(MyException ex)
        {
            cout<<"Error: "<<ex.what()<<endl;
            cout<<"请重新输入正确的学生生日（格式：2000-10-20）：\n";
            DateInvalidtion=false;
            continue;
        }
        DateInvalidtion=true;
        cout<<"学生生日设置成功\n";
    }
    return student1;
}

int Console::RemoveCourse(Student& s)
{
    int num,order;
    try
    {
        cout<<"现在已选课程数目: "<<s.getCourseNumber()<<endl;
        if(s.getCourseNumber()==0)
        {
            throw -1;
        }
    }
    catch(int i)
    {
        cout<<"无课程可设置成绩\n";
        return 0;
    }
    cout<<"现在可移除课程，输入想移除课程数目(输入0以退出)\n";
    cin>>num;
    if(num==0)
    {
        return 0;
    }
    else
    {
        while(num--)
        {
            cout<<"输入想要移除的课程序号\n";
            bool RangeInvalidation=false;
            while(!RangeInvalidation)
            {
                try
                {
                    cin>>order;
                    s.removeCourse(order);
                }
                catch(MyException ex)
                {
                    cout<<"Error: "<<ex.what()<<endl;
                    cout<<"请重新输入输入想要移除的课程序号\n";
                    RangeInvalidation=false;
                    continue;
                }
                RangeInvalidation=true;
            }
        }
    }
    return 0;
}

void Console::SelectCourse(Student& s)
{
    cout<<"现在开始选课\n";
    cout<<"先选必修课，请输入必修课数目(1-5)\n";
    int course_num;
    cin>>course_num;
    cout<<"先选必修课，请输入必修课编号（1-5）\n";
    int i;
    while(course_num--)
    {
        bool NumInvalidation=false;
        while(!NumInvalidation)
        {
            try
            {
                cin>>i;
                if(i<1||i>5)
                {
                    throw -1;
                }
                s.addCourse(&ss1[i]);
            }
            catch(int i)
            {
                cout<<"Error: 选课超过范围，请重新输入"<<endl;
                NumInvalidation=false;
                continue;
            }
            NumInvalidation=true;
        }
    }
    cout<<"再选选修课，请输入选修课数目(1-5)\n";
    cin>>course_num;
    cout<<"再选选修课，请输入选修课编号（1-5）\n";
    while(course_num--)
    {
        bool NumInvalidation=false;
        while(!NumInvalidation)
        {
            try
            {
                cin>>i;
                if(i<1||i>5)
                {
                    throw -1;
                }
                s.addCourse(&ss2[i]);
            }
            catch(int i)
            {
                cout<<"Error: 选课超过范围，请重新输入"<<endl;
                NumInvalidation=false;
                continue;
            }
            NumInvalidation=true;
        }
    }
}


