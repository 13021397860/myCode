#ifndef STU_H
#define STU_H
#include "Time.h"
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#include<cstring>
#define MAX_SIZE 12
class Stu
{
    public:
        Stu(const char *n, int y1, int m1, int d1);
        Stu(const Stu &a);
        int setName(const char *n);
        int getName(char *n)const;
        int getBirthDate(int &y, int &m, int &d)const;
        int print();
        virtual ~Stu();
		Stu& addCourse(const Course *const course);
		Stu& addCourse(const string &courseName,const int creditHour);
		friend ostream& operator << (ostream&,Stu&);
		bool removeCourse(const int i);
		bool removeCourse(const string& courseNumber);
		friend ostream& operator<<(ostream& ,const Stu&);
		int setScore();
        double calCredit()const;
    private:
        char *name;
        const Time birthDate;
        static int count;
        static int courseNumber;
        Course *courseList[MAX_SIZE];
};

#endif
