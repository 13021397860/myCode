#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;
class date
{
    public:
        date( int = 1, int = 1, int = 2000);
        date( const date& d);
        virtual ~date();
        bool isLeapYear();
        void nextDay();
        int getYear()const;
        int getMonth()const;
        int getDay()const;
        void setDate(int ,int ,int);
        void setYear( int );
        void setDay( int );
        void setMonth( int );
        bool judgeInput();
        int judgeMonth(int);

        friend ostream& operator<<(ostream& out,const date& c){
            out<<c.year<<"-"<<c.month<<"-"<<c.day;
            return out;
        }
        friend date& operator++(date&);
        friend date operator++(date&,int);

    protected:

    private:
        int month;
        int day;
        int year;
};

#endif // DATE_H
