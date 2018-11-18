#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "student.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Interaction.h"
using namespace std;

int main()
{
    while(1)
    {
    system("cls");
    printf("input student information please\n");
    student a;
    char sss[100];
//    printf("请输入学生姓名\n");
    printf("input name\n");
    scanf("%s",sss);
//    printf("请输入出生日期 按 年 月 日 的形式\n");
    printf("input birth date\n");
    Date y;
    cin>>y;
    /*对日期+和输出功能的测试
    cout<<(y+5)<<endl;
    */
    a.setBirthDate(y);
    a.setname(sss);
    Interaction x;
    int opt;
    bool st=true;
    while(st)
    {
        st=x.engine(a);
//        system("cls");
//        printf("    功能列表\n");
//        printf("输入1 进行选课及给定分数\n");
//        printf("输入2 保存学生信息\n");
//        printf("输入3 查询该学生绩点\n");
//        printf("输入4 输出该学生信息\n");
//        printf("输入5 结束该学生操作\n");
//        scanf("%d",&opt);
//        if(opt==1)
//            x.chooseCourse(a);
//        else if(opt==2)
//        {
//            ofstream out((string)a.getname()+".txt");
//            out<<a;
//        }
//        else if(opt==3)
//            {
//                cout<<a.calcCredit()<<endl;
//                system("pause");
//            }
//        else if(opt==4)
//            {
//                cout<<a<<endl;
//                system("pause");
//            }
//        else
//            throw (-1);



//    int ttem=0;
//    printf("输入数学成绩\n");

//    printf("input maths score\n");
//    scanf("%d",&ttem);
//    a.fen("Maths",&ttem);
//    printf("Maths over\n");

//    char teem='C';char tt[30];
//    printf("Games得分为C\n");
//    printf("输入Games成绩\n");
//    printf("inpt games score\n");
//    scanf("%s",tt);
//    teem=tt[0];
//    a.fen("Games",&teem);

//    cout<<a.calcCredit()<<endl;

    /*对去除课的测试
    cout<<a;
    a.removeCourse(3);
    cout<<a;
    a.removeCourse(2);
    cout<<a;
    */
    }
    printf("输入1继续操作 输入2结束操作\n");
    scanf("%d",&opt);
    if(opt==1)
        continue;
    else
        break;
    }
    return 0;
}
