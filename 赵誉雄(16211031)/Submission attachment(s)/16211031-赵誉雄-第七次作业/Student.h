#define MAX_SIZE 15 
#ifndef STUDENT_H
#define STUDENT_H

#include "Date.h"
#include "Course.h" 
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"

class Student {
	friend ostream& operator<<(ostream& output, const Student& s)
	{
		output<<"Name: "<<s.name<<"	BirthDate: "<<s.birthDate;
		output<<"Credit: "<<s.calcCredit2()<<endl;
		//cout<<"Credit2: "<<s.calcCredit1()<<endl;
		output<<"Selected Courses: "<<endl;
		for(int i=0;i<s.courseNumber;i++){
			output<<(*s.courseList[i]);
		}
		output<<"\n";
	} 
	
	public:
		Student(const char *, const Date &);
		Student(const Student &);
		~Student();
		//Student& addCourse(const string &,int);
		Student& addCourse(Course *);
		char* getName() const;
		Date getBirthDate() const;
		int getCourseNumber() const;
		static int getCount();
		void setName(const char* const);
		bool removeCourse(int );
		//void printS() const;
		void printCourse() const;
		void setGrade(int);
		double calcCredit1() const;
		double calcCredit2() const;
		/*Course& operator[] (int sub) const
		{
			if(sub<0||sub>=courseNumber){
				throw MyException(OUT_OF_RANGE);
			}
		}*/
	private:
		char* name;
	    const Date birthDate;
		static int count;
		Course *courseList[MAX_SIZE];
		int courseNumber;
};


#endif
