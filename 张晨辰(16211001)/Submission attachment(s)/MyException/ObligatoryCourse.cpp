#include "ObligatoryCourse.h"
#include "MyException.h"

ObligatoryCourse::ObligatoryCourse(string na,int credit,int score) : Course(na,credit)
{
    setScore(score);
}
void ObligatoryCourse::setScore(int score)
{
    if(score<=100&&score>=0)
        mark=score;
    else
        throw MyException(SCORE_INVALID);
}
int ObligatoryCourse::getScore()const
{
    return mark;
}
ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
