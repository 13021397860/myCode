#ifndef DATE_H
#define DATE_H

#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
class Date
{

public:

	friend istream& operator>> (istream& os,Date& date);
	friend ostream& operator<<(ostream&os,const Date&date);



	virtual ~Date();
	Date(int = 1900, int = 1, int = 1);//构造函数
	Date(const Date &);//拷贝构造函数
    int getMonth()const  { return month; }
	int getDay() const { return day; }
	int getYear() const { return year; }
	bool setDate(int y, int m, int d);
	bool isLeapyear()const;//判断闰年
	void nextDate();//递增一天，注意点为需要日满进月，月满进年

	 Date& operator++();  //重载前++；
	 Date operator++(int);//重载后++

protected:

private:
	int year;
	int month;
	int day;
    bool check();
};

#endif // DATE_H
