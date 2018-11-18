#ifndef CONSOLE_H
#define CONSOLE_H
#define Max_Size 10
#include"Exception.h"


class Console
{
    public:
        Console();
        virtual ~Console();
        int run();    //运行控制台
    private:
        int displayMenu() const;    //显示系统主菜单
        Course* selectCourse(int op);
        bool setCourseScore();       //设置所有的课程成绩
        Console& buildStudent();//构造学生对象
        Console& buildCourse();//构造所有的可选课程（包括必修和选修课）
        void removeC();
        Student student;           //当前学生对象
        Course *oc[Max_Size];	//全部可选的必修课程清单
        Course *ec[Max_Size];	//全部可选的选修课程清单
        int ocNum;      //可选的必修课程实际数量
        int ecNum;
    protected:
};

#endif // CONSOLE_H
