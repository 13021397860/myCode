#include <iostream>

#include "Course.h"

using namespace std;

Course::Course() :name("Unknown"), credit_hour(0) {}

Course::Course(const string input_name, const int input_credit_hour) : name(input_name), credit_hour(input_credit_hour) {}

Course::~Course(){}

const std::string Course::GetName() const
{
	return name;
}

const int Course::GetCreditHour() const
{
	return credit_hour;
}

Course& Course::SetName(const std::string input_name)
{
	name = input_name;
	return *this;
}

Course& Course::SetCreditHour(const int input_credit_hour)
{
	credit_hour = input_credit_hour;
	return *this;
}

ostream& operator<<(ostream &output, const Course &c)
{
	output << "Course Name: " << c.name << ", Credit Hour: " << c.credit_hour << ", Grade: " << c.GetScore();
	return output;
}