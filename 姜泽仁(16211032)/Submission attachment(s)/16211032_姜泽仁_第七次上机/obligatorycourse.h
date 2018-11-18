#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "course.h" // inheriting class's header file
#include<string>
using namespace std;
// No description
class ObligatoryCourse : public Course
{
	// private section
	public:
		bool setmark(const int &);
		virtual const int getScore()const{return mark;}
		virtual const int getType()const{return 1;}
		// class constructor
		ObligatoryCourse(const string &,const int &,const int &);
		ObligatoryCourse(const string &,const int &);
		void print()const;
		// class destructor
		virtual ~ObligatoryCourse();

	protected:
		int mark;
};

#endif // OBLIGATORYCOURSE_H

