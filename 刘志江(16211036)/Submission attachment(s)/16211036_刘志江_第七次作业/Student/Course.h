#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Course
{
    friend ostream& operator<<(ostream& , Course& );
    public:
        Course(const string n="", const int ch=0);
        string getName() const;
        void setName(const string);
        int getCreditHour() const;
        virtual int getScore() const=0;
        void setCreditHour(const int);
        virtual ~Course();
        void setSetSc();
        int getSetSc();

    protected:

    private:
        string name;
        int creditHour;
        int setSc;
};

#endif // COURSE_H
