#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 10
#include<iomanip>
#include<typeinfo>
#include "Date.h"
#include "Course.h"
class Student
{
    friend ostream& operator<<(ostream& os,const Student& s)
    {
        os<<"name: "<<s.getName()<<", birthday: "<<s.getBirthdate();
        os<<"information of curricula-variable:\n";
        if(s.i==0)
            os<<"no courses";
        else
        {
            for(int j=0;j<s.getCourseNumber();j++)
                os<<j+1<<": "<<*(s.courseList[j]);
            os<<"achievement points: <"<<s.calcCredit()<<">";
        }
        return os;
    }
    public:
        static void getCount();
        Student(char *,const Date);
        Student(Student &);
        void setName(char *);
        char *getName()const;
        void print();
        int addCourse(Course *course);
        const Date getBirthdate()const
        {
            return birthDate;
        }
        bool removeCourse(int);
        int getCourseNumber()const;
        bool setCourseScore ();
        double calcCredit()const;
        virtual ~Student();
    protected:
    private:
        static int count;
        char *name=NULL;
        Date birthDate;
        Course *courseList[MAX_SIZE];
        int courseNumber;
        double OWeight=0.6;
        double EWeight=0.4;
        int i=0;
};
#endif // STUDENT_H
