#include <iostream>
#include <cstdio>
#include "Student.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Operation.h"

using namespace std;

int main()
{
    Operation select;
    select.read();
    select.run();
//    select.test_date();
    return 0;
}
