#include <iostream>
#include <string>
#include "electiveCourse.h"
#include "course.h"

electiveCourse::electiveCourse()
{

}
electiveCourse::electiveCourse(const string _name,const int _hour)
{
    this->setName(_name);
    this->setHour(_hour);
}
void electiveCourse::setGrade(char _grade)
{
    grade=_grade;
}
int electiveCourse::getScore()
{
    switch (grade)
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
    }
}
