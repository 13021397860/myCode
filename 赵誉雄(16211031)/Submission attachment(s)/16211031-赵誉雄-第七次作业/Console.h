#ifndef CONSOLE_H
#define CONSOLE_H

#include "Student.h"

class Console{
	public:
		void run();
		Console();
		~Console();
	private:
		int menu() const;
		int choose(int) const;
		bool buildCourse();
		bool SaveStu();
		void buildStudent();
		Course* selectCourse(int);
		void dropCourse();
		void setCourseScore();
		
		Student *stu;
		Course *_oc[5];
		Course *_ec[3];
};

#endif 
