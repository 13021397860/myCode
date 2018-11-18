#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"

class ElectiveCourse : virtual public Course
{
    public:
        ElectiveCourse();
        ElectiveCourse(const std::string&);
        ElectiveCourse(const std::string&, const int&);
        ElectiveCourse(const std::string&, const int&, const char&);
        ElectiveCourse(const ElectiveCourse&);
        ElectiveCourse(const Course&);
        virtual ~ElectiveCourse();

        bool setGrade(const char&); //throw(Illegal_EC_Score_Exception)

        virtual int getScore() const;

    private:
        char grade;
        static const int gradeToScore[5];
};

#endif // ELECTIVECOURSE_H
