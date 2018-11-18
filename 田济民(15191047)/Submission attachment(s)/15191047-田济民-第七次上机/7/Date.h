#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;

class Date
{
public:
    Date();                                     //构造函数
    Date(int y,int m,int d);                    //构造函数
    Date(const Date&c);                        //拷贝构造函数
    virtual ~Date();
    bool isLeapYear();                          //判断是否是闰年
    void nextDay();                             //输出后一天
    //  void print();                               //输出日期
    void setDate(int year,int month,int day);   //设置日期
    //  void showDate();
    int getYear();                              //返回年份
    int getMonth();                             //返回月份
    int getDay();                               //返回日子
    Date& operator ++ ();                       //++Date,日子+1天
    Date operator ++ (int);                     //Date++
    friend ostream& operator<<(ostream& os,const Date& d)//重载流
    {
        os<<d.year<<"-"<<d.month<<"-"<<d.day<<"\n";
        return os;
    }
protected:

private:
    int year;
    int month;
    int day;

};

#endif // DATE_H
