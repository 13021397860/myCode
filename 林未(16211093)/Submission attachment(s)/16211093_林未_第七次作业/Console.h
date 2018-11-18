#ifndef CONSOLE_H
#define CONSOLE_H

#include "Student.h"

class Console
{
	public:
		Console();
		void run();
		bool readSequentialFile(const char *);
        virtual ~Console();
		
		
	protected:
		
	private:
		Course *obligatoryCourse[MAX_SIZE];
        Course *electiveCourse[MAX_SIZE];
        int numberofOC;
        int numberofEC;        
        void printOC();
		void printEC(); 
		bool setCourseGrade(Student &); 
};

#endif
