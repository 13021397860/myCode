#include "ObligatoryCourse.h"
#include "MyException.h"
ObligatoryCourse::ObligatoryCourse()
{
    creditHour = 0;
    mark = 0;
    //ctor
}

ObligatoryCourse::ObligatoryCourse(const string _name, const int _creditHour, const int _mark){
    name = _name;
    creditHour = _creditHour;
    mark = _mark;
}

ObligatoryCourse::ObligatoryCourse(const ObligatoryCourse &other){
    name = other.name;
    creditHour = other.creditHour;
    mark = other.mark;
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}

void ObligatoryCourse::setScore(const int _mark){
    if(_mark>=0 && _mark<=100){
        mark = _mark;
    }
    else{
        throw MyException(SCORE_INVALID);
    }
}

void ObligatoryCourse::getScore(int &_mark) const{
    _mark = mark;
}
const int ObligatoryCourse::getScore() const{
    return mark;
}
//重载 <<
//ostream& operator <<(ostream &os, const ObligatoryCourse &c){
//    os << "课程名：" << c.name << "学分：" << c.creditHour << endl;
//    return os;
//}
