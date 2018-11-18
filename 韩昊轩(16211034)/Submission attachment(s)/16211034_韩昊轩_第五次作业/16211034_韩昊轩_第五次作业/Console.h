#ifndef CONSOLE_H
#define CONSOLE_H

#include "Student.h"
#include "Course.h"
#define MAX_SIZE 200
class Console
{
    public:
        void run();
        Console();
        virtual ~Console();

    protected:

    private:
        int Menu()const;
        Course*& selectCourse(int option);//选择必修课和选修课
        void setCourseScore();//设置成绩
        Student *student;
        void getCourseGrade(int num);
        Course *obligatory[MAX_SIZE];
        Course *elective[MAX_SIZE];
        int ObligatoryNumber;
        int ElectiveNumber;
        void newStudent();
        void newCourse();

};

#endif // CONSOLE_H
