#include "MyException.h"
#include "Date.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <cstdio>

using std::string;
using std::cout;

void helper_continue(string prompt="按任意键继续...\n")
{
    cout<<prompt;
    getch();
}

MyException::MyException(string _name, string _msg, Date &_date)
{
    name = _name;
    msg = _msg;
    birthday = _date;
}

MyException::MyException(string _msg)
{
    msg = _msg;
}

void MyException::LoadError()
{
    system("cls");
    time_t now;
    time(&now);
    struct tm *now_tm = localtime(&now);
    cout<<string("系统时间：")<<asctime(now_tm)
        <<string("触发异常：")<<msg<<"\n";
    helper_continue();
    exit(0);
}

void MyException::InfoError()
{
    system("cls");
    time_t now;
    time(&now);
    struct tm *now_tm = localtime(&now);
    cout<<string("系统时间：")<<asctime(now_tm)
        <<string("学生名：")<<name<<string("  生日:")<<birthday<<"\n"
        <<string("触发异常：")<<msg<<"\n";
    helper_continue();
    exit(0);
}


void MyException::SingleError()
{
    time_t now;
    time(&now);
    struct tm *now_tm = localtime(&now);
    cout<<string("系统时间：")<<asctime(now_tm)
        <<string("触发异常：")<<msg<<"\n";
    helper_continue();
}

MyException::~MyException()
{}
