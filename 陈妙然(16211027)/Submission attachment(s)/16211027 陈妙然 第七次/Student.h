#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#include "Course.h"
#define maxsize 10
#include <string>
#include <iomanip>
using namespace std;
#define MAX_SIZE 10
class Student:public Course
{

    public:
        Student();
        friend ostream &operator<<(ostream &, Student &);
        Student(const char* const n,int m,int d,int y);
        Student(const char* const n ,const Date &birthDate);
        Student(const Student &);
        virtual ~Student();
        int getscore()
        {
            return 1;
        }
        void test();
        bool removeCourse(int i);
        void printeve()const;
        void setname(const char*n);
        char* getname()const;
        Date getbirth() const;
        void print() const;
        void printcourselist() const;
        int getcoursenumber() const;
        void printalone(int,int);
        void printzifu(int,char);
        int getscoreel(char) const;
        void printcourselistfu()const;
        Student& addCourse(Course *course);
        Student& addCourse(const string &coursename, int credithour,int scorestart=0,int flag=0);
        void shezhichengji(Student &);
        void calcCredit();


    protected:

    private:
        char *name;
        const Date birthDate;
        static int count;
        Course *courselist[MAX_SIZE];
        static int coursenumber;//amount
        friend class Course;
        friend class ElectiveCourse;
};
//
#endif // STUDENT_H
