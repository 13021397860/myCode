#include"course.h"
#include<string>
#include<iostream>
using namespace std;
course::course(char *ch, int x)
{
	name = ch;
	credithour = x;
}

course::course(string s, int x)
{
	name = s;
	credithour = x;
}

course::~course()
{}

ostream &operator<<(ostream &os, const course &t)
{
	os << "课程名：" << t.getname() << "   学分：" << t.getch() << "   成绩:";
	if (t.getscore() == -1)
		os << "暂未设置";
	else
		os << t.getscore() << "";
	return os;
}