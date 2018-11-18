#ifndef DATE_H
#define DATE_H

class date
{
    public:
        date(int =2000,int =1,int=1);
        date(const date &);
        int getYear()const{return year;}
        int getMonth()const{return month;}
        int getDay()const{return day;}
        void setDate(int ,int ,int );
        bool isLeapYear();
        void nextDay();
        void print()const;
        bool isLegalDate();
    protected:
    private:
        int year;
        int month;
        int day;
};

#endif // DATE_H
