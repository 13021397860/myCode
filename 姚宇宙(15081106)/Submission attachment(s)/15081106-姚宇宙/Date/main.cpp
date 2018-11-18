#include <iostream>
#include <cstdio>
#include "Date.h"
#include "Student.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Console.h"

using namespace std;

int main()
{
    Student test2("Bob", 2001, 2, 28);
    Console inst;
    inst.buildStudent(test2);
    inst.runInstance();
}
