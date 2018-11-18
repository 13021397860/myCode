#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
#include "Student.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#define MAX_SIZE 100
#define SIZE 32

using namespace std;

/* ------ begin of Student -------*/

int Student::count = 0;

Student::Student()
{
    name = NULL;
    setName(NULL);
    birthDate.setDate(2000, 1, 1);
    courseNumber = 0;
    count++;
}

Student::Student(const char *n, int y, int m, int d)
{
    name = NULL;
    setName(n);
    birthDate.setDate(y, m, d);
    courseNumber = 0;
    count++;
}

Student::Student(const char *n, const Date &_copydate)
{
    name = NULL;
    setName(n);
    birthDate = _copydate;
    courseNumber = 0;
    count++;
}

Student::Student(const Student &_s)
{
    int i;
    name = NULL;
    setName(_s.name);
    birthDate = _s.birthDate;
    courseNumber = 0;
    for(i = 0; i < _s.courseNumber; i++) addCourse(_s.courseList[i]);
    count++;
}

Student::~Student()
{
/*
    cout << "Student " << this -> name << " who is born on ";
    birthDate.print();
    cout << " has been deleted.\n";
*/
    delete[] name;
    int i;
    for(i = 0; i < courseNumber; i++) delete courseList[i];
    count--;
}

char* Student::getName() const
{
    return name;
}

Date Student::getBirthDate() const
{
    return birthDate;
}

void Student::setName(const char *n)
{
    if(name) delete[] name;
    if(n != NULL and strlen(n) != 0)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    else
    {
        char a[] = "Unknown";
        name = new char[8];
        strcpy(name, a);
    }
}

void Student::setBirthDate(int y, int m, int d)
{
    birthDate.setDate(y, m, d);
}

void Student::setBirthDate(const Date &_copydate)
{
    birthDate = _copydate;
}

void Student::print() const
{
    cout << "Student " << name << " is born on " << birthDate << "." << endl;
}

int Student::getStudentCount()
{
    return Student::count;
}

Student& Student::addCourse(const Course *_c)
{
    if(_c and courseNumber < MAX_SIZE)
    {
        Course *c;
        if(_c -> testObligatory()) c = new ObligatoryCourse(_c -> getName(), _c -> getCreditHour(), _c -> getScore());
        else c = new ElectiveCourse(_c -> getName(), _c -> getCreditHour(), _c -> getScore());
        courseList[courseNumber] = c;
        courseNumber++;
    }
    return *this;
}

Student& Student::addCourse(const string &cname, int chours, bool isObligatory)
{
    if(courseNumber < MAX_SIZE)
    {
        Course* c;
        if(isObligatory) c = new ObligatoryCourse(cname, chours);
        else c = new ElectiveCourse(cname, chours);
        courseList[courseNumber] = c;
        courseNumber++;
    }
    return *this;
}

bool Student::removeCourse(int j)
{
    if(j < 1 or j > courseNumber) throw MyException("course not selected by student");
    else
    {
        int i;
        delete courseList[j - 1];
        for(i = j; i < courseNumber; i++) courseList[i - 1] = courseList[i];
        courseNumber--;
        return true;
    }
}

void Student::printCourseList() const
{
    int i;
    cout << "Student " << name << "'s course list:" << endl;
    for(i = 0; i < courseNumber; i++)
    {
        cout << "#" << i + 1 << ": "
        << left << setw(SIZE) << courseList[i] -> getName() << " "
        /*<< courseList[i] -> getCreditHour() << "\t"
        << courseList[i] -> getScore() << "\t"
        << (courseList[i] -> testObligatory() ? "Yes" : "No")*/
        << endl;
    }
}

int Student::getCourseNumber() const
{
    return courseNumber;
}

ostream& operator << (ostream &os, const Student &_s)
{
    int i;
    os << "Student: " << _s.getName() << "   Birth Date: " << _s.getBirthDate() << endl;
    if(!_s.getCourseNumber()) os << "No Course has been selected yet." << endl;
    else
    {
        for(i = 0; i < _s.getCourseNumber(); i++) os << "#" << i + 1 << " " << *_s.courseList[i] << endl;
        os << "Credit Score: " << _s.calcCredit() << endl;
    }
    return os;
}

ofstream& operator << (ofstream &os, const Student &_s)
{
    int i;
    os << _s.getName() << endl;
    os << _s.getBirthDate() << endl;
    for(i = 0; i < _s.getCourseNumber(); i++)
    {
        os << _s.courseList[i] -> getName() << endl;
        os << _s.courseList[i] -> getCreditHour() << " " << (_s.courseList[i] -> testObligatory() ? "1" : "0") << " " << (_s.courseList[i] -> getScore()) << endl;
    }
    os << "###" << endl;
    return os;
}

Student& Student::setCourseScore(int coursenum, int grade)
{
    if(coursenum >= 1 and coursenum <= courseNumber) courseList[coursenum - 1] -> setScore(grade);
    return *this;
}

double Student::calcCredit() const
{
    double obligatoryCourseScore = 0, electiveCourseScore = 0;
    double obligatoryCourseCreditHour = 0;
    int electiveCourse = 0;
    int obligatoryCourse = 0;
    double res = 0;
    int i;
    for(i = 0; i < courseNumber; i++)
    {
        if(courseList[i] -> testObligatory())
        {
            if(courseList[i] -> getCreditHour() > 0.001)
            {
                obligatoryCourseScore += courseList[i] -> getScore() * courseList[i] -> getCreditHour();
                obligatoryCourseCreditHour += courseList[i] -> getCreditHour();
                obligatoryCourse++;
            }
        }
        else
        {
            electiveCourseScore += courseList[i] -> getScore();
            electiveCourse++;
        }
    }
    if(obligatoryCourse > 0) res += obligatoryCourseScore / obligatoryCourseCreditHour * CREDITOBLIGATORY;
    if(electiveCourse > 0) res += electiveCourseScore / electiveCourse * CREDITELECTIVE;
    return res;
}

/* ------ end of Student ---------*/
