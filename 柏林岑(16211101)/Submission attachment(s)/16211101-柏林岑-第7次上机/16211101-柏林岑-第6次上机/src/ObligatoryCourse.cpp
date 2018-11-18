#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse(){
    name="NULL";
	creditHour=0;
}
ObligatoryCourse::ObligatoryCourse(const string na,const int cr):Course(na,cr){
	 mark=0;
}
void ObligatoryCourse::setScore(const int m){
     mark=m;
}
int ObligatoryCourse::getScore()const{
     return mark;
}
ObligatoryCourse::~ObligatoryCourse()
{
	//dtor
}
