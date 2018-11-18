#include "elective_course.h"

int ElectiveCourse::getScore()
{
    if (grade == 'A')
        return 95;
    else if (grade == 'B')
        return 85;
    else if (grade == 'C')
        return 75;
    else if (grade == 'D')
        return 65;
    else
        return 55;
}
