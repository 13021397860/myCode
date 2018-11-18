#ifndef DATE_H
#define DATE_H
#include <iostream>
//#include "MyException.h"
using namespace std;
class Date
{
    public:
        Date();
        Date(int ,int ,int );//���������� 
        Date(const Date &);//�������� 
        inline friend ostream& operator<< (ostream&o,const Date &t )//o����cout ,inline�Ƿ����ɾ���� 
        {
			o<<t.getYear()<<"-"<<t.getMonth()<<"-"<<t.getDay();
			return o;//����ֵΪostream���� ,��������ʹ��<<(cout<<...<<...<<...)��һ�ε���ʱ��o=cout 
		}
		/*inline friend istream& operator >> (istream& i, Date &t)//i����cin 
		{
     		i >> t._a;
     		return i;
		}*/
		Date& operator ++()//++a ���ô��� (--)
		{
			Date before = *this; 
			this->nextDay();
			return *this;
		}
		Date operator ++(int )//a++ ,ֵ���ݣ�����(--) 
		{
			Date before = *this; 
			this->nextDay();
			return before;
		}
        int  getYear()const;
        int  getMonth()const;
        int  getDay()const;
        void setTime(int, int, int);
        bool isLeapYear()const;//�ж����꣬��const 
        void nextDay();
        //void print()const;
        ~Date();
    private:
        int year, month, day;
};


#endif
