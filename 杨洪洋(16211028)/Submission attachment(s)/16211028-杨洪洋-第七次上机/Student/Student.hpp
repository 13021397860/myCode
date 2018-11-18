
#ifndef Student_hpp
#define Student_hpp
#include "Date.hpp"
#include<cstring>
#include<iostream>
#include "Course.hpp"
#include "ObligatoryCourse.hpp"
#include "ElectiveCourse.hpp"
using namespace std;
#define MAX_SIZE 10
class Student
{
public:
    Student();
    Student(const char *const text);
    Student (const Student &s);
    char *getName();
    void setName(char *s);
    bool setBirthday(int y,int m,int d);
    virtual ~Student();
    void printstu();
    void printcount();
    static int getCount();
    //新增接口
    Student& addCourse(Course *course);//实现学生选课
    int getCourseNumber();
    friend ostream &operator <<(ostream &,Student &);
    int removeCourse(int i,string name);
    Course* getCourse(int i);
    void setCourseNumber();
    //新增接口2
    double calcCredit();
    Course *getCourseList(int j);
    bool createSequentialFile(const char *fileName);
    //新增接口3
    bool check(Course *course);
protected:
private:
    char *name;
    Date birthDate;
    static int count;
    //增加内容
    int courseNumber;
    Course *courseList[MAX_SIZE];
    //增加内容2
    double jidian;
 
};


#endif /* Student_hpp */
