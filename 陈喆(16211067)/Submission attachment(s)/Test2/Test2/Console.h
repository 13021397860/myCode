#ifndef CONSOLE_H
#define CONSOLE_H
#include "Student.h"
#include "MyException.h"
#include <fstream>
#define OC_MAXNUM 10
#define EC_MAXNUM 10

class Console
{
    public:
        Console();
        virtual ~Console();
        void printWelcome();
        void run();
        void printIntroduction_Indicator();
        void printIntroduction_ElectiveCourse();
        void printIntroduction_ObligatoryCourse();

        void select_ObligatoryCourse(Student &);
        void select_ElectiveCourse(Student &);
        void removeCourse(Student &);
        void set_courseGrade(Student&);

        void out_information(Student& ,char* );
        ObligatoryCourse* getOc(const int num);
        ElectiveCourse* getEc(const int num);
    protected:

    private:
        ObligatoryCourse* Oc[OC_MAXNUM];
        ElectiveCourse* Ec[EC_MAXNUM];
        int OcNum;
        int EcNum;
};

#endif // CONSOLE_H


