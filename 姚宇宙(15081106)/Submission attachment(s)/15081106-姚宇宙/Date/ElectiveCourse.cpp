#include "ElectiveCourse.h"
#include<iostream>
#include "MyException.h"

using namespace std;

ElectiveCourse::ElectiveCourse()
{
    grade = 'D';
    //cout << "default constructor of ElectiveCourse has been used.\n";
}

ElectiveCourse::ElectiveCourse(string n, int c, int m)
    :Course(n, c)
{
    setScore(m);
    //cout << "parameter constructor of ElectiveCourse has been used.\n";
}

ElectiveCourse::ElectiveCourse(const ElectiveCourse &_copy)
    :Course(_copy),
     grade(_copy.grade)
{
    //cout << "copy constructor of ElectiveCourse has been used.\n";
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}

int ElectiveCourse::getScore() const
{
    switch(grade)
    {
    case 'A':
        return 95;
    case 'B':
        return 85;
    case 'C':
        return 75;
    case 'D':
        return 65;
    case 'E':
        return 55;
    }
    return 0;
}

void ElectiveCourse::setScore(int m)
{
    if(m >= 0 and m <= 100)
    {
        if(m >= 90 and m <= 100) grade = 'A';
        else if(m >= 80 and m < 90) grade = 'B';
        else if(m >= 70 and m < 80) grade = 'C';
        else if(m >= 60 and m < 70) grade = 'D';
        else if(m >= 0 and m < 60) grade = 'E';
    }
    else throw MyException("illegal score");
}

bool ElectiveCourse::testObligatory() const
{
    return false;
}
