#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>
using namespace std;
class Course
{
    public:
        Course();
        Course(string x,int y);
        virtual ~Course();
        string getName()const;
        int getCreditHour()const;
        void setName(string n);
        void setCreditHour(int c);
//        void
        friend ostream & operator<<(ostream &out,Course &x)
        {
            out<<"Course: "<<x.name<<" Credit"<<x.creditHour<<" Score "<<x.getScore()<<"\n";
            return out;
        }
        friend ostream & operator<<(ostream &out,Course *x)
        {
            out<<"Course: "<<(*x).name<<" Credit"<<(*x).creditHour<<" Score "<<(*x).getScore()<<"\n";
            return out;
        }
        virtual void setGrade(char z);
        virtual void setGrade(int x);
        virtual int getScore()const=0;
        virtual int who()=0;
    protected:
        string name;
        int creditHour;
    private:
};



#endif // COURSE_H
