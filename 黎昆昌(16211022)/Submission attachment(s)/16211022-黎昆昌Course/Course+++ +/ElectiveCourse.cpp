#include "ElectiveCourse.h"

ElectiveCourse::ElectiveCourse(const string s,
    const int n,const int c) : Course(s,n)
{
    setScore(c);
}

void ElectiveCourse::setScore(const int &c)
{
    if(c>=95){
        grade='A';
    }
    else if(c>=85){
        grade='B';
    }
    else if(c>=75){
        grade='C';
    }
    else if(c>=65){
        grade='D';
    }
    else if(c>0){
        grade='E';
    }
    else{
        grade='F';
    }
}

int ElectiveCourse::getScore() const
{
    int score;
    switch(grade){
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
    default:
        score=0;
        break;
    }
    return score;
}


ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
