#include "ElectiveCourse.h"
#include <iostream>
using namespace std;
ElectiveCourse::ElectiveCourse()
{
    grade = 'O';
    //ctor
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}

void ElectiveCourse::setScore(char a)
{
    if(a=='A'||a=='E'||a=='D'||a=='C'||a=='B')
    {
        grade = a;
    }
    else {
        cout<<"Input the wrong grade!"<<endl;
    }
}

int ElectiveCourse::getScore()const
{
    switch (grade)
    {
        case 'A':return 95;
        case 'B':return 85;
        case 'C':return 75;
        case 'D':return 65;
        case 'E':return 55;
        default:return -1;
    }
}
