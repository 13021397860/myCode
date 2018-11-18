#include "ElectiveCourse.h"
#include "Course.h"
#include <iostream>
#include <cstring>
#include <typeinfo>
using namespace std;

ElectiveCourse::ElectiveCourse(){

}
ElectiveCourse::ElectiveCourse(const string na, const int cr):Course(na,cr)
{
    setcourseName(na);
    setCreditHour(cr);
    grade='G';
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}

void ElectiveCourse::setGrade(const char cla){
    grade=cla;
}
int ElectiveCourse::getscore()const{
    return getScore();
}

int ElectiveCourse::getScore()const{
    switch (grade){
    case 'A':
        return 95;
        break;
    case 'B':
        return 85;
        break;
    case 'C':
        return 75;
        break;
    case 'D':
        return 65;
        break;
    case 'E':
        return 55;
        break;
    default:
        return 0;
        break;
    }
}
