#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

class ElectiveCourse
:public Course
{
	private:
		char grade;
	public:
		ElectiveCourse(const string& a = "sss",char b = 'E',int c = 0);
		void setGrade(char);
		char getGrade() const;
		int getScore();
		void print(){};
};
#endif
