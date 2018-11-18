#include "xuanke.h"
#include <cstring>
#include <string>
#include <fstream>
#include <cstdlib>
xuanke::xuanke()
{
    memset(coursetype, 0, sizeof(coursetype));
    //ctor
}

bool xuanke::init()
{
    int credit;
    string name;
    ifstream inFile("coursedata.txt", ios::in);
    if(!inFile)
    {
        return false;
    }
    for(int i =1; i <= 4; i++)
    {
        inFile >> name >> credit;
        CourseList1[i] = new Obligatory(name, credit);
    }
    for(int i =1; i <= 4; i++)
    {
        inFile >> name >> credit;
        CourseList2[i] = new ElectiveCourse(name, credit);
    }
    inFile.close();
    return true;
    /*CourseList1[1] = new Obligatory("PE", 1);
    CourseList1[2] = new Obligatory("Math", 2);
    CourseList1[3] = new Obligatory("English", 1);
    CourseList1[4] = new Obligatory("Chinese", 10);

    CourseList2[1] = new ElectiveCourse("C++", 2);
    CourseList2[2] = new ElectiveCourse("PCR", 2.5);
    CourseList2[3] = new ElectiveCourse("OpenGL", 1);
    CourseList2[4] = new ElectiveCourse("UML", 2);*/
}

void xuanke::SetScore(const int score, int nCourse)
{
    if(nCourse > stu->GetCoursenumber() || nCourse < 1) return;
    stu->setStuScore(coursetype[nCourse], score, nCourse);
}

void xuanke::AddCourse(const int type,const  int nCourse)
{

    if(stu->GetCoursenumber() >= 8 || nCourse < 1 || nCourse >4)
    {
        cout << "Error choose\n";
        return;
    }
    if(type == 1)
    {
        stu->addCourse(CourseList1[nCourse], type);
        coursetype[stu->GetCoursenumber()] = 1;
    }
    else if(type == 2)
    {
        stu->addCourse(CourseList2[nCourse], type);
        coursetype[stu->GetCoursenumber()] = 2;
    }

}

void xuanke::RemoveCourse(const int nCourse)
{
    if(nCourse <= 0 || nCourse > stu->GetCoursenumber())
    {
        MyException course(2);
        throw course;
    }
    if(!stu->removeCourse(nCourse)) cout << "you do not have this course\n";
    else
    {
        for(int i = nCourse; i <= stu->GetCoursenumber(); i++)
        {
            coursetype[i] = coursetype[i+1];
        }
    }

}

const void xuanke::print()
{
    cout << *stu;
}

const void xuanke::save()
{
    ofstream outFile("student.txt", ios::out);
    outFile << *stu;
}
void xuanke::testDate()
{
    cout <<endl;
    cout<< "test class Date: \n";
    Date m(02,24,1998);
    cout << m<<endl;
    cout <<"Date++ = : "<< m++<<endl;
    cout <<"++Date = : "<< ++m<<endl;
    m+=3;

    cout <<"Date = : "<< m<<endl;
}

const void xuanke::printcourse()
{
    cout << "There are two kinds of course for you:\n";
    cout << "Obligatory course(type 1):\n";
    for(int i= 1; i <= 4; i++) cout << i<<","<< *CourseList1[i];
    cout << "Elective course(type 2):\n";
    for(int i= 1; i <= 4; i++) cout << i<<","<< *CourseList2[i];
}

const void xuanke::printindex()
{
    cout << "接下来做什么？\n";
    cout << "1,选课\n2,退课\n3,查询\n4,设置成绩(type1: 0-100, type2: A-E)\n5,测试Date类\n6,保存学生信息\n0,退出系统\n";
}

void xuanke::run()throw(MyException)
{
    if(!init())
    {
        cerr << "文件打开失败";
        exit(1);
    }
    cout << "Welcome to course system:\nWhat is your name and birthday(es: 1998 02 22)\n";
    char stuname[15];
    cin >> stuname;
    try
    {
        int y,m,d;
        cin >> y>>m>>d ;
        stu = new Student(stuname, y,m,d);
    }
    catch(MyException &except)
    {
        except.print();
        stu = new Student(stuname, 1,1,1);
    }

    while(1)
    {
        printindex();
        int x;
        try
        {
            cin >>x;
            if(cin.fail())
            {
                cin.clear();		//清除错误标记
                cin.ignore();	//移除错误字符
                cerr << "输入错误,请重新输入\n";
                continue;
            }
            if(x == 0)
            {
                cout << "谢谢使用，再见\n";
                break;
            }
            else if(x == 1)
            {
                printcourse();
                cout << "请输入要选的课程类别（ 1 / 2）和第几个:\n";
                int type, n;
                cin >> type>>n;
                if(cin.fail())
                {
                    cin.clear();		//清除错误标记
                    cin.ignore();	//移除错误字符
                    cout << "输入错误,请重新输入\n";
                    continue;
                }
                if(type < 1 || type > 2 || n < 1|| n > 4)
                {
                    MyException course(2);
                    throw course;
                }
                AddCourse(type, n);
            }
            else if(x == 2)
            {
                cout << "请问要退掉哪门课?\n";
                int i;
                cin >> i;

                RemoveCourse(i);
            }
            else if(x == 3)
            {
                print();
            }
            else if(x == 4)
            {
                cout<< "您要设第几门课的成绩，成绩是多少？\n";
                int nu;
                cin >> nu;
                if(nu <= 0 || nu > stu->GetCoursenumber())
                {
                    MyException course(2);
                    throw course;
                }
                if(cin.fail())
                {
                    cin.clear();		//清除错误标记
                    cin.ignore();	//移除错误字符
                    cerr << "输入错误,请重新输入\n";
                    continue;
                }
                if(coursetype[nu] == 1)
                {
                    int score;
                    cin >> score;
                    if(cin.fail())
                    {
                        cin.clear();		//清除错误标记
                        cin.ignore();	//移除错误字符
                        cerr << "输入错误,请重新输入\n";
                        continue;
                    }
                    SetScore(score, nu);
                }
                else if(coursetype[nu] == 2)
                {
                    char score;
                    cin >> score;
                    if(cin.fail())
                    {
                        cin.clear();		//清除错误标记
                        cin.ignore();	//移除错误字符
                        cerr << "输入错误,请重新输入\n";
                        continue;
                    }
                    SetScore(score, nu);
                }

            }
            else if(x == 5)
            {
                testDate();
            }
            else if(x == 6)
            {
                save();
            }
            else
            {
                cout << "输入错误,请重新输入\n";
            }

        }
        catch(MyException except)
        {
            except.print();
        }

    }


}

xuanke::~xuanke()
{
    //dtor
}
