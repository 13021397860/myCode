#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;


class Course
{
    public:
        Course(const string ="untitled",const int =0);
        virtual ~Course();
        string GetName() const;
        int GetCreditHour() const;
        bool SetName(const string);
        bool SetCreditHour(const int);
        virtual int getScore()=0;
        friend ostream & operator << (ostream &, Course &);
        //virtual void SetMark(const int ){};
        //virtual void SetMark(const char){};
    protected:
        string name;
        int creditHour;
    private:

};

#endif // COURSE_H
