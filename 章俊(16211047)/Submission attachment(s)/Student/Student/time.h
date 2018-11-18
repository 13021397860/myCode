#ifndef TIME_H
#define TIME_H
#include <iostream>
using std::ostream;
using std::istream;
class Time
{
    public:
        Time(const int ,const int ,const int );
        Time();
        Time(const Time &);
        virtual ~Time();
        void setTime(const int ,const int ,const int);
        void setyear(const int);
        void setmonth(const int);
        void setday(const int);
        int getyear()const ;
        int getmonth()const ;
        int getday()const ;
        bool isLeapyear()const ;
        void nexDay();
        int check(const int y,const int m,const int d)const;

        friend ostream& operator << (ostream&,Time &t);
        friend istream& operator >> (istream& ,Time &t);

        Time& operator ++ ();
        Time& operator ++ (int);//∫Û÷√++
    protected:
    private:
        int year;
        int month;
        int day;
};

#endif // TIME_H
