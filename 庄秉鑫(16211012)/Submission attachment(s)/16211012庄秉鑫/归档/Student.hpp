//
//  Student.hpp
//  Student
//
//  Created by Pirate Hero on 17/3/24.
//  Copyright © 2017年 mac. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include "Date.hpp"
#include <iostream>
#include "course.hpp"
using namespace std;
#endif /* Student_hpp */
/*
 （1）数据成员：姓名name，必须使用char*类型（不能使用char[],或string），在构造和析构函数中实现动态内存分配；
 
 （2）组成数据成员：出生日期birthDate，使用实验1所完成的Date类型；
 
 （3）静态数据成员：学生数量count，用于统计在程序中产生学生对象的个数（第二次完成）；
 
 （4）提供构造函数、拷贝构造函数和析构函数；
 
 （5）提供必要的get和set函数，存取私有数据成员；
 
 （6）在单独的cpp文件中编写main函数，测试各项功能。
 
 （3）完善学生类Student
 
 （3.1）增加数据成员courseList，类型为Course类指针数组(即 为Course *courseList[MAX_SIZE]，MAX_SIZE为常量宏，表示可选的最大课程数)，表示学生所选的所有课程
 
 （3.2）增加数据成员courseNumber，int类型，表示实际的课程总数
 
 （3.3）不修改构造函数（构造学生的时候还没有课程），添加addCourse接口，即实现学生选课，接口如下：
 
 Student& addCourse(Course *course);
 Student& addCourse(const string &courseName, int creditHour);
 （3.4）重载流输出运算符<<，输出学生姓名、生日以及所选课程信息，输出格式如下示例：
 
 姓名：李四 出生日期：1987-3-1，选课信息如下：
 课程名：面向对象的程序设计    学分：3
 课程名：数学分析   学分：5
 课程名：体育    学分：2
 （4）编写main函数，测试所要求的功能
 
 （4.1）定义学生对象，并为其添加几门课程信息
 */
class Student
{
public:
    char*name;
    
    Date birthdate;
    
    Student();
    Student(const Student&X);
    course *OCName[20];//play为必修课
    course *ECName[20];//此为选修课
    ElectiveCourse *e[20];//
    int E;
    ObligatoryCourse *o[20];//
    int O;
    
    int courseNumber;
    int courseNumber2;
    long  int length;
    char*name2;
     int year;
    int month;
    int day;
    void get();
    void set(long int,char*);
    void  coutbirthdate();
    void coutname()const;
    double GPA;
    static int Count;
    Student& addCourse(course *c);
   void  addCourse(const string &coursename, int credithour);
    void addCourse2(const string &M, int C);

    friend ostream & operator<<(ostream &out, Student &A);
     friend ostream & operator>>(ostream &in, Student &A);
    void calcCredit();
    
    
    ~Student();
};












