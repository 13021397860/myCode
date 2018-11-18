#include "ElectiveCourse.h"

ElectiveCourse::ElectiveCourse(int ch,string nam,int s) :Course(nam,ch)
{
    setscore(s);
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
void ElectiveCourse::setscore(int s)
{
    if(s>90) sorce='A';
    else if(s>80) sorce='B';
    else if(s>70) sorce='C';
    else if(s>60) sorce='D';
    else if(s>50) sorce='E';
    else sorce='F';
}
int ElectiveCourse::getscore()
{
    if(sorce=='A') return 95;
    else if(sorce=='B') return 85;
    else if(sorce=='C') return 75;
    else if(sorce=='D') return 65;
    else if(sorce=='E') return 55;
    else return 0;
}
