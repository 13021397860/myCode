#ifndef COURSE_H
#define COURSE_H

#include <string>

using namespace std;

class Course
{
	public:
		Course();
		Course(const string &,const int &);
		virtual ~Course();
		
		void setName(const string &);
		string getName()const;
		
		void setCreditHour(const int &);
		int getCreditHour()const;
		
		friend ostream& operator <<(ostream &,Course &);
		
		virtual int getScore()const=0;
	private:
		string name;
		int creditHour;
}; 
#endif
