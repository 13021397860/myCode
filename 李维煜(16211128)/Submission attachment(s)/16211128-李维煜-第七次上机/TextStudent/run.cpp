#include "run.h"
#include <typeinfo>
#include"TextStudentClass.h"
#include<iostream>
using namespace std;


string E[22];

string O[22];

int EN=0;
int ON=0;

run::run()
{
    //ctor
}

run::run(int)
{

}

run::~run()
{
    //dtor
}

void run::loadElectiveclass()//选修
{
    ifstream infile("选修课程.txt",ios::in);
    if(!infile)
    {
        cerr<<"读取选修课失败"<<endl;
        exit(1);
    }
    for(int i=1;i<=20;i++)
    {
        E[i]="empty";
    }
    for(int i=1;i<20;i++)
    {
        infile>>E[i];
        if(E[i]=="empty")
        {
            break;
        }
        EN++;
    }
    infile.close();
}

void run::loadObligatoryclass()//必修
{
    ifstream infile("必修课程.txt",ios::in);
    if(!infile)
    {
        cerr<<"读取选修课失败"<<endl;
        exit(1);
    }
    for(int i=1;i<=20;i++)
    {
        O[i]="empty";
    }
    for(int i=1;i<20;i++)
    {
        infile>>O[i];
        if(O[i]=="empty")
        {
            break;
        }
        ON++;
    }
    infile.close();
}


void run::saveinf(TextStudentClass *a)
{
    ofstream outfile("学生信息.txt",ios::out);
    if(!outfile)
    {
        cerr<<"储存失败"<<endl;
        exit(1);
    }
    outfile<<"姓名"<<" "<<"出生日期"<<endl;
    outfile<<a->Getname()<<" "<<a->Getbirth()<<endl;
    outfile.close();
}

void run::saveclass(TextStudentClass *a)
{
    Course *temp;
    ofstream outfile("学生信息.txt",ios::app);
    if(!outfile)
    {
        cerr<<"储存失败"<<endl;
        exit(1);
    }
    outfile<<"所选课程: "<<endl;
    for(int i=1;i<=a->getcoursenumber();i++)
    {
        a->getcourseList(i,temp);
        outfile<<*temp;
    }
}


void run::bixiu(TextStudentClass *a)
{
    int k=1;
    loadObligatoryclass();
    while(k)
    {

        cout<<"有这些课程供您选择"<<endl;
        for(int i=1;i<=ON;i++)
        {
            cout<<i<<'.'<<O[i]<<" ";
        }
        cout<<endl;
        cout<<"请输入要选择的课程序号"<<endl;
       int cou;
       cin>>cou;
       if(cin.fail())
       {
           cin.clear();
           cin.ignore();
           cout<<"请输入正确序号"<<endl;
           continue;
       }
       while(!(cou<=ON&&cou>=1))
       {
           cout<<"请输入正确序号"<<endl;
           cin>>cou;
           if(cin.fail())
           {
               cin.clear();
               cin.ignore();
               continue;
           }
       }
        a->addCourse(O[cou],4,0);
        cout<<"输入任意数字继续选课，或输入0退出"<<endl;
        cin>>k;
    }
}

void run::xuanxiu(TextStudentClass *a)
{
    int k=1;
    loadElectiveclass();
    while(k)
    {

        cout<<"有这些课程供您选择"<<endl;
        for(int i=1;i<=EN;i++)
        {
            cout<<i<<'.'<<E[i]<<" ";
        }
        cout<<endl;
        cout<<"请输入要选择的课程序号"<<endl;
        int cou;
        try
        {
             cin>>cou;
             if(cin.fail())
             {
                 throw MyException();
             }
        }
        catch(MyException x)
        {
               cout<<"出现异常:"<<x.Seceterror()<<endl;
               cin.clear();
               cin.ignore();
               continue;
        }
       //if(cin.fail())
       //{
       //    cin.clear();
       //    cin.ignore();
        //   cout<<"请输入正确序号"<<endl;
        //   continue;
      // }
       while(!(cou<=EN&&cou>=1))
       {
           cout<<"请输入正确序号"<<endl;
           //cin>>cou;
           try
           {
            cin>>cou;
            if(cin.fail())
            {
                throw MyException();
            // cin.clear();
               //cin.ignore();
               //continue;
            }
           }
           catch(MyException x)
           {
               cin.clear();
               cin.ignore();
               continue;
           }
       }
       try
       {
          a->addCourse(E[cou],1,'G');
          cout<<"输入任意数字继续选课，或输入0退出"<<endl;
          cin>>k;
       }
       catch(MyException x)
       {
          cout<<"选课异常:"<<x.Courserror()<<endl;
            k=0;
            cout<<"已返回主界面"<<endl;
       }

    }
}

void run::xuanke(TextStudentClass *a)
{
    cout<<"********************************************************************************"<<endl;
    cout<<"1选修                           2必修                                      0退出"<<endl;
    cout<<"********************************************************************************"<<endl;
    int i;
    cin>>i;
    switch(i)
    {
        case 1:xuanxiu(a);break;
        case 2:bixiu(a);break;
        case 0:leave();break;
        default:cout<<"请按提示输入"<<endl;
                menu();
                break;
    }
}

TextStudentClass* run::info()
{
    char N[20];
    cout<<"请输入学生姓名"<<endl;
    cin>>N;
    int year,month,day;
    cout<<"请输入学生的出生日期"<<endl;
    try
    {
        cin>>year>>month>>day;
        Date birth(year,month,day);
    }
    catch(MyException k)
    {
        cout<<"异常错误: "<<k.Daterror()<<endl;
        if(day<=0)
        {
            day=1;
        }
        if(month<=0)
        {
            month=1;
        }
        if(year<=0)
        {
            year=1;
        }
        cout<<"已讲错误参数设置为1"<<endl;
    }
    Date birth(year,month,day);
    TextStudentClass *student1=new TextStudentClass(N,birth);
    cout<<*student1;
    return student1;
}

void run::leave()
{
    exit(1);
}

void run::chengji(TextStudentClass *a)
{
    int score;
    char s;

    cout<<"请输入您要设置成绩的课程"<<endl;
    for(int i=1;i<=a->getcoursenumber();i++)
    {
        cout<<*a->getcourse(i)<<endl;
        Course *p=a->getcourse(i);
        if (typeid(*p)==typeid(ObligatoryCourse))
        {
            cout<<"输入1-100"<<endl;
            cin>>score;
            try
            {
                a->getcourse(i) ->SetMark(score);
            }
            catch(MyException x)
            {
                cout<<"输入成绩异常: "<<x.Scorerror()<<endl;
                score=60;
                cout<<"已将成绩设置为及格(60)"<<endl;
                a->getcourse(i) ->SetMark(score);
            }
        }
        else
        {
            cout<<"输入A-E"<<endl;
            cin>>s;
            try
            {
                 a->getcourse(i)->SetGrade(s);
            }
            catch(MyException x)
            {
                cout<<"输入成绩异常: "<<x.Scorerror()<<endl;
                s='D';
                cout<<"已将成绩设置为及格(60)"<<endl;
                a->getcourse(i)->SetGrade(s);
            }
        }
    }
    cout<<*a;
}
void run::jidian(TextStudentClass *a)
{
    a->calcCredit();
}

void run::SAVE(TextStudentClass *a)
{
    saveinf(a);
    saveclass(a);
}

/*void run::searchcourse(TextStudentClass *a)
{
}
*/
void run::tuike(TextStudentClass *a)
{
    Course *temp;
    cout<<"您所选的课程有："<<endl;
    for(int i=1;i<=a->getcoursenumber();i++)
    {
        a->getcourseList(i,temp);
        cout<<i<<'.'<<*temp;
    }
    cout<<"请输入你要退掉的课程序号"<<endl;
    int i;
    try
    {
     cin>>i;
     if(i>a->getcoursenumber())
     {
         throw MyException();
     }
     a->removeCourse(i);
     cout<<"退课成功！已返回主菜单"<<endl;
    }
    catch(MyException x)
    {
        cout<<"出现异常："<<x.Removerror()<<endl;
        cout<<"已返回主菜单"<<endl;

    }
}


void run::menu()
{
     int i=1;
     TextStudentClass *student1;
     cout<<"                    欢迎使用学生课程管理系统，请按提示操作！                             "<<endl;
     cout<<"************************************************************************************************************************"<<endl;
     cout<<"1录入学生信息        2学生选课        3设置课程成绩       4查询学生绩点      5储存信息     6退课         0退出"<<endl;
     cout<<"**********************************************************************************************************************"<<endl;
     while(i){
     cin>>i;
     switch(i)
     {
         case 1:student1=info();break;
         case 2:xuanke(student1);break;
         case 3:chengji(student1);break;
         case 4:jidian(student1);break;
         case 5:SAVE(student1);break;
         case 6:tuike(student1);break;
         case 0:leave();break;
         default:cout<<"请按照提示输入"<<endl;
                 menu();
                 break;
     }
     }
}
