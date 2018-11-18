#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class Date
{
	public:
	    Date(); //构造函数； 
	    Date(int ,int ,int ) ;//构造函数； 
	    Date ( const Date&);//拷贝构造函数；
	     ~Date(); 
		int  getYear()const;
		int  getMonth()const;
		int  getDay()const;
		void setYear(int);
		void setMonth(int);
		void setDay(int);
		bool isLeapYear();//是否闰年； 
		void nextDay();//下一天；  
		bool checkLegal();//检查合法性； 
	    friend ostream &operator <<( ostream &,const Date & );
		 Date &operator ++();
		 Date operator ++( int  );
	protected:
	
	private:
		int year;
		int month;
		int day;

};

#endif

