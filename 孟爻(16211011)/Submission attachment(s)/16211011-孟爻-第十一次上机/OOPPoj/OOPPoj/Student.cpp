#include "stdafx.h"
#include"Student.h"
#include<cstring>

int Student::count = 0;

Student::Student(const char *n, Date *bd) {
	courseNumber = 0;
	name = NULL;
	birthDate = NULL;
	if (n == NULL || bd == NULL) {
		printf("Null Pointer Exception !\n");
	}
	else {
		count++;
		int len = strlen(n);
		name = new char[len + 1];
		strcpy(name, n);
		birthDate = new Date(*bd);
	}
}



Student::Student(const Student &stu) {
	count++;
	int len = std::strlen(stu.name);
	name = new char[len + 1];
	strcpy(name, stu.name);
	birthDate = new Date(*stu.birthDate);
}

Student::~Student() {
	count--;
	if (name) delete name; else  printf("name is NULL!\n");
	if (birthDate)delete birthDate; else  printf("birthDate is NULL!\n");
	for (int i = 0; i < courseNumber; i++) {
		Course *p;
		p = courseList[i];

		if (typeid(*p).name() == typeid(ObligatoryCourse).name()) {
			ObligatoryCourse *Op = dynamic_cast<ObligatoryCourse*>(p);
			delete Op;
		}
		if (typeid(*p).name() == typeid(ElectiveCourse).name()) {
			ElectiveCourse *Ep = dynamic_cast<ElectiveCourse*>(p);
			delete Ep;
		}

	}
}

void Student::SetName(const char *n) {
	if (n == NULL) {
		printf("Null Pointer Exception !\n");
	}
	else {
		if (name)delete name;
		int len = std::strlen(n);
		name = new char[len + 1];
		strcpy(name, n);
	}
}

char* Student::GetName(void) {
	return name;
}

void Student::SetBirthday(Date *bd) {
	if (bd == NULL) {
		printf("Null Pointer Exception !\n");
	}
	else {
		if (birthDate)delete birthDate;
		birthDate = new Date(*bd);
	}
}

Date* Student::GetBirthday(void) {
	return birthDate;
}

bool Student::setScore(int _index, int _score) {
	if (_index <= 0 || _index > courseNumber) {
		return false;
	}
	Course *p;
	p = courseList[_index - 1];
	if (typeid(*p).name() == typeid(ElectiveCourse).name())return false;
	p->setScore(_score);
	return true;
}


bool Student::setScore(int _index, char _score) {
	if (_index <= 0 || _index > courseNumber) {
		return false;
	}
	Course *p;
	p = courseList[_index - 1];

	if (typeid(*p).name() == typeid(ObligatoryCourse).name())return false;
	p->setScore(_score);
	return true;
}

int Student::GetCount(void) {
	return count;
}

int Student::getCourseCount(void) {
	return courseNumber;
}

Student& Student::addCourse(Course *course) {
	if (course == NULL) {
		printf("Course added connot be NULL!\n");
		return *this;
	}



	if (typeid(*course).name() == typeid(ObligatoryCourse).name()) {
		Course* c;
		c = new ObligatoryCourse(course->getName(), course->getCreditHour());
		courseList[courseNumber++] = c;
	}
	if (typeid(*course).name() == typeid(ElectiveCourse).name()) {
		Course* c;
		c = new ElectiveCourse(course->getName(), course->getCreditHour());
		courseList[courseNumber++] = c;
	}


	return *this;
}
/*
string Student::getCourseTAG(int _index) {
	if (_index <= 0 || _index > courseNumber) {
		return "请输入正确的课程序号";
	}
	return courseList[_index-1]->getTAG();
}
*/

bool Student::removeCourse(int k) {
	if (courseNumber < k || k <= 0)return false;
	Course *p, *s;
	p = courseList[k - 1];
	for (int i = k - 1; i < courseNumber - 1; i++) {
		courseList[i] = courseList[i + 1];
	}
	courseList[courseNumber - 1] = NULL;


	if (typeid(*p).name() == typeid(ObligatoryCourse).name()) {
		ObligatoryCourse *Op = dynamic_cast<ObligatoryCourse*>(p);
		delete Op;
		courseNumber--;
	}
	else if (typeid(*p).name() == typeid(ElectiveCourse).name()) {
		ElectiveCourse *Ep = dynamic_cast<ElectiveCourse*>(p);
		delete Ep;
		courseNumber--;
	}

	return true;
}

float Student::calcCredit(void) {
	float obCredit = 0.0f, elCredit = 0.0f;
	float obCreditHour = 0.0f, elCreditHour = 0.0f;
	//			
	for (int i = 0; i < courseNumber ; i++) {
		if (typeid((*courseList[i])).name() == typeid(ObligatoryCourse).name()) {
			obCreditHour += (1.0f)*(courseList[i]->getCreditHour());
		}
		else if (typeid((*courseList[i])).name() == typeid(ElectiveCourse).name()) {
			elCreditHour += (1.0f)*(courseList[i]->getCreditHour());
		}
	}
	for (int i = 0; i < courseNumber ; i++) {
		if (typeid((*courseList[i])).name() == typeid(ObligatoryCourse).name()) {
			obCredit += (1.0f)*(courseList[i]->getScore())*(courseList[i]->getCreditHour()) / obCreditHour;
		}
		else if (typeid((*courseList[i])).name() == typeid(ElectiveCourse).name()) {
			elCredit += (1.0f)*(courseList[i]->getScore())*(courseList[i]->getCreditHour()) / elCreditHour;
		}
	}
	return obCredit*0.6 + elCredit*0.4;


}

ostream& operator<<(ostream& os, Student& student) {
	os << "姓名: " << student.GetName() << " 出生日期: " << *(student.GetBirthday()) << " 选课信息如下:" << endl;
	for (int i = 0; i < student.courseNumber; i++) {
		os << *(student.courseList[i]) << endl;
	}
	return os;
};