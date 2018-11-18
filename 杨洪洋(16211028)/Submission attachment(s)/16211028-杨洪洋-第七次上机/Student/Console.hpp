//
//  Console.hpp
//  Student
//
//  Created by apple on 2017/5/2.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef Console_hpp
#define Console_hpp
#include"Student.hpp"
#define MAX_SIZE 10
class Console
{
public:
    int run();
    Console();
    virtual ~Console();
private:
    int displayMenu();//显示系统主菜单
    //选课，参数:op=1:必修，op=2：选修
    Course *selectCourse(int op);
    bool setCourseScore();//设置所有的课程成绩
    Console& buildStudent();//构造学生对象
    Console& buildCourse();//构造所有的可选课程（包括必修和选修课）
    bool readSequentialFile(const char *fileName);
    Student *student;//当前的学生对象
    Course *oc[MAX_SIZE];
    Course *ec[MAX_SIZE];
    int askScore();
    int askJidianScore();
    int ocNum;//可选的必修课程的实际数量
    int ecNum;//可选的选修课程的实际数量
    int tempocNum;//已经选择的必修课程的数量
    int tempecNum;//已经选择的选修课程的数量
    //新增异常处理
    int throwErrorCode;
};
#endif /* Console_hpp */
