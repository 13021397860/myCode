#include "Course.h"
#include "ElectiveCourse.h"
#include<iostream>
using namespace std;

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}

void ElectiveCourse::setGrade(char gra)
{
    grade=gra;
}

int ElectiveCourse::getScore()
{
    switch(grade){
    case 'A':
        return 95;
    case 'B':
        return 85;
    case 'C':
        return 75;
    case 'D':
        return 65;
    case 'E':
        return 55;
    default:
        throw MyException(score);
        return 0;
    }
}
