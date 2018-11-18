#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H//选修

#include "Course.h"
#include "MyException.h"

#define  _CRT_SECURE_NO_WARNINGS
class ElectiveCourse : public Course
{
public:

	ElectiveCourse(string, int);
	virtual ~ElectiveCourse();
	 void setGrade(char grade) {
	       if(grade<0 || grade >100)
            throw MyException("成绩非法异常");
		this->grade = grade;
	}
	 char getGrade() const { return grade; }
	virtual int  getScore()const;
protected:

private:
	char grade;

};

#endif // ELECTIVECOURSE _H
