#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
//ѡ�� 
#include "Course.h"

class ElectiveCourse:public Course
{
	public: 
	        ElectiveCourse(){};
	        ElectiveCourse(std::string name,int hour):Course(name,hour){};
	        void setGrade(const char);
		    int  getScore()const;
			char getGrade()const; 
		    void print()const;
	protected:
		    
	private:
			char grade;//�ɼ� ��A��B�� 
};
#endif
