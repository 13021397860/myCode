#include"stdafx.h"
#include"Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"

Course::Course(string _name, int _creditHour) {
	name = _name;
	creditHour = _creditHour;
	//TAG = "Course";
};
Course::~Course() {
}
/*
string Course::getTAG(void) {
	return TAG;
}
*/
string Course::getName(void)const {
	return name;
};
int Course::getCreditHour(void)const {
	return creditHour;
};
void Course::setName(string _name) {
	name = _name;
};
void Course::setCreditHour(int _creditHour) {
	creditHour = _creditHour;
};
void Course::setScore(int) {
}
void Course::setScore(char) {
}
int Course::getScore(void)const {
	return 0;
};
ostream& operator<<(ostream& os, Course& course) {
	os << "�γ���: " << course.getName() << " ѧ��: " << course.getCreditHour() << " �ɼ�: " << course.getScore() ;
	if (typeid(course).name() == typeid(ObligatoryCourse).name())
		os << " " << "���޿�";
	else if(typeid(course).name() == typeid(ElectiveCourse).name())
		os << " " << "ѡ�޿�";
	return os;
}