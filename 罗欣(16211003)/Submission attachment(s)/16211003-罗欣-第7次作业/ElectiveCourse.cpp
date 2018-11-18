#include "ElectiveCourse.h"
#include<iostream>
using namespace std;

ElectiveCourse::ElectiveCourse()
{
    //ctor
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}

void ElectiveCourse::setmark(const int c)
{
    if(c>=95)
        grade='A';
    else if(c>=85 && c<95)
        grade='B';
    else if(c>=75 && c<85)
        grade='C';
    else if(c>=65 && c<75)
        grade='D';
    else if(c<65)
        grade='E';
    switch(grade)
    {
    case 'A':
        score=95;
        break;
    case 'B':
        score=85;
        break;
    case 'C':
        score=75;
        break;
    case 'D':
        score=65;
        break;
    case 'E':
        score=55;
        break;
    }
}


int ElectiveCourse::getScore()const
{
    return score;
}
