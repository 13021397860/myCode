#ifndef CONSOLE_H
#define CONSOLE_H

#include "Student.h"
#include "Course.h"
class Console
{
    public:
        int run();

        Console();
        virtual ~Console();
    protected:
    private:
        int displayMenu() const;
        Course* selectCourse(int op);
        bool setCourseScore();

        Console& buildStudent();
        Console& buildCourse();

        Student *student;
        Course *oc[MAX_SIZE];
        Course *ec[MAX_SIZE];
        int ocNum;
        int ecNum;
};

#endif // CONSOLE_H
