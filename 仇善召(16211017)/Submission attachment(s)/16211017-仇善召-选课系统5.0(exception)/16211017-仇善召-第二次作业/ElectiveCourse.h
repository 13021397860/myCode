#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"
using namespace std;
class ElectiveCourse: public Course
{
    public:
        ElectiveCourse(){grade='A';}

        ElectiveCourse( string, int ,char );

        void setScore( int );

        int getScore() const;
        string toString() const;
        virtual ~ElectiveCourse();

    protected:

    private:
        char grade;

};

#endif // ELECTIVECOURSE_H
