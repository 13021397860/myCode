#ifndef DATE_H
#define DATE_H
#include<string>
using namespace std;
class Date
{
    friend ostream& operator<<(ostream& os,const Date& d)
    {
        os<<d.getYear()<<"-"<<d.getMonth()<<"-"<<d.getDay()<<endl;
        return os;
    }
    public:
        Date(int,int,int);
        ~Date();
        Date(const Date &);
        void setDate(int,int,int);
        static int islegal(int,int,int);
        int getMonth()const;
        int getDay()const;
        int getYear()const;
        static bool isLeapYear(int);
        void nextDay();
        //Ç°ÖÃ
        Date &operator ++()
        {
            this->nextDay();
            return *this;
        }
        //ºóÖÃ
        Date &operator ++(int)
        {
            Date temp=*this;
            this->nextDay();
            return temp;
        }
    private:
        int year;
        int month;
        int day;
};
#endif // DATE_H
