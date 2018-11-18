#include <iostream>
#include <cstdio>
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Student.h"
#include "function.h"
#include "MyException.h"
using namespace std;

int main()
{
    function f;
    Student s(f.BuildStudent());
    f.run(s);
}
