#ifndef INTERFACE_H
#define INTERFACE_H
#include <cstdio>
#include <cctype>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <windows.h>
#include "Student.h"
#include "InputException.h"
using namespace std;

class Interface
{
    friend ifstream &operator>>(ifstream &,Interface &);
    public:
        Interface();
        void Run(){
            PrintFirstFace();
            PrintInputInformation();
            system("cls");
            PrintFirstFace();
        }
        void IniCourse(ifstream &);
        void MainSelectCourseFace();
        void PrintFirstFace();
        void PrintNeedingSelectCourse()const;
        void SelectingCourse();
        void PrintSelectedCourse()const;
        Student *PrintInputInformation();
        void PrintInputingGrade();
        void RemoveCourse(int i);
        virtual ~Interface();

    protected:
        int op;
        bool is_have;
        Student *p;
};

#endif // INTERFACE_H
