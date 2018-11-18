
#ifndef Date_hpp
#define Date_hpp
#include<iostream>
using namespace std;
class Date
{
    friend ostream &operator <<(ostream &,const Date &);
    
public:
    Date();
    Date(int ,int ,int );
    Date(const Date &);
    virtual ~Date();
    bool setdate(int y,int m,int d);
    void sety(int y);
    void setm(int m);
    void setd(int d);
    bool check(int y,int m,int d);
    int gety() const ;
    int getm() const ;
    int getd() const ;
    bool isLeapYear(int y);
    void nextDay(int &y,int &m,int &d);
    int maxDay(int y,int m,int d);
    //void print() const;
    Date& operator ++();
    Date operator ++(int);
    protected:
private:
    int year,month,day;
};

#endif /* Date_hpp */
