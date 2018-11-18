#ifndef COURSE_H_
#define COURSE_H_
#include<string>
#include<iostream>
using namespace std;
class course
{
public:
	course(char *ch, int x = 0);
	course(string s = "NULL", int x = 0);
	virtual ~course();
	string getname() const { return name; }
	int getch() const { return credithour; }
	virtual bool type()const { return 1; }
	void setname(char * ch) { name = ch; }
	void setname(string ch) { name = ch; }
	virtual void setgrade(int x) { ; }
	virtual void setgrade(char ch) { ; }
	virtual int getscore() const = 0 { return -1; }
	void setch(int x) { credithour = x; }
	friend ostream &operator<<(ostream &os, const course &t);
private:
	string name;
	int credithour;
};
#endif
