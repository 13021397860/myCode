#ifndef COURSE_H
#define COURSE_H
#include<string>
#include"MyException.h"
#include<exception>
using namespace std;

class Course
{
    public:
        Course(string _name, int _creditHour);
        virtual ~Course();
        string getname() const;
        int setname( string );
        virtual int getcreditHour() const;
        int setcreditHour(int _creditHour);
        virtual int getscore() const = 0;

        friend ostream &operator << (ostream&,const Course&);

    protected:
        const string name;
        int creditHour;
        int id;

    private:

};

#endif // COURSE_H
