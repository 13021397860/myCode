#ifndef MAINTEST_H
#define MAINTEST_H
#include <iostream>
#include "student.h"
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
using namespace std;

class mainTest
{
    public:
        mainTest();
        void test();
        virtual ~mainTest();
        Course *a[10];
    protected:

    private:
};

#endif // MAINTEST_H
