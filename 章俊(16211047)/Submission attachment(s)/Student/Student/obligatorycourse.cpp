#include "obligatorycourse.h"
#include "course.h"
#include <iostream>
#include <string>
#include "student.h"
#include "time.h"
using namespace std;
using std::ostream;
using std::istream;
ObligatoryCourse::ObligatoryCourse(const string n,const int c,const int m):Course(n,c)
{
    //ctor
    setmark(m);
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
/*ObligatoryCourse::ObligatoryCourse(const ObligatoryCourse &o):Cousre(o)
{
    mark=o.mark;
}*/
void ObligatoryCourse::setmark(const int m)
{
    mark=m;
}
int ObligatoryCourse::getmark()const
{
    return mark;
}
void ObligatoryCourse::print()const
{
    cout<<getname()<<" "<<getcreditHour()<<" "<<getmark()<<endl;
}


int ObligatoryCourse::getElectiveNumber() const
{
    return 0;
}
int ObligatoryCourse::getScore() const
{
    return getmark();
}
