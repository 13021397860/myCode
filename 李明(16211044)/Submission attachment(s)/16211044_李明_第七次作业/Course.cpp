#include "Course.h"

#include <iomanip>

Course::Course() : name("default")
{
    setCreditHour(0);
}

Course::Course(const std::string& nawa, const int& CH) : name(nawa)
{
    setCreditHour(CH);
}

Course::Course(const Course& another) : name(another.name)
{
    setCreditHour(another.creditHour);
}

Course::~Course()
{

}

bool Course::operator ==(const Course& another)
{
    return (this->creditHour == another.creditHour) && (this->name == another.name);
}

//std::istream& operator >>(std::istream& input, Course& course)
//{
//
//    return input;
//}

std::ostream& operator <<(std::ostream& output, const Course& course)
{
    output << "Course name: "
        << std::setw(32) << std::left << course.name
        << "Credit hour: "
        << std::setw(16) << std::left << course.creditHour;
    return output;
}

void Course::setCreditHour(const int& CH)
{
    creditHour = CH;
}

std::string Course::getName() const
{
    return name;
}

int Course::getCreditHour() const
{
    return creditHour;
}
