
#include "Student.h"
#include "Date.h"
#include "MyException.h"
#include<iostream>
#include<cstring>

using namespace std;

int Student::count = 0;

Student::Student() {
	name = NULL;
	count++;
	courseNumber = 0;//electiveNumber = obligatoryNumber = 0;
}

Student::Student(const char *const _name, const Date &birth) :birthDate(birth) {
	name = NULL;
	setname(_name);
	count++;
	courseNumber = 0;//electiveNumber = obligatoryNumber = 0;
}

Student::Student(const char *const _name, int y, int m, int d) :birthDate(y, m, d) {
	name = NULL;
	setname(_name);
	count++;
	courseNumber = 0;//electiveNumber = obligatoryNumber = 0;
}

Student::Student(const Student &stu) :birthDate(stu.birthDate) {
	name = NULL;
	setname(stu.name);
	count++;
	courseNumber = 0;//electiveNumber = obligatoryNumber = 0;
}

Student::~Student() {
	if(name != NULL) delete[] name;
	--count;
	//for (int i = 0; i < courseNumber; ++i) delete courseList[i];
	//if(courseNumber > 0) delete[] courseList;
}

Student & Student::addCourse(Course * course)
{
	if (courseNumber < MAX_SIZE) {
		courseList[courseNumber++] = course;
	}
	return *this;
}
/*
Student & Student::addCourse(const string & n, int h)
{
	if (courseNumber < MAX_SIZE) {
		courseList[courseNumber++] = new Course(n, h);//不能实例化，删除该方式
	}
	return *this;
}
*/
bool Student::removeCourse(int i)
{
	if (i < courseNumber) {
		--courseNumber;
		for (int k = i; k < courseNumber; ++k)
			courseList[k] = courseList[k + 1];
		return true;
	}
	return false;
}

bool Student::removeCourse(const string & n)
{
	int pos = courseNumber;
	for (int i = 0; i < courseNumber; ++i) {
		if (n == courseList[i]->getName()) {
			pos = i;
			break;
		}
	}
	if (pos < courseNumber) return removeCourse(pos);
	return false;
}

void Student::setbirthDate(const Date &a) {
	birthDate = a;
}

void Student::setname(const char * const _name) {
	if (name != NULL) delete[] name;
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
}

const Date& Student::getbirthDate() const{
	return birthDate;
}

const char* Student::getname() const{
	return name;
}

bool Student::print() {////由于输出中存在对不合法日期的修改，没有加const。bool类型表示输出成功与否
	if (name == NULL) return 0;
	cout << "name : " << name << ";   birthday : ";
	return birthDate.print();
}

int Student::getcount()
{
	return count;
}

const Course & Student::operator[](int index) const
{
	if (index > courseNumber || index < 0) {
		//cerr << "下标越界\n";
		//return *courseList[0];
		throw MyException(Range_error);
	}
	return *courseList[index];
}

Course & Student::operator[](int index)
{
	if (index > courseNumber || index < 0) {
		//cerr << "下标越界\n";
		//return *courseList[0];
		throw MyException(Range_error);
	}
	return *courseList[index];
}

const double Student::getAchievement() const
{
	double ecNum = 0, ocCredit = 0, result = 0, ecScore = 0, ocScore = 0;
	for (int i = 0; i < courseNumber; i++)
	{
		if (typeid(ElectiveCourse) == typeid((*this)[i])) {
			ecNum++;
			ecScore += courseList[i]->getScore();
		}
		else {
			ocCredit += courseList[i]->getCreditHour();
			ocScore += courseList[i]->getScore() * courseList[i]->getCreditHour();
		}
	}
	if (ocCredit > 0) result += 0.6 * ocScore / ocCredit;
	if (ecNum > 0) result += 0.4 * ecScore / ecNum;
	return result;
}

ostream & operator<<(ostream & output, const Student & s)
{
	output << "姓名： " << s.name << "\t出生日期： " << s.birthDate
		<< "\t 绩点成绩： " << s.getAchievement()
		<< ", 选课信息如下:\n";
	for (int i = 0; i < s.courseNumber; ++i) {
		output << *s.courseList[i] << '\n';//(*s.courseList[i]) ?
	}
	return output;
}
