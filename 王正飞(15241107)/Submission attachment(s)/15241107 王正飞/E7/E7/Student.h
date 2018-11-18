#pragma once
#include <string>

#include "Time.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"

#define MaxCourse 100

class Student: public Time
{
	friend std::ostream& operator<<(std::ostream& output, Student &s);

public:
	Student();
	Student(const std::string input_name, const int input_year, const int input_month, const int input_date);
	Student(const Student &copy_student);
	virtual ~Student();
	Student& SetName(const std::string input_name);
	Student& SetBirthday(Time t);
	Student& SetBirthday(const int input_year, const int input_month, const int input_date);
	const std::string GetName() const;
	const Time GetBirthday() const;
	const int GetCourseNumber() const;
	static const int GetCount();
	Student& AddCourse(Course *input_course);
	const bool RemoveCourse(const int input_course_num);
	const bool SetCourseScore(const int input_course_num);
	const void ShowCurrentCourse();
	const void ShowCurrentCourse(std::ostream &output);
	const double CalCredit();
	const bool isCorrectBirthday() const;

private:
	std::string name;
	Time birthday;
	static int count;
	Course* courst_list[MaxCourse];
	int course_number;
};