#include "electivecourse.h"
#include "course.h"
#include <iostream>
#include <string>
using namespace std;
using std::ostream;
using std::istream;
ElectiveCourse::ElectiveCourse(string n,int c,char g):Course(n,c)
{
    //ctor
    setgrade(g);
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
/*ElectiveCourse(const  ElectiveCourse &e)
{

}*/
void ElectiveCourse::setgrade(char g)
{
    grade=g;
}
int ElectiveCourse::getgrade()const
{
    int ans;
    switch (grade)
    {
        case 'A':ans=95;break;
        case 'B':ans=85;break;
        case 'C':ans=75;break;
        case 'D':ans=65;break;
        case 'E':ans=55;break;
        default:ans=0;break;
    }
    return ans;
}
void ElectiveCourse::print()const
{
    cout<<getname()<<" "<<getcreditHour()<<" "<<getgrade()<<endl;
}


int ElectiveCourse::getObligatoryCredit() const
{
    return 0;
}
int ElectiveCourse::getScore() const
{
    return getgrade();
}

