#include "Console.h"
#include "Student.h"
#include "MyException.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
Console::Console()
{
    //ctor
}

Console::~Console()
{
    //dtor
}

bool isLeapYear(const int &year)
{
    if((year%400==0)||(year%4==0&&year%100!=0))
        return true;
    return false;
}

bool isStandard(const int &year,const int &month,const int &day)
{
    int LMonth_day[]={31,29,31,30,31,30,31,31,30,31,30,31};
    int NMonth_day[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(year<0)
    {
        return false;
    }
    if(month>12||month<=0)
    {
        return false;
    }
    if(isLeapYear(year))
    {
        if(day<=0||day>LMonth_day[month-1])
            return false;
    }
    else
    {
        if(day<=0||day>NMonth_day[month-1])
            return false;
    }
    return true;
}

void Console::output_OcourseList(){
    string b="\n";
    ifstream fileopen;
    fileopen.open("ZO_Course.txt",ios::out);
    char a=fileopen.get();
    while(a!=EOF)
    {
        b+=a;
        a=fileopen.get();
    }
    cout<<b<<endl;
}

void Console::output_EcourseList(){
    string b="\n";
    ifstream fileopen;
    fileopen.open("ZE_Course.txt",ios::out);
    char a=fileopen.get();
    while(a!=EOF)
    {
        b+=a;
        a=fileopen.get();
    }
    cout<<b<<endl;
}

void Console::add_stuInformation(Student &A){
    cout<<"\n请输入学生姓名:"<<endl;
    char name[10];
    cin>>name;
    cout<<"\n请输入学生出生日期:\n示例：1999 01 01"<<endl;
    int year,month,day;
    while(cin>>year>>month>>day){
        try{
            if(cin.fail()||!isStandard(year,month,day))throw MyException("invalid_Date");
            A.setStudentName(name);
            A.setStudentBirth(year,month,day);
            cout<<"\n添加学生信息成功!"<<endl;
            break;
        }
        catch(MyException &X){
            X.what();
        }
    }
}

void Console::query_stuInformation(Student &A){
    int n;
    while(1){
        cout<<"\n1.查询学生全部信息\n2.查询学生绩点成绩\n3.查询学生课程成绩\n4.退出本次操作\n";
        cin>>n;
        if(n==1)
        {
            cout<<A<<endl;
            ofstream file("zout.txt",ios::out);
            file<<A;
        }
        else if(n==2)
        {
            cout<<"\n学生绩点成绩为："<< setprecision(4) << A.calcCredit() << endl;
        }
        else if(n==3)
        {
            cout<<"\n请输入要查询的课程号：";
            int i;
            cin>>i;
            if(A.consultCourse(i)==-1)cout<<"\n不存在此课程或该课程尚未录入成绩"<<endl;
            else
                cout<<A.getConsultCourseName(i)<<": "<<A.consultCourse(i)<<endl;
        }
        else
            break;
    }
}
//设置课程成绩//
void Console::add_stuCourse(Student &A){
    int n;
    while(1){
        cout<<"\n1.必修课程\n2.选修课程\n3.返回\n";
        cin>>n;
        if(n==1){
            output_OcourseList();
            cout<<"\n请输入课程编号：";
            string str;
            while(cin>>str){
                try{
                    if(str.length()>1)
                        throw MyException("invalid_CourseNum");
                    else if(str[0]>'4'||str[0]<'1')
                        throw MyException("invalid_CourseNum");
                    else{break;}
                }
                catch(MyException &X){X.what();}
            }
            string CourseName;
            double Credit;
            int tag=1;
            switch(str[0]){
                case '1':CourseName="data_structure";Credit=3;break;
                case '2':CourseName="OOP";Credit=3;break;
                case '3':CourseName="advanced_math";Credit=4;break;
                case '4':CourseName="linear_algebra";Credit=4;break;
                case '5':
                         cout<<"\n请输入课程名称：";
                         cin>>CourseName;
                         cout<<"\n请输入课程学分：";
                         cin>>Credit;
                         break;
                default:tag=0;cout<<"\n添加课程失败！"<<endl;break;
            }
            if(tag==1){
                cout<<"\n课程添加成功！"<<endl;
                Course *ptr1=new ObligatoryCourse(CourseName,Credit,1,-1);
                A.addCourse(ptr1);
            }
        }
        else if(n==2){
            output_EcourseList();
            cout<<"\n请输入课程编号：";
            string str;
            while(cin>>str){
                try{
                    if(str.length()>1)
                        throw MyException("invalid_CourseNum");
                    else if(str[0]>'4'||str[0]<'1')
                        throw MyException("invalid_CourseNum");
                    else{break;}
                }
                catch(MyException &X){X.what();}
            }
            string CourseName;
            double Credit;
            int tag=1;
            switch(str[0]){
                case '1':CourseName="Google_Analytics";Credit=1;break;
                case '2':CourseName="Aerospace_overview";Credit=1.5;break;
                case '3':CourseName="Information_retrieval";Credit=1;break;
                case '4':
                         cout<<"\n请输入课程名称：";
                         cin>>CourseName;
                         cout<<"\n请输入课程学分：";
                         cin>>Credit;
                         break;
                default:tag=0;cout<<"\n添加课程失败！"<<endl;break;
            }
            if(tag==1){
                Course *ptr2=new ElectiveCourse(CourseName,Credit,2,'F');
                A.addCourse(ptr2);
            }
        }
        else
            break;
    }
}

void Console::remove_stuCourse(Student &A){
    cout<<"\n请输入所要退选课程编号："<<endl;
    int t;
    int times=0;
    while(cin>>t){
        try{
            if(A.removeCourse(t)){cout<<"\n退课成功"<<endl;break;}
            else throw MyException("invalid_CourseNum");
        }
        catch(MyException &X){
            X.what();
        }
        if(++times>3)
            break;
    }

}

void Console::add_courseSorce(Student &A){
    cout<<"\n请输入所要添加成绩课程编号："<<endl;
    int t;
    cin>>t;
    if(t<=A.getcourseNum()&&t>0){
        if(A.courseList[t-1]->Tag()==1){
            cout<<"\n请输入课程成绩：\n(0~100)"<<endl;
            double sorce;
            while(cin>>sorce){
                try{
                    if(sorce<0||sorce>100)throw MyException("invalid_Sorce");
                    break;
                }
                catch(MyException &X){
                    X.what();
                }
            }
            A.courseList[t-1]->setScore(sorce);
        }
        else{
            cout<<"\n请输入课程成绩：\n(A,B,C,D,E)"<<endl;
            string sorce;
            while(cin>>sorce){
                try{
                    if(sorce.length()>1)
                        throw MyException("invalid_Sorce");
                    else if(sorce[0]<'A'||sorce[0]>'E')
                        throw MyException("invalid_Sorce");
                    else{break;}
                }
                catch(MyException &X){
                    X.what();
                }
            }
            A.courseList[t-1]->setScore(sorce[0]);
        }
    }
    else
        cout<<"\n课程编号错误"<<endl;
}

void Console::set_stuInformation(){
    int Num=0;
    Student A;
    cout<<"#请先添加学生信息#";
    if(Num==0)
    {
        add_stuInformation(A);
    }
    while(1){
        cout<<"\n1.查询学生信息\n2.添加课程\n3.退选课程\n4.添加课程成绩\n5.退出当前学生信息\n";
        cin>>Num;
        if(Num==1){
            query_stuInformation(A);
        }
        else if(Num==2){
            add_stuCourse(A);
        }
        else if(Num==3){
            remove_stuCourse(A);
        }
        else if(Num==4){
            add_courseSorce(A);
        }
        else
            break;
    }
}
