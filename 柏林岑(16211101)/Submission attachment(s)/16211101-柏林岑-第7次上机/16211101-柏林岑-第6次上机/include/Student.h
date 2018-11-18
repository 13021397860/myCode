#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "MyException.h"
#define MAX_SIZE 10
class Student
{
	public:
		Student();
		Student(char*,const Date&);
		Student(const Student&);
        Student& addCourse(Course*);
		Student& addCourse(const string &, int );
		char *getname()const;
		void getbirthDate(Date &)const;
		void setname(const char*);
		bool removeCourse(int);
		void setGrade(const int);
		double calcCredit()const;
		int calcObligatoryCredit() const;
		int calcElectiveNumber() const;
        static int getcount();
        int getcoursenumber()const;
        friend ostream &operator<<(ostream &,const Student&);

		virtual ~Student();



	protected:

	private:
	char *name;
	const Date birthDate;
	static int count;
	Course *CourseList[MAX_SIZE];
	int courseNumber;

};

#endif // STUDENT_H
