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
        void if_cin_wrong(int&);
        void displaymenu();
        Console& buildCourse();
        Console& buildStudent();
        Student *student;
};

#endif // CONSOLE_H
