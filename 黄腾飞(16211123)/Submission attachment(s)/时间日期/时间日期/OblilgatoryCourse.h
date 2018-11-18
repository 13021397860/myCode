#ifndef OBLILGATORYCOURSE_H
#define OBLILGATORYCOURSE_H
//±ØÐÞ 
#include "Course.h"

class OblilgatoryCourse:public Course
{
	public:
		    OblilgatoryCourse(){};
		    OblilgatoryCourse(string name,int hour):Course(name,hour){};
			void setMark(const int  );
			int  getScore()const;
			void print()const;
	protected:
	private:
			 int mark;//³É¼¨ 
		
	 
};


#endif
