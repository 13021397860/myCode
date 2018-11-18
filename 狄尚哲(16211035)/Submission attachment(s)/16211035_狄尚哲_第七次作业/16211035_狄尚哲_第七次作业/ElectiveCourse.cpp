#include "ElectiveCourse.h"
#include "MyException.h"

ElectiveCourse::ElectiveCourse()
{
    creditHour = 0;
    grade = 'N';
    //ctor
}

ElectiveCourse::ElectiveCourse(const string _name, const int _creditHour,  const char _grade){
    name = _name;
    creditHour = _creditHour;
    grade = _grade;
}

ElectiveCourse::ElectiveCourse(const ElectiveCourse &other){
    name = other.name;
    creditHour = other.creditHour;
    grade = other.grade;
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}

void ElectiveCourse::getScore(int &_grade) const{
    switch(grade){
    case 'A':
        _grade = 95;
        break;
    case 'B':
        _grade = 85;
        break;
    case 'C':
        _grade = 75;
        break;
    case 'D':
        _grade = 65;
        break;
    case 'E':
        _grade = 55;
        break;
    case 'N':
        _grade = 0;
        break;
    }
}
const int ElectiveCourse::getScore() const{
    int _grade;
    switch(grade){
    case 'A':
        _grade = 95;
        break;
    case 'B':
        _grade = 85;
        break;
    case 'C':
        _grade = 75;
        break;
    case 'D':
        _grade = 65;
        break;
    case 'E':
        _grade = 55;
        break;
    case 'N':
        _grade = 0;
        break;
    }
    return _grade;
}

void ElectiveCourse::setScore(const char _grade){
    if(_grade>='A' && _grade<='E'){
        grade = _grade;
    }
    else throw MyException(SCORE_INVALID);
}

//重载 <<
//ostream& operator <<(ostream &os, const ElectiveCourse &c){
//    os << "课程名：" << c.name << "学分：" << c.creditHour << endl;
//    return os;
//}
