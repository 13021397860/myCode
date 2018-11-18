#ifndef COURSE_H
#define COURSE_H
#include<string>
using namespace std;
class Course
{
	public:
		Course(const string,const int);
		string getname() const;
		int getCreditHour() const;
		void setname(const string);
		void setCreditHour(const int);
		friend ostream& operator<<(ostream&,const Course&);
		virtual int getScore() const=0;
		virtual ~Course();
	protected:
	private:
		string name;
		int creditHour;
};

#endif
