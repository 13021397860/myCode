#include <iostream>
#include <windows.h>
#include "student.h"
#include "date.h"
#include "choosecoursegui.h"
int main()
{
    student s;
    ChooseCourseGUI a;
    a.cmd(s);
    return 0;
}
