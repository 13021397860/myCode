#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <typeinfo>
#include "electivecourse.h"
#include "obligatorycourse.h"
#include "course.h"
#include "student.h"
#include "myexception.h"

using namespace std;

#define MAX_CLS 6

class Console
{
    public:
        Console();
        void start();
        void open()throw(exception);
        void addO();
        void addE();
        void setgrade();
        void show();
        void rm();
        void rout();
        void atcl();
        friend ostream &operator<<(ostream &,const Console &);
        virtual ~Console();
        Console(const Console& other);

    protected:

    private:
        Student m;
        ObligatoryCourse a[MAX_CLS+1];
        ElectiveCourse b[MAX_CLS+1];
        int p[MAX_CLS+1],q[MAX_CLS+1];
        MyException exc;
};

#endif // CONSOLE_H
