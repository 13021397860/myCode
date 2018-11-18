#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse(const string n, const int c, const int m)
    :Course(n, c), mark(0)
{
    //setMark(m);
    //ctor
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}

void ObligatoryCourse::setMark(const int m)
{
    if(m>=0 && m<=100)
        mark=m;
    else{
        MyException except("grade");
        throw except;
    }
    return ;
}

double ObligatoryCourse::getScore() const//virtual
{
    return mark;
}

void ObligatoryCourse::print() const
{
    cout<<"课程："<<getName()<<"\t学分："<<getCreditHour()<<"\t成绩："<<getScore()<<endl;
    return ;
}

double ObligatoryCourse::getWeight() const//virtual
{
    return 0.6;
}

double ObligatoryCourse::getNumber() const//virtual
{
    return 0;
}
