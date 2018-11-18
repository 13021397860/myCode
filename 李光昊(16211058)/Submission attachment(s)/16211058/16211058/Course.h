#ifndef COURSE_H
#define COURSE_H
#include<iostream>
#include<string>
class Course
{
	friend std::ostream &operator<<(std::ostream &,const Course &);
	public:
		Course(std::string,int);
		Course();
		virtual~Course();
		
		Course& setName(const std::string &);
		Course& setCreditHour(int);
		std::string getName()const;
		int getCreditHour()const;
		void print()const;
		
		virtual int getScore() const =0;
		
	protected:
		std::string name;
		int creditHour;
};

#endif
