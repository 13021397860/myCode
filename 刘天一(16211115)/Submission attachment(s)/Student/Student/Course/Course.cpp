#include "Course.h"
#include <iomanip>
using namespace std;
Course::Course()
{
    //ctor
}

Course::~Course()
{
    //dtor
}
ostream& operator<<(ostream &output,const Course& c)
{
    output<<"courseName: "<<c.getName()<<"  CreditHour: "<<c.getCreditHour();
    output<<"  courseScore: "<<c.getScore()<<endl;
    return output;
}
