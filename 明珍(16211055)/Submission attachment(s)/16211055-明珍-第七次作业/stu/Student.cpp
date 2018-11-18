#include "Student.h"
#include "Date.h"
#include <iostream>
#include <string.h>
#include "Course.h"
#include "obligatorycourse.h"
//#include "obligatorycourse.h"
//#include "obligatorycourse.h"
#include "electivecourse.h"
#include "fstream"
#include <sstream>
using namespace std;

int Student::count=0;

ostream& operator<<(ostream& o, const Student& c) {


	o << "������" << c.getName() << "   ��������:" << c.getBirthDate().getYear() << "-" << c.getBirthDate().getMonth() << "-" << c.getBirthDate().getDay()
		<< ",ѡ����Ϣ����:" << std::endl;

	for (int i = 0; i < c.getCourseNumber(); ++i) {
		o << *c.courseList[i];
	}
	return o;
}

istream& operator >> (istream& i,  Student& c) {

	char name[32];
	char date[32];
	char line[1024];

	i.getline(line, 1024);
	sscanf(line,"������%s   ��������:%s,ѡ����Ϣ����:",name,date);
	c.setName(name);

	std::istringstream iss(date);

	Date d;
	iss >> d;
	c.setBirthdate(d);

	//�ָ��γ���Ϣ
	while (!i.eof()) {
		i.getline(line, 1024);
		if(strlen(line)<5)
			continue;
		int s;
		int s2;
		sscanf(line, "�γ����ƣ�%s   ѧ�֣�%d  �ɼ���%d", name,&s,&s2);

		ObligatoryCourse* oc = new ObligatoryCourse(name,s);
		oc->setMark(s2);
		oc->setCreditHour(s);
		c.addCourse(oc);

	}


	return i;
}
Student::Student(const string &name, const Date& birthDate):birthDate(birthDate) {

	this->name = new char[name.size()+1];
	strcpy(this->name, name.data());
	++count;
	courseNumber = 0;
}
Student::Student(const char* const n,int y,int m,int d):birthDate(Date(y, m, d))
{

    //CourseNumber=0;
    name=new char[strlen(n)+1];
    strcpy(name, n);
	++count;
	courseNumber = 0;
}

Student::Student(const Student& stu) {



	setBirthdate(stu.getBirthDate());

	char *name = stu.getName();
	if (!name)
		return;

	delete[]this->name;
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);

	++count;
	courseNumber = 0;
}

bool Student::removeCourse(int i) {
	if (i >= courseNumber)
		return false;

	for (int k = i + 1; k < courseNumber; ++k)
	{
		courseList[k - 1] = courseList[k];
	}
	--courseNumber;
	return true;

}

void Student::setName(char *name)
{
    char x[5]="Jack" ;
    if(!name)
    {
        delete []name ;
        name = new char[5] ;
        strcpy(name,x) ;
    }
}

Student::~Student()
{
    delete []name;
    cout <<" xiaoqu";//dtor
    count --;
}

void Student::setBirthdate(const Date& date)
{
    birthDate.setDate(date.getYear(),date.getMonth(),date.getDay());
}

Student& Student::addCourse(Course *course)
{
    if(courseNumber>=MAX_SIZE)
        throw MyException("�����±�Խ�磡");

        courseList[courseNumber]=course;
		courseNumber++;
		return *this;
}
Student& Student::addCourse(const string &courseName, int creditHour)
{
	//��Ȼ�����˴���ӿڣ���ô�������������ʹ����

#if 0
        Course *course = new Course(courseName,creditHour);
        course->setName(name);
        course->setCreditHour(creditHour);
        courseList[courseNumber]=course;
		courseNumber++;
#endif
		return *this;
}

float Student::calcCredit()const {

	float ret = 0.0f;
	float objW = .6f;
	float electW = .4f;
	int allCredit = 0;
	int eleCount = 0;
	for (int i = 0; i < courseNumber; ++i) {
		Course* c = courseList[i];
		if (c->type) {
			allCredit += c->getCreditHour();
		}
		else
			++eleCount;
	}
	for (int i = 0; i < courseNumber; ++i) {
		Course* c = courseList[i];
		if (c->type) {
			ret += objW*(c->getScore()*c->getCreditHour() / allCredit);
		}
		else {
			ret += electW*(c->getScore()/eleCount);
		}
	}

	return ret;
}
