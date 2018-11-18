#ifndef CONSOLE_H
#define CONSOLE_H
#include <cstdio>
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#include "date.h"
#include "student.h"
using std::ostream;
class console
{
    public:
        int run();
        console();
        virtual ~console();
    protected:
    private:
        int displayMenu()const;
        console& buildstudent();
        console& buildcourse();
        Student s;
        string studentname;
        int year, month, day;
        ObligatoryCourse *oc[Max_Size];
        ElectiveCourse *ec[Max_Size];
        int ocNum=3;
        int ecNum=2;
};

#endif // CONSOLE_H
