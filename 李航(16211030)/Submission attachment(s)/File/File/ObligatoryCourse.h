#pragma once
#include "Course.h"
#include <string>
#include "Base.h"
class ObligatoryCourse: public Course, virtual public Base
{
public:
	virtual int classID() const;
	explicit ObligatoryCourse(const std::string OCourseName, int credit);
	ObligatoryCourse(const ObligatoryCourse &T);
	~ObligatoryCourse();
	virtual void setMark(int new_mark);
	virtual int getScore()const;
private:
	int mark;
	bool ifMark;
	static const int ClassID = 150212;
};

