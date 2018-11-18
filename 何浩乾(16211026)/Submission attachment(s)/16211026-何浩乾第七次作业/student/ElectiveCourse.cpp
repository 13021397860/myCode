#include "ElectiveCourse.h"
#include "MyException.h"

ElectiveCourse::ElectiveCourse(const string &n, int ch, char g)
	:Course(n, ch)
{
	setGrade(g);
}

ElectiveCourse::~ElectiveCourse()
{

}

int ElectiveCourse::getScore() const
{
	switch(grade){
	    case 'A': return 95;
	    case 'B': return 85;
	    case 'C': return 75;
	    case 'D': return 65;
	    case 'E': return 55;
	    default: return 0;
	}
}

bool ElectiveCourse::setGrade(char g)
{
	if(((g>='A')&&(g<='E'))||(g=='\0')){
		grade=g;
		return true;
	}else{
		throw MyException(SCORE_INVALID);
	}
}
