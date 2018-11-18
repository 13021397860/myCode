#ifndef STUDENT_H
#define STUDENT_H

#include "date.h"
#include "course.h"
#include "obligatory_course.h"
#include "elective_course.h"
#define MAX_SIZE 10
class student
{
    friend std::ostream& operator<< (std::ostream& out, student&);
private:
    char * name;
    const date birthdate;
    static int counts;
    Course * courseList[MAX_SIZE];
    int courseNumber;
public:
    student(const char * _name = 0, int _year = 0, int _month = 1, int _day = 1);
    student(const char * _name = 0);
    student(const student & another_student);
    ~student();
    void getName(char *) const;
    void setName(const char *);
    void getBirthDate(int &y, int &m, int &d) const;
    //void print() const;
    student& addCourse(Course * _course)    {courseList[courseNumber++] = _course;}
    //student& addCourse(const string& _courseName, int _creditHour)  {courseList[courseNumber++] = new Course(_courseName, _creditHour);}
    bool removeCourse(int i);
    double calcCredit();
};


#endif // STUDENT_H
