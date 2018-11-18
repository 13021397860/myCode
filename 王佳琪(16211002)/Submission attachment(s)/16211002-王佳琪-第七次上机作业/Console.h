#ifndef CONSOLE_H
#define CONSOLE_H
#include <cstring>
#include "Date.h"
#include "Student.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "MyException.h"

using namespace std;
class Console
{
	public:
		Console();
		virtual ~Console();
		int run();//运行控制台
		 
	protected:
	private:
		void displayMenu() const; //显示系统主菜单
		Course* selectCourse(int); //选课 返回课程地址 op = 1 必修 op = 2 选修
		void setCourseScore(); //设置所有课程成绩
		
		void buildStudent(); //构造学生对象
		Console& buildcourse(); //设置所有可选课程 
		
		Student *student; 
		int num,num1,num2;
		string str; 
		Date date;
		
    	int y,m,d,hour;
    	char* n;
    	int courseNum,courseNum1,classy;
    	ElectiveCourse ele[10];
    	ObligatoryCourse obl[10];
};


#endif
