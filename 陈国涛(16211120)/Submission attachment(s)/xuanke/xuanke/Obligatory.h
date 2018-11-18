#ifndef OBLIGATORY_H
#define OBLIGATORY_H
#include "Course.h"

class Obligatory : public Course
{
    public:
        Obligatory(string = "unknown", int = 0);
        Obligatory(const Obligatory&);
        virtual  int getScore()const;
        void setScore(int = 0, char = 'E') throw(MyException);
        const void print();
        virtual ~Obligatory();
    protected:
        int mark;
    private:
};

#endif // OBLIGATORY_H
