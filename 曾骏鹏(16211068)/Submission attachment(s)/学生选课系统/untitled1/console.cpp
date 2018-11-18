//
// Created by zjp on 2017/4/25.
//

#include "console.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "myException.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
/*
ObligatoryCourse on[MAX_SIZE_1]={{"程序设计",4},{"数据结构",3},
                                {"大学英语",2}, {"高等数学",4}};
ElectiveCourse en[MAX_SIZE_2]={{"体育",1},{"音乐",1},{"美术",1},
                                {"日语",2},{"法语",2},{"俄语",2}};
*/

console::console()
{
    ocNum=0;
    ecNum=0;
}
console::~console() {}

int console::displayMenu() const
{
    cout << "\n请选择后续操作，输入序号后以回车结束。\n";
    cout <<"1.查看学生当前信息\n" << "2.选课\n" << "3.退课\n" << "4.查看课程列表\n" << "5.查看当前绩点\n" << "6.以学生姓名为文件名保存其信息\n" << "7.结束选课并退出\n" << "你选择的操作序号：";
    int operation;
    cin >> operation;
    cout << '\n';
    while(cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "错误操作！请重新输入：";
        cin >> operation;
    }
    cout << '\n';
    return operation;
}

void console::print_courseList()
{
    cout << "\n必修课程：\n";
    /*for(int i=0;i<MAX_SIZE_1;i++)
        cout << i+1 << '.' << oc[i] << '\n';
    cout << "选修课程：";
    for(int i=0;i<MAX_SIZE_2;i++)
        cout << i+5 << '.' << "课程名：" << ec[i] << '\n';*/
    for(int i=0;i<4;i++)
        cout << i+1 << '.' << "课程名：" << oc[i]->getName() << " 学分：" << oc[i]->getCreditHour() << '\n';
    cout << "选修课程：\n";
    for(int i=0;i<6;i++)
        cout << i+5 << '.' << "课程名：" << ec[i]->getName() << " 学分：" << ec[i]->getCreditHour() << '\n';
}

void console::operation_judge(int i)
{
    switch(i)
    {
        case 1:
            cout << (*student) << '\n';
            operation_judge(displayMenu());
            break;
        case 2:
            cout << "选课上限7门。\n请输入课程序号并以回车确认输入。\n";
            cout << "若需要查看备选课程，请输入数字0并以回车确认输入。\n" << "你选择的课程序号为：";
            int z;
            while(1)
            {
                cin >> z;
                try {
                    cout << '\n';
                    if (cin.fail() || z < 0 || z > MAX_SIZE_1 + MAX_SIZE_2) {
                        cin.clear();
                        cin.ignore();
                        throw myException(RANGE_ERROR);
                    }
                    else if (!z) {
                        print_courseList();
                        cout << "请重新输入课程序号：";
                        continue;
                    }
                }
                catch(myException &exc1) {
                    cout << exc1.what();
                    continue;
                }
                break;
            }
            selectCourse(z);
            operation_judge(displayMenu());
            break;
        case 4:
            print_courseList();
            operation_judge(displayMenu());
            break;
        case 5:
            cout << "当前绩点为：" << student->calcCredit() << '\n';
            operation_judge(displayMenu());
            break;
        case 3:
            cout << "请输入已选课程中需要退选的课程的序号，如需查看当前学生信息请输入0\n你需要退选的课程序号是：";
            int number;
            while(1) {
                cin >> number;
                try {
                    if(cin.fail() || number<0 || number>student->getNumber()) {
                        cin.clear();
                        cin.ignore();
                        throw myException(RANGE_ERROR);
                    }
                    else if(!number) {
                        cout << "\n";
                        cout << *student;
                        cout << "\n   当前已选课程数为：" << student->getNumber() << endl << endl;
                        cout << "请重新选择需要退选的课程序号：";
                        continue;
                    }
                }
                catch(myException &exc2) {
                    cout << exc2.what();
                    continue;
                }
                break;
                if(!number) {
                    cout << (*student) << '\n';
                    cout << "请重新输入需要退选的课程序号：";
                }
                else if(number<1 || number>student->getNumber()){
                    cout << "输入有误，请重新输入：";
                }
                else break;
            }
            student->removeCourse(number);
            operation_judge(displayMenu());
            break;
        case 6: {
            string fileName=student->getName();
            fileName+=".txt";
            ofstream outfile(fileName, ios::out);
            if (!outfile) {
                cout << "无法打开文件\n";
                break;
            }
            outfile << *student << "   绩点：" << student->calcCredit() << endl;
            operation_judge(displayMenu());
            break;
        }
        case 7:
            student->printInfo(*student);
            break;
    }
}

int console::run()
{
    buildStudent();
    buildCourse();
    operation_judge(displayMenu());
    cout << "操作结束\n" << "学生信息：\n" << *student << "   绩点为：" << student->calcCredit();
    return 1;
}

course* console::selectCourse(int op)
{
    switch((op+3)/4)
    {
        case 1:
            student->addCourse(oc[op-1]);
            break;
        case 2:
        case 3:
            student->addCourse(ec[op-5]);
            break;
        default:
            cout << "错误序号，请重新输入：\n";
            selectCourse(op);
            break;
    }
    student->setCourseScore();
    return ec[op];
}

console& console::buildStudent()
{
    char name[20];
    date t;
    cout << "请输入学生姓名:";
    cin >> name;
    cout << "请输入学生的出生日期(格式：年-月-日)：";
    while(1)
    {
        cin >> t;
        try {
            if (cin.fail() || !t.check()) {
                cin.clear();
                cin.ignore();
                throw myException(DATE_INVALID);
            }
        }
        catch (myException &me) {
            cout << me.what();
            continue;
        }
        break;
    }
    student = new class student(name,t.getYear(),t.getMonth(),t.getDay());
    return *this;
}

console& console::buildCourse()
{
    /*oc[0]=new ObligatoryCourse("程序设计",4);
    oc[1]=new ObligatoryCourse("数据结构",3);
    oc[2]=new ObligatoryCourse("大学英语",2);
    oc[3]=new ObligatoryCourse("高等数学",4);

    ec[0]=new ElectiveCourse("大学体育",1);
    ec[1]=new ElectiveCourse("音乐鉴赏",1);
    ec[2]=new ElectiveCourse("绘画艺术",1);
    ec[3]=new ElectiveCourse("西班牙语",2);
    ec[4]=new ElectiveCourse("葡萄牙语",2);
    ec[5]=new ElectiveCourse("繁体中文",2);*/
    fstream infile("CourseInfo.txt",ios::in);
    if(!infile) {
        cout << "文件不存在\n";
        return *this;
    }
    string name;
    int credit;
    int i=0;
    while(i<MAX_SIZE_1 && infile >> name >> credit)
        oc[i++]=new ObligatoryCourse(name,credit);
    i=0;
    while(i<MAX_SIZE_2 && infile >> name >> credit)
        ec[i++]=new ElectiveCourse(name,credit);
    infile.close();
    return *this;
}