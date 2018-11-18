#ifndef OBLIGATORYCOURSE_H_
#define OBLIGATORYCOURSE_H_
#include"course.h"
#include"MyException.h"
#include<string>
#include<iostream>
using namespace std;
class obligatorycourse : public course
{
private:
	int grade;
public:
	obligatorycourse();
	obligatorycourse(char *ch, int x, int m=-1);
	obligatorycourse(string s, int x, int m=-1);
	obligatorycourse(const course &x, int m=-1);
	~obligatorycourse();
	void setgrade(int x=90);
	bool type() const { return 1; }
	int getscore() const { return grade; }
	friend ostream &operator<<(ostream &os, const obligatorycourse &t);
};
#endif
