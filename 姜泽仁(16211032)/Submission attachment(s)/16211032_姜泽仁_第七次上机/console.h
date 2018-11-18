#ifndef CONSOLE_H
#define CONSOLE_H
#include "student.h"
#include "course.h"
// No description
class Console
{
	// private section
	private:
		int displayMenu()const;
		void selectCourse(int);
		bool setCourseScore();
		void removeCourse();
		void save();
		void printCredit()const; 
        Console& buildStudent();
        Console& buildCourse();
        Student *student;    
        Course *oc[MAX_SIZE];	
        Course *ec[MAX_SIZE];
        int ocNum;
        int ecNum;
	public:
		int run();
		// class constructor
		Console();
		// class destructor
		~Console();
	protected:
};

#endif // CONSOLE_H

