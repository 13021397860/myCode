#ifndef OPERATION_H
#define OPERATION_H
#include "Student.h"
class operation
{
    public:
        operation();
        virtual ~operation();
        void mainoperation();
        void setNameanData(Student &s);
        void getmessageformfile(Student &s);
        void SelectionOperation();
        void SelectCourses(Student &s);
        void selectiveCourses(Student &s);
        void setScore(Student &s);
        void getScore(Student &s);
        void dropCourses(Student &s);
        void showmessage(Student &s);
        void showcoursemessage();
        void outputuofile(Student &s);
    protected:
    private:
};

#endif // OPERATION_H
