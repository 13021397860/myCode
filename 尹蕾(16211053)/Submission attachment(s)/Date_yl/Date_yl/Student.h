#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include <iostream>
#include <string>
#include <iomanip>
#define MAX_SIZE 10
class Student
{
    friend ostream& operator<<(ostream&, const Student &);
    public:
        Student(const char *const n ,int by,int bm,int bd);
        Student(Student &);
        virtual ~Student();

        int getCountNumber()const;
        int getCount()const;
        char * getName()const;

        Student& setName(const char *const n);
        //void printinf()const;

        Student& addCourse(Course *);
        //Student& addCourse(const string &, int );

       // void printCourseInf()const;
        bool removeCourse(int );
        //bool removeCourse(const string& );

        bool existCourse(Course *course);//判断是否已经存在某门课程
        double calcAchievement() const;	//计算学生的成绩

        Course *courseList[MAX_SIZE];

    protected:

    private:
        char *name;
        Date d;
        static int count;
        int countNumber;

        int calcObligatoryCredit() const;//计算必修课总学分
        int calcElectiveNumber() const;//计算选修课总门数
};

#endif // STUDENT_H
