#include "Console.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Date.h"
#include <iostream>
#include <typeinfo>
#include<cstdlib>
using namespace std;
#define MAX_SIZE 200
Console::Console()
{
    ObligatoryNumber = 0;//ctor
    ElectiveNumber = 0;
}

Console::~Console()
{
    if(student!=NULL) delete student;
    for(int i = 0; i < ObligatoryNumber; i++)
        delete obligatory[i];
    for(int i = 0; i < ElectiveNumber; i++)
        delete elective[i];
}
void Console::newStudent()
{
    char s[200];
    Date birthDate;
    cout<<"请输入姓名\n";
    cin>>s;
    cout<<"请输入出生日期(年 月 日)\n";
    cin>>birthDate;
    student = new Student(s, birthDate);
}
void Console::newCourse()
{
    ObligatoryNumber = 4;
    ElectiveNumber = 6;
    obligatory[0] = new ObligatoryCourse("面向对象的程序设计", 3);
    obligatory[1] = new ObligatoryCourse("线性代数", 5);
    obligatory[2] = new ObligatoryCourse("数据结构", 4);
    obligatory[3] = new ObligatoryCourse("高等数学", 4);
    elective[0] = new ElectiveCourse("职业规划", 2);
    elective[1] = new ElectiveCourse("网站分析工具", 2);
    elective[2] = new ElectiveCourse("航空航天概论", 2);
    elective[3] = new ElectiveCourse("英语口语强化", 1);
    elective[4] = new ElectiveCourse("系统管理", 2);
    elective[5] = new ElectiveCourse("网络管理", 2);
}

Course*& Console::selectCourse(int option)
{
    int choice = -1;
    if(option == 1)
    {
        cout<<"请选择必修课：\n";
        while(choice > ObligatoryNumber || choice < 0)
        {
            for(int i = 0; i < ObligatoryNumber; i++)
            {
                cout<<i+1<<".";
                cout<<*obligatory[i];
            }
            cout<<"请输入选择课程的编号,输入0取消本次选课\n";
            cin>>choice;
        }
        if(choice) return obligatory[choice-1];

    }
    else
    {
        cout<<"请选择选修课：\n";
        while(choice > ElectiveNumber || choice < 0)
        {
            for(int i = 0; i < ElectiveNumber; i++)
            {
                cout<<i+1<<".";
                cout<<*elective[i];
            }
            cout<<"请输入选择课程的编号,输入0取消本次选课\n";
            cin>>choice;
        }
        if(choice) return elective[choice-1];

    }
}
void Console::run()
{
    newStudent();
    newCourse();
    int n;
    int operate = Menu();
    while(operate)
    {
        if(!operate) return;
        switch(operate)
        {
            case 1:student->addCourse(selectCourse(operate));
                cout<<endl;break;
            case 2:student->addCourse(selectCourse(operate));
                cout<<endl;break;
            case 3:cout<<*student;
                cout<<endl;break;
            case 4:setCourseScore();
                cout<<endl;break;
            case 5:for(int i = 0; i < student->getCourseNumber(); i++)
                cout<<i<<"."<<*(student->courseList[i]);
                cout<<"请输入需要查询的课程编号（按照已选顺序）";
                cin>>n;
                getCourseGrade(n); break;
            case 6:student->getCredit();break;
            default: return ;
        }
        operate = Menu();
    }
}
void Console::getCourseGrade(int num)
{

    student->getScore(num);
}
int Console::Menu() const
{
	int choice=0;
	cout<<"**********主菜单**********\n";
	cout<<"1. 选必修课程\n";
	cout<<"2. 选选修课程\n";
    cout<<"3. 查看选课情况\n";
    cout<<"4. 设置课程成绩\n";
    cout<<"5. 查看课程成绩\n";
    cout<<"6. 查看绩点成绩\n";
    cout<<"0. 退出系统\n";
    cout<<"请输入操作序号：";
	cin>>choice;
    system("cls");
	return choice;
}
void Console::setCourseScore()
{
    int mark;
    char grade;
    for(int i = 0; i < student->getCourseNumber(); i++)
        cout<<*(student->courseList[i]);
    for(int i = 0; i < student->getCourseNumber(); i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*(student->courseList[i])))
        {//利用RTTI,判断是不是必修课
			cout<<"必修课程“"<<student->courseList[i]->getName()<<"”的成绩(0-100)：";
			cin>>mark;
			dynamic_cast<ObligatoryCourse &>(*(student->courseList[i])).setMark(mark);
		}
		else if(typeid(ElectiveCourse)==typeid(*(student->courseList[i])))
        {//利用RTTI,判断是不是选修课
			cout<<"选修课程“"<<student->courseList[i]->getName()<<"”的成绩(A-E)：";
			cin>>grade;
			dynamic_cast<ElectiveCourse &>(*(student->courseList[i])).setGrade(grade);
		}
    }
}
