#ifndef STUDENT_H
#define STUDENT_H
#include "date.h"
#include "course.h"
using namespace std;

class Student
{
    public:
        Student();
        virtual ~Student();

        Student(const char* ,const int,const int ,const int );
        Student(const Student&);

        void setname(const char* );

        char* getname() const;
        void getbirthDate(Date&) const;
        int getcoursenumber()const;

        static int getcount();

        Student& addCourse( Course*);
        Student& addCourse(const string &, int);
        bool removeCourse(int);

        bool setScore(int i);
        double calcCredit()const;

        friend ostream& operator<<(ostream&, const Student&);



    private:
        static int count;
        char *name;
        const Date birthDate;
        Course *courseList[20];
        int courseNumber;
};

#endif // STUDENT_H
