#include "ElectiveCourse.h"

void ElectiveCourse::print()
{
    std::cout<<getName()<<std::endl;
    std::cout<<" the hour is : "<<getCreditHour()<<std::endl;
    if(getScore()==-1) std::cout<<"uncataloged grade\n";
    else std::cout<<" score:"<<getScore()<<std::endl;
}
