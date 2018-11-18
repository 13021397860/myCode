#ifndef COURSE_H
#define COURSE_H
#include <string>

using namespace std;

class Course
{
    public:
        friend ostream &operator<<(ostream &, Course &);
        virtual int getscore()=0;
        Course();
        Course(string mingzi,int xuefen,int =0);
        void setname(string );
        void setcredit(int );
        string getname() const;
        int getcredit();
        int getmyscore();
        void printcourseinforfu();
        void printcourseinfor();
        string getcoursename();
        virtual ~Course();
        int myscore;
        string name;
        int creditHour;
    protected:

    private:

        char scorezifu;
        friend class Student;
};

#endif // COURSE_H
