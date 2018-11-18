//
//  course.hpp
//  Student
//
//  Created by Pirate Hero on 17/4/17.
//  Copyright © 2017年 mac. All rights reserved.
//

#ifndef course_hpp
#define course_hpp

#include <iostream>
#include <string>
#include <string.h>
using namespace std;



class course
{
public:
    string name;
    int creditHour;

     friend ostream & operator<<(ostream & out, course & A);
    string Name;
    int CreditHour;
    course();
    course(const string &coursename,const int c);
    void get();
  //  virtual void getscore()=0;
    virtual void getscore()=0;
    void set();//set是存，get是取
    void set(const string& ,int);
    ~course();
};
/* course_hpp */
/*
 （1）为课程类Course添加子类必修课程ObligatoryCourse
 
 （1.1）数据成员：课程成绩mark，int类型，表示某门必修课程的成绩；同时为该成员提供set函数
 
 （1.2）成员函数getScore，返回整数类型的课程成绩（即mark值）
 
 （2）为课程类Course添加子类选修课程ElectiveCourse
 
 （1.1）数据成员：课程成绩grade，char类型，表示某门选修课程的等级（A、B、C、D、E五个等级），同时为该成员提供set函数
 
 （1.2）成员函数getScore，返回整数类型的课程成绩（A、B、C、D、E分别对应95、85、75、65、55分）
 
 （3）编写main函数实现下列功能
 
 （3.1）接收输入，根据输入信息（包括姓名、出生日期等信息）构造一个学生对象
 
 （3.2）提供简易的交互界面，为这个新构造的学生实现如下功能：
 
 （3.2.1）选课，可以分别选必修课和选修课
 （3.2.2）设置成绩：为所选的课程设定成绩
 */

class ObligatoryCourse: public course
{
public:
 /*   fish():animal(400,300)
    　　　　{
        　　　　　　cout<<"fish construct"<<endl;
        　　　　}
    
    ObligatoryCourse():course("tiyu",3)
    {
        
    }
  */
   int mark;
  void set();
   void getscore()
    {
        cout<< mark;
    //   cout<<"fuck you"<<endl;

    }
 
 
};








class ElectiveCourse:public course
{
    public :
    char grade;
    int mark;
    void set();
  void getscore()
    {
        cout<<mark<<endl;
 
     //   cout<<"fuck you"<<endl;
    }
  

};



#endif
