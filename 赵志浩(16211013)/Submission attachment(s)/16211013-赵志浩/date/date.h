#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>
using namespace std;
class date
{
    public:
        date(int=1,int=1,int=1990);
        date(const date&);
        virtual ~date();
        bool isLeapYear() const;
        int getYear() const;
        int getMonth() const;
        int getDay() const;
        void nextDay();
        bool setdate(int,int,int);
        string toString() const;
        friend ostream& operator << (ostream& out,const date& d)
        {
            out<<d.getYear()<<"-"<<d.getMonth()<<"-"<<d.getDay();
            return out;
        }
        date& operator ++()
        {
            this->nextDay();
            return *this;
        }
        date operator ++(int)
        {
            date before=*this;
            this->nextDay();
            return before;
        }
    protected:
    private:
        int year;
        int month;
        int day;
        bool yearLegal(int) const;
        bool monthLegal(int) const;
        bool yearLegal() const;
        bool monthLegal() const;
        bool dayLegal() const;
        bool dayLegal(int,int,int) const;
        static const int calendar[13];
};

#endif // DATE_H
