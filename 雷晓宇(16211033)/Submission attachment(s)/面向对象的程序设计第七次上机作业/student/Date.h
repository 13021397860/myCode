#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class Date
{
    public:
    	Date(Date &);
        Date(int=1,int=1,int=1);
        virtual ~Date();
        int getYear() const;
        int getMonth() const;
        int getDay() const;
        bool judge();
        void setDate(int y,int m,int d);
        bool isLeapYear();
        void nextDay();
        friend ostream& operator<<(ostream& output,const Date& p);
		Date& operator ++ ();
        Date operator ++ (int);


    protected:

    private:
        int year;
        int month;
        int day;
};

#endif // DATE_H
