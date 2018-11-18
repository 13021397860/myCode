#ifndef RUN_H
#define RUN_H

#include"Course.h"
#include"Date.h"
#include"ElectiveCourse.h"
#include"ObligatoryCourse.h"
#include"TextStudentClass.h"
#include"MyException.h"
#include<stdlib.h>
#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;


class run
{
    public:
        run();
        run(int);
        virtual ~run();
        TextStudentClass *info();
        void xuanke(TextStudentClass *a);
        void bixiu(TextStudentClass *a);
        void xuanxiu(TextStudentClass *a);
        void menu();
        void leave();
        void chengji(TextStudentClass *a);
        void jidian(TextStudentClass *a);
        void saveclass(TextStudentClass *a);
        void saveinf(TextStudentClass *a);
 //       void saveObligatoryclass(TextStudentClass *a);
        void loadObligatoryclass();
        void loadElectiveclass();
        void SAVE(TextStudentClass *a);
       // void searchcourse(TextStudentClass *a);
        void tuike(TextStudentClass *a);

   protected:

    private:
};

#endif // RUN_H
