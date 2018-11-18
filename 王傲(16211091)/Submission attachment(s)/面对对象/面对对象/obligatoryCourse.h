#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

class ObligatoryCourse
:public Course
{
	private:
		int mark;
	public:
		ObligatoryCourse(const string& a = "sss",int b = 0,int c = 0);
		void setMark(int);
		int getScore();
		void print(){};
};

#endif
