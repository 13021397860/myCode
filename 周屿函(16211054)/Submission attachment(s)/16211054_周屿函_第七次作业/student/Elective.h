#ifndef ELECTIVE_H
#define ELECTIVE_H
#include"Exception.h"
#include "Course.h"


class Elective : public Course
{
    public:
        Elective();
        Elective(const string a,int x,char t)
            :Course(a,x),grade(t){};
        Elective(const Elective& x)
            :Course(x),grade(x.grade){};
        virtual ~Elective();
        void setGrade(char x)
        {
            if(x>='A'&&x<='F')
                grade=x;
            else
                throw Exception(Grade_Invalid);
        }
        virtual int getScore();
    private:
        char grade;
    protected:
};

#endif // ELECTIVE_H
