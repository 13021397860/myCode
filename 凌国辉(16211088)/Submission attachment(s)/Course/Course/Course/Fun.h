#ifndef FUN_H
#define FUN_H
#include"Date.h"
#include"Student.h"
#include"Course.h"
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include"MyException.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include<strstream>
#include<cstring>
using namespace std;

class Fun
{
    public:
        Fun();
        virtual ~Fun();
        void create();
        void choose();
        void setScore();
        bool control();
        void PPtest();
        //bool createSequentialFile(const char *fileName);
        bool readSequentialFile(const char *fileName);
        void writeSFile(Student &x);
        bool chooseCourse(const char *fileName,int kk);

    protected:

    private:
        Student *temp;
        string x;
        int y,d,m,score,credit,num;
        char c[100],grade;
};

#endif // FUN_H
