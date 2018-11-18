#include "ElectiveCourse.h"

ElectiveCourse::ElectiveCourse()
{
	SetName("Unknown");
	SetCreditHour(0);
	SetGrade(0);
}

ElectiveCourse::ElectiveCourse(std::string input_name, const int input_credit_hour, const int input_grade)
{
	SetName(input_name);
	SetCreditHour(input_credit_hour);
	SetGrade(input_grade);
}

ElectiveCourse& ElectiveCourse::SetGrade(const char input_grade)
{
	grade = input_grade;
	return *this;
}

ElectiveCourse& ElectiveCourse::SetGrade(const int input_grade)
{
	grade = char('E' - (input_grade - 55) / 10);
	return *this;
}

const int ElectiveCourse::GetScore() const
{
	return 55 + ('E' - grade) * 10;
}