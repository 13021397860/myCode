#pragma once
#include <string>
#include <fstream>
#include "Base.h"
class Course:virtual public Base
{
public:
	virtual int classID() const;
	explicit Course(const std::string &nameOfCourse,int credit);
	Course(const Course &T);
	virtual void getName(std::string &nameOfCourse)const;
	virtual void getCreditHour(int &credit)const;
	virtual void changeName(const std::string &new_nameOfCourse);
	virtual void changeCredit(int new_credit);
	virtual int getScore() const = 0;
	friend std::ostream& operator << (std::ostream& output_course, const Course& course);
	friend std::ofstream& operator <<(std::ofstream& outputf_course, const Course& course);
	virtual ~Course();
private:
	std::string name;
	int creditHour;
	static const int ClassID = 031521;
};

