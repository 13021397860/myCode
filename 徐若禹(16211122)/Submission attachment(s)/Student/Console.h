#ifndef CONSOLE_H
#define CONSOLE_H
#include<iostream>
#include<cstdio>
#include<cctype>
#include<fstream>
#include<stdexcept>
#include"Date.h"
#include"Student.h"
#include"Course.h"
#include"MyException.h"
using namespace std;

class Console
{
    public:
        Console();
        void menu();
        void operate();
        void loadCourse();
        void selectCourse();
        void addMG();
        void removeCourse();
        void queryScore();
        void queryCalcCredit();
        void print() const;
        void save();
        virtual ~Console();

    protected:

    private:
        Student *s;
        Course *oc[MAX_SIZE];
        Course *ec[MAX_SIZE];
        int ocNum;
        int ecNum;
};

#endif // INTERFACE_H
