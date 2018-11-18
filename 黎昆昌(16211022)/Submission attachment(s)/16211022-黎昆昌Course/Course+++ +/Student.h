#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#include "Course.h"
#define MAX_SIZE 10

class Student
{
    public:
        Student(char *,int=1998 ,int=4 ,int=4);
        Student(char *,Date);
        Student(const Student &t);
        ~Student();

        void setMessage(char *,int ,int ,int);
        void setName(char *);
        void setBirthDate(int ,int ,int);
        char *getName() const;
        Date getBirthDate() const;
        static int getCount();
        Student& addCourse(Course *);
        //Student& addCourse(const string &,int);
        int getCourseNumber() const;
        void setCourseScore(int,int);
        bool removeCourse(int);
        void getCourseScore(int) const;
        float calcCredit();
        void readCourseMessage() const;
        void readObligatoryCourseMessage() const;
        void readElectiveCourseMessage() const;
        void safeMessage() const;

        friend ostream &operator<<(ostream &, const Student &);

    private:
        char *name;
        Date birthDate;
        static int count;
        Course *courseList[MAX_SIZE];
        int courseNumber;
};

#endif // STUDENT_H
