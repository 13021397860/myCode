#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 10
#include "Date.h"
#include "Course.h"
#include <iostream>
#include <string>
using namespace std;
class Student
{
    friend ostream& operator<<(ostream&, const Student &s);
    public:
        double calcAchievement() const;	//计算学生的积点成绩

    bool existCourse(Course *course);
        Student& addCourse(Course *course);


        bool removeCourse(int i);
        bool removeCourse(const string& courseName);
    const Course& operator[](int subscript) const;
        Course& operator[](int subscript);

        Student& setName(const char* const n);

    const char* getName() const {return name;}
        const Date& getBirthDate() const {return birthDate;}
        static int getCount() {return count;}
        int getCourseNumber()const {return courseNumber;}

        Student(const char* const n, int y, int m, int d);
        Student(const char* const n, const Date &d);
        ///
        Student(const Student &s);
        virtual ~Student();


    private:
        char *name;
        const Date birthDate;
        static int count;

    int courseNumber;   //当前实际课程数目
        Course *courseList[MAX_SIZE];

        int calcObligatoryCredit() const;
        int calcElectiveNumber() const;
};

#endif // STUDENT_H
