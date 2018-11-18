#ifndef CONSOLE_H
#define CONSOLE_H
#include "Student.h"

class Console
{
    public:
        int run();
        Console();
        virtual ~Console();

    private:
        int displayMenu()const;
        Course* selectCourse(int op);
        int setObCourse(int id);
        int setElCourse(int id);
        bool setCourseScore();
        Console& buildStudent();
        Console& buildCourse();
        int askforScore()const;
        int askforGPA()const;
        bool save()const;
        Student *student;
        Course *oc[MAX_SIZE];
        Course *ec[MAX_SIZE];
        int ocNum;
        int ecNum;
};

#endif // CONSOLE_H
