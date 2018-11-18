#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"

class ObligatoryCourse : public Course
{
	friend ostream &operator<<(ostream &,const ObligatoryCourse&);
	public:
		ObligatoryCourse(string ,int,int);
		~ObligatoryCourse();
		const int getScore()const;
		const string getname()const;
		const double getWeight()const;
		ObligatoryCourse(const ObligatoryCourse&oc)
			:Course(oc),mark(oc.mark)
		{
			
		}
	protected:
	private:
		int mark;
};

#endif
