#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
using namespace std;
class Course
{
    public:
        Course();
        Course(const Course& other);
        Course(const string& _name,int _creditHour);
        bool setName(const string& _name);
        bool setCreditHour(int _creditHour);
        const string& getName()const;
        int getCreditHour()const;
        virtual int getScore()const=0;
        virtual void printCourse()const=0;
        friend ostream& operator <<(ostream &out,const Course& A);
        virtual ~Course();
    protected:
    private:
        int creditHour;
        string name;
};

#endif // COURSE_H
