#ifndef STUDENT_H
#define STUDENT_H

#include"Date.h"
#include"Course.h"
#define MAX_SIZE 40

class Student
{
    public:
        Student();
        Student(const char*);
        Student(const Student&);
        virtual ~Student();
        void SetName(char*);
        void SetBirthday(Date);
        Date& GetBirthday();
        char* GetName();
        Date birth;
        void PrintStu();
        static int GetCount();
        Student& addCourse(Course *);
        bool removeCourse(int &);
        void quitCourse(int &);
        void printcourselist();
        void setscore(int &);
        friend ostream& operator<<(ostream& cout,Student&);

    protected:

    private:
        char* name;
        Date birthday;
        static int Count;
        Course *courseList[MAX_SIZE];
        int courseNumber;
        double point;
        void calcCredit();
};
//int Student::Count=0;
#endif // STUDENT_H

