#ifndef ELECTIVECOURSE_H_INCLUDED
#define ELECTIVECOURSE_H_INCLUDED
#include "electiveCourse.h"
#include "course.h"
class electiveCourse:public course
{
private:
    char grade;
public:
    electiveCourse();
    electiveCourse(const string ,const int );
    void setGrade(char );
    int getScore();
};



#endif // ELECTIVECOURSE_H_INCLUDED
