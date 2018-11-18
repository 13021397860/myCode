#ifndef CONSOLE_H
#define CONSOLE_H
#include "Student.h"

class Console
{
    public:
        void run();
        void testdate();
        void displaycourse();
        void chooseandgive();
        void testinfor(Student);
        Console();
        virtual ~Console();

    protected:

    private:
};

#endif // CONSOLE_H
