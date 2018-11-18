#ifndef CONSOLE_H
#define CONSOLE_H

#include "Student.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "MyException.h"

class Console
{
    public:
        int run();
        Console();
        virtual ~Console();

    protected:

    private:
};

#endif // CONSOLE_H
