#include "Elective.h"
#include"Exception.h"

Elective::Elective()
{
    //ctor
}

Elective::~Elective()
{
    //dtor
}
int Elective::getScore()
{
    switch(grade)
    {
        case'A':
            return 95;
        case'B':
            return 85;
        case'C':
            return 75;
        case'D':
            return 65;
        case'E':
            return 55;
        default:
            return 0;
    }
}


