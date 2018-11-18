#ifndef CONSOLE_H
#define CONSOLE_H
#include "Course.h"
#include "Student.h"
#define MAX_NUM 30
class Console
{
    public:
        Console();
        void run();
        void test();
        virtual ~Console();
    protected:
    private:
        bool init();
        bool addCourse(Student &A,bool Mark);
        Course* allCourses[MAX_NUM];
        int courseNum;
};

#endif // CONSOLE_H
