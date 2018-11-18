#include "Student.h"
#include "Course.h"
#include <string>
#include <iostream>
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#include <fstream>
#include "Exception.h"
Student::Student(int stuID, const char *nam,const Date &birth):birthDate(birth){
    number++;
    ID=stuID;
    int i;
    for(i=0;nam[i]!='\0';i++);//名字长度
    length=i;
    name=new char[i+1];
    strcpy(name,nam);
	courseNumber = 0;
}
Student::Student(const Student &T):birthDate(T.birthDate){
    number++;
    name=new char[T.length+1];
    length=T.length;
    strcpy(name,T.name);
	courseNumber = 0;
}
Student::~Student()
{
    if (name) delete[] name;
    number--;
	while (courseNumber != 0) {
		delete courseList[--courseNumber];
	}
}
bool Student::changeName(const char *newName){
	if (name) delete[] name;
    int i;
    for(i=0;newName[i]!='\0';i++);//新名字长度
    length=i;
    name=new char[length+1];
    strcpy(name,newName);
    return true;
}
void Student::getName(char*& get)const{
    get=new char[length+1];
    strcpy(get,name);
}
void Student::getBirthday(Date& get)const{
    get.setAll(birthDate.getYear(),birthDate.getMonth(),birthDate.getDay());
}
void Student::getID(int& get)const{
    get=ID;
}
void Student::howMany(int& num)const{
    num=number;
}
int Student::number=0;
bool Student::courseMax() {
	return courseNumber >= MAX_SIZE;
}
Student& Student::addCourse(Course &course) {
	if (courseMax()) {
		IOOBException ex(ClassID);
		throw ex;
		return *this;
	}
	int temp_hour;
	std::string temp_name;
		course.getCreditHour(temp_hour);
		course.getName(temp_name);
	if (typeid(course) == typeid(ElectiveCourse)) {
		//ECOURSE
		courseList[courseNumber++] = new ElectiveCourse(temp_name, temp_hour);
	}
	else if(typeid(course) == typeid(ObligatoryCourse)) {
		courseList[courseNumber++] = new ObligatoryCourse(temp_name, temp_hour);
	}
	return *this;
}
Student& Student::addCourse(const std::string &courseName, int creditHour, bool ifAECourse) {
	if (courseMax()) {
		IOOBException ex(ClassID);
		throw ex;
		return *this;
	}
	Course *temp;
	if (ifAECourse) {
		temp = new ElectiveCourse(courseName,creditHour);
	}
	else {
		temp = new ObligatoryCourse(courseName, creditHour);
	}
	courseList[courseNumber++] = temp;
	return *this;
}
int Student::getCourseNumber()const {
	return courseNumber;
}
void Student::getBirthday(int &Year, int &Month, int &Day) {
	Year = birthDate.getYear();
	Month = birthDate.getMonth();
	Day = birthDate.getDay();
}
std::ostream& operator <<(std::ostream& output_student,const Student& student) {
	output_student << "姓名：" << student.name << " 出生日期：" << student.birthDate << ", 选课信息如下：" << std::endl;
	for (int i = 0; i < student.courseNumber; i++) { 
		output_student << *(student.courseList[i]) << std::endl;
	}
	return output_student;
}
std::ofstream& operator <<(std::ofstream& outputf_student,const Student& student) {
	outputf_student << student.name/*这个是C风格的字符串*/ << " ";
	outputf_student<< student.birthDate/*这个是date类型，里面重载了ofstream流运算符*/ << " "<<std::endl ;
	/*
	这么写会炸，会调用student.birthDate重载的ostream流
	outputf_student << student.name<< " "<< student.birthDate<< " "<<std::endl ;
	感觉是student.name输出以后那个运算符重载函数返回了什么奇奇怪怪的东西。
	虽然从断点调试来看调用了ostream的流运算符，
	但不知为啥还是能输出到文件
	*/
	for (int i = 0; i < student.courseNumber; i++) {
		outputf_student << *(student.courseList[i]) << std::endl;
	}
	return outputf_student;
}
bool Student::removeCourse(int i) {
	if (getCourseNumber() < i || i<1) {
		OORException ex(ClassID);
		throw ex;
		return false;
	}
	else {
		i--;//从0开始
		delete courseList[i];
		courseList[i]=courseList[--courseNumber];
		return true;
	}
}
bool Student::changeGrade(int i, int grade) {
	i--;
	if (i > courseNumber || i < 0) { 
		OORException ex(ClassID);
		throw ex;
		return false;
	}
	if (typeid(*(courseList[i])) != typeid(ObligatoryCourse)) {
		OORException ex(ClassID);
		throw ex;
		return false;
	}
	dynamic_cast<ObligatoryCourse*> (courseList[i])->setMark(grade);
	return true;
}
bool Student::changeGrade(int i, char grade) {
	i--;
	if (i > courseNumber || i < 0) {
		OORException ex(ClassID);
		throw ex;
		return false;
	}
	if (typeid(*(courseList[i])) != typeid(ElectiveCourse)) {
		OORException ex(ClassID);
		throw ex;
		return false;
	}
	dynamic_cast<ElectiveCourse*> (courseList[i])->setScore(grade);
	return true;
}
void Student::printGrade(int i)const {
	i--;
	if (typeid(*(courseList[i])) == typeid(ElectiveCourse)) {
		std::cout<<dynamic_cast<ElectiveCourse*> (courseList[i])->getScore()<<std::endl;
	}
	else {
		std::cout << dynamic_cast<ObligatoryCourse*> (courseList[i])->getScore() << std::endl;
	}
}
const Course& Student::getCourse(int i)const {
	i--;
	if (0 <= i && i <= courseNumber) {
		return *courseList[i];
	}
	else {
		OORException ex(ClassID);
		throw ex;
	}
}
double Student::caleCredit() const {
	int sumcre_Oc=0;
	int sumcre_Ec=0;
	int temp=0;
	int sum_Ec=0,sum_Oc=0;
	for (int i = 0; i < courseNumber; i++) {
		if (typeid(*courseList[i]) == typeid(ElectiveCourse)) {
			sumcre_Ec ++;
		}else if (typeid(*courseList[i]) == typeid(ObligatoryCourse)) {
			(dynamic_cast<ObligatoryCourse*>(courseList[i]))->getCreditHour(temp);
			sumcre_Oc += temp;
		}
	}
	for (int i = 0; i < courseNumber; i++) {
		int score=(*courseList[i]).getScore();
		if (score == -1) {
			//未设置成绩
			NGException ex(ClassID);
			throw ex;
			return -1;
		}
		if (typeid(*courseList[i]) == typeid(ElectiveCourse)) {
			(dynamic_cast<ElectiveCourse*>(courseList[i]))->getCreditHour(temp);
			sum_Ec += (score/ sumcre_Ec);
		}
		else if (typeid(*courseList[i]) == typeid(ObligatoryCourse)) {
			(dynamic_cast<ObligatoryCourse*>(courseList[i]))->getCreditHour(temp);
			sum_Oc += (score*temp / sumcre_Oc);
		}
	}
	return 0.6*sum_Oc + 0.4*sum_Ec;
}
int Student::classID() const {
	return ClassID;
}