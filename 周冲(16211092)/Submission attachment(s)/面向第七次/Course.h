#ifndef COURSE_H
#define COURSE_H
#include<string>
#include<iostream>
#include<cstring>
#include<string>
class Course
{
    public:
        Course();
        Course(std::string x,int y)
		{
			className=x;creditHour=y;
		}
        virtual ~Course();
        void setClassName(std::string a)
		{
			className=a;
		}
        std::string getClassName()const
		{
			return className;
		}
        void setCreditHour(int b)
		{
			creditHour=b;
		}
        int getCreditHour()const
		{	
			return creditHour;
		}
        virtual void printClass(){}
        friend std::ostream&operator<<(std::ostream& o,const Course& a);
        virtual void setGrade(){}
        virtual int getScore()const=0;
    protected:
        std::string className;
        int creditHour;
};
#endif
