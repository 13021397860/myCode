#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>
using namespace std;

class Course
{
    public:
        Course(const string &,int);
        void setName(const string &);
        void steCreditHour(int);
        string getName()const;
        int getCreditHour()const;
        virtual void setScore(int){}
        virtual void setScore(char){}
        virtual int getScore()const{}
        virtual bool is_haveScore()const{}
        virtual ~Course();
        friend ostream & operator<<(ostream &out,Course &Cc);
    //protected:
    private:
        string name;
        int creditHour;
};

#endif // COURSE_H
