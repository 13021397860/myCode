#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include<string>
#include<iostream>
#include<cstring>
#include"Course.h"
class ObligatoryCourse:public Course
{
    public:
        ObligatoryCourse();
        ObligatoryCourse(std::string a,int b,int c=100):Course(a,b)
		{
			mark=c;
		}
        virtual ~ObligatoryCourse();
        void setGrade()
		{	
			int a;
			std::cin>>a;
			mark=a;
		}
        int getScore()const
		{	
			return mark;
		}
        void printClass()
		{
		 	std::cout<<className<<" "<<creditHour<<" "<<mark<<std::endl;
		}
	private:
        int mark;
};
#endif
