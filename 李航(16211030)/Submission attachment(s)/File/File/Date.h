#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <fstream>
#include "Base.h"
class Date:virtual public Base
{
    public:
		virtual int classID() const;
		explicit Date(int year,int month,int day);
		Date(const Date&);
        virtual ~Date();
        virtual bool setAll(unsigned int, unsigned int, unsigned int);
        virtual unsigned int getYear()const;
        virtual unsigned int getMonth()const;
        virtual unsigned int getDay()const;
        virtual void getAll(unsigned int &Y,unsigned int &M,unsigned int &D)const;
        virtual bool isLeapYear()const;
        virtual void nextDay();
        //下面开始搞事情
        virtual bool operator== (const Date&) const;
		virtual Date& operator++ ();//前自增
		virtual Date operator++(int);
		virtual Date operator +(int days)const;
		friend std::ostream &operator << (std::ostream& output_date,const Date& date);
		friend std::istream &operator >> (std::istream& input_date, Date& date);
		friend std::ofstream &operator<< (std::ofstream& outputf_date, const Date& date);
		//virtual operator int();
    protected:

    private:
        bool rightData()const;
        unsigned int year;
        unsigned int month;
        unsigned int day;
		static const int ClassID = 040120;
};

#endif // DATE_H
