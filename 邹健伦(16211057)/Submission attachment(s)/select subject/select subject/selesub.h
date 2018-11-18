#ifndef SELESUB_H
#define SELESUB_H
#include <iostream>
#include"Date.h"
#include"student.h"
#include"course.h"
#include"obligatorycourse.h"
#include"electivecourse.h"
#include<string>
using namespace std;

class selesub
{
    public:
        int run();
        selesub();
        virtual ~selesub();

    protected:

    private:
        void displaymenu()const;
        void seleoc();
        void seleec();
        void displaycourse()const;
        bool setcoursescore();

        student *s;
        obligatorycourse *oc[10];
        electivecourse *ec[10];
        int ocnum;
        int ecnum;

};

#endif // SELESUB_H
