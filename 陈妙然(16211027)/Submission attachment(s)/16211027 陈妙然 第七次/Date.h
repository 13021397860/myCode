#ifndef DATE_H
#define DATE_H
#include <iomanip>
#include <iostream>
using namespace std;
class Date
{
    public:
        friend ostream &operator<<(ostream &,const Date &);
        Date& operator ++();
        Date operator++(int);
        Date(int =1,int =1,int =2000);
        Date(const Date &OtherDate);
        virtual ~Date();
        void setDate(int,int,int);
        int getDatemonth()const;
        int getDateday()const;
        int getDateyear()const;
        bool isLeapYear(int,int,int)const;
        bool legis()const;
        void nextDay();
        void printdate()
        {
            cout<<year<<"  "<<month<<"   "<<day<<"   "<<endl;
        }
        //void print()const;

    protected:

    private:
        int month;
        int day;
        int year;
};

#endif // DATE_H
