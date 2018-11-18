#ifndef STUDENTS_H
#define STUDENTS_H
#include <iostream>
#include <cstdio>
#include "Date.h"
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#define MAX_SIZE 100
#include "MyException.h"
class Students
{
    public:
        Students(char *,const Date &);//参数为指向名字的指针，data类型的变量 
        Students(const Students &);//拷贝构造 
        void getName(char *);
        static int getCounter();//静态变量，用于计算学生数 
        void print()const;
        Date getBirthDate();
        Students& addCourse(Course *course);//用于向指针数组中传入已选课程的相关信息，参数为&课程名（子类类型的变量也行） 
        Students& addElectiveCourse(char grade, const string &courseName, int creditHour);//传入必修课 
        Students& addObligatoryCourse(int score, const string &courseName, int creditHour);//传入选修课 
        int getCourseNumber()const;
        Course *getCourseList(int);//返回courseList数组，参数为数组下标 
        ~Students();
        inline friend ostream& operator<< (ostream& o, Students& s)
		{
			char *S;
			S=new char[20];//一定要分配内存，否则容易覆盖掉其他重要数据 
			s.getName(S);
			o<<"姓名："<<S<<" 出生日期："<<s.birthDate<<", 选课信息如下："<<endl;//birthDate是const类型，所以<<的重载参数需要const 
			for(int i=0;i<s.getCourseNumber();i++)
		{
			o<<s.getCourseList(i);
		} 
			return o;
		} 
		bool removeCourse(int);//传入第几门课 
		void SetCourseGrade(MyException &);
		int calcCredit();
    private:
        static int counter;//静态数据成员，用于学生计数 
        char *name;
        const Date birthDate;
        Course *courseList[MAX_SIZE];//指针数组，用于存储学生已选课程 
        int courseNumber;
};

#endif // STUDENTS_H
