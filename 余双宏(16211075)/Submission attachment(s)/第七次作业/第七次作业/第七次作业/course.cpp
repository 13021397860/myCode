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
	os << "�γ�����" << t.getname() << "   ѧ�֣�" << t.getch() << "   �ɼ�:";
	if (t.getscore() == -1)
		os << "��δ����";
	else
		os << t.getscore() << "";
	return os;
}