#define COURSE_FILE "./Course/courses.dat"
#define MAX_SIZE 50

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<conio.h>
#include<typeinfo>
#include"Student.h"
#include"Course.h"
#include"ElectiveCourse.h"
#include"ObligatoryCourse.h"
#include"Console.h"
#include "MyException.h"

using std::cin;
using std::cout;

//helper function
void to_next(string prompt="按任意键继续。\n")
{
    cout<<prompt;
    getch();
    return;
}


Console::Console(int type)
{
    if(type==1)
    {
        system("chcp 65001");
        system("cls");
    }
    else if(type==0)
    {
        system("chcp 936");
        system("cls");
    }
    user = NULL;
    total = -1;
}

bool Console::init_course()
{
    system("cls");
    cout<<string("开始初始化课程列表。\n");
    char path[200] = COURSE_FILE;
    FILE *fp = fopen(path, "r");
    if(fp==NULL)
    {
        cout<<string("课程列表不存在，将创建默认列表。\n");
        fclose(fp);
        fp = fopen(path, "w+");
        if(fp==NULL)
        {
            cout<<string("课程目录不存在！\n")
                <<string("请尝试手动创建文件:")<<path<<"\n";
            return 0;
        }
        else fprintf(fp,"1|OOP|2.5\n1|CPP|3.4\n0|OS|4.5\n");
    }
    char temp[2000];
    while(fgets(temp,sizeof(temp),fp)!=NULL)
    {
        char *pch = strtok(temp, "|");
        if(atoi(pch)==1)
        {
            total++;
            ObligatoryCourse* course = new ObligatoryCourse;
            pch = strtok(NULL, "|");
            course->setname(pch);
            pch = strtok(NULL, "|");
            course->setcredithour(atoi(pch));
            course->setmark(-1);
            course_list[total] = course;
        }
        else if(atoi(pch)==0)
        {
            total++;
            ElectiveCourse* course = new ElectiveCourse;
            pch = strtok(NULL, "|");
            course->setname(pch);
            pch = strtok(NULL, "|");
            course->setcredithour(atoi(pch));
            course->setgrade('\0');
            course_list[total] = course;
        }
    }
    fclose(fp);
    cout<<"初始化成功。\n";
    return 1;
}

char Console::main_page()
{
    system("cls");
    cout<<string("━━━━━━━━━┒                        ┍━━━━━━━━━\n")
        <<string("┓┏┓┏┓┏┓┏┓┃                        ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┛┗┛┗┛┗┛┗┛┃     欢迎进入选课系统!  ┃┗┛┗┛┗┛┗┛┗\n")
        <<string("┓┏┓┏┓┏┓┏┓┃                        ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┛┗┛┗┛┗┛┗┛┃      按1选课           ┃┗┛┗┛┗┛┗┛┗\n")
        <<string("┓┏┓┏┓┏┓┏┓┃      按2退课           ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┛┗┛┗┛┗┛┗┛┃      按3设置成绩       ┃┗┛┗┛┗┛┗┛┗\n")
        <<string("┓┏┓┏┓┏┓┏┓┃      按4查看已选课程   ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┃┃┃┃┃┃┃┃┃┃      按0退出           ┃┃┃┃┃┃┃┃┃┃\n")
        <<string("┻┻┻┻┻┻┻┻┻┻                        ┻┻┻┻┻┻┻┻┻┻\n");
    return getch();
}

void Console::login()
{
    system("cls");
    cout<<string("━━━━━━━━━┒                        ┍━━━━━━━━━\n")
        <<string("┓┏┓┏┓┏┓┏┓┃                        ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┛┗┛┗┛┗┛┗┛┃     欢迎进入选课系统!  ┃┗┛┗┛┗┛┗┛┗\n")
        <<string("┓┏┓┏┓┏┓┏┓┃                        ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┛┗┛┗┛┗┛┗┛┃                        ┃┗┛┗┛┗┛┗┛┗\n")
        <<string("┓┏┓┏┓┏┓┏┓┃                        ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┛┗┛┗┛┗┛┗┛┃        请先登录！      ┃┗┛┗┛┗┛┗┛┗\n")
        <<string("┓┏┓┏┓┏┓┏┓┃                        ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┃┃┃┃┃┃┃┃┃┃                        ┃┃┃┃┃┃┃┃┃┃\n")
        <<string("┻┻┻┻┻┻┻┻┻┻                        ┻┻┻┻┻┻┻┻┻┻\n");
    string name;
    int y,m,d;
    cout<<string("欢迎登录选课系统！\n");
    cout<<string("姓名：");
    cin>>name;
    cout<<string("出生年：");
    cin>>y;
    cout<<string("出生月：");
    cin>>m;
    cout<<string("出生日：");
    cin>>d;
    Date* Birthday = new Date;
    if(cin.fail()||!Birthday->SetDay(d)||!Birthday->SetMonth(m)||!Birthday->SetYear(y))
    {
        Date a(y,m,d);
        throw MyException(name, string("学生信息有误"), a);
        /*cout<<string("出生月：");
        cin>>m;
        if(!cin.fail())
        {
            cout<<string("出生日：");
            cin>>d;
        }*/
    }
    /*while(cin.fail())
    {
        cin.clear(); // clear flag
        cin.ignore(); // ignore wrong character
        cin.sync(); // flush cache
        cout<<"年月日输入有误，请重新输入！\n";
        cout<<string("出生年：");
        cin>>y;
        if(!cin.fail())
        {
            cout<<string("出生月：");
            cin>>m;
            if(!cin.fail())
            {
                cout<<string("出生日：");
                cin>>d;
            }
            else continue;
        }
        else continue;
    }*/
    user = new Student(name,Birthday);
    return;
}

void Console::load_course()
{
    system("cls");
    int load_status = user->create_coursefile();
    if(load_status==1)
    {
        cout<<string("已经存在学生选课记录，从文件读取.\n");
        if(user->load_course()==-1)throw MyException(string("未知错误，是不是文件有中文？"));
        else cout<<string("读取成功。\n");
    }
    else if(load_status==0)
    {
        cout<<string("没有找到相应学生选课记录，创建默认记录并读取。\n");
        if(user->load_course()==-1)throw MyException("未知错误。");
    }
    else cout<<string("未知错误，是不是文件有中文？\n");
    to_next();
    return;
}

bool Console::select_page()
{
    system("cls");
    cout<<string("━━━━━━━━━┒                        ┍━━━━━━━━━\n")
        <<string("┓┏┓┏┓┏┓┏┓┃                        ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┛┗┛┗┛┗┛┗┛┃       欢迎选课!        ┃┗┛┗┛┗┛┗┛┗\n")
        <<string("┓┏┓┏┓┏┓┏┓┃                        ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┛┗┛┗┛┗┛┗┛┃   输入课程前序号选课   ┃┗┛┗┛┗┛┗┛┗\n")
        <<string("┓┏┓┏┓┏┓┏┓┃                        ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┛┗┛┗┛┗┛┗┛┃                        ┃┗┛┗┛┗┛┗┛┗\n")
        <<string("┓┏┓┏┓┏┓┏┓┃   输入0返回上级菜单    ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┃┃┃┃┃┃┃┃┃┃                        ┃┃┃┃┃┃┃┃┃┃\n")
        <<string("┻┻┻┻┻┻┻┻┻┻                        ┻┻┻┻┻┻┻┻┻┻\n");
    for(int i=0;i<=total;i++)
    {
        cout<<(i+1)<<string("：");
        course_list[i]->old_out();
        if(dynamic_cast<ObligatoryCourse*>(course_list[i])!=NULL)cout<<string("课程性质：必修课\n");
        else cout<<"课程性质：选修课\n";
    }
    cout<<string("请输入课程序号：");
    char ch[250];
    cin>>ch;
    int select = atoi(ch); // if ch is invalid, atoi() returns 0
    if(select==0)return 0;
    else
    {
        if(select<1||select>total+1)
        {
            cout<<string("非法输入。\n");
            to_next();
            return 1;
        }
        if(user->get_coursenum()==10)throw MyException(user->get_name(),"选课异常：选课过多。",*user->get_birthday());
        for(int i=0;i<user->get_coursenum();i++)
        {
            if(course_list[select-1]->getname()==user->get_courselist()[i]->getname())
            {
                cout<<string("已经选过该课程。\n");
                to_next();
                return 1;
            }
        }
        user->add_course(course_list[select-1]);
        cout<<string("选课成功！\n");
        to_next();
        return 0;
    }
}

bool Console::remove_page()
{
    system("cls");
    cout<<string("━━━━━━━━━┒                        ┍━━━━━━━━━\n")
        <<string("┓┏┓┏┓┏┓┏┓┃                        ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┛┗┛┗┛┗┛┗┛┃       欢迎退课!        ┃┗┛┗┛┗┛┗┛┗\n")
        <<string("┓┏┓┏┓┏┓┏┓┃                        ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┛┗┛┗┛┗┛┗┛┃   输入课程前序号退课   ┃┗┛┗┛┗┛┗┛┗\n")
        <<string("┓┏┓┏┓┏┓┏┓┃                        ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┛┗┛┗┛┗┛┗┛┃   输入0返回上级菜单    ┃┗┛┗┛┗┛┗┛┗\n")
        <<string("┓┏┓┏┓┏┓┏┓┃                        ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┃┃┃┃┃┃┃┃┃┃                        ┃┃┃┃┃┃┃┃┃┃\n")
        <<string("┻┻┻┻┻┻┻┻┻┻                        ┻┻┻┻┻┻┻┻┻┻\n");
    for(int i=0;i<user->get_coursenum();i++)
    {
        cout<<(i+1)<<string("：");
        user->get_courselist()[i]->old_out();
        if(dynamic_cast<ObligatoryCourse*>(user->get_courselist()[i])!=NULL)cout<<string("课程性质：必修课\n");
        else cout<<string("课程性质：选修课\n");
    }
    cout<<string("请输入课程序号：");
    char ch[250];
    cin>>ch;
    int select = atoi(ch); // if ch is invalid, atoi() returns 0
    int total = user->get_coursenum()-1;
    if(select==0)return 0;
    else
    {
        if(select<1||select>total+1)
        {
            cout<<string("非法输入。\n");
            to_next();
            return 1;
        }
        if(user->remove_course(select-1))cout<<string("退课成功！\n");
        else cout<<string("退课失败。\n");
        to_next();
        return 0;
    }
}

bool Console::grade_page()
{
    system("cls");
    cout<<string("━━━━━━━━━┒                        ┍━━━━━━━━━\n")
        <<string("┓┏┓┏┓┏┓┏┓┃                        ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┛┗┛┗┛┗┛┗┛┃     欢迎设置成绩!      ┃┗┛┗┛┗┛┗┛┗\n")
        <<string("┓┏┓┏┓┏┓┏┓┃                        ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┛┗┛┗┛┗┛┗┛┃                        ┃┗┛┗┛┗┛┗┛┗\n")
        <<string("┓┏┓┏┓┏┓┏┓┃                        ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┛┗┛┗┛┗┛┗┛┃   输入0返回上级菜单    ┃┗┛┗┛┗┛┗┛┗\n")
        <<string("┓┏┓┏┓┏┓┏┓┃                        ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┃┃┃┃┃┃┃┃┃┃                        ┃┃┃┃┃┃┃┃┃┃\n")
        <<string("┻┻┻┻┻┻┻┻┻┻                        ┻┻┻┻┻┻┻┻┻┻\n");
    cout<<*user;
    string temp;
    cout<<string("您要设置成绩课程的名称：");
    cin>>temp;
    if(temp[0]=='0')return 0;
    Course* course=NULL;
    for(int i=0;i<user->get_coursenum();i++)
    {
        if(temp==user->get_courselist()[i]->getname())
        {
            course = user->get_courselist()[i];
            break;
        }
    }
    if(!course)
    {
        cout<<string("没有找到该课程。\n");
        return 1;
    }
    if(dynamic_cast<ObligatoryCourse*>(course)!=NULL)
    {
        ObligatoryCourse* ocourse = dynamic_cast<ObligatoryCourse*>(course);
        cout<<string("这是一门必修课，请输入你要设置的成绩（一个整数）:\n");
        int x;
        cin>>x;
        if(x<0||x>100)
        {
            /*cout<<string("设置失败，成绩超出范围。\n");
            to_next();
            return 1;*/
            throw MyException("设置失败，成绩超出范围。");
        }
        ocourse->setmark(x);
        cout<<string("设置成功。\n");
        to_next();
    }
    else
    {
        ElectiveCourse* ecourse =  dynamic_cast<ElectiveCourse*>(course);
        cout<<string("这是一门选修课，请输入你要设置的成绩（A/B/C/D/E）:\n");
        char x;
        cin>>x;
        if(x!='A'&&x!='B'&&x!='C'&&x!='D'&&x!='E')
        {
            throw MyException("设置失败，成绩超出范围。");
        }
        ecourse->setgrade(x);
        cout<<string("设置成功。\n");
        to_next();
    }
    return 0;
}

void Console::list_page()
{
    system("cls");
    cout<<string("━━━━━━━━━┒                        ┍━━━━━━━━━\n")
        <<string("┓┏┓┏┓┏┓┏┓┃                        ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┛┗┛┗┛┗┛┗┛┃      学生选课信息      ┃┗┛┗┛┗┛┗┛┗\n")
        <<string("┓┏┓┏┓┏┓┏┓┃                        ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┛┗┛┗┛┗┛┗┛┃                        ┃┗┛┗┛┗┛┗┛┗\n")
        <<string("┛┗┛┗┛┗┛┗┛┃                        ┃┗┛┗┛┗┛┗┛┗\n")
        <<string("┓┏┓┏┓┏┓┏┓┃                        ┃┏┓┏┓┏┓┏┓┍\n")
        <<string("┃┃┃┃┃┃┃┃┃┃                        ┃┃┃┃┃┃┃┃┃┃\n")
        <<string("┻┻┻┻┻┻┻┻┻┻                        ┻┻┻┻┻┻┻┻┻┻\n");
    cout<<*user;
    to_next();
    return;
}

Console::~Console()
{
    delete user;
    delete[] course_list;
}
