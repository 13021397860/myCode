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
    cout<<"����������������"<<endl;
    cin>>y>>m>>d;
    date.setDate(y,m,d);;
    date.cheakDate();
    cout<<"��������:"<<endl;
    printf("%c",&name);
    stu.cheakName();
    scanf("%c",name);
    cout<<"��ʾһ�����\n";
    date.print();

    system("pause");


    return 0;
}
