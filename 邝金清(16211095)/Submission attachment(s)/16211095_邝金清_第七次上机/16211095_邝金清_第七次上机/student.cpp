#include "student.h"
#include <typeinfo>
#include <cstring>
#include <stdio.h>
#include <iostream>
int student::counts = 0;

void student::setName(const char * _name)
{
    name = new char [strlen(_name) + 1];
    strcpy(name, _name);
}
void student::getBirthDate(int &y, int &m, int &d) const
{
    y = birthdate.getYear();
    m = birthdate.getMonth();
    d = birthdate.getDay();
}
void student::getName(char * _name) const
{
    strcpy(_name, name);
}
student::student(const char * _name, int _year, int _month, int _day) : birthdate(_year, _month, _day)
{
    courseNumber = 0;
    ++counts;
    setName(_name);
}
student::student(const student & another_student) : birthdate(another_student.birthdate)
{
    courseNumber = 0;
    ++counts;
    int y, m, d;
    another_student.getBirthDate(y, m, d);
    char * _name = new char [50];
    another_student.getName(_name);
    setName(_name);
    delete [] _name;
}
student::~student()
{
    --counts;
    delete [] name;
    for (int i = 0; i < courseNumber; ++i)
        delete courseList[i];
}
std::ostream& operator<< (std::ostream& out, student& A)
{
    out << "\t-----The Student Info-----\n";
    out << "Name: " << A.name << std::endl;
    out << "Birth Date: " << A.birthdate << std::endl;
    out << "The following is his(her) course info:\n";
    for (int i = 0; i < A.courseNumber; ++i)
        out << '(' << i + 1 << ')' << *A.courseList[i] << std::endl;
}
bool student::removeCourse(int i)
{
    if (i > courseNumber)
        throw MyException("Course Error.");
    delete courseList[i - 1];
    for (int j = i; j < courseNumber; ++j)
        courseList[j - 1] = courseList[j];
    --courseNumber;
}
double student::calcCredit()
{
    double obl_score = 0, sum_score = 0, ele_score = 0, eles = 0;
    for (int i = 0; i < courseNumber; ++i)
    {
        if (typeid(*courseList[i]) == typeid(ObligatoryCourse))
        {
            obl_score += courseList[i]->getCredit() * courseList[i]->getScore();
            sum_score += courseList[i]->getScore();
        }
        else
        {
            ele_score += courseList[i]->getScore();
            ++eles;
        }
    }
    return (0.6 * (obl_score / sum_score) + 0.4 * (ele_score / eles));
}
/*void student::print() const
{
    printf("\t-----The Student Info-----\n");
    printf("Name: %s\n", name);
    printf("Birth Date: %d/%d/%d\n", birthdate.getYear(), birthdate.getMonth(), birthdate.getDay());
    printf("Now the number of students is %d\n", student::counts);
    printf("The following is his(her) course info:\n");
    for (int i = 0; i < courseNumber; ++i)
        courseList[i]->print();
}*/
