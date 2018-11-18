#include "date.h"
#include <iostream>
#include"MyException.h"
using namespace std;


istream& operator >> (istream& is,Date& date) {
	int year;
	int mon;
	int d;
	char del;
	is >> year >> del>>mon>>del>>d;

	date.setDate(year, mon, d);
	if (!date.check()) {


	}
	return is;
}

ostream& operator<<(ostream&os, const Date&date) {

	os << date.year << "-" << date.month << "-" << date.day << endl;
	return os;
}

Date& Date::operator++() {
	static int monday[2][12] = { 31,28,31,30,31,30,31,31,31,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31 };//����һ����ά���飬�������ƽ��ĸ�������������
	int allDay;
	if (isLeapyear())
	{
		allDay = monday[0][month - 1];//month֮���Լ�һ����Ϊ�����Ǵ��㿪ʼ����һ�����׺���

	}
	else
	{
		allDay = monday[1][month - 1];
	}

	if (day < allDay)
	{
		++day;
		return *this;
	}

	if (month < 12) {
		++month;
		day = 0;
		return *this;
	}

	++year;
	month = 0;
	day = 0;
	return *this;

}
Date Date::operator++(int) {
	Date bak = *this;

	static int monday[2][12] = { 31,28,31,30,31,30,31,31,31,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31 };//����һ����ά���飬�������ƽ��ĸ�������������
	int allDay;
	if (isLeapyear())
	{
		allDay = monday[0][month - 1];//month֮���Լ�һ����Ϊ�����Ǵ��㿪ʼ����һ�����׺���

	}
	else
	{
		allDay = monday[1][month - 1];
	}

	if (day < allDay)
	{
		++day;
		return bak;
	}

	if (month < 12) {
		++month;
		day = 0;
		return bak;
	}

	++year;
	month = 0;
	day = 0;
	return bak;
}

Date::Date(int y,int m,int d)
{
   year=y;
   month=m;
   day=d;
   //ctor
}

Date::Date(const Date &q)//��Ϊ�ǿ������캯��
{
    year=q.year;
    month=q.month;
    day=q.day;
}
Date::~Date()
{
    //dtor//�����Դ��������������������仰��ʱ��˵����һ�������ѱ�����
}
bool Date::setDate(int y,int m,int d)
{
    int a=year;
    int b=month;
    int c=year;
    year=y;
    month=m;
    day=d;
    if(check())
        return true;
    else
    {
     year=a;month=b;day=c;
    return false;
    }
}


bool Date::isLeapyear()const//�ж���bool��������
{
    if ((year%4==0&&year%100!=0)||year%400==0)
        return true;
    else
        return false;
}
bool Date::check()
{

    int monday[2][12]={31,28,31,30,31,30,31,31,31,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};//����һ����ά���飬�������ƽ��ĸ�������������
    if (isLeapyear())
    {
        if (day>monday[0][month-1])//month֮���Լ�һ����Ϊ�����Ǵ��㿪ʼ����һ�����׺���
            throw MyException("�Ƿ����ڸ�ʽ");
    }
    else
    {
        if(day>monday[1][month-1])
             throw MyException("�Ƿ����ڸ�ʽ");
    }
    if (year<1||month>12||month<1||day<1)
    {
		 throw MyException("�Ƿ����ڸ�ʽ");
	}

    return true;
}
void Date::nextDate()
{
    int monday[2][12]={31,28,31,30,31,30,31,31,31,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
    day++;
    if (day>monday[isLeapyear()][month-1])
    {
        month ++;
        day=1;
    }
    if (month >12)
    {
        year++;
        month=1;
    }
}
