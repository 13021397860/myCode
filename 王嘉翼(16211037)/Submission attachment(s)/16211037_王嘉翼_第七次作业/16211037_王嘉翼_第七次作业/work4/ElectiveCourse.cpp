#include "ElectiveCourse.h"
ElectiveCourse::ElectiveCourse()
{

}
ElectiveCourse::ElectiveCourse(char y)
{
    grade=y;
}
void ElectiveCourse:: setGrade(char z)
{
    grade=z;
    cout<<(*this).name<<" "<<(*this).grade<<endl;
}
int ElectiveCourse::getScore()const
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
    default:
        return -1;
    }
}
int ElectiveCourse::who()
{
    return 1;
}
