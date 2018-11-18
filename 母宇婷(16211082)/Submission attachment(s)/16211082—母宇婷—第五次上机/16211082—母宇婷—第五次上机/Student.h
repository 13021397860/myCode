#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 3
#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"

class Student
{
	friend ostream &operator<<(ostream &,const Student&);
	public:    
		Student(const char *,const Date&);
		Student(const Student &);
		Student&addObligatoryCourse(ObligatoryCourse *course);
		Student&addElectiveCourse(ElectiveCourse *course1);
		virtual ~Student();
		static int getcount();
		char* getname()const;
		void setbirthdate(int y,int m,int d);
		void setname(const char *n);
		bool remove(const char* ,int );
		int search();
		int calcCredit();
		
	protected:
		
	private:
		const Date birthdate;
		char *name;
		static int count;
		static int courseNumber1;
		static int courseNumber2;
		ObligatoryCourse *courselist[MAX_SIZE];
		ElectiveCourse *courselist2[MAX_SIZE]; 
};

#endif
