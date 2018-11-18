#include "Student.h"
#include "Date.h"

#include <iostream>
#include <cstring>
#include <iomanip>
#include <typeinfo>

#define OC_POWER 0.6
#define EC_POWER 0.4

int Student::counter = 0;

Student::Student() : birthDate()
{
    setName("default");
    courseNumber = 0;
    ++counter;
}

Student::Student(const char* const nawa) : birthDate()
{
    setName(nawa);
    courseNumber = 0;
    ++counter;
}

Student::Student(const int &y, const int &m, const int &d) : birthDate(y,m,d)
{
    setName("default");
    courseNumber = 0;
    ++counter;
}

Student::Student(const char* const nawa, const int &y, const int &m, const int &d) : birthDate(y,m,d)
{
    setName(nawa);
    courseNumber = 0;
    ++counter;
}

Student::Student(const char* const nawa, const Date& date) : birthDate(date)
{
    setName(nawa);
}

Student::Student(const Date& date) : birthDate(date)
{
    setName("default");
}

Student::Student(const Student& another):birthDate(another.birthDate)
{
    setName(another.name);
    courseNumber = 0;
    ++counter;
}

Student::~Student()
{
    delete[] name;
    while(courseNumber)
    {
        delete courseList[--courseNumber];
    }
    --counter;
}

void Student::setBirthDate(const Date &birthday)
{
    birthDate.setDate(birthday);
}

void Student::setBirthDate(const int &y, const int &m, const int &d)
{
    birthDate.setDate(y,m,d);
}

void Student::setName(const char* const nawa)
{
    delete[] name;
    name = new char[strlen(nawa)+1];
    strcpy(name,nawa);
}

Date Student::getBirthDate() const
{
    return birthDate;
}

char* Student::getName() const
{
    return name;
}

int Student::getCourseNumber() const
{
    return courseNumber;
}

int Student::getCounter()
{
    return counter;
}

std::istream& operator >>(std::istream& input, Student& stu)
{
    std::cin.sync();
    char* nawa = new char[100];

    std::cout << "Name: ";
    std::cin >> nawa;
    stu.setName(nawa);

    std::cin.sync();
    std::cout << "Birthday (for example, 1998-1-8) : ";
    std::cin >> stu.birthDate;

    delete nawa;

    return input;
}

std::ostream& operator <<(std::ostream& output, const Student& stu)
{
    output << "Name: "
        << std::left << stu.name << "    "
        << "Birthday: "
        << stu.birthDate << "\n"
        << "Selected lesson:\n";
    if(stu.courseNumber == 0)
    {
        output << "    None\n";
    }
    else for(int i = 0; i < stu.courseNumber; ++i)
    {
        output << "    " << i+1 << "    "
            << *stu.courseList[i]
            << "Score: "
            << std::setw(3) << std::left << stu.courseList[i]->getScore()
            << " ";
        if(typeid(ObligatoryCourse&) == typeid(*stu.courseList[i]))
        {
            output << "OC" << std::endl;
        }
        else
        {
            output << "EC" << std::endl;
        }
    }
    return output;
}

Student& Student::addCourse(Course* course) //throw(Course_List_Full_Exception,Course_Existent_Exception)
{
    if(courseNumber >= MAX_COURSE)
    {
        throw Course_List_Full_Exception();
    }
    for(int i = 0; i < courseNumber; ++i)
    {
        if(*course == *courseList[i])
        {
            throw Course_Existent_Exception();
        }
    }
    courseList[courseNumber++] = course;
    return *this;
}

//Student& Student::addCourse(const std::string& courseName, const int& CH, const bool& isElective)
//{
//    if(courseNumber != MAX_COURSE)
//    {
//        if(isElective)
//            courseList[courseNumber++] = new ElectiveCourse(courseName,CH);
//        else
//            courseList[courseNumber++] = new ObligatoryCourse(courseName,CH);
//    }
//    return *this;
//}

bool Student::removeCourse(int i) //throw(Course_List_Empty_Exception)
{
    if(courseNumber == 0)
    {
        throw Course_List_Empty_Exception();
        return false;
    }
    if((i > courseNumber) || (i <= 0))
    {
        throw Course_NonExistent_Exception();
        return false;
    }
    delete courseList[--i];
    for(; i < courseNumber; ++i)
    {
        courseList[i] = courseList[i+1];
    }
    --courseNumber;
    return true;
}

double Student::calcCredit() const
{
    double gpa = 0.0;
    if(courseNumber != 0)
    {
        double oc_sum = 0.0;
        double oc_power = 0.0;
        double ec_sum = 0.0;
        double ec_power = 0.0;
        for(int i = 0; i < courseNumber; ++i)
        {
            if(typeid(ObligatoryCourse) == typeid(*courseList[i]))
            {
                oc_sum += courseList[i]->getScore() * courseList[i]->getCreditHour();
                oc_power += courseList[i]->getCreditHour();
            }
            else
            {
                ec_sum += courseList[i]->getScore();
                ++ec_power;
            }
        }
        if(oc_power != 0.0)
        {
            gpa += OC_POWER * oc_sum / oc_power;
        }
        if(ec_power != 0.0)
        {
            gpa += EC_POWER * ec_sum / ec_power;
        }
    }
    return gpa;
}
