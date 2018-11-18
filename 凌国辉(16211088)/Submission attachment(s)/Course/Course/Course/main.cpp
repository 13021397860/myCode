#include <iostream>
#include"Date.h"
#include"Student.h"
#include"Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include"Fun.h"
#include"MyException.h"
using namespace std;

int main()
{
    Fun test;
    test.create();
    while(test.control()){}
    return 0;
}
