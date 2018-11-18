#include"course.h"
#include"ObligatoryCourse.h"
#include"MyException.h"
#include<string>
using namespace std;
obligatorycourse::obligatorycourse():course()
{}
obligatorycourse::obligatorycourse(char *ch, int x, int m) :course(ch, x)
{
	grade = m;
}
obligatorycourse::obligatorycourse(string s, int x, int m) : course(s, x)
{
	grade = m;
}
obligatorycourse::obligatorycourse(const course &x, int m) : course(x)
{
	grade = m;
}
obligatorycourse::~obligatorycourse()
{}
void obligatorycourse::setgrade(int x)
{
	grade = x;
}
ostream &operator<<(ostream &os, const obligatorycourse &t)
{
	os << "�γ�����" << t.getname() << "   ѧ�֣�" << t.getch() << "������" << t.getscore();
	return os;
}