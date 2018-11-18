#include "OblilgatoryCourse.h"
#include"MyException.h"
using namespace std; 
void   OblilgatoryCourse::setMark(int  a)
{
	if((a>=0)&&(a<=100))
	  mark=a;
	 else throw MyException(Grade_wrong);
}
int OblilgatoryCourse::getScore()const
{
	 return mark;
}
 void OblilgatoryCourse::print()const
{

    cout<<*this;
}
