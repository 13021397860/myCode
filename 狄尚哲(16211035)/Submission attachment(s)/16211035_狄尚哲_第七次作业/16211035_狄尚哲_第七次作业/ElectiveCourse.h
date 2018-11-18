#include "Course.h"
#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
class ElectiveCourse : public Course
{
    public:
        ElectiveCourse();
        ElectiveCourse(const string, const int,  const char);
        ElectiveCourse(const ElectiveCourse &);
        virtual ~ElectiveCourse();
        virtual void getScore(int &) const;
        virtual const int getScore() const;
        void setScore(const char);
        //жиди <<
//        friend ostream& operator <<(ostream &os, const ElectiveCourse &c);

    protected:

    private:
        char grade; //A, B, C, D, E
};

#endif // ELECTIVECOURSE_H
