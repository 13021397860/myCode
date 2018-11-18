#ifndef ELECTIVECOURSE_H_
#define ELECTIVECOURSE_H_
#include"course.h"
#include<string>
#include<iostream>
using namespace std;
class electivecourse : public course
{
private:
	char grade;
public:
	electivecourse();
	electivecourse(char *ch, int x, char m = 'F');
	electivecourse(string s, int x, char m = 'F');
	electivecourse(const course &x, char m = 'F');
	~electivecourse();
	bool type() const { return 0; }
	void setgrade(char ch) { grade = ch; }
	int getscore() const;
	friend ostream &operator<<(ostream &os, const electivecourse &t);
};
#endif
