#include "Course.h"
#include "Student.h"
#include "fstream"
#ifndef CONTROL_H
#define CONTROL_H


class Control
{
    public:
        int run();
        Control();
        virtual ~Control();
    protected:
    private:
        int display() const;
        Course* selectCourse(int );
        bool setScore();
        bool get();
        Control& buildStudent(char *, int a,int b,int c);
        Control& buildCourse();
        Student *student;
        Course *o[10];
        Course *e[10];
        //fstream *file;
        void refer();
        int oNum;
        int eNum;
};

#endif // CONTROL_H
