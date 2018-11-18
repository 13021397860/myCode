#include <iostream>
using namespace std;
#include "ElectiveCourse.h"

int ElectiveCourse::getScore()const
{
    switch(grade)
    {
        case 'A':    return 95;
        case 'B':    return 85;
        case 'C':    return 75;
        case 'D':    return 65;
        case 'E':    return 55;
    }
}

ElectiveCourse::ElectiveCourse(string n,int c,char g):Course(n,c)
{
    grade=g;
}
void ElectiveCourse::CoursePrint()const{
    cout<<getName()<<" "<<getcreditHour()<<" "<<getScore()<<endl;
}

/*
ElectiveCourse:: ElectiveCourse(Course c,char g)
{
    name=c.getName();
    creditHour=c.getcreditHour();
    grade=g;
}
*/
