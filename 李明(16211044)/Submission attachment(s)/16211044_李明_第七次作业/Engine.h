#ifndef ENGINE_H
#define ENGINE_H

#include "Date.h"
#include "Student.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Exception.h"

class Engine
{
    public:
        Engine();
        virtual ~Engine();

        void start();
        bool exit() const;

    private:
        bool isEnd;

        Student** studentList;
        int studentNumber;

        ObligatoryCourse** OC;
        int OCNumber;
        ElectiveCourse** EC;
        int ECNumber;

        void studentMenu(Student*);
        void teacherMenu();

        Student* createStudent();
        Student* selectCourse(Student*);
        Student* removeCourse(Student*);
        Student* calcCredit(Student*);
        Student* setScore();
};

#endif // ENGINE_H
