//
// Created by zjp on 2017/4/17.
//

#include "ElectiveCourse.h"

void ElectiveCourse::setGrade(const char g)
{
    grade=g;
}

int ElectiveCourse::getScore() const
{
    switch (grade) {
        case 'A':
            return 95;
        case 'B':
            return 85;
        case 'C':
            return 75;
        case 'D':
            return 65;
        default:
            return 55;
    }
}

ElectiveCourse::ElectiveCourse(string s, int cHour):course(s,cHour) {}

ElectiveCourse::~ElectiveCourse() {}