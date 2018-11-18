#include "Student.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "StudentException.h" 
#include <iostream>
#include <typeinfo>
#include <cstring>
using namespace std;

int Student::count=0;

Student::Student(const char *studentName, int y, int m, int d) 
:birthDate(y, m, d), courseNumber(0), name(NULL)
{
    setName(studentName);
    count++;
}

Student::Student(const char *studentName, const Date &studentDate)
:birthDate(studentDate), courseNumber(0), name(NULL)
{
    setName(studentName);
	count++;	
}

Student::Student(const Student &stud)
:birthDate(stud.birthDate), courseNumber(0), name(NULL)
{
    setName(stud.name);
    count++;
}

Student &Student::setName(const char *studentName)
{
    if(name == NULL) delete[] name;
    name = new char[strlen(studentName)+1];
    strcpy(name, studentName);
    return *this;
}

ostream& operator<<(ostream& output, const Student& stud)
{
	output << "姓名：" << stud.name << "，出生日期：" << stud.birthDate
		   << "，选课信息如下：" << endl;
    for(int i = 0; i < stud.courseNumber; i++)
    {
        output << (*stud.courseList[i]) << endl;
    }
	return output;
}

/*void Student::printStudent() const
{
	cout<<"The student\'name is: "<<name<<endl
		<<"The student\'s birthdaty is：";
	birthDate.printDate();
}

void Student::printCourse() const
{
	for(int i = 0; i < courseNumber; i++)
    {
        cout<< "The course is: " << courseList[i] -> getCourseName() << endl
        	<< "The credit hour is：" << courseList[i] -> getCreditHour() <<endl
			<< "The grade is：" << courseList[i] -> getScore()
			<< "\n" << endl;
    }
}*/

Student &Student::addCourse(Course *course)
{
    if(courseNumber >= MAX_SIZE)	throw StudentException();
    else
    {
        courseList[courseNumber] = course;
        courseNumber++;
    }
    return *this;	
}

/*Student &Student::addCourse(const string &courseName, int credit)
{
    if(courseNumber >= MAX_SIZE)	exit(1);
    else
	{
		courseList[courseNumber] = new Course(courseName, credit);
		courseNumber++;
	}
	return *this;	
}*/

double Student::calcCredit()
{
	int temp1 = 0, sumhourOC = 0;
	int temp2 = 0, sumhourEC = 0;
	for(int i = 0; i < courseNumber; i++)
	{
		if(typeid(ObligatoryCourse) == typeid(*courseList[i]))
		{
			temp1 += (courseList[i]->getScore() * courseList[i]->getCreditHour());
			sumhourOC += courseList[i]->getCreditHour();
		}
		else if(typeid(ElectiveCourse) == typeid(*courseList[i])) 
		{
			temp2 += (courseList[i]->getScore() * courseList[i]->getCreditHour());
			sumhourEC += courseList[i]->getCreditHour();
		}		
	}
	if(sumhourOC == 0 && sumhourEC == 0) return 0;
	else if(sumhourOC == 0) return (0.4*(temp2/sumhourEC));
	else if(sumhourEC == 0) return (0.6*(temp1/sumhourOC));
	else return (0.6*(temp1/sumhourOC) + 0.4*(temp2/sumhourEC));
}

bool Student::removeCourse(int i)
{
	if(i > courseNumber || i <= 0)
	{
		throw StudentException();
		return false;
	}
	
	else
	{
        for(int k = i; k < courseNumber; k++)
        {
            courseList[ k - 1 ]=courseList[ k ];
        }
        courseNumber--;
		return true;
	}
}

Student::~Student()
{
	delete[] name;
	count--;
}
