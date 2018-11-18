#ifndef OBLITARYCOURSE_H
#define OBLITARYCOURSE_H
#include"course.h"
class OblitaryCourse:public Course 
{
	public:
		OblitaryCourse();
		OblitaryCourse(const string tname,const int tcreditHour);
		OblitaryCourse(const string tname,const int tcreditHour,const int tmark);
		OblitaryCourse(const OblitaryCourse &O);
		int getMark()const;
		int setMark(int tmark);
		virtual int getScore()const;
		void printCourse()const;
		~OblitaryCourse();
	protected:
		int mark;
};

#endif
