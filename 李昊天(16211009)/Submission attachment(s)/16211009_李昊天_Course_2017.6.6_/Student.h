#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 10
#include "Date.h"
#include "Course.h"
using namespace std;
class Student
{
    public:
        Student(char*,int,int ,int);
        Student(const Student &);
        virtual ~Student();
        char *getName() const {return name;}
        int getBirthDateyear() const {return birthDate.getYear();}
        int getBirthDatemonth() const {return birthDate.getMonth();}
        int getBirthDateday()const {return birthDate.getDay();}
        int getCount()const {return count;}
        int getCourseNumber() const {return courseNumber;}
        void setNameBirthday(char*,int,int,int);
        void CheckNamelen();
        bool removeCourse(int);
        Course *getCourse(int) const;
        Student& addCourse(Course *course);
        Student& addCourse(const string&, int);
        void print();
        void calcCredit();
        void calcCourseType();
        bool getda() const {return birthDate.getdda();}
    protected:

    private:
        char *name;
        Date birthDate;
        static int count;
        float Credit;
        int ObCourseNum;
        int ObCourseCreditHour;
        int ObCourseScore;
        int ElCourseNum;
        int ElCourseScore;
        const float ObCourseWeight=0.6;
        const float ElCourseWeight=0.4;
        Course *courseList[MAX_SIZE];
        int courseNumber;
        friend ostream& operator<<(ostream& os,const Student & p);
};


#endif // STUDENT_H
