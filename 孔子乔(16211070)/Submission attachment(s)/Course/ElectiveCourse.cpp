#include "ElectiveCourse.h"

ElectiveCourse::ElectiveCourse()
{
    Grade = '\0';
}

ElectiveCourse::ElectiveCourse(const char _grade)
{
    Grade = _grade;
}

ElectiveCourse::ElectiveCourse(const ElectiveCourse &another)
{
    Grade = another.Grade;
    Name = another.Name;
    CreditHour = another.CreditHour;
}

void ElectiveCourse::setgrade(const char _grade)
{
    Grade = _grade;
}

void ElectiveCourse::setgrade(const int score)
{
    if(score == 95)Grade = 'A';
    else if(score == 85)Grade = 'B';
    else if(score == 75)Grade = 'C';
    else if(score == 65)Grade = 'D';
    else if(score == 55)Grade = 'E';
    else if(score == 0)Grade = 'N';
    else Grade = '\0';
}

// 'N' means NULL
// '\0' means not initialized
int ElectiveCourse::getscore()const
{
    if(Grade ==  'A')return 95;
    else if(Grade == 'B')return 85;
    else if(Grade == 'C')return 75;
    else if(Grade == 'D')return 65;
    else if(Grade == 'E')return 55;
    else if(Grade == 'N')return 0;
    else return -1;
}

char ElectiveCourse::getgrade()const
{
    return Grade;
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
