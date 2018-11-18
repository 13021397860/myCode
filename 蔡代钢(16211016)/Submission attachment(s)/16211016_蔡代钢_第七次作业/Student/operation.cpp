#include "operation.h"
#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<fstream>
using namespace std;
void outexception(int k,int num1)
{
    if(k<=0||k>num1)
        throw MyException();
}
operation::operation()
{
    //ctor
}
void operation::mainoperation()
{
    char n[100];
    Student s;
    operation a;
    printf("#请选择是从文件中读取学生信息(请输入1)，还是现在建立一个学生信息(请输入2)！\n");
    while(cin>>n)
    {
        if(n[0]=='1'&&n[1]=='\0')
        {
            a.getmessageformfile(s);
            break;
        }
        else if(n[0]=='2'&&n[1]=='\0')
        {
            a.setNameanData(s);
            break;
        }
        else
            printf("输入信息错误，请重新输入:\n");
    }
    a.SelectionOperation();
    while(cin>>n)
    {
        if(n[0]=='1'&&n[1]=='\0')
        {
            a.showmessage(s);
        }
        else if(n[0]=='2'&&n[1]=='\0')
        {
            cout<<"#推荐选择课程如下：\n";
            a.showcoursemessage();
            cout<<"\n";
            a.SelectCourses(s);
            cout<<"\n";
        }
        else if(n[0]=='3'&&n[1]=='\0')
        {
            a.showmessage(s);
            a.setScore(s);
            cout<<"\n";
        }
        else if(n[0]=='4'&&n[1]=='\0')
        {
            a.getScore(s);
            cout<<"\n";
        }
        else if(n[0]=='5'&&n[1]=='\0')
        {
            a.showmessage(s);
            a.dropCourses(s);
            cout<<"\n";
        }
        else if(n[0]=='6'&&n[1]=='\0')
        {
            a.showcoursemessage();
            cout<<"\n";
        }
        else if(n[0]=='7'&&n[1]=='\0')
        {
            a.outputuofile(s);
            cout<<"#数据成功输入文件中!\n";
        }
        else if(n[0]=='8'&&n[1]=='\0')
            break;
        else
        {
            printf("#输入信息错误，请重新输入!\n");
            cout<<"\n";
        }
        a.SelectionOperation();
    }
}
void operation::setNameanData(Student &s)
{
    printf("#请输入姓名！(20个字节以内)\n");
    //printf("请输入姓名！(20个字节以内)\n");
    char *names;
    names=new char [1000];
    cin>>names;
    printf("#请输入生日！(包括年 月 日，中间用空格隔开)\n");
    //printf("请输入生日！(包括年 月 日，中间用空格隔开)\n");
    int y,m,d;
    cin>>y>>m>>d;
    s.setmessage(names,y,m,d);
}
void operation::getmessageformfile(Student &s)
{
    ifstream cindata("Student information.txt",ios::in);
    char *names;
    string a,b,c; char d;
    int year,month,day;
    names=new char [1000];
    cindata>>a>>names>>b>>year>>d>>month>>d>>day>>d;
    s.setmessage(names,year,month,day);
    string CourseName,Subjecttype;
    double creditHour,Score;
    for(int i=0;i<12;i++)
        cindata>>a;
    while(cindata>>a>>CourseName>>Subjecttype>>b>>creditHour>>c>>Score)
    {
        if(Subjecttype=="Elective")
        {
            char grade;
            if(Score==95)
                grade='A';
            else if(Score==85)
                grade='B';
            else if(Score==75)
                grade='C';
            else if(Score==65)
                grade='D';
            else if(Score==55)
                grade='E';
            else if(Score==-1)
                grade='F';
            Course* a=new ElectiveCourse();
            a->setall(CourseName,creditHour,grade);
            a->setpd(2);
            s.addCourse(a);
        }
        else
        {
            Course* a=new ObligatoryCourse();
            a->setall(CourseName,creditHour,Score);
            a->setpd(1);
            s.addCourse(a);
        }
    }
}
void operation::SelectionOperation()
{
    printf("#请输入您的操作！(1为显示学生信息，2为选课，3为设置成绩，4为查询成绩，5为退课，6为查看可选课程信息，7为将学生信息输入到文件中，8为结束操作)\n");
    //printf("#请输入您的操作！(1为显示学生信息，2为选课，3为设置成绩，4为查询成绩，5为退课，6为结束操作)\n");
}
void operation::SelectCourses(Student &s)
{
    printf("#请问您要选择的是推荐课程还是其他课程！(1为推荐课程，2为其他课程)\n");
    int m;
    cin>>m;
    if(m==1)
    {
        ifstream cindata("Course information.txt",ios::in);
        string CourseName[2][20];
        double creditHour[2][20];
        string Name,type;
        double credit;
        int num1=0,num2=0;
        while(cindata>>Name>>type>>credit)
        {
            if(type=="Elective")
            {
                num2++;
                CourseName[1][num2-1]=Name;
                creditHour[1][num2-1]=credit;
            }
            else
            {
                num1++;
                CourseName[0][num1-1]=Name;
                creditHour[0][num1-1]=credit;
            }
        }
        printf("#请输入您要选择的推荐课程的科目类型(1为必修，2为选修)以及其之前的编号！\n");
        int n,k;
        cin>>n>>k;
        if(n==1)
        {
            try{
                outexception(k,num1);
                int pd=1;
                for(int i=1;i<=s.getcourseNumber();i++)
                {
                    if(s.getcourseList(i)->getname()==CourseName[0][k-1])
                    {
                        printf("#此课程已经选择过，请勿重复选择！\n");
                        pd=0;
                        break;
                    }
                }
                if(pd==1)
                {
                    double mm=-1;
                    Course* a=new ObligatoryCourse();
                    a->setall(CourseName[0][k-1],creditHour[0][k-1],mm);
                    a->setpd(1);
                    s.addCourse(a);
                }
            }catch(MyException ex){
                cout<<"#出现异常："<<ex.what2()<<"\n";
                cout<<"#您输入的编码有误，此次操作无效！\n";
            }
        }
        else if(n==2)
        {
            try{
                outexception(k,num2);
                int pd=1;
                for(int i=1;i<=s.getcourseNumber();i++)
                {
                    if(s.getcourseList(i)->getname()==CourseName[1][k-1])
                    {
                        printf("#此课程已经选择过，请勿重复选择！\n");
                        pd=0;
                        break;
                    }
                }
                if(pd==1)
                {
                    Course* a=new ElectiveCourse();
                    a->setall(CourseName[1][k-1],creditHour[1][k-1],'F');
                    a->setpd(2);
                    s.addCourse(a);
                }
            }catch(MyException ex){
                cout<<"#出现异常："<<ex.what2()<<"\n";
                cout<<"#您输入的编码有误，此次操作无效！\n";
            }
        }
    }
    else if(m==2)
    {
        selectiveCourses(s);
    }
}
void operation::selectiveCourses(Student &s)
{
    printf("#请输入要选的科目类型(1为必修，2为选修)！\n");
    //printf("请输入要选的科目类型(1为必修，2为选修)！\n");
    char m[20];
    cin>>m;
    string Name;
    double score;
    if(m[0]=='1')
    {
        printf("#请输入要选的必修科目名，学分以及成绩！(中间用空格隔开，若没有成绩，则输入-1)\n");
        //printf("请输入要选的必修科目名，学分以及成绩！(若没有成绩，则输入-1)\n");
        double grade;
        int pd=1;
        cin>>Name>>score>>grade;
        for(int i=1;i<=s.getcourseNumber();i++)
        {
            if(s.getcourseList(i)->getname()==Name)
            {
                printf("#此课程已经选择过，请勿重复选择！\n");
                pd=0;
                break;
            }
        }
        if(pd==1)
        {
            Course* a=new ObligatoryCourse();
            a->setall(Name,score,grade);
            a->setpd(1);
            s.addCourse(a);
        }
    }
    else if(m[0]=='2')
    {
        printf("#请输入要选的选修科目名，学分以及成绩等级！(中间用空格隔开，若没有成绩等级，则输入F)\n");
        //printf("请输入要选的选修科目名，学分以及成绩等级！(若没有成绩等级，则输入F)\n");
        char grade;
        int pd=1;
        cin>>Name>>score>>grade;
        for(int i=1;i<=s.getcourseNumber();i++)
        {
            if(s.getcourseList(i)->getname()==Name)
            {
                printf("#此课程已经选择过，请勿重复选择！\n");
                pd=0;
                break;
            }
        }
        if(pd==1)
        {
            Course* a=new ElectiveCourse();
            a->setall(Name,score,grade);
            a->setpd(2);
            s.addCourse(a);
        }
    }
}
void operation::setScore(Student &s)
{
    printf("#请输入要设置成绩的科目编号！\n");
    //printf("请输入要设置成绩的科目编号！\n");
    int m;
    cin>>m;
    try{
        outexception(m,s.getcourseNumber());
        if(s.getcourseList(m)->getpd()==1)
        {
            double scores;
            printf("#请输入此必修课的成绩！\n");//printf("请输入此必修课的成绩！\n");
            cin>>scores;
            s.getcourseList(m)->setScore(scores);
        }
        else if(s.getcourseList(m)->getpd()==2)
        {
            char scores;
            printf("#请输入此选修课的成绩等级！\n");//printf("请输入此选修课的成绩等级！\n");
            cin>>scores;
            s.getcourseList(m)->setScore(scores);
        }
    }catch(MyException ex){
        cout<<"#出现异常："<<ex.what2()<<"\n";
        cout<<"#您输入编号有误，此操作无效!\n";
    }
}
void operation::getScore(Student &s)
{
    int n;
    printf("#请输入你想要查询的成绩类型(1为查询科目成绩，2为查询积点成绩)\n");
    cin>>n;
    if(n==1)
    {
        cout<<"\n";
        for(int i=1;i<=s.getcourseNumber();i++)
        {
            cout<<" "<<i<<".课程名："<<s.getcourseList(i)->getname()<<"  学分:"<<fixed<< setprecision(1)<<s.getcourseList(i)->getcreditHour();
            cout<<"\n";
        }
        int m;
        printf("#请输入要查询成绩的科目编号！\n");
        cin>>m;
        try{
            outexception(m,s.getcourseNumber());
            if(s.getcourseList(m)->getpd()==1)
                cout<<"#此必修课的课程名为:";
            else if(s.getcourseList(m)->getpd()==2)
                cout<<"#此选修课的课程名为:";
            cout<<s.getcourseList(m)->getname()<<" 学分:"<<fixed<<setprecision(1)<<s.getcourseList(m)->getcreditHour();
            cout<<" 成绩为："<<s.getcourseList(m)->getScore()<<"(-1表示未设置成绩！)\n";
        }catch(MyException ex){
            cout<<"#出现异常："<<ex.what2()<<"\n";
            cout<<"#您输入编号有误，此操作无效!\n";
        }
    }
    else if(n==2)
    {
        double sum=0;
        int pd=s.calcCredit(sum);
        if(pd==0){}
        else
        {
            cout<<"#积点成绩为："<<fixed<<setprecision(1)<<sum<<"\n";
        }
    }
}
void operation::dropCourses(Student &s)
{
    printf("#请输入要退课的课程的编号！\n");
    //printf("请输入要退课的课程的编号！\n");
    int m;
    cin>>m;
    s.removeCourse(m);
}
void operation::showmessage(Student &s)
{
    cout<<s<<endl;
    cout<<"#若分数为-1，则表示未设置成绩！\n";
}
void operation::showcoursemessage()
{
    ifstream cindata("Course information.txt",ios::in);
    string CourseName,Subjecttype;
    double creditHour;
    cout<<"ObligatoryCourse:\n";
    int pd=1,i=1;
    while(cindata>>CourseName>>Subjecttype>>creditHour)
    {
        if(pd==1&&Subjecttype=="Elective")
        {
            cout<<"\nElectiveCourse:\n";
            pd=0;
            i=1;
        }
        cout<<i++<<"."<<std::left<<setw(14)<<CourseName<<fixed<<setprecision(1)<<creditHour<<"\n";
    }
}
void operation::outputuofile(Student &s)
{
    ofstream coutdata("Student information.txt",ios::out);
    coutdata<<"Name: "<<s.getname();
    coutdata<<"   Birthday: "<<s.getbirthday().get_year()<<"-"<<setfill('0')
    <<setw(2)<<s.getbirthday().get_month()<<"-"<<setfill('0')<<setw(2)<<s.getbirthday().get_day()<<endl;
    coutdata<<"Course: ( Score = -1 means no score have been set！ )\n";
    for(int i=1;i<=s.getcourseNumber();i++)
    {
        coutdata<<" Name: "<<s.getcourseList(i)->getname();
        if(s.getcourseList(i)->getpd()==1)
            coutdata<<"  Obligatory ";
        else if(s.getcourseList(i)->getpd()==2)
            coutdata<<"  Elective ";
        coutdata<<"  CreditHour: "<<fixed<<setprecision(1)<<s.getcourseList(i)->getcreditHour();
        coutdata<<"  Score: "<<s.getcourseList(i)->getScore()<<"\n";
    }
}
operation::~operation()
{
    //dtor
}
