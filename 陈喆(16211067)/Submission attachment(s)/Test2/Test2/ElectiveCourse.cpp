#include "ElectiveCourse.h"
#include <cstdio>


ElectiveCourse::ElectiveCourse(const string a,const int b)
{
    SetName(a);
    SetCreditHour(b);
    mark='E';
    //ctor
}
ElectiveCourse::ElectiveCourse(ElectiveCourse &A)
{
    SetName(A.GetName());
    SetCreditHour(A.GetCreditHour());
    SetMark(A.getMark());
}
ElectiveCourse::~ElectiveCourse()
{
    //dtor
}

void ElectiveCourse::SetMark(const char m)
{
    if(mark=='A'||mark=='B'||mark=='C'||mark=='D'||mark=='E')
        mark=m;
    else
        printf("Failure of mark setting!\n");
}

int ElectiveCourse::getScore()
{
    int tmp;
    switch(mark)
    {
        case 'A':tmp=95;break;
        case 'B':tmp=85;break;
        case 'C':tmp=75;break;
        case 'D':tmp=65;break;
        case 'E':tmp=55;break;
    }
    return tmp;
}

char ElectiveCourse::getMark()
{
    return mark;
}
