#pragma once

#ifndef OBLIGATORY_H
#define OBLIGATORY_H

#include "MyException.h"
#include "Course.h"
class ObligatoryCourse : public Course {
private:
	int mark;
public:
	ObligatoryCourse(const string &n = "", int h = 0);
	ObligatoryCourse(const Course &a);
	virtual ~ObligatoryCourse();
	//∂‡Ã¨
	virtual int getElectiveCredit() const {
		return 0;
	}
	virtual int getObligatoryNumber() const {
		return 1;
	}
	//
	void setMark(int m) {
		if (m < 0 || m > 100) throw MyException(Score_invalid);
		mark = m;
	}
	virtual int getScore() const {
		return mark;
	}
};

#endif // !OBLIGATORY_H