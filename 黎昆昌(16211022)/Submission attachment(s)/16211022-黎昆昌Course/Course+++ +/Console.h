#ifndef CONSOLE_H
#define CONSOLE_H
#include "Student.h"
#include "MyException.h"
#define COURSE_MAX_SIZE 10

class Console
{
    public:
        int run();
        Console();
        virtual ~Console();

    protected:

    private:
        int displayMenu();
        Course* selectCourse(int);
        bool setCourseScore();
        bool removeCourse();
        void showCourseScore() const;
        void showCalcCredit() const;
        void showCourseMessage() const;
        void safeStudentMessage() const;
        void readStudentMessage() const;
        void setMessageByFile();
        void buildCourseList();

        Console& buildStudent();
        Console& buildCourse();

        Student* student;
        Course *oblPtr[COURSE_MAX_SIZE];
        Course *elePtr[COURSE_MAX_SIZE];
        int oblNum;
        int eleNum;
};

#endif // CONSOLE_H
