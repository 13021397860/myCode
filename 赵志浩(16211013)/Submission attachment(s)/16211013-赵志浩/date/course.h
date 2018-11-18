#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>
using namespace std;
class Course
{
    public:
        Course(string="",int=0);
        Course(const Course&);
        string getName() const {return name;};
        int getCredictHour() const {return creditHour;};
        void setName(string n){this->name=n;return;};
        void SetCrediectHour(int c){this->creditHour=c;return;}
        virtual void setScore(int){};
        virtual int getScore()=0;
        virtual ~Course();
        friend ostream& operator << (ostream& out,Course& c)
        {
            out<<"course name:"<<c.getName()<<" credit:"<<c.getCredictHour()<<" score:"<<c.getScore();
            return out;
        }
    protected:
        string name;
        int creditHour;
    private:
};

#endif // COURSE_H
