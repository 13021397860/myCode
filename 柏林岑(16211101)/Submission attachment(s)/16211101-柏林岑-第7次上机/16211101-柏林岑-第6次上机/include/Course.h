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
		virtual int getScore()const=0; //�麯��Ҫ��֤���Ͳ��� constһ��
		friend ostream &operator<<(ostream &,const Course&);
		virtual ~Course();

	protected:
    string name;
	int creditHour;
	private:

};

#endif // COURSE_H
