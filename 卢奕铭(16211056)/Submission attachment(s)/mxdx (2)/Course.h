#ifndef COURSE_H
#define COURSE_H
#include<string>

using namespace std;
class Course
{
	public:
		Course();
		Course(string n,int c);
		setCourse(string n,int c);
		int getCourse(string &s, int &h)const;
		virtual ~Course();
		string getName()const;
		int getCreditHour()const;
		int setName(string n);
		int setCreditHour(int c);
		virtual int getScore() const =0;
		friend ostream& operator << (ostream&,Course&);
	protected:
		string Name;
		int credithour;
};


#endif
