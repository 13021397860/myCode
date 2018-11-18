#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"
using namespace std;

class ElectiveCourse : public Course
{
    public:
        ElectiveCourse(const string ,int , char );
        ElectiveCourse(const ElectiveCourse &);
        ElectiveCourse(const string ,int );
        virtual ~ElectiveCourse();

        bool setGrade(char );
        virtual int getScore() const;


        virtual double getWeight() const {return 0.4;}
        virtual int getObligatoryCredit() const { return 0;}

    protected:

    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
