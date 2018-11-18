#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>
using namespace std;

class Course
{
    public:
        Course(const string ="math", const int =4);
        virtual ~Course();
        void setName(const string &);
        string getName() const;
        void setCreditHour(const int&);
        int getCreditHour() const;
        virtual void setScore(const int &);
        virtual int getScore() const=0;
        friend ostream &operator<<(ostream &, const Course &);

    private:
        string name;
        int creditHour;
};

#endif // COURSE_H
