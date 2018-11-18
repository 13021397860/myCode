#ifndef INTERACTION_H
#define INTERACTION_H
#include <string>
#include "student.h"
#include "Course.h"
const int MAX=100;
class Interaction
{
    public:
        Interaction();
        virtual ~Interaction();
        void ObligatoryCourseChoice(string Name,int CreditHour,student &a);
        void ElectiveCourseChoice(string Name,int CreditHour,student &a);
        void chooseCourse(student &a);
        bool engine(student &a);
    protected:
        string Obligatory[MAX]={"Maths","Chinese","C++","OO"};
        int ObCreditHour[MAX]={200,10,240,180,0};
        string Elective[MAX]={"Games","Life","Music","Art"};
        int ElCreditHour[MAX]={75,48,24,25,0};
        int obnum,elnum;
    private:
};

#endif // INTERACTION_H
