#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse()
{
	SetName("Unknown");
	SetCreditHour(0);
	SetMark(0);
}

ObligatoryCourse::ObligatoryCourse(std::string input_name, const int input_credit_hour, const int input_mark)
{
	SetName(input_name);
	SetCreditHour(input_credit_hour);
	SetMark(input_mark);
}

ObligatoryCourse& ObligatoryCourse::SetMark(const int input_mark)
{
	mark = input_mark;
	return *this;
}

const int ObligatoryCourse::GetScore() const
{
	return mark;
}