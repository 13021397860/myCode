#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include<string>
#include<iostream>
#include<cstring>
#include"Course.h"
class ElectiveCourse:public Course
{
    public:
        ElectiveCourse();
        ElectiveCourse(std::string a,int b,char c='A'):Course(a,b)
		{	
			grade=c;
		}
        virtual ~ElectiveCourse();
        void setGrade()
		{
			char a;
			std::cin>>a;
			grade=a;
		}
        int getScore()const
		{
			return 95-(grade-'A')*10;
		}
        void printClass()
        {
			std::cout<<className<<" "<<creditHour<<" "<<grade<<std::endl;
		}
    private:
        char grade;
};
#endif
