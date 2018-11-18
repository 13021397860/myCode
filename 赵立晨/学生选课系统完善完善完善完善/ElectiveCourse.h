#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"
#include "MyException.h"

class ElectiveCourse : public Course
{
    public:
        ElectiveCourse();
        ElectiveCourse(const ElectiveCourse& other);
        ElectiveCourse(const ElectiveCourse& other,char _grade);
        ElectiveCourse(const string& _name,int _creditHour);
        ElectiveCourse(const string& _name,int _creditHour,char _grade);
        void printCourse()const;
        bool setGrade(char _grade) throw(MyException);
        int getScore()const;
        virtual ~ElectiveCourse();
    protected:
    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
