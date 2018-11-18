#pragma once
#include"Course.h"

class ElectiveCourse : public Course
{
public:
	ElectiveCourse();
	ElectiveCourse(std::string input_name, const int input_credit_hour, const int input_grade);
	ElectiveCourse& SetGrade(const char input_grade);
	ElectiveCourse& SetGrade(const int input_grade);
	virtual const int GetScore() const;
private:
	char grade;
};