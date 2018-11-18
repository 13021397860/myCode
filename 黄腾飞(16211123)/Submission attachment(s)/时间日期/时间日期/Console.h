#ifndef CONSOLE_H
#define CONSOLE_H
#include"Date.h"
#include"student.h"
class Console
{
	public:
		Console();
		~Console();
		void run();
		void text(Date);
		Student  student(char *,Date&); //创建学生信息 
		void menu();//打印菜单 
		void course(Student&);//选课 
		void  withdraw(Student&);//退课
		void  score(Student&);//打分 
		void  information(Student&);//打印学生信息  
		void  view(Student& );//查询分数 
		Console& buildCourse();
	protected:
	private:
	      Course *oc[max_size];
		  Course *ec[max_size];
		  int ocnum,ecnum;
};

#endif
