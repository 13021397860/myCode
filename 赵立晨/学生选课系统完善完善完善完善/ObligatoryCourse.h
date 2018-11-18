#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"
#include "MyException.h"

class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse();
        ObligatoryCourse(const ObligatoryCourse& other);
        ObligatoryCourse(const ObligatoryCourse& other,int _mark);
        ObligatoryCourse(const string& _name,int _creditHour,int _mark=-1);
        void printCourse()const;
        bool setMark(int _mark) throw(MyException);
        int getScore()const;
        virtual ~ObligatoryCourse();
    protected:
    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
