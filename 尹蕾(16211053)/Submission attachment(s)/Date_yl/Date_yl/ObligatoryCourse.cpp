#include "ObligatoryCourse.h"
using namespace std;
ObligatoryCourse::ObligatoryCourse(const string x,int a,int b):Course(x,a)
{
    setMark(b);
    //ctor
}

ObligatoryCourse::ObligatoryCourse(const string x,int a):Course(x,a)
{
    mark=0;
}

ObligatoryCourse::ObligatoryCourse(const ObligatoryCourse &ob):Course(ob)
{
    mark=ob.mark;
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
bool ObligatoryCourse::setMark(int q)
 {
     if((q<=100)&&(q>=0))
     {
         mark=q;
         return true;
     }
     else
        throw Exception(SCORE_INVALID);
 }

 int ObligatoryCourse::getScore() const
 {
     return mark;
 }
