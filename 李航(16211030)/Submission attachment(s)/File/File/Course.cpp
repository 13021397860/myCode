#include "Course.h"
#include <string>
int Course::classID() const {
	return ClassID;
}
Course::Course(const std::string &nameOfCourse, int credit) {
	name = nameOfCourse;
	creditHour = credit;
}
Course::Course(const Course &T) {
	name = T.name;
	creditHour = T.creditHour;
}
Course::~Course()
{
}
void Course::getName(std::string &nameOfCourse)const {
	nameOfCourse = name;
}
void Course::getCreditHour(int &credit)const {
	credit = creditHour;
}
void Course::changeName(const std::string &new_nameOfCourse) {
	name = new_nameOfCourse;
}
void Course::changeCredit(int new_credit) {
	creditHour = new_credit;
}
std::ostream& operator<<(std::ostream& output_course,const Course& course) {
	output_course << "课程名：" << course.name << " 学分：" << course.creditHour;
	if (course.getScore() != -1) output_course << "成绩："<<course.getScore();
	return output_course;
}
std::ofstream& operator<<(std::ofstream& outputf_course,const Course& course) {
	outputf_course << course.name << " " << course.creditHour;
	outputf_course << " " << course.getScore();
	return outputf_course;
}