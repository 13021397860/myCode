#include "ElectiveCourse.h"

ElectiveCourse::ElectiveCourse(){
    name="NULL";
	creditHour=0;
}
ElectiveCourse::ElectiveCourse(const string na,const int cr):Course(na,cr){
   grade='F';
}
void ElectiveCourse::setgrade(const char g){
     grade=g;
}
int ElectiveCourse::getScore()const{
	if(grade=='A')return 95;
	if(grade=='B')return 85;
	if(grade=='C')return 75;
	if(grade=='D')return 65;
	if(grade=='E')return 55;
	else return 0;
}

ElectiveCourse::~ElectiveCourse()
{

}
