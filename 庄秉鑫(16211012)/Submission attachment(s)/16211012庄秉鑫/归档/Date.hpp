//
//  Date.hpp
//  Date
//
//  Created by Pirate Hero on 17/3/7.
//  Copyright © 2017年 mac. All rights reserved.
//

#ifndef Date_hpp
#define Date_hpp


#include <iostream>
using namespace std;


class Date{
public :
    int year;
    int month;
    int day;
    

    int Month,Year,Day;
    Date();
    Date(const Date & X);
    friend istream & operator>>(istream &in, Date &A);
    friend ostream & operator<<(ostream &out, Date &A);
    void getDate();
    void setDate();
    void nextDay();

    int Judge()const;
    bool isLeapYear()const;
    ~Date();
};
#endif /* Date_hpp */
