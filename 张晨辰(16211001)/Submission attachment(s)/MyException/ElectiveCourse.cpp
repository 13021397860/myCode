#include "ElectiveCourse.h"
#include "MyException.h"

using namespace std;

ElectiveCourse::ElectiveCourse(string na,int credit,char score) : Course(na,credit)
{
    setScore(score);
}
void ElectiveCourse::setScore(char score)
{
    switch (score)
    {
    case 'A':
        grade=95;
        break;
    case 'B':
        grade=85;
        break;
    case 'C':
        grade=75;
        break;
    case 'D':
        grade=65;
        break;
    case 'E':
        grade=55;
        break;
    default:
        throw
            MyException(SCORE_INVALID);
        break;
    }
}
int ElectiveCourse::getScore()const
{
    return grade;
}
ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
