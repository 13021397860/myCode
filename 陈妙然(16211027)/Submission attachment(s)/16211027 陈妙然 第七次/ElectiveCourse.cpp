#include "ElectiveCourse.h"
#include "Course.h"
ElectiveCourse::ElectiveCourse(const string &n,int ch, char g)
:Course(n,ch),grade(g)
{
    setxuanxiu(g);
}

void ElectiveCourse::setxuanxiu(char dengji)
{

    grade=dengji;
}

int ElectiveCourse::getscore()
{
    switch (grade)
    {
        case 'A':
            {
                return 95;
                break;

            }
        case 'B':
            {
                return 85;
                break;
            }

        case 'C':
            {
                return 75;
                break;

            }

        case 'D':
            {

                return 65;
                break;
            }

        case 'E':
            {
                 return 55;
                    break;
            }

        default:
            return 0;
            break;
    }
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
