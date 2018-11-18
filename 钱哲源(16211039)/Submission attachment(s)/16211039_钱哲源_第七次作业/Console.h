#ifndef CONSOLE_H
#define CONSOLE_H
#include "Course.h"
#include "Date.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#include "Student.h"

class Console
{
    friend class Student;
    public:
        int start();
        Console();
        virtual ~Console();

    protected:

    private:
        int displayMenu() const;
        bool setCourseScore();
        Console& buildStudent();
        Console& buildCourse();
        void selectCourse1();
        void selectCourse2();
        Student *student;
        Course *oc[3];
        Course *ec[3];
        int ocNum=3;
        int ecNum=3;
};


#endif // CONSOLE_H

