#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;

class Date
{
public:
    Date();                                     //���캯��
    Date(int y,int m,int d);                    //���캯��
    Date(const Date&c);                        //�������캯��
    virtual ~Date();
    bool isLeapYear();                          //�ж��Ƿ�������
    void nextDay();                             //�����һ��
    //  void print();                               //�������
    void setDate(int year,int month,int day);   //��������
    //  void showDate();
    int getYear();                              //�������
    int getMonth();                             //�����·�
    int getDay();                               //��������
    Date& operator ++ ();                       //++Date,����+1��
    Date operator ++ (int);                     //Date++
    friend ostream& operator<<(ostream& os,const Date& d)//������
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
