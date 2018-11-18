#include "ObligatoryCourse.h"
#include <iostream>
using namespace std;
ObligatoryCourse::ObligatoryCourse(const string &n,int ch, int m)
:Course(n, ch), mark(m)
{
}

void ObligatoryCourse::setscore(int m)
{
    mark=m;
}

int ObligatoryCourse::getscore()
{

    return mark;
}

void ObligatoryCourse::printobliga()
{
    cout<<"the obligatory course is :"<<getname()<<endl;
    cout<<"the credithour is :"<<getcredit()<<endl;
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
