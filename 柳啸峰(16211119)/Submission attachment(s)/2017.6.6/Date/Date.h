#ifndef DATE_H
#define DATE_H
#include <iostream>
//#include "MyException.h"
using namespace std;
class Date
{
    public:
        Date();
        Date(int ,int ,int );//传入年月日 
        Date(const Date &);//拷贝构造 
        inline friend ostream& operator<< (ostream&o,const Date &t )//o代替cout ,inline是否可以删除？ 
        {
			o<<t.getYear()<<"-"<<t.getMonth()<<"-"<<t.getDay();
			return o;//返回值为ostream类型 ,方便连续使用<<(cout<<...<<...<<...)第一次调用时，o=cout 
		}
		/*inline friend istream& operator >> (istream& i, Date &t)//i代替cin 
		{
     		i >> t._a;
     		return i;
		}*/
		Date& operator ++()//++a 引用传递 (--)
		{
			Date before = *this; 
			this->nextDay();
			return *this;
		}
		Date operator ++(int )//a++ ,值传递！！！(--) 
		{
			Date before = *this; 
			this->nextDay();
			return before;
		}
        int  getYear()const;
        int  getMonth()const;
        int  getDay()const;
        void setTime(int, int, int);
        bool isLeapYear()const;//判断闰年，用const 
        void nextDay();
        //void print()const;
        ~Date();
    private:
        int year, month, day;
};


#endif
