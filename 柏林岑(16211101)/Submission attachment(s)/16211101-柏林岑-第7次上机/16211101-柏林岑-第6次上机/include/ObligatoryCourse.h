#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include<string>
#include"Course.h"
using namespace std;
class ObligatoryCourse:public Course
{
	public:
	ObligatoryCourse();
	~ObligatoryCourse();
	ObligatoryCourse(const string ,const int);
	void setScore(const int);
	int getScore()const;
	private:
	int mark;
};

#endif // OBLIGATORYCOURSE_H
