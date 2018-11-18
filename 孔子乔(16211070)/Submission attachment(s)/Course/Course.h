#ifndef COURSE_H
#define COURSE_H
#include<string>
#include<iostream>

using std::string;
using std::ostream;

class Course
{
    public:
        Course();
        Course(const string _name, const int _credithour);
        Course(const Course &another);

        virtual int getscore()const = 0;

        void setname(const string _name);
        void setname(const char* _name);
        void setcredithour(const int _credithour);
        void clearcourse();
        string getname()const;
        int getcredithour()const;
        Course& operator[](int i);
        void old_out()const;
        friend ostream& operator<<(ostream &output,Course &course);

        virtual ~Course();
    protected:
        string Name;
        int CreditHour;
};

#endif // COURSE_H
