#ifndef COURSE_H
#define COURSE_H
#include <iostream>
using namespace std;

class Course
{
    public:
        Course();
        Course(const string,const int);

        string getname() const;
        int getcreditHour() const;

        void setname(const string);
        void setcreditHour(const int);

        virtual int getScore()const=0 ;

        friend ostream& operator<<(ostream&, const Course&);

        virtual ~Course();

    protected:

    private:
        string name;
        int creditHour;
};

#endif // COURSE_H
