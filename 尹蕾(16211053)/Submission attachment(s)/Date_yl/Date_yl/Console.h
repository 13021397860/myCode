#ifndef CONSOLE_H
#define CONSOLE_H
#include "Student.h"
#include <cstdlib>
#include <cstring>
#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include <typeinfo>
#include "Exception.h"

class Console
{
    public:
        Console();
        virtual ~Console();

        int run();

    protected:
    private:
        int displayMenu() ;
        Course* selectCourse(int );
        bool setCourseScore();
        bool removeCCourse();

        Console& buildStudent();
        Console& buildCourse();

        Student *student;
        Course *oblC[MAX_SIZE];
        Course *eleC[MAX_SIZE];
        int obnum;
        int elnum;
};

#endif // CONSOLE_H
