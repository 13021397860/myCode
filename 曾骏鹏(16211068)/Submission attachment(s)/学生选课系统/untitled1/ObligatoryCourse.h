//
// Created by zjp on 2017/4/17.
//

#include "course.h"

#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H


class ObligatoryCourse : public course
{
public:
    ObligatoryCourse(string s,int cHour);
    virtual  ~ObligatoryCourse();
    void setMark(const int);
    virtual int getScore() const;
private:
    int mark;
};


#endif //OBLIGATORYCOURSE_H
