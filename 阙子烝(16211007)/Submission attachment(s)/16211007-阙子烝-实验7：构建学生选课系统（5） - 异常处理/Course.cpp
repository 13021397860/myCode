#include <string>
#include <iostream>
#include <fstream>
#include "Course.h"

Course::Course(const std::string s,const int c)
{
	setCourse(s,c);
}

Course::~Course()
{
}

void Course::setCourse(const std::string s,const int c)
{
	name=s;
	creditHour=c;
}

void Course::setName(const std::string s)
{
	name=s;
}

void Course::setCreditHour(const int c) 
{
	creditHour=c;
}

std::string Course::getName() const
{
	return name;
}

int Course::getCreditHour() const
{
	return creditHour;
}

//int Course::getScore() const{}

void Course::setScore(const int s){}

std::ostream& operator<<(std::ostream& output,const Course& c)
{
	output<<"课程名："<<c.getName()<<" 学分："<<c.getCreditHour()<<"成绩："<<c.getScore();
	return output;
}

std::ofstream& operator<<(std::ofstream& output,const Course& c)
{
	output<<"课程名："<<c.getName()<<" 学分："<<c.getCreditHour()<<"成绩："<<c.getScore();
	return output;
}

