#include "ObligatoryCourse.h"
#include<iostream>
#include "MyException.h"

using namespace std;

ObligatoryCourse::ObligatoryCourse()
{
    mark = 0;
    //cout << "default constructor of ObligatoryCourse has been used.\n";
}

ObligatoryCourse::ObligatoryCourse(string n, int c, int m)
    :Course(n, c)
{
    setScore(m);
    //cout << "parameter constructor of ObligatoryCourse has been used.\n";
}

ObligatoryCourse::ObligatoryCourse(const ObligatoryCourse &_copy)
    :Course(_copy),
     mark(_copy.mark)
{
    //cout << "copy constructor of ObligatoryCourse has been used.\n";
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}

int ObligatoryCourse::getScore() const
{
    return mark;
}

void ObligatoryCourse::setScore(int m)
{
    if(m >= 0 and m <= 100)
    {
        mark = m;
    }
    else throw MyException("illegal score");
}

bool ObligatoryCourse::testObligatory() const
{
    return true;
}
