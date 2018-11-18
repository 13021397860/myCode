#ifndef CONSOLE_H
#define CONSOLE_H
#include"Student.h"

class Console
{
    public:
        Console();
        virtual ~Console();
        int run();
    protected:

    private:
        int displayMenu() ;
        course* selectCourse(int);
        bool setCourseScore();
        Console& buildStudent();
        Console& buildCourse();
        void outPutStuIfo();
        Console& removeCour(int);
        Student *student;
        course* oc[3];
        course* ec[2];
        int quotient(int);
        int quotientOc(int);
        int quotientEc(int );
        int mxDay(int ,int ,int );

};

#endif // CONSOLE_H
