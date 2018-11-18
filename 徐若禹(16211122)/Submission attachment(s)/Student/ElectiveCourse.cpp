#include "ElectiveCourse.h"

ElectiveCourse::ElectiveCourse(string n,int c,char g) : Course(n,c)
{
    setGrade(g);
}

int ElectiveCourse::eCreditHour = 0;

void ElectiveCourse::addECreditHour(int c)
{
    eCreditHour += c;
}

int ElectiveCourse::getECreHour() const
{
    return eCreditHour;
}

void ElectiveCourse::setGrade(char g)
{
    grade = (g >= 'A' && g <= 'E')? g:'E';
}

char ElectiveCourse::getGrade() const
{
    return grade;
}

int ElectiveCourse::getScore() const
{
    switch(grade)
    {
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

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
