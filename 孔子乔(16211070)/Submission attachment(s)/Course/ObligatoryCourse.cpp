#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse()
{
    Mark = -1;
}

ObligatoryCourse::ObligatoryCourse(const int _mark)
{
    Mark = _mark;
}

ObligatoryCourse::ObligatoryCourse(const ObligatoryCourse &another)
{
    Mark = another.Mark;
    Name = another.Name;
    CreditHour = another.CreditHour;
}

void ObligatoryCourse::setmark(const int _mark)
{
    Mark = _mark;
}

int ObligatoryCourse::getmark()const
{
    return Mark;
}

int ObligatoryCourse::getscore()const
{
    return this->getmark();
}

ObligatoryCourse::~ObligatoryCourse()
{
    // nothing needs to be done here.
}
