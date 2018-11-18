#include"Course.h"

ostream& operator<<(ostream& output, const Course& _Course) {
	output<<"CourseName: "<<left<<setw(20)<<_Course.getName()<<"   CreditHour: "<<_Course.getCreditHour()<<"   Grade: "<<_Course.getScore();
	return output;
}

Course::Course() {
	name="Undefined";
	creditHour=0;
}

Course::Course(const string _name,const int _creditHour) {
	setName(_name);
	setCreditHour(_creditHour);
}

Course::Course(const Course& _Course) {
	setName(_Course.name);
	setCreditHour(_Course.creditHour);
}

void Course::setName(const string _name) {
	name=_name;
}

void Course::setCreditHour(const int _creditHour) {
	creditHour=_creditHour;
}

string Course::getName() const {
	return name;
}

int Course::getCreditHour() const {
	return creditHour;
}

//int Course::getScore() const {
//	return 0;
//}

Course::~Course() {}

