#include "student.h" // class's header file
#include <iostream> 
#include <cstring> 
#include<stdio.h>
#include "date.h"
#include "course.h" 
#include"obligatorycourse.h"
#include"electivecourse.h"
#include "myexception.h"
#include<iomanip>
using namespace std;
int Student::count=0;
// class constructor
Student::Student(const char *const n,const int &y,const int &m,const int &d)
	:birthDate(y,m,d)
{
	courseNumber=0; 
	name=0;
	count++;
	setname(n);
	// insert your code here
}
Student::Student(const char *const n,const Date &d)
	:birthDate(d)
{
	courseNumber=0;
	name=0;
	count++;
	setname(n);
}
Student::Student(const Student &s)
	:birthDate(s.birthDate)
{
	///差一个相等 
	courseNumber=s.courseNumber;
	name=0;
	count++;
	setname(s.name);
}
// class destructor
Student::~Student()
{
	while(courseNumber){
		delete courseList[courseNumber-1];
		courseNumber--;
	}
	delete[] name;
	count--;
	// insert your code here
}
void Student::setname(const char *const n){
	if(name!=NULL)delete[] name;
	name=new char[strlen(n)+1];
	strcpy(name,n);
	return;
}
void Student::print()
const
{
	printf("%s ",name);
	birthDate.print();
}
Student& Student::addCourse(Course *&course){
	courseList[courseNumber]=course;//这种方法不占内存，没有NEW 
	courseNumber++;
	return *this;
} 
/*Student& Student::addCourse(ObligatoryCourse *course){
	courseList[courseNumber]=new ObligatoryCourse(*course);
	courseNumber++;
	return *this;
} 
Student& Student::addCourse(ElectiveCourse *course){
	courseList[courseNumber]=new ElectiveCourse(*course);
	courseNumber++;
	return *this;
} */
/*Student& Student::addCourse(const string &courseName, int creditHour){
	courseList[courseNumber]=new Course(courseName,creditHour);//这种方法占内存，而且析构是需要DELETE 
	//courseList[courseNumber]->setname(courseName);
	//courseList[courseNumber]->setcreditHour(creditHour);
	courseNumber++;
	return *this;
}*/ 
bool Student::removeCourse(int i){
	if(i<=courseNumber&&i>=1){
		delete courseList[i-1];
		for(int j=i;j<=courseNumber-1;j++){
			courseList[j-1]=courseList[j];
		}
		courseNumber--;
		return 1;
	}
	else{
		return 0;
	}
}
void Student::printCourse()const{
	cout<<"已选课程："<<endl; 
	for(int i=0;i<courseNumber;i++){
		cout<<setw(2)<<i+1;
		courseList[i]->print();
	}
}
ostream & operator <<(ostream &output,Student &s){
	output<<"姓名："<<s.name<<"出生日期："<<s.birthDate<<"选课信息如下"<<endl;
	for(int i=0;i<s.courseNumber;i++){
		output<<setw(2)<<i+1;
		output<<*s.courseList[i];
	}
	return output;
}
Course & Student::operator [](int i){
	if (i<0||i>=courseNumber ){
	   throw MyException(RANGE_ERROR);
	}
	return *courseList[i];
}
const double Student::calcCredit()const{
	double t1=0,t2=0,t3=0,t4=0;
	for(int i=0;i<courseNumber;i++){
		if(courseList[i]->getScore()==-1){
			return -1; 
		}
		else{
			if(courseList[i]->getType()==1){
				t1+=courseList[i]->getScore()*courseList[i]->getcreditHour();
				t2+=courseList[i]->getcreditHour();
			}
			else{
				t3+=courseList[i]->getScore();
				t4++;
			}
		}
	}
	if(t2==0||t4==0){
		return -3;
	}
	return 0.6*t1/t2+0.4*t3/t4;
}
