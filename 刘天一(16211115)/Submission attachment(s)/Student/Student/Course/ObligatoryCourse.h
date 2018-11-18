#ifndef STUDENT_OBLIGATORYCOURSE_H
#define STUDENT_OBLIGATORYCOURSE_H

#include "Course.h"

class ObligatoryCourse:public Course
{
public:
    ObligatoryCourse(std::string name,int hour)
            :Course(name,hour)
    {}
    virtual ~ObligatoryCourse();
    void setMark(int m){if(m>=-1&&m<=100)mark=m;else throw MyException(GRADE_ERROR);}
    int getScore()const{return mark;}
    void print();
protected:
    int mark;
private:
};

#endif //STUDENT_OBLIGATORYCOURSE_H
