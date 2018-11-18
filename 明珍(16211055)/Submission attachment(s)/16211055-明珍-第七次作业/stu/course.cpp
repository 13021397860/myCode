#include "course.h"
using namespace std;



ostream& operator<<(ostream& o, const Course& c) {
	// <课程名称> 学分：<学分>（例如：课程名：高级语言程序 设计 - 2   学分：3）
	o  <<"课程名称："<< c.getCname()  << "   学分：" << c.getCreditHour() <<"  成绩："<<c.getScore()<< std::endl;

	return o;
}




