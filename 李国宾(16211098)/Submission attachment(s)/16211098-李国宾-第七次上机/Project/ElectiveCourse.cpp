#include"ElectiveCourse.h"

ElectiveCourse::ElectiveCourse() {
	grade='F';
}

ElectiveCourse::ElectiveCourse(const string _name,const int _creditHour,const char _grade)
	:Course(_name,_creditHour) {
	setGrade(_grade);
}

void ElectiveCourse::setGrade(const char _grade) {
	if(_grade>='A'&&_grade<='E') grade=_grade;
	else grade='F';
}

int ElectiveCourse::getScore() const  {
	if(grade=='A') return 95;
	else if(grade=='B') return 85;
	else if(grade=='C') return 75;
	else if(grade=='D') return 65;
	else if(grade=='E') return 55;
	else return 0;
}
