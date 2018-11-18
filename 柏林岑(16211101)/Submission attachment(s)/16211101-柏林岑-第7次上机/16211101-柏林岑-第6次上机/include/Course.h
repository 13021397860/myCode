#ifndef COURSE_H
#define COURSE_H
#include<string>
using namespace std;
class Course
{
	public:
		Course();
		Course(const string ,const int );
        void setname(const string);
        void setcreditHour(int const);
		string getname()const;
		int getcreditHour()const;
		virtual int getScore()const=0; //虚函数要保证类型参数 const一致
		friend ostream &operator<<(ostream &,const Course&);
		virtual ~Course();

	protected:
    string name;
	int creditHour;
	private:

};

#endif // COURSE_H
