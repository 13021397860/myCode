#include "ElectiveCourse.h"

ElectiveCourse::ElectiveCourse(const string _name,int _creditHour):Course(_name,_creditHour)
{
    grade = 'E';
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
int ElectiveCourse::setgrade(char _grade){
    if(_grade<'A' || _grade >'E') throw -2;
    grade = _grade;
    return 1;
}
int ElectiveCourse::setgrade(int _grade){
    if(_grade == 95) grade = 'A';
    else if(_grade == 85) grade = 'B';
    else if(_grade == 75) grade = 'C';
    else if(_grade == 65) grade = 'D';
    else grade = 'E';
    return 1;
}
int ElectiveCourse::getscore() const{
    if(grade == 'A') return 95;
    else if(grade == 'B') return 85;
    else if(grade == 'C') return 75;
    else if(grade == 'D') return 65;
    else if(grade == 'E') return 55;
    return 0;
}
