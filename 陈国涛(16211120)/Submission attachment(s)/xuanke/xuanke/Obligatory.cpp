#include "Obligatory.h"
#include <iostream>
using namespace std;
Obligatory::Obligatory(string newname, int credit) :Course(newname, credit)
{
    //ctor
}

Obligatory::Obligatory(const Obligatory & a) :Course(a.name, a.creditHour)
{
    setScore(a.mark);
}

int Obligatory::getScore()const
{
    return mark;
}

void Obligatory::setScore(int newmark , char grade ) throw(MyException)
{
    if(newmark < 0 || newmark > 100)
    {
        MyException course(3);
        mark = 0;
        throw course;
    }
    mark = (newmark > 0)? newmark:0;
}


const void Obligatory::print() {
 cout << " ³É¼¨: "<< mark<<endl;
}

Obligatory::~Obligatory()
{
    //dtor
}
