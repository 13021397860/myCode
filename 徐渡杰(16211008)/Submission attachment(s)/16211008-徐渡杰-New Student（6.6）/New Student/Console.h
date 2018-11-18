#ifndef CONSOLE_H
#define CONSOLE_H
#include "Student.h"

class Console
{
    public:
        Console();
        virtual ~Console();
        void output_OcourseList();
        void output_EcourseList();
        void add_stuInformation(Student &A);
        void query_stuInformation(Student &A);
        void add_stuCourse(Student &A);
        void remove_stuCourse(Student &A);
        void add_courseSorce(Student &A);
        void set_stuInformation();
    protected:

    private:
};

#endif // CONSOLE_H
