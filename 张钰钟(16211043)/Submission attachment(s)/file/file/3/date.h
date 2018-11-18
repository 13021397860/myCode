#ifndef DATE_H
#define DATE_H


class Date
{
    public:
        Date();
        Date(int,int,int);
        Date(Date& date);
        virtual ~Date();


        void setDate(int,int,int);
        bool isLeapYear(int);
        //void print();
        void nextDay();
        int getDateYear();
        int getDateMonth();
        int getDateDay();
        Date operator << (Date &d);
        Date& operator ++ ();
        Date operator ++ (int);


    protected:
    private:
        int year;
        int month;
        int day;
};

#endif // DATE_H
