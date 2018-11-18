#include "Course.h"
#include "MyException.h"
Course::Course()
{
    //ctor
}

Course::~Course()
{
    //dtor
}

Course::Course(const string _name, const int _creditHour){
    name = _name;
    creditHour = _creditHour;
}

Course::Course(const Course &c){
    name = c.name;
    creditHour = c.creditHour;
}

const string& Course::getName() const{
    return name;
}

void Course::getCreditHour(int &_creditHour) const{
    _creditHour = creditHour;
}

void Course::setName(string _name){
    name = _name;
}

void Course::setCreditHour(int _creditHour){
    creditHour = _creditHour;
}

//重载 <<
ostream& operator <<(ostream &os, const Course &c){
    //os << "课程名：" << c.name << "学分:" << c.creditHour << endl;
    os << "课程名：";
    os << c.name;
    os << " 学分：";
    os << c.creditHour;
    os << " 成绩: ";
    os << c.getScore() << endl;
    return os;
}
