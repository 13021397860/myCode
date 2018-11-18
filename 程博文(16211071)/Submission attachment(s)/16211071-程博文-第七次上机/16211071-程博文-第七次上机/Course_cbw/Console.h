#ifndef CONSOLE_H
#define CONSOLE_H
#include"Student.h"
#include"Course.h"
#include"ElectiveCourse.h"
#include"ObligatoryCourse.h"

class Console
{
public:
    Console();
    virtual ~Console();
    Console(const Console& other);
    Student CreateStudent();
    void SelectCourse(Student& s);
    int RemoveCourse(Student& s);
    void DispMenu();//display menu;
    virtual void Run();

protected:

private:
    ObligatoryCourse ss1[6];
    ElectiveCourse ss2[6];
};

#endif // CONSOLE_H
