#include "Course.h"

Course::Course( const string &n, int ch)
{
    name=n;
    creditHour=ch;
}

  void Course::setScore( int )
 {

 }
 string Course::toString() const
 {

 }
  int Course::getScore(  )const
 {

 }

ostream &operator << ( ostream &output, const Course& A )
{

    output <<"CourseName: "<<A.toString();
    output <<"  CreditHour: "<<A.creditHour;
    output <<"  ¿Î³Ì³É¼¨ÊÇ:"<<A.getScore()<<endl;
    return output;
}
void Course::setname( string a)
{
    name = a;
}

void Course::setHour( int b)
{
    creditHour = b;
}
Course::~Course()
{
    //dtor
}
