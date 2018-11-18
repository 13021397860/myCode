#include"stdafx.h"
#include"ElectiveCourse.h"

ElectiveCourse::ElectiveCourse(string _name, int _creditHour) :Course(_name, _creditHour) {
	//TAG = "ElectiveCourse";
	grade = 'F';
}

ElectiveCourse::~ElectiveCourse() {
};

int ElectiveCourse::getScore(void)const {
	switch (grade) {
	case 'A':
		return 95;
		break;
	case 'B':
		return 85;
		break;
	case 'C':
		return 75;
		break;
	case 'D':
		return 65;
		break;
	case 'E':
		return 55;
		break;
	default:
		return 0;
		break;
	}
}



void ElectiveCourse::setScore(char _grade){
	if (_grade == 'A' || _grade == 'B' || _grade == 'C' || _grade == 'D' || _grade == 'E' )
		grade = _grade;
	else
		grade = 'F';
}
