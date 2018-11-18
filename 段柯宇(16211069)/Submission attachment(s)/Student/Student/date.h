#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;

class Date
{
    public:
        Date( int = 1900,int = 1,int = 1);
        ~Date();
        Date(Date&);
        int getyear()const{return year;}
        int getmonth()const{return month;}
        int getday()const{return day;}
        int Set(int x,int y,int z);
        int setyear(int x){
            year = x;
            check();
            return 1;
        }
        int setmonth(int x){
            month = x;
            check();
            return 1;
        }
        int setday(int x){
            day = x;
            check();
            return 1;
        }
        bool isLeapYear();
        void nextDay();
        friend ostream& operator << (ostream&, const Date&);
        Date& operator ++ (int);
        Date& operator ++ ();

    protected:
        int year;
        int month;
        int day;
        bool check();
    private:

};

#endif // DATE_H
