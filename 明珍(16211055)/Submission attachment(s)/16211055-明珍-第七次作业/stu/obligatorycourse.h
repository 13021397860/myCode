#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H//����

#include "course.h"
#include "MyException.h"
#define  _CRT_SECURE_NO_WARNINGS

class ObligatoryCourse : public Course
{
public:
	ObligatoryCourse(string, int);
	virtual ~ObligatoryCourse();
	 void setMark(int mark) {
	    if(mark<0 || mark >100)
            throw MyException("�ɼ��Ƿ��쳣");
		this->mark = mark;
	}
	 virtual int getScore()const {
		return mark;
	}



private:
	int mark;
};



#endif // OBLIGATORYCOURSE _H
