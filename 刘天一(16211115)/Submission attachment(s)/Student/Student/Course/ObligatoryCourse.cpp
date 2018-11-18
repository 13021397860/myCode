#include "ObligatoryCourse.h"

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
void ObligatoryCourse::print()
{

    std::cout<<getName()<<std::endl;
    std::cout<<" the hour is : "<<getCreditHour()<<std::endl;
    if(getScore()==-1) std::cout<<"uncataloged grade\n";
    else std::cout<<" it's mark:"<<getScore()<<std::endl;
}
