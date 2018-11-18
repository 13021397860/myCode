#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include"Course.h"
#include"MyException.h"

class ObligatoryCourse:public Course
{
    public:
        ObligatoryCourse();
        const void print(){cout<<mark<<endl;}
        ObligatoryCourse(std::string,int,int );
        virtual ~ObligatoryCourse();
        //void Setmark(int );
        void SetMark(int);
        int Getscore()const;
    protected:

    private:
        int mark;

};

#endif // OBLIGATORYCOURSE_H
