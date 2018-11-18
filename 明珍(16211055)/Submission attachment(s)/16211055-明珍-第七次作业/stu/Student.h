#ifndef STUDATE_H
#define STUDATE_H
#include "Date.h"
#include "Course.h"

#include <string>

#define MAX_SIZE 50
using namespace std;
#define  _CRT_SECURE_NO_WARNINGS
class Student
{
public:
	friend ostream& operator<<(ostream& o, const Student& c);
	friend istream& operator>>(istream& i,  Student& c);

	virtual ~Student();
	Student(const string &name="", const Date& birthDate=Date());
	Student(const char* const, int, int, int);//构造函数
	Student(const Student&);//拷贝构造
	char *getName()const { return name; }//可以不用get  直接输出name
	Date getBirthDate() const{
		return birthDate;
	}
	void setBirthdate(const Date& date);
	void setName(char *);

	Student& addCourse(Course *course);
	Student& addCourse(const string &courseName, int creditHour);
	int setCourseNumber(int n) {
		courseNumber = n;
	}
	int getCourseNumber() const { return courseNumber; }
	Course *courseList[MAX_SIZE];
	bool removeCourse(int i);



	float calcCredit()const;

protected:

 private:
    char* name;
    Date birthDate;
    static int  count;
    int courseNumber;

};
#endif // STUDATE_H
;
