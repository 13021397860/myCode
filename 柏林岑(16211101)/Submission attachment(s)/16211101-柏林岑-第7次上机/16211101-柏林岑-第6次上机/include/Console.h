#ifndef CONSOLE_H
#define CONSOLE_H
#include "Student.h"
#include<iostream>
using namespace std;

class Console
{
	public:
		Console();
		virtual ~Console();
    void showchoose() ;
    void Choose() ;
    void Remove() ;
    void Setgrade() ;
    void initStudent() ;
    void Show() ;
    void run() ;
    void menu() ;

	protected:

	private:
    Course *_course[20];
    Student *student;
    static int countcourse;
};


#endif // CONSOLE_H
