#pragma once
#ifndef ELECTIVE_H
#define ELECTIVE_H

#include "MyException.h"
#include "Course.h"
class ElectiveCourse :
	public Course
{
private:
	char grade;
public:
	ElectiveCourse(const string &n = "", int h = 0);
	ElectiveCourse(const Course &a);
	virtual ~ElectiveCourse();
	//∂‡Ã¨
	virtual int getElectiveCredit() const {
		return creditHour;
	}
	virtual int getObligatoryNumber() const {
		return 0;
	}
	//
	void setGrade(char g) {
		if (g < 'A' || g > 'E')throw MyException(Score_invalid);
		grade = g;
	}
	virtual int getScore() const {
		switch (grade) {
			case 'A': return 95;
			case 'B': return 85;
			case 'C': return 75;
			case 'D': return 65;
			case 'E': return 55;
			default: return 0;
		}
	}
};


#endif // !ELECTIVE_H
