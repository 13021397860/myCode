#ifndef STU_H
#define STU_H
#include "date.h"
#include <iostream>
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include <typeinfo>
#define MAX_SIZE 20

class Stu
{
    public:
        Stu();
        Stu(const char*s);
        Stu(const Stu& s);
        Stu& addCourse(Course *course);
        //Stu& addCourse(const string &courseName, int creditHour);
        int getlenth() const {return lenth;}
        char* getname() const {return name;}
        Stu& setname(const char*s);
        void setdate(int m,int d,int y){
            birthdate.setDate(m,d,y);
        }
        date& getdate()
        {
            return birthdate;
        }
        int getday(){
            int d;
            d = birthdate.getDay();
            return d;
        }
        int getmonth(){
            int m;
            m = birthdate.getMonth();
            return m;
        }
        int getyear(){
            int y;
            y = birthdate.getYear();
            return y;
        }
        void printname();
        virtual ~Stu();
        static void view();
        static int getCount();
        static int getCoursenumber();
        Course* getcourselist(int);
        bool removeCourse(int);
        static void printScore(Stu&,int);
        friend ostream& operator<<(ostream& out,Stu& c);
        bool judgedate();
        bool setCourseScore(Stu&);
        float calCredit();

    protected:

    private:
        static int count;
        char* name;
        int lenth;
        date birthdate;
        Course *courseList[MAX_SIZE];
        static int courseNumber;
};

#endif
