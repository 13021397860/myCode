#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
using namespace std;
using std::ostream;
using std::istream;
class Course
{
    public:
        Course(const string ,const int = 0);
        virtual ~Course();
        Course(const Course &c);
        void setCourse(const string n,const int c);
        int getcreditHour()const;
        string getname()const;

    friend ostream& operator << (ostream&,Course& c);

        virtual int getScore() const=0;
        virtual int getObligatoryCredit() const	;
        virtual int getObligatoryNumber() const;
        virtual int getElectiveNumber() const;

    protected:

    private:
        string name;
        int creditHour;
};

#endif // COURSE_H
