#ifndef COURSE_H
#define COURSE_H
#include<iostream>
using std::string;
using std::ostream;
class course
{
   friend ostream &operator<<(ostream &os,const course &course_);
    public:
        string name;
        int creditHour;
        course();
        course(const string ,int);
        virtual ~course();
        string  getName() const ;
        int getCredit() const ;
        void  set_(string, int );
        virtual void print(){};//Ðéº¯Êý£»
        virtual void setChengji(int ,char ){};
        virtual int getScore() const =0;
    protected:

    private:


};

#endif // COURSE_H
