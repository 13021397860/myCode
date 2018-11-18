#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;

class Date
{
    public:
        Date();
        bool isLeapYear();
        void nextDay();
        //void print();
        int getYear();
        int getMonth();
        int getDay();
        void setDate(int, int, int);
        bool wrongDate(int, int, int);
        Date(const Date&);
        ~Date();
        friend ostream& operator<< (ostream &, const Date&);  
   	 	//friend istream& operator>> (istream &is, Date& c); 
   	 	Date& operator++ ();
		Date operator++(int);		 	

    private:
        int year;
        int month;
        int day;
};


#endif // DATE_H
