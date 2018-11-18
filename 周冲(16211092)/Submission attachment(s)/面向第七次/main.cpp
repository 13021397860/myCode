#include <iostream>
#include"Date.h"
#include"Student.h"
#include"Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include"Console.h"
using namespace std;
int main()
{
    Console test;
    test.create();
    while(test.control()){}
    return 0;
}
