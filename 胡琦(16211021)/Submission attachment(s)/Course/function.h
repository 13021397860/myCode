#ifndef FUNCTION_H
#define FUNCTION_H
#include "Student.h"
#include "Course.h"
#include <iostream>
class function
{
    public:
        void run(Student &s);
        bool createSequentialFile(const char *fileName);
        bool readSequentialFile(const char *fileName);
        Student BuildStudent();
        function();
        virtual ~function();
    protected:
    private:
        void displayMenu1() const;
        void displayMenu2() const;
        void selectCourse(Student &s,int op);//op=1必修,op=0选修。
        void setCourseScore(Student &s, Course *&c);
        void RemoveCourse(Student& s);
};

#endif // FUNCTION_H
