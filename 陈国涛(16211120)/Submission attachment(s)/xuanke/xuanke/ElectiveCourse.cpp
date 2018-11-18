#include "ElectiveCourse.h"
#include <iostream>
using namespace std;
ElectiveCourse::ElectiveCourse(string newname, int credit) :Course(newname, credit)
{
    //ctor
}

ElectiveCourse::ElectiveCourse(const ElectiveCourse &a) :Course(a.name, a.creditHour)
{
}

void ElectiveCourse::setScore(int score , char newgrade ) throw(MyException)
{
    if(newgrade < 'A' || newgrade > 'E')
    {
        MyException course(3);
        grade = 'E';
        throw course;
    }
    grade = (newgrade >= 'A' && newgrade <= 'E')? newgrade:'E';
}

int ElectiveCourse::getScore()const
{
    switch(grade)
    {
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
        return 55;
    }
}
const void ElectiveCourse::print()
{
    cout << " ³É¼¨£º"<<getScore()<<endl;
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
