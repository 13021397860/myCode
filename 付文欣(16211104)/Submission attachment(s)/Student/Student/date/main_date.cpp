#include <iostream>
#include "date.h"
using namespace std;

int main()
{
    //测试程序
    cout<<"请输入年 月 日:"<<endl;
    int year,month,day;
    cin>>year>>month>>day;
    //构造函数
    date mydate(year,month,day);
    //进入下一天
    mydate.print();
    cout<<"下一天是:";
    mydate.nextDay();
    //get函数获得私有变量
    cout<<mydate.getYear()<<"."<<mydate.getMonth()<<"."<<mydate.getDay()<<endl;
    //判断是否是闰年
    if(mydate.isLeapYear()) cout<<"It's leap year\n";
    else cout<<"It isn't leap year\n";
    //set函数重新输入日期
    cout<<"请输入想修改的日期:";
    cin>>year>>month>>day;
    mydate.setDate(year,month,day);

    cout<<"当前日期为:";
    mydate.print();
    return 0;
}


