#include <iostream>
#include <cstring>
#include <fstream>
#include "Date.h"
#include "student.h"
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#define MAX_SIZE 20
#define ObCourse 0.6
#define ElCourse 0.4
using namespace std;
int student::count=0;
int student::courseNumber=0;
student::student()
{
	name=new char[20];
	count++;
}
void student::setname(char *s)
{
	if (s==NULL)
	{
		strcpy(name,"xxx");
	}
	else
		name=s;
}
bool student::setdate(int y,int m,int d)
{
	return t.setDate(m,d,y);
}
char* student::getname()
{
	return name;
}
int student::getYear()
{
	return t.getyear();
}
int student::getMonth()
{
	return t.getmonth();
}
int student::getDay()
{
	return t.getday();
}
Date student::getDate()
{
	return t;
}
int student::getcount()
{
	return count;
}
student& student::addCourse(Course *c)
{
	courseList[courseNumber]=c;
	courseNumber++;
	return *this;
}
string student::getCourseName(int i)
{
	return courseList[i]->getname(); 
}
int student::getCourseHour(int i)
{
	return courseList[i]->getCreditHour();
}
int student::getCourseNumber()
{
	return courseNumber;
}
Course* student::getCourse(int i)
{
	return courseList[i];
}
bool student::removeCourse(int i)
{
	if (i==0)
		return false;
	else
	{
		courseList[i]=NULL;
		delete courseList[i];
		courseNumber--;
		this->delStudentData();
		return true;
		
		
	}
	
}
int student::getmark(int i)
{
	return courseList[i]->getScore();
}
void student::setJudgeCourse(int op)
{
	judgeCourse[courseNumber-1]=op;
}
int student::calcCredit()
{
	
	int SumObCourseCredit=0;
	int SumElCourseScore=0;
	int ElCourseNumber=0;
	int SumObScoreCredit=0;
	for (int i=0;i<courseNumber;i++)
	{
		if (judgeCourse[i]==2)
		{
			SumObCourseCredit+=courseList[i]->getCreditHour();
			SumObScoreCredit+=(courseList[i]->getScore()*courseList[i]->getCreditHour());
		}
		else if (judgeCourse[i]==1)
		{
			SumElCourseScore+=courseList[i]->getScore();
			ElCourseNumber++;
		}
	}
	if (SumObCourseCredit==0&&ElCourseNumber==0)
		return 0;
	else if (SumObCourseCredit==0)
		return ElCourse*SumElCourseScore/ElCourseNumber;
	else if (ElCourseNumber==0)
		return ObCourse*SumObScoreCredit/SumObCourseCredit;
	else
		return ObCourse*SumObScoreCredit/SumObCourseCredit+ElCourse*SumElCourseScore/ElCourseNumber;
	
	
}
void student::delStudentData()
{
	vector<string> tmp_files;
 
 ifstream winfile( "StudentData.txt" );
 if ( ! winfile )
 {
 	cerr<<"文件不能打开"<<endl;
 	exit(1);
 }
 
 string lineContent;
 while ( getline( winfile, lineContent, '\n' ) )
 {
 tmp_files.push_back( lineContent + "\r\n" );
 }
 
 winfile.close();
 
 ofstream offile( "StudentData.txt",ios::out );
 vector<string>::iterator siter = tmp_files.begin();
 
 copy( tmp_files.begin(), tmp_files.end()-1, ostream_iterator<string>(offile) );
 
 offile.close();
}


