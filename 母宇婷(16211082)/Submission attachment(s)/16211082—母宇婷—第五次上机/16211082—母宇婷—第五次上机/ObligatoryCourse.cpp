#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse(string a,int b,int c)
	:Course(a,b),mark(c)
{
	
}

const int ObligatoryCourse::getScore()const
{
	return mark;
}

const string ObligatoryCourse::getname()const
{
	return name;
}

const double ObligatoryCourse::getWeight()const
{
	return 0.6;
}
ostream& operator<<(ostream& output,const ObligatoryCourse &s)
{
	output<<"��Ŀ��"<<s.getCoursename()<<" ѧ��:"<<s.getCoursecreditHour()<<"  �ɼ���"<<s.getScore()<<"\n";
}

ObligatoryCourse::~ObligatoryCourse()
{
}
