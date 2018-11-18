#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Student.h"
using namespace std;

class Console
{
    public:
        int run();
        Console();
        void option();
        virtual ~Console();
    protected:

    private:
};

#endif // CONSOLE_H
