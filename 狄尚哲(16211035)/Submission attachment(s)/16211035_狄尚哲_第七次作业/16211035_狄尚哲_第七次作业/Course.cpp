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

//���� <<
ostream& operator <<(ostream &os, const Course &c){
    //os << "�γ�����" << c.name << "ѧ��:" << c.creditHour << endl;
    os << "�γ�����";
    os << c.name;
    os << " ѧ�֣�";
    os << c.creditHour;
    os << " �ɼ�: ";
    os << c.getScore() << endl;
    return os;
}
