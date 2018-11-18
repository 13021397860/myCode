#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse()
{
    setMark(100);
}

ObligatoryCourse::ObligatoryCourse(const std::string& nawa) : Course(nawa)
{
    setMark(100);
}

ObligatoryCourse::ObligatoryCourse(const std::string& nawa, const int& CH) : Course(nawa,CH)
{
    setMark(100);
}

ObligatoryCourse::ObligatoryCourse(const std::string& nawa, const int& CH, const int& score) : Course(nawa,CH)
{
    setMark(score);
}

ObligatoryCourse::ObligatoryCourse(const ObligatoryCourse& another) : Course(another)
{
    setMark(another.mark);
}

ObligatoryCourse::ObligatoryCourse(const Course& another) : Course(another)
{
    setMark(0);
}

ObligatoryCourse::~ObligatoryCourse()
{
    ;
}

bool ObligatoryCourse::setMark(const int& score) //throw(llegal_OC_Score_Exception)
{
    if(score < 0 || score > 100)
    {
        throw Illegal_OC_Score_Exception();
        return false;
    }
    else
    {
        mark = score;
        return true;
    }
}

int ObligatoryCourse::getScore() const
{
    return mark;
}
