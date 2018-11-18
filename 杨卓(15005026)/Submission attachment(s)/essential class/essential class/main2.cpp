#include <iostream>
#include <cstdio>
#include "Date.h"
#include "student.h"
#include <cstdlib>
using namespace std;

int main()
{
    Date date;
    student stu[];
    int y,m,d,year,month,day;
    char * name=new char[500];
    cout<<"快点输入你的年月日"<<endl;
    cin>>y>>m>>d;
    date.setDate(y,m,d);;
    date.cheakDate();
    cout<<"输入名字:"<<endl;
    printf("%c",&name);
    stu.cheakName();
    scanf("%c",name);
    cout<<"演示一下输出\n";
    date.print();

    system("pause");


    return 0;
}
