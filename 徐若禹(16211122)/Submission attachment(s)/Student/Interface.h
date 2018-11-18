#ifndef INTERFACE_H
#define INTERFACE_H
#include<iostream>
#include<cstdio>
#include"Date.h"
#include"Student.h"
#include"Course.h"
using namespace std;

class Interface
{
    public:
        Interface();
        void menu();
        void operate();
        void selectCourse();
        void addMG();
        void removeCourse();
        void print() const;
        virtual ~Interface();

    protected:

    private:
        Student *s;
};

#endif // INTERFACE_H
