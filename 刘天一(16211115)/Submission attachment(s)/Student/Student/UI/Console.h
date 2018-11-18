#ifndef STUDENT_UI_H
#define STUDENT_UI_H

#include <iostream>
#include <fstream>
#include "../Student/Student.h"
#include "../Course/Course.h"
#include "../Course/ObligatoryCourse.h"
#include "../Course/ElectiveCourse.h"
#define Course_num 5
//static ObligatoryCourse* ObliCourse[Course_num]={
//        new ObligatoryCourse("Obli1",10),
//        new ObligatoryCourse("Obli2",8),
//        new ObligatoryCourse("Obli3",16),
//        new ObligatoryCourse("Obli4",16),
//        new ObligatoryCourse("Obli5",15)
//};
//static ElectiveCourse* ElecCourse[Course_num]={
//        new ElectiveCourse("Elec1",8),
//        new ElectiveCourse("Elec2",10),
//        new ElectiveCourse("Elec3",5),
//        new ElectiveCourse("Elec4",6),
//        new ElectiveCourse("Elec5",16)
//};

class UI
{
public:
    UI();
    virtual ~UI();
    void run();

protected:

private:
    int choice;
    Student* s;
    ObligatoryCourse *ObliCourse[Course_num];
    ElectiveCourse *ElecCourse[Course_num];

    void printfMainInterface();
    void addObligatoryCourse();
    void addElectiveCource();
    void inputStudent();
    void setGrade();
    void scanGrade();
    void saveData();
    void dropCourse();
    void option();
    void buildCourse();
};


#endif //STUDENT_UI_H
