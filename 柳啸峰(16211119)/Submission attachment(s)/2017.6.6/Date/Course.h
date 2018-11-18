#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>
using namespace std;
class Course
{
	string name;//课程名称 
	int creditHour;//课程学分 
	public:
		Course();
		Course(string , int );//参数分别为名称和学分 
		void setName(string );
		string getName()const;//返回课程名 
		int getCreditHour()const;//返回课程学分 
		void setCreditHour(int );
		inline friend ostream& operator<< (ostream& o, const Course *t)
		{
			o<<"课程名："<<t->getName()<<" 学分："<<t->getCreditHour()<<" 成绩为："<<t->getScore()<<endl;
			return o; 
		}
	virtual void printCourse(){}//虚函数：1.就这样写（{}里可写可不写）2.这里不打{}，在.cpp里写实现 
	virtual int getScore()const = 0 ; //纯虚函数，该类：course t；（错）course *t；（对） 
	//virtual void setScore(){}
	virtual ~Course();
};

#endif
