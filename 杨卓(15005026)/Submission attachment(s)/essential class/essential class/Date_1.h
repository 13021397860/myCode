#ifndef DATE_H
#define DATE_H


class Date
{
    public:
        Date(int=1949,int=1,int=1);
        Date(Date &);
        ~Date();
        virtual ~Date();
        void printUniversal();
        void printStandard();
        void setDate(int,int,int);
        int getYear(){return year;}
        int getMonth(){return month;}
        int getDay(){return day;}
        void cheakDate();
        bool isLeepYear();
        void print();
        void nextDay();

    protected:
    private:
        int year;
        int month;
        int day;
        int monkey[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};

};

#endif // DATE_H
