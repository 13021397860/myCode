#include "Student.h"
#include "MyException.h"
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;

int Student::count=0;

Student::Student(const char* const n, const Date &d)
    :birthDate(d)
{
    name=NULL;
    setName(n);
    count++;
    courseNumber=0;
}

Student::Student(const char* const n, int y, int m, int d)//���캯��
    :birthDate(y, m, d)
{
    name=NULL;
    setName(n);
    count++;
    courseNumber=0;
}

Student::Student(const Student &s)  //�������캯��
    :birthDate(s.birthDate)
{
    name=NULL;
    setName(s.name);
    count++;
    courseNumber=0;
}

Student::~Student()
{
    delete[] name;
    count--;
}

Student& Student::setName(const char * const n)
{
    if(name) delete[] name;
    name = new char[strlen(n)+1];
    strcpy(name, n);
    return *this;
}

/*void Student::print() const
{
	cout<<"������"<<name
		<<"\t���գ�";
	birthDate.print();
	cout<<"\n";
}*/

Student& Student::addCourse(Course *course)
{
    //�Ѿ�ѡ��Ŀγ̲�����ѡ�񣬱�֤�γ�ֻ��ѡ��һ��
	if ((course!=NULL)&&!existCourse(course)){
		if(courseNumber<MAX_SIZE){
			courseList[courseNumber++]=course;	//ֱ��ָ�븳ֵ
		}
	}
	return (*this);
}

/*Student& Student::addCourse(const string &courseName, int creditHour)
{
    if(courseNumber<MAX_SIZE){
		courseList[courseNumber++]=new Course(courseName, creditHour);
	}
	return (*this);
}*/

bool Student::removeCourse(int i)
{
	if(i<courseNumber){
		//delete courseList[i];
		for(int j=i;j<courseNumber-1;j++){
			courseList[j]=courseList[j+1];
		}
		courseNumber--;
		return true;
	}else{
		return false;
	}
}

bool Student::removeCourse(const string& courseName)
{
    int i;
	for(i=0;i<courseNumber;i++){
		if (courseName==courseList[i]->getName())
            break;
	}
	if (i<courseNumber){
		return removeCourse(i);
	}else{
		return false;
	}
}


bool Student::existCourse(Course *course)
{
	for(int i=0;i<courseNumber;i++){
		if(courseList[i]==course) return true;
	}
	return false;
}

const Course& Student::operator[](int subscript) const
{
	if (subscript < 0 || subscript >=courseNumber )
    {
	   throw MyException(RANGE_ERROR);
	}
	return (*courseList[subscript]);
}

Course& Student::operator[](int subscript)
{
	if (subscript < 0 || subscript >=courseNumber ){

	   throw MyException(RANGE_ERROR);
	}
	return (*courseList[subscript]);
}

int Student::calcObligatoryCredit() const
{
	int totalCredit=0;
	for(int i=0;i<courseNumber;i++){

		totalCredit += (*this)[i].getObligatoryCredit();
	}
	return totalCredit;
}

int Student::calcElectiveNumber() const
{
	int number=0;
	for(int i=0;i<courseNumber;i++){
		number += (*this)[i].getElectiveNumber();
	}
	return number;
}

double Student::calcAchievement() const
{
	int obligatoryCredit=calcObligatoryCredit();	//���޿���ѧ��
	int electiveNumber=calcElectiveNumber();	//ѡ�޿����Ŵ�

	double result=0;
	for(int i=0;i<courseNumber;i++){
		if(obligatoryCredit>0)
			result+=(*this)[i].getWeight() * (*this)[i].getScore() * (*this)[i].getObligatoryCredit()/obligatoryCredit;
		if(electiveNumber>0)
			result+=(*this)[i].getWeight() * (*this)[i].getScore() * (*this)[i].getElectiveNumber()/electiveNumber;
	}
	return result;
}

ostream& operator<<(ostream& output, const Student& s)
{
	output<<"������"<<s.name<<"\t�������ڣ�"<<s.birthDate
		<<"\t����ɼ���"<<s.calcAchievement()
		<<"��ѡ����Ϣ���£�\n";
	for(int i=0;i<s.getCourseNumber();i++){
		output<<s[i];
	}
	return output;
}
