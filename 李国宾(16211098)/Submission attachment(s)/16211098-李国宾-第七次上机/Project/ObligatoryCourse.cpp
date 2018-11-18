#include"ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse() {
	mark=0;
}

ObligatoryCourse::ObligatoryCourse(const string _name,const int _creditHour,const int _mark)
	:Course(_name,_creditHour) {
	setGrade(_mark);
}

void ObligatoryCourse::setGrade(const int _mark) {
	mark=_mark;
}

int ObligatoryCourse::getScore() const {
	return mark;
}
