#ifndef COURSE_H
#define COURSE_H
#include<iostream>
#include<string.h>
using namespace std;
class Course
{
    public:
        Course(string nam="self-taught Class",int ch=0);
        virtual ~Course();
        void setname(string);
        void setcredithour(int);
        string getname();
        int getcredithour();
        virtual void setscore(int);
        virtual int getscore()=0;
        virtual void toString();
        friend ostream& operator << (ostream& out, Course& c)
        {
              //c.toString();
               out<<"CourseName:"<<c.getname()<<" "<<"Credithour:"<<c.getcredithour()<<" ";
               out<<"Score:"<<c.getscore();

                                                return out;
                                    }

    protected:
         string name;
        int creditHour;
    private:

};

#endif // COURSE_H
