#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date
{
    public:
        Date();
        Date(int ,int ,int);
        Date(const Date&);
        ~Date();
        bool CheckDate();
        void setDate(const int ,const int ,const int);
        int getday() const;
        int getmonth() const;
        int getyear() const;
        bool isLeapYear();
        void nextDay();
        //void print();
        friend ostream& operator<<(ostream&, const Date&);
        Date& operator++();
        Date operator++(int);

    protected:

    private:
        int year;
        int month;
        int day;
        int maxday;
        void MaxDay();

};

#endif // DATE_H
