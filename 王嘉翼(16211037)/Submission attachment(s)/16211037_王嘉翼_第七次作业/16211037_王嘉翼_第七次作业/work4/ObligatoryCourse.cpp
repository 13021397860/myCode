#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse()
{
    mark=-1;
}
int ObligatoryCourse::getScore()const
{
    return mark;
}
ObligatoryCourse::ObligatoryCourse(int x)
{
    mark=x;
}
void ObligatoryCourse::setGrade(int x)
{
    mark=x;
    cout<<(*this).name<<" "<<(*this).mark<<endl;
}
int ObligatoryCourse::who()
{
    return 2;
}
