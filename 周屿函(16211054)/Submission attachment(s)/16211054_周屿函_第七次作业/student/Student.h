#ifndef NAME_H
#define NAME_H
#include"date.h"
#include"Course.h"
#include"ObligatoryCourse.h"
#include"Elective.h"
#include"Exception.h"

#define Max_Size 10
class Student
{
    friend ostream& operator<<(ostream&,Student&);
    public:
        Student(){};
        virtual ~Student();
        Student(const char* const n,int y,int m,int d);
        Student(const char* const n,const Date &s);
        Student(const Student &s);
        void setName(const char* const n);
        void setBirth(const int y,const int m,const int d);
        char* getName()const;
        int getYear()const;
        int getMonth()const;
        int getDay()const;
        void print()const;
        int getCount()const;
        int getCourseNumber(){return courseNumber;}
        Student& addCourse(Course *course);
        //Student& addCourse(const string &courseName,int creditHour);
        Course *courseList[Max_Size];
        bool removeCourse(int i);
        bool removeCourse(const string& courseName);
        void printCourseList()
        {
            for(int i=0;i<courseNumber;i++)
            {
                cout<<i+1<<"."<<*courseList[i];
            }
        }
        double calcAchievement() const;//
    protected:

    private:
        static int count;
        char *name;
        Date birthDate;
        int courseNumber;
        int calcObligatoryCredit() const;
        int calcElectiveNumber() const;

};

#endif // NAME_H
