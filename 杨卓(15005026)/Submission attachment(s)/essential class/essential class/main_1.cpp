#include <iostream>
#include "Date.h"
#include <cstdlib>
using namespace std;

int main()
{
    Date date;
    int y,m,d,year,month,day;
    cout<<"����������������"<<endl;
    cin>>y>>m>>d;
    date.setDate(y,m,d);
    date.cheakDate();
    cout<<"get��������"<<endl;
    year=date.getYear();
    month=date.getMonth();
    day=date.getDay();
    cout<<year<<"��"<<month<<"��"<<day<<"��"<<endl;
    cout<<"��һ���ǲ�������\n";
    if(date.isLeepYear()==1) {cout<<"The answer is yes"<<endl;}
    if(date.isLeepYear()==0) {cout<<"The answer is no"<<endl;}
    cout<<"��ʾһ�����\n";
    date.print();
    cout<<"��һ��nextday��\n";
    date.nextDay();
    date.print();
    cout<<"���� Date t1(2000,2,28)"<<endl;
    Date t1(2000,2,28);
    date.cheakDate();
    t1.print();
    cout<<"���� Date t2(t1)"<<endl;
    Date t2(t1);
    t2.print();
    cout<<"cees Date t3=t1"<<endl;
    Date t3=t1;
    t3.print();
    system("pause");


    return 0;
}
