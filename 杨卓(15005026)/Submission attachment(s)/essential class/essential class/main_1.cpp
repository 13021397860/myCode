#include <iostream>
#include "Date.h"
#include <cstdlib>
using namespace std;

int main()
{
    Date date;
    int y,m,d,year,month,day;
    cout<<"快点输入你的年月日"<<endl;
    cin>>y>>m>>d;
    date.setDate(y,m,d);
    date.cheakDate();
    cout<<"get函数测试"<<endl;
    year=date.getYear();
    month=date.getMonth();
    day=date.getDay();
    cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
    cout<<"看一下是不是闰年\n";
    if(date.isLeepYear()==1) {cout<<"The answer is yes"<<endl;}
    if(date.isLeepYear()==0) {cout<<"The answer is no"<<endl;}
    cout<<"演示一下输出\n";
    date.print();
    cout<<"看一下nextday吧\n";
    date.nextDay();
    date.print();
    cout<<"测试 Date t1(2000,2,28)"<<endl;
    Date t1(2000,2,28);
    date.cheakDate();
    t1.print();
    cout<<"测试 Date t2(t1)"<<endl;
    Date t2(t1);
    t2.print();
    cout<<"cees Date t3=t1"<<endl;
    Date t3=t1;
    t3.print();
    system("pause");


    return 0;
}
