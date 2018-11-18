#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse()
{
	
} 
ObligatoryCourse::ObligatoryCourse(const string theName,const int theCreditHour)
:Course(theName,theCreditHour)
{
	mark=-1;
}

void ObligatoryCourse::setScore(const int score)
{
	mark=score;
}

int ObligatoryCourse::O_credit() const
{
	return this->getCreditHour();
}

int ObligatoryCourse::if_E() const
{
	return 0;
}

int ObligatoryCourse::getScore() const
{
	return mark;
}


