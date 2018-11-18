#include "ObligatoryCourse.h"
#include <iostream>

using namespace std;

ObligatoryCourse::ObligatoryCourse(string n,int c,int m):Course(n,c)
{
    mark=m;//ctor
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}

void ObligatoryCourse::setMark(int m)
{
    if( m >= 0 && m <= 100 )
    {
        mark = m;
    }
    else
    {
        throw IllegalGrade();
    }
}

int ObligatoryCourse::getScore()const
{
    return mark;
}

void ObligatoryCourse::printScore()const
{
    cout << mark << endl;
}
