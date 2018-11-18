#ifndef CONSOLE_H
#define CONSOLE_H

#include "Student.h"
#include "Course.h"

#define MAX_SIZE 100

class Console
{
    public:
        Console();
        void run();
        virtual ~Console();

    protected:

    private:
        int displayMenu();
        void selectCourse(int op);
        void setCourseScore();
        void cancelCourse();
        void saveStudentDate() const;
        Console& buildStudent();
        Console& bulidCourse();
        Student *s1;
        Course *oc[MAX_SIZE];
        Course *ec[MAX_SIZE];
        int ocNum;
        int ecNum;
        int kc;
        int cz;
};

#endif // CONSOLE_H
