#ifndef CONSOLE_H
#define CONSOLE_H
#include "Student.h"
using namespace std;

class Console
{
    public:
        Console();
        virtual ~Console();
        int run();
        int set_mark(int i,Student &);

    protected:
        ObligatorayCourse *O[12];
        ElectiveCourse *E[12];
    private:
        int Onum;
        int Enum;

};

#endif // CONSOLE_H
