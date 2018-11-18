//
// Created by zjp on 2017/4/25.
//
#include "course.h"
#include "student.h"
#include <fstream>
#ifndef CONSOLE_H
#define CONSOLE_H
#define MAX_SIZE_1 4
#define MAX_SIZE_2 6

class console {
public:
    int run();
    console();
    virtual ~console();
private:
    int displayMenu() const;
    course *selectCourse(int op);
    console& buildStudent();
    console& buildCourse();
    void print_courseList();
    void operation_judge(int i);
    student *student;
    course *oc[MAX_SIZE_1];
    course *ec[MAX_SIZE_2];
    int ocNum;
    int ecNum;
};

#endif //CONSOLE_H