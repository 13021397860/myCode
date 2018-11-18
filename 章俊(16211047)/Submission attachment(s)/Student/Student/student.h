#ifndef STUDENT_H
#define STUDENT_H
#include "time.h"
#include <cstring>
#include "course.h"
#include "obligatorycourse.h"
#include "electivecourse.h"
#include <typeinfo>
#define MAX_SIZE 10
using namespace std;
using std::ostream;
using std::istream;
class Student
{
    public:
        Student();
        Student(char *n);
        Student(char *n,int y,int m,int d);
        virtual ~Student();
        Student(const Student &s);
        void setStudent(const char* a,const Time d);
        void setname(const char *a);
        void setbirthDate(const Time d);
        char* getname()const ;
        int getcoursenumber()const;
        Time getbirthDate()const ;
        void printstudent()const ;
        void printcounter()const ;
        void printcourseList()const;
        void printcoursenumber()const;
        Student& addCourse(Course *course);
        //Student& addCourse(const string &courseName,const int creditHour);
        bool removeCourse(const int i);
        bool removeCourse(const string &s);
        bool setCourseScore();

        int calObligatorycredit() const;
        int calElectiveNumber() const;
        int calElectivecredit() const;
        int calObligatoryNumber() const;
        double calAchievement() ;
        friend ostream& operator<<(ostream& output, const Student& s);
        Course* operator[](int ) const;
    protected:

    private:
        char *name;
        Time birthDate;
        static int counter;
        Course *courseList[MAX_SIZE];
        int coursenumber;
};

#endif // STUDENT_H
