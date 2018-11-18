#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include"Course.h"
#include"MyException.h"


class ElectiveCourse : public Course
{
    public:
        ElectiveCourse();
        const void print(){cout<<Getscore()<<endl;}
        ElectiveCourse(std::string ,int ,char);
        virtual ~ElectiveCourse();
        void Setgrade(char);
        int Getscore()const;
        void SetGrade(char);

    protected:

    private:
        char grade;//A,B,C,D,E
};

#endif // ELECTIVECOURSE_H
