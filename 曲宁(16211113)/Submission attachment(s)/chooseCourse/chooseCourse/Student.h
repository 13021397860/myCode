#ifndef STUDENT_H
#define STUDENT_H
#include"Date.h"
#include"Course.h"
#define MAX_SIZE 10
class Student
{
    friend ostream& operator<<(ostream&,const Student& s);
    friend ostream &operator<<(ostream &,const Course &);
    public:
        Student(const Student &);
        Student(char*,const Date &);
        virtual ~Student();
        void print()const;
        const char* getName()const;
        const Date& getBirthDate()const {return birthDate;}
        Student& setName(const char*,const char* n);
        void setName(char*);
        static int getCount() {return stuCount;}
        int getCourseNumber()const;
        bool removeCourse(int c);
        bool removeCourse(const string& courseName);
        Student& addCourse(Course *course);
        Student& addCourse(const string &courseName,int creditHour,int coursetype);
        void settheScore(const int coursetype, const int score,const char score2, const int ncourse);
        double calcCredit(int xuanNumber,int biNumber);
        int printGrade()const;

    protected:

    private:
        char *name;
        const Date birthDate;
        static int stuCount;
        Course *courseList[MAX_SIZE];
        int courseNumber=0;
};

#endif // STUDENT_H
