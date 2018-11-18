#ifndef COURSE_H
#define COURSE_H
#include <string>
#include "MyException.h"
using namespace std;

class Course
{
    friend ostream &operator<<( ostream &, const Course&);
    public:

        Course(string= "unknown", int = 0 );

        void SetCoursename(string );
        void SetCreditHour(int );
        const int GetCreditHour();
        const string GetCoursename();
        virtual  int getScore() const= 0;
        virtual const void print(){};
        virtual void setScore(int ,char){};
        virtual ~Course();
    protected:
        string name;
        int creditHour;

    private:
};

#endif // COURSE_H
