#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"

class ObligatoryCourse : virtual public Course
{
    public:
        ObligatoryCourse();
        ObligatoryCourse(const std::string&);
        ObligatoryCourse(const std::string&, const int&);
        ObligatoryCourse(const std::string&, const int&, const int&);
        ObligatoryCourse(const ObligatoryCourse&);
        ObligatoryCourse(const Course&);
        virtual ~ObligatoryCourse();

        bool setMark(const int&); //throw(Illegal_OC_Score_Exception)

        virtual int getScore() const;

    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
