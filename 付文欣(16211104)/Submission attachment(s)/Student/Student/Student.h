#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 20
#include "date.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
class Student
{
    public:
        void setName();

        void setName(const string &);

        Student(const int y,const int m,const int d,string s="0"):birthDate(y,m,d){
            if(s!="0") setName(s);  else setName();
            stu_count++; courseNumber=0;
        }

        Student(const Student &s):birthDate(s.birthDate){
            setName(s.getName()); stu_count++; courseNumber=0;
        }

        int get_studentnum()const{
            return stu_count;
        }

        bool is_overflow()const{
            return (courseNumber==MAX_SIZE)?true:false;
        }

        Student &addCourse(Course *course);

        Student &addCourse(const string &courseName,int creditHour);

        void setName(const char *);

        const string &getName()const;

        void print_Name()const;

        void print_birthDate()const;

        void setScore(int i,const int);

        void setScore(int i,const char);

        Course *getCourse(int i){
            return (courseList[i]);
        }

        int GetCourseNum()const{
            return courseNumber;
        }

        bool removeCourse(int i);

        virtual ~Student(){
            for(int i=1;i<courseNumber;i++) delete courseList[i];
        }

        friend ostream & operator<<(ostream & out,const Student &);
    //protected:
    private:
        int courseNumber;
        string name;
        Course *courseList[MAX_SIZE+2];
        const date birthDate;
        static int stu_count;
};

#endif // STUDENT_H
