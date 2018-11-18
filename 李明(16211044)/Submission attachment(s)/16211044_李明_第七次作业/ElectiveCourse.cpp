#include "ElectiveCourse.h"

const int ElectiveCourse::gradeToScore[5] = {95,85,75,65,55};

ElectiveCourse::ElectiveCourse()
{
    setGrade('A');
}

ElectiveCourse::ElectiveCourse(const std::string& nawa) : Course(nawa)
{
    setGrade('A');
}

ElectiveCourse::ElectiveCourse(const std::string& nawa, const int& CH) : Course(nawa,CH)
{
    setGrade('A');
}

ElectiveCourse::ElectiveCourse(const std::string& nawa, const int& CH, const char& score) : Course(nawa,CH)
{
    setGrade(score);
}

ElectiveCourse::ElectiveCourse(const ElectiveCourse& another) : Course(another)
{
    setGrade(another.grade);
}

ElectiveCourse::ElectiveCourse(const Course& another) : Course(another)
{
    setGrade('A');
}

ElectiveCourse::~ElectiveCourse()
{
    ;
}

bool ElectiveCourse::setGrade(const char& score) //throw(Illegal_EC_Score_Exception)
{
    if(score > 'E' || score < 'A')
    {
        throw Illegal_EC_Score_Exception();
        return false;
    }
    else
    {
        grade = score;
        return true;
    }
}

int ElectiveCourse::getScore() const
{
    return gradeToScore[grade - 'A'];
}
