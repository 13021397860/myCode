#include "Console.h"
#include <iostream>

#include "Student.h"

#include "Obligatorycourse.h"
#include "electivecourse.h"
#include "course.h"
#include <vector>
#include <fstream>
#include <string>
#include "MyException.h"
#include<stdlib.h>
using namespace std;


Console::Console()
{
}


Console::~Console()
{
}
void Console::run() {

    try{

        string name;
        Date  brithday;
        //构造学生
        cout << "请输入学生姓名:";
        cin >> name;
        cout << "请输入学生生日(格式:xxxx-mm-dd):";
        cin >> brithday;

        Student* stu = new Student(name, brithday);


        //定义存放必修课和选修课的数组
        std::vector<ObligatoryCourse*> obligatoryCourses;
        std::vector<ElectiveCourse*> electiveCourses;

        obligatoryCourses.push_back(new ObligatoryCourse("c++", 4));
        obligatoryCourses.push_back(new ObligatoryCourse("离散数学", 4));
        obligatoryCourses.push_back(new ObligatoryCourse("高等数学", 3));

        electiveCourses.push_back(new ElectiveCourse("音乐欣赏", 2));
        electiveCourses.push_back(new ElectiveCourse("航天概论", 1));
        electiveCourses.push_back(new ElectiveCourse("文化发展史", 2));



        while (1){
            cout << "请输入您要选择的课程类型" << endl;
            cout << "1.必修课" << endl;
            cout << "2.选修课" << endl;
            cout << "-1.退出选课" << endl;
            int op;
            cin >> op;

            if (op == 1){
                int k = 5;
                while (k--) {
                    cout << "请输入选课的编号" << endl;
                    for (int i = 0; i < obligatoryCourses.size(); ++i) {
                        cout << i+1<<"." << *obligatoryCourses[i] << endl;
                    }
                    cout << "-1.结束选课" << endl;
                    cin >> op;
                    if (op == -1)
                        break;
                    if (op <= 0 || op > obligatoryCourses.size()) {
                        cerr << "您输入的信息有误，程序意外退出！" << endl;
                        exit(1);
                    }
                    cout << "请输入该课的分数:";
                    int scor;
                    cin >> scor;
                    obligatoryCourses[op - 1]->setMark(scor);
                    stu->addCourse(obligatoryCourses[op - 1]);
                    cout << "添加成功" << endl;
                }


            }
            else if (op == 2) {
                int k = 5;
                while (k--) {
                    cout << "请输入选课的编号" << endl;
                    for (int i = 0; i < electiveCourses.size(); ++i) {
                        cout << i+1<<"." << *electiveCourses[i] << endl;
                    }
                    cout << "-1.结束选课" << endl;
                    cin >> op;
                    if (op == -1) {
                        break;
                    }
                    if (op <= 0 || op > electiveCourses.size()) {
                        cerr << "您输入的信息有误，程序意外退出！" << endl;
                        exit(1);
                    }
                    cout << "请输入该课的成绩(A-E):";
                    char scor;
                    cin >> scor;
                    electiveCourses[op - 1]->setGrade(scor);
                    stu->addCourse(electiveCourses[op - 1]);
                    cout << "添加成功!" << endl;
                }
            }
            else if(op == -1){
                break;
            }
            else {
                cerr << "您输入的信息有误，程序意外退出！" << endl;
                exit(1);
            }



        }

        //把所有的必修课和选修课存入到文件中

        //创建文件输出流
        std::ofstream of_c("课程信息.txt");

        //of_c << "------------------必修课------------------- " << endl;
        //遍历必修课
        for (int i = 0; i < obligatoryCourses.size(); ++i) {

            //输出到文件中。
            of_c << *obligatoryCourses[i] << endl;
        }
        //of_c << endl<< endl;
        //of_c << "------------------选修课------------------- " << endl;

        //遍历选修课
        for (int i = 0; i < electiveCourses.size(); ++i) {

            //输出到文件中。
            of_c << *electiveCourses[i] << endl;
        }

        //关闭文件流
        of_c.close();



        //创建文件输入流，用于读取文件中的内容

        std::ifstream if_c("课程信息.txt");

        string line;

        cout << endl << endl << "文件中的内容为-------------------------->" << endl;

        //还没读到结束就一直循环
        while (!if_c.eof()) {

            //从文件流中读入一行，存在line中
            getline(if_c,line);

            //打印到控制台显示
            cout << line << endl;
        }

        //关闭流
        if_c.close();

        //存储学生的信息和他选课的信息到文件中

        //创建文件输出流
        std::ofstream stu_of("学生信息及选课信息.txt");

        stu_of << *stu;
        stu_of.close();
    //	std::cout << *stu << std::endl;

        Student stu2;

        //再从文件中读取课程信息并恢复
        std::ifstream stu_if("学生信息及选课信息.txt");
        stu_if >> stu2;

        //关闭文件输入流

        stu_if.close();

        cout << "从文件中读入的学生的信息为-------------------------->" << endl;
        cout << stu2 << endl;
    }catch(const MyException& e){
        cout<<"catch excepton:"<<e.info<<endl;
    }


	//stu->removeCourse(1);
	//std::cout << "删除后：" << std::endl;
	//cout << *stu << std::endl;
}
