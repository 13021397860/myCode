#include <iostream>
#include <cstring>
#include <typeinfo>
#include "Student.h"
#include "Date.h"

using namespace std;

int Student::count=0;

Student::Student(const char *theName, const Date &dateOfBirth)
	:birthDate(dateOfBirth)
{
	setName(theName);
	count++;
	courseNumber=0;
}

Student::Student(const Student &S)
	:birthDate(S.birthDate)
{
	strcpy(name,S.name);
	courseNumber=S.courseNumber;
	count++;
}

Student::~Student()
{
	delete[] name;
	/*for(int i=0;i<courseNumber;i++){
		delete courseList[i];
	}*/
	count--;
}

/*Student& Student::addCourse(const string &courseName,int creditHour)
{
	//courseList[courseNumber]=new Course(courseName,creditHour);
	if(courseNumber<MAX_SIZE)
	{
		courseList[courseNumber]=new Course;
		courseList[courseNumber]->_setName(courseName).setCreditHour(creditHour);
		courseNumber++;
	}
	return *this;
}*/

Student& Student::addCourse(Course *course)
{
	if(courseNumber<MAX_SIZE && course!=NULL)
	{
		courseList[courseNumber++]=course;
		cout<<"Success!"<<endl<<endl;
	}
	return *this;
}

char* Student::getName() const 
{
	return name;
}

Date Student::getBirthDate() const
{
	Date d(birthDate);
	return d;
}

int Student::getCount()
{
	return count;
} 

int Student::getCourseNumber() const
{
	return courseNumber;
}

void Student::setName(const char* theName)
{
	name = new char[strlen(theName)+1];
	strcpy(name,theName);
}

bool Student::removeCourse(int i)
{
	if(i<=courseNumber)
	{
		for(int j=i-1;j<courseNumber-1;j++){
			courseList[j]=courseList[j+1];
		}
		courseNumber--;
		cout<<"Success!"<<endl<<endl;
		return true;
	}
	return false;
}

/*void Student::printS() const
{
	cout<<"Name: "<<name<<endl;
	cout <<"BirthDate: "<< birthDate.getYear() << '/' << birthDate.getMonth() << '/' << birthDate.getDay()<<endl;
	//cout <<"BirthDate: "
}*/

void Student::setGrade(int n)
{
	if(n<0||n>=courseNumber){
		throw MyException(OUT_OF_RANGE);
	}
	if(typeid(ObligatoryCourse)==typeid(*courseList[n]))
	{
		cout<<"Please input the score (0-100): ";
		int x;
		scanf("%d",&x);
		if(x<0||x>100)
		{
			throw MyException(INVALID_SCORE);
		}
		dynamic_cast<ObligatoryCourse*>(courseList[n])->setScore(x);
		cout<<"Success!"<<endl<<endl;
	}
	else if(typeid(ElectiveCourse)==typeid(*courseList[n]))
	{
		cout<<"Please input the score (A-E): ";
		char c;
		cin>>c;
		if(c<'A'||c>'E')
		{
			throw MyException(INVALID_SCORE);
		}
		dynamic_cast<ElectiveCourse*>(courseList[n])->setScore(c);
		cout<<"Success!"<<endl<<endl;
	}
}

void Student::printCourse() const
{
	for(int i=0;i<courseNumber;i++){
		cout<<"    "<<i+1<<".";
		cout<<*courseList[i];
	}
}

double Student::calcCredit1() const //多态实现  本程序使用 
{
	double O_weight=0.6,E_weight=0.4,Credit=0;
	int O_Credit=0,O_sum=0,E_num=0,E_sum=0;
	int _score,_credit;
	for(int i=0;i<courseNumber;i++)
	{
		_score=courseList[i]->getScore();
		if(_score>=0)
		{
			_credit=courseList[i]->O_credit();
			O_Credit+=_credit;
			O_sum+=(_score*_credit); 
			E_num+=courseList[i]->if_E();
			E_sum+=(courseList[i]->if_E()*_score);
		}
	}
	if(O_Credit!=0){
		Credit = Credit + O_weight * O_sum / double(O_Credit);
	}
	if(E_num!=0){
		Credit = Credit + E_weight * E_sum / double(E_num);
	}
	return Credit;
}

double Student::calcCredit2() const // RTTI实现 本程序不使用 
{
	double O_weight=0.6,E_weight=0.4,Credit=0;
	int O_Credit=0,O_sum=0,E_num=0,E_sum=0;
	int _score,_credit;
	for(int i=0;i<courseNumber;i++)
	{
		_score=courseList[i]->getScore();
		if(_score>=0)
		{
			if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
			{
				_credit=courseList[i]->getCreditHour();
				O_Credit+=_credit;
				O_sum+=(_score*_credit); 
			}
			else if(typeid(ElectiveCourse)==typeid(*courseList[i]))
			{
				E_num++;
				E_sum+=_score;
			}
		}
	}
	if(O_Credit!=0){
		Credit = Credit + O_weight * O_sum / double(O_Credit);
	}
	if(E_num!=0){
		Credit = Credit + E_weight * E_sum / double(E_num);
	}
	return Credit;
}
