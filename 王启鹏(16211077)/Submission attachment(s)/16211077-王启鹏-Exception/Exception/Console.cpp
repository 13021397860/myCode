#include "Console.h"

Console::Console()
{
    //ctor
//    构建课程
//    ocList[0]=new ObligatoryCourse("数据结构", 5);
//    ocList[1]=new ObligatoryCourse("高等数学", 4);
//    ocList[2]=new ObligatoryCourse("大学英语", 2);
//    ocList[3]=new ObligatoryCourse("面向对象程序设计", 3);
//    ocList[4]=new ObligatoryCourse("工科大学物理", 4);
//    ocList[5]=new ObligatoryCourse("线性代数", 4);
//
//    ecList[0]=new ElectiveCourse("口语强化", 0);
//    ecList[1]=new ElectiveCourse("系统管理", 1);
//    ecList[2]=new ElectiveCourse("走进软件", 2);
//    ecList[3]=new ElectiveCourse("网站分析工具", 1);
}

Console::~Console()
{
    for(int i=0; i<6; i++){
        if(ocList[i])
            delete ocList[i];
    }
    for(int i=0; i<4; i++){
        if(ecList[i])
            delete ecList[i];
    }
    cout<<"退出系统"<<endl;
    //dtor
}

void Console::run()
{
    int a;
    char fileName[20]="WriteFile.txt";
    buildStudent();
    //cout<<"*****"<<endl;
    buildCourse();
    a=display();
    while(a){
        if(a==0){
            break;
        }
        else if(a==1 || a==2){
            Course *tmp=chooseCourse(a);
            person->addCourse(tmp);
            cout<<"选课成功"<<endl;
        }
        else if(a==3){
            deleteCourse();
        }
        else if(a==4){
            cout<<"**********************************************"<<endl;
            cout<<*person;
            cout<<"**********************************************"<<endl;
        }
        else if(a==5){
            setCourseScore();
        }
        else if(a==6){
            cout<<"**********************************************"<<endl;
            cout<<"绩点："<<fixed<<setprecision(4)<<person->calcCredit()<<endl;
            cout<<"**********************************************"<<endl;
        }
        else if(a==7){
            ofstream write(fileName);
            if(!write.is_open()){
                cout<<"文件“WriteFile.txt”保存失败"<<endl;
            }
            else{
                cout<<"文件“WriteFile.txt”保存成功"<<endl;
                write<<*person<<endl;
                write<<"绩点："<<fixed<<setprecision(4)<<person->calcCredit()<<endl;
                write.close();
            }
        }
        a=display();
    }
    return ;
}

void Console::buildStudent()
{
    char name[100];
    int y, m, d;
    cout<<"请输入学生姓名：";
    cin>>name;
    cout<<"请输入学生生日(“年 月 日”的格式输入)：";
    while(1){
        cin>>y>>m>>d;
        try{

            Date tmp(y, m, d);
            person=new Student(name, y, m, d);
            break;
        }
        catch(MyException){}
    }
    return ;
}

void Console::buildCourse()
{
    char fileName[20]="readFile.txt";
    ifstream read(fileName);
    if(!read.is_open()){
        cout<<"创建课程失败"<<endl;
    }
    else{
        string name;
        int credit;
        for(int i=0; i<6; i++){
            read>>name>>credit;
            ocList[i]=new ObligatoryCourse(name, credit);
        }
        for(int i=0; i<4; i++){
            read>>name>>credit;
            ecList[i]=new ElectiveCourse(name, credit);
        }
        read.close();
    }
    return ;
}

int Console::display()
{
    cout<<"============学生选课系统===========\n"
        <<"\t 0、退出系统\n"
        <<"\t 1、选必修课\n"
        <<"\t 2、选选修课\n"
        <<"\t 3、退课\n"
        <<"\t 4、查看选课情况\n"
        <<"\t 5、设置每门课程的成绩\n"
        <<"\t 6、查询绩点\n"
        <<"\t 7、将学生和选课信息保存在“WriteFile.txt”中\n"
        <<"===================================\n"
        <<"输入操作：";
    int a;
    cin>>a;
    while(cin.fail() || a<0 || a>7){
        cout<<"输入错误，请重新输入：";
        cin.clear();
        cin.ignore();
        cin>>a;
    }
    return a;
}

Course* Console::chooseCourse(int a)
{
    int which;
    if(a==1){
        cout<<"==============必修课===============\n"
            <<"\t 1.数据结构   5\n"
            <<"\t 2.高等数学   4\n"
            <<"\t 3.大学英语   2\n"
            <<"\t 4.面向对象程序设计   3\n"
            <<"\t 5.工科大学物理   4\n"
            <<"\t 6.线性代数   4\n"
            <<"===================================\n"
            <<"请输入课程编号：";
        cin>>which;
        while(cin.fail() || which<1 || which>6){
            cout<<"输入错误，请重新输入：";
            cin.clear();
            cin.ignore();
            cin>>which;
        }
        return ocList[which-1];
    }
    else {
        cout<<"==============选修课===============\n"
            <<"\t 1.口语强化  0\n"
            <<"\t 2.系统管理   1\n"
            <<"\t 3.走进软件   2\n"
            <<"\t 4.网站分析工具   1\n"
            <<"===================================\n"
            <<"请输入课程编号：";
        cin>>which;
        while(cin.fail() || which<1 || which>4){
            cout<<"输入错误，请重新输入：";
            cin.clear();
            cin.ignore();
            cin>>which;
        }
        return ecList[which-1];
    }
}

void Console::deleteCourse()
{
    if(person->getCourseNumber()==0)
        return ;
    int which;
    cout<<"**********************************************"<<endl;
    cout<<"已选课程：\n";
        for(int i=0; i<person->getCourseNumber(); i++)
            cout<<i+1<<"、"<<(*person)[i]<<endl;
    cout<<"**********************************************"<<endl;
    cout<<"请输入退课的编号：";
    while(1){
        cin>>which;
        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"输入错误"<<endl;
        }
        else{
            try{
                person->removeCourse(which);
                cout<<"退课成功"<<endl;
                return ;
            }
            catch(MyException){}
        }
    }
    return ;
}

void Console::setCourseScore()
{
    char grade;//ElectiveCourse.setGrade
    int mark;//ObligatoryCourse.setMark
    for(int i=0; i<person->getCourseNumber(); i++){
        if( typeid(ObligatoryCourse)==typeid((*person)[i]) ){
            cout<<"请输入必修课：“"<<(*person)[i].getName()<<"” 的成绩（0-100）：";
            cin>>mark;
            while(cin.fail()){
                cout<<"输入错误，请重新输入（0-100）：";
                cin.clear();
                cin.ignore();
                cin>>mark;
            }
            while(1){
                try{
                    dynamic_cast<ObligatoryCourse&>((*person)[i]).setMark(mark);
                    break;
                }
                catch(MyException my){}
                cin>>mark;
            }
        }
        else{
            cout<<"请输入选修课：“"<<(*person)[i].getName()<<"” 的成绩（A-E）：";
            cin>>grade;
            while(cin.fail()){
                cout<<"输入错误，请重新输入（A-E）：";
                cin.clear();
                cin.ignore();
                cin>>grade;
            }
            while(1){
                try{
                    dynamic_cast<ElectiveCourse&>((*person)[i]).setGrade(grade);
                    break;
                }
                catch(MyException){}
                cin>>grade;
            }

        }
        cout<<"设置成功"<<endl;
    }
    return ;
}
/*
WQP
21 32 3
1 1 1
1
1
2
2
5
123
87
T
A
3
a
6
3
1
4
0
*/
