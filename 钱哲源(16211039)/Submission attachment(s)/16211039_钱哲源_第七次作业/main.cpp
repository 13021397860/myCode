#include <iostream>
#include "Student.h"
#include "Date.h"
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#include "Console.h"
using namespace std;


int main()
{
    Console console;    //构造控制台界面
    int a=console.start();      //运行控制台
    return a;
}

