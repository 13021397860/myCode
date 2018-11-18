#include "ElectiveCourse.h"
#include <iostream>
#include "Course.h"
using namespace std;
ElectiveCourse::ElectiveCourse(){

}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
void ElectiveCourse::setgrade(char grades){
    grade=grades;

}
int  ElectiveCourse::getScore() const{
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
            return 0;
    }

}
