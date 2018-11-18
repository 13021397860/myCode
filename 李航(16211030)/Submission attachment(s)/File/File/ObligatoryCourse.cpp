#include "ObligatoryCourse.h"
#include <string>
ObligatoryCourse::ObligatoryCourse(const std::string OCourseName, int credit) :Course(OCourseName, credit) {
	mark = 0;
	ifMark = false;
}
ObligatoryCourse::ObligatoryCourse(const ObligatoryCourse &T):Course(T) {
	mark = T.mark;
	ifMark = T.ifMark;
}
ObligatoryCourse::~ObligatoryCourse()
{
}
void ObligatoryCourse::setMark(int new_mark) {
	if (mark >= 0) {
		mark = new_mark;
		ifMark = true;
	}
}
int ObligatoryCourse::getScore()const {
	if (!ifMark) return -1;
	return mark;
}
int ObligatoryCourse::classID() const {
	return ClassID;
}