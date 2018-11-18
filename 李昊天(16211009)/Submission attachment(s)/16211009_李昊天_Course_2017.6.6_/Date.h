#ifndef DATE_H
#define DATE_H

#include<string>
using namespace std;
class Date
{
    public:
        Date(int y=1970 ,int m=1,int d=1);
        Date(Date &);
        virtual ~ Date();
        void CheckDate();
        int getYear() const{return year;}
        int getMonth() const{return month;}
        int getDay() const{return day;}
        void setDate(int ,int ,int);
        bool isLeapYear();
        bool getdda() const {return da;}
        //void print();
        void nextDay();
        string toString() const;
        Date& operator ++ ();
        Date operator ++ (int);
    protected:

    private:
        bool da;
        int year;
        int month;
        int day;
        int mon[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};
        friend ostream& operator<<(ostream& os,const Date& p){
            os<<p.toString();
            return os;
        }
};

#endif // DATE_H
