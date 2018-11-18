#include"ElectiveCourse.h"

electivecourse::electivecourse():course()
{}

electivecourse::electivecourse(char *ch, int x, char m) :course(ch, x)
{
	grade = m;
}

electivecourse::electivecourse(string s, int x, char m) :course(s, x)
{
	grade = m;
}

electivecourse::electivecourse(const course &x, char m) :course(x)
{
	grade = m;
}

electivecourse::~electivecourse()
{}

int electivecourse::getscore() const
{
	switch (grade) { case 'A':return 95; case'B':return 85; case'C':return 75; case'D':return 65; case'E':return 55; case'F':return -1; }
}

ostream &operator<<(ostream &os, const electivecourse &t)
{
	cout << "课程名：" << t.getname() << "   学分：" << t.getch();
	return os;
}