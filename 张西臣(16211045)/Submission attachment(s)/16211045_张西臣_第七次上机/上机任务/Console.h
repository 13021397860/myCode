#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include <string>
#include <cstring>
#include "Date.h"
#include "Student.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#define MAX_SIZE 3
using namespace std;
class Console
{
    public:
        void run();
        Console();  //构造函数，初始化控制台数据
        virtual ~Console();//析构函数，释放内存
        Student *student; //当前学生对象
private:
        int displaycaidan() const;
        int selectCourse(Course* course[], int );
        Console& buildStudent();//构造学生对象
        void buildCourse();//构造所有的可选课程（包括必修和选修课）
        Course *ocke[MAX_SIZE];
        Course *ecke[MAX_SIZE];//全部可选的选修课程清单
        int ocnum;      //可选的必修课程实际数量
        int ecnum;	//可选的选修课程实际数量
};


#endif // CONSOLE_H
