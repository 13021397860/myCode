#pragma once
#include<string>

class Course
{
	friend std::ostream& operator<<(std::ostream& output, const Course &c);

public:
	Course();
	Course(const std::string input_name, const int input_credit_hour);
	virtual ~Course();
	const std::string GetName() const;
	const int GetCreditHour() const;
	Course& SetName(const std::string input_name);
	Course& SetCreditHour(const int input_credit_hour);
	virtual const int GetScore() const = 0;

private:
	std::string name;
	int credit_hour;
};