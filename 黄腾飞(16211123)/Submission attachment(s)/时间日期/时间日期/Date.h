#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class Date
{
	public:
	    Date(); //���캯���� 
	    Date(int ,int ,int ) ;//���캯���� 
	    Date ( const Date&);//�������캯����
	     ~Date(); 
		int  getYear()const;
		int  getMonth()const;
		int  getDay()const;
		void setYear(int);
		void setMonth(int);
		void setDay(int);
		bool isLeapYear();//�Ƿ����ꣻ 
		void nextDay();//��һ�죻  
		bool checkLegal();//���Ϸ��ԣ� 
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

