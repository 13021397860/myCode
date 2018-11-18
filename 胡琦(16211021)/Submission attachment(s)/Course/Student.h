#include"date.h"
#include"Course.h"
#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 15
class Student
{
    public:
        static int count;
        const double weight;
        Student(char _name[]="huqi", date _birthDate={1999,12,31});
        Student(const Student &);
        virtual ~Student();
        const date& getBirthDate() const{return birthDate;}
        char *getName() const {return name;}
        void setBirthDate(const date);
        void setName(const char*);
        void print();
        Student& addCourse(Course*);
        //Student& addCourse1(Course*, int);
        friend ostream& operator<<(ostream&, const Student&);
        bool removeCourse(int);
        void setGrade(int, int);
        double calcCredit()const;
        int courseNumber;
    protected:

    private:
        char *name;
        date birthDate;
        Course *courseList[MAX_SIZE+1];
        void displayMessage();
};

#endif // STUDENT_H
