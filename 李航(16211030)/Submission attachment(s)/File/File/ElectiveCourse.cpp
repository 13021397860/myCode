#include "ElectiveCourse.h"
#include"Exception.h"
int ElectiveCourse::classID() const {
	return ClassID;
}
ElectiveCourse::ElectiveCourse(const std::string &ECourseName, int credit):Course(ECourseName,credit) {
	grade = 0;
	ifGrade = false;
}
ElectiveCourse::ElectiveCourse(const ElectiveCourse &T) : Course(T) {
	grade = T.grade;
	ifGrade = T.ifGrade;
}
ElectiveCourse::~ElectiveCourse(){}
int ElectiveCourse::setScore(char theGrade) {
	grade = theGrade;
	int t;
	try {
		t = changeToScore(theGrade);
	}
	catch (MyException& ex) {
		ex.show();
		t = -1;
	}
	if (t == -1) {
		grade = '\0';
	}
	else {
		ifGrade = true;
	}
	return t;
}
int ElectiveCourse::getScore()const {
	if (!ifGrade) return -1;
	int t;
	try {
		t=changeToScore(grade);
	}
	catch (MyException& ex) {
		t = -1;
	}
}
int ElectiveCourse::changeToScore(char theGrade)const {
	switch (theGrade){
	case 'A':
		return 95;
	case 'B':
		return 85;
	case 'C':
		return 75;
	case 'D':
		return 65;
	case 'E':
		return 55;
	default:
		OORException ex(ClassID);
		throw ex;
	}
}
