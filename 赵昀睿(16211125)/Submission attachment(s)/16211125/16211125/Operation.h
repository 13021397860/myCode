#ifndef OPERATION_H
#define OPERATION_H

#include "Date.h"
#include "Student.h"
#include <string>
#include <iostream>
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include <fstream>
#include "IllegalDate.h"
#include "IllegalGrade.h"
#include "OutArray.h"

class Operation
{
    public:
        Operation();
        virtual ~Operation();
        void run();
        void read();
        //void test_date();
        Course *c[2][3];
    protected:

    private:
};

#endif // OPERATION_H
