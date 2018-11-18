#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class date
{
    friend ostream &operator<<(ostream&,const date &);
	private:
		int year;
		int month;
		int day;
	public:
	    date();
	    date(const date&);
	    ~date();
	    date(int =1998,int=10,int =25);
		int getyear()const;
		int getmonth()const;
		int getday()const;
		void setdate(int,int,int);
		bool isleapyear()const;
		date operator ++(int);
		//void nextday(int,int,int)const;
		void print_ymd()const;

	protected:
};

#endif
