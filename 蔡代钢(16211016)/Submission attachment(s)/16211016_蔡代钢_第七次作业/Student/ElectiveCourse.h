#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "Course.h"
#include "MyException.h"
class ElectiveCourse : public Course
{
    public:
        ElectiveCourse();
        ElectiveCourse(string ,double ,char );
        virtual ~ElectiveCourse();
        void setall(string ,double, char);
        void setScore(char );
        double getScore();
    protected:
    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
