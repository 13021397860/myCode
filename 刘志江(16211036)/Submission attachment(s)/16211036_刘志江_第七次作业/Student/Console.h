#ifndef CONSOLE_H
#define CONSOLE_H
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#include "Student.h"
#include "MyException.h"
#include <conio.h>
#include <stdlib.h>
class Console
{
    public:
        Console();
        void run();
        virtual ~Console();

    protected:

    private:
        char ch;
        int ocNum, ecNum;
        Student *stu;
        int inp, inp1, inp2, inp3, inp4, inp5;
        ElectiveCourse *ec[15];
        ObligatoryCourse *oc[15];

    private:
        Console& buildCourse();
        Console& buildStudent();
        void mainMenu();
        void obCourse();
        void elCourse();
        void setGrade();
        void remCourse();
        void expose();

};

#endif // CONSOLE_H
