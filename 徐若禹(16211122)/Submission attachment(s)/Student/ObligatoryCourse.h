#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include"Course.h"
using namespace std;

class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse(string ,int ,int );
        void addOCreditHour(int);
        int getOCreHour() const;
        void setMark(int);
        int getMark() const;
        int getScore() const;
        void setCourse(string n, int c,int m);
        virtual ~ObligatoryCourse();

    protected:

    private:
        int mark;
        static int oCreditHour;
};

#endif // OBLIGATORYCOURSE_H
