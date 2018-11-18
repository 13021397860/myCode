#include <iostream>
#include "date.h"
#include "Stu.h"
#include <string.h>
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include <stdlib.h>
#include "UserInterface.h"
using namespace std;

int main()
{
    Stu stu1;
    UserInterface ui;
    ui.FirstMenu(stu1);
    system("cls");
    while(1){
        ui.FunctionList(stu1);
        system("cls");
    }
}
