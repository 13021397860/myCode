#include <iostream>
#include <fstream>
#include "date.h"
#include "student.h"
#include "course.h"
#include "obligatoryCourse.h"
#include "electiveCourse.h"
#include <string>
#include "test.h"
#include "myException.h"
#include <typeinfo>
using namespace std;

test::test()
{

}
test::~test()
{

}
bool test::readFile(student &stu)
{
    ifstream File(".\\course.txt");
    if(!File)
    {
        cout<<"课程数据异常！"<<endl;
        return false;
    }
    else
    {
        bool e1o0;
        string courseName;
        int creditHour;
        int i=1;
        while(File>>e1o0>>courseName>>creditHour)
        {
            if(e1o0)
            {
                course *C=new electiveCourse(courseName,creditHour);
                choose[i++]=C;
            }
            else
            {
                course *C=new obligatoryCourse(courseName,creditHour);
                choose[i++]=C;
            }
        }
        File.close();
        return true;
    }
}
bool test::createFile(student &stu)
{
    ofstream File(".\\student.txt");
    if(!File)
    {
        //cout<<"无法写入文件！"<<endl;
        return false;
    }
    else
    {
        File<<"name: "<<stu.getName()<<"  birthdate: "<<stu.getBirthDate()<<"class information: "<<endl;
        for(int i=0;i<stu.getNumber();i++)
        {
            course *temp;
            stu.getCourseList(i,temp);
            //stu.getCourseList(i,temp);
            File<<"name:"<<temp->getName()<<"    credit hour:"<<temp->getHour()<<"    score:"<<temp->getScore()<<endl;
        }
        cout<<"Write successfully!"<<endl;
        File.close();
        return true;
    }
}
void test::run()
{
    cout<<"Please input the student name:"<<endl;
    char name[15];
    cin>>name;
    cout<<"Please input the student birthdate:"<<endl;
    date birthday;
    cin>>birthday;
    student stu(name,birthday);
    stu.getInformation();
    cout<<"Course1 is:"<<endl;
    cout<<"Name: cpp;    CreditHour: 5;    Mark: 100;"<<endl;
    cout<<"Course2 is:"<<endl;
    cout<<"Name: English;    CreditHour: 4;    Grade: A;"<<endl;
    cout<<"Course3 is:"<<endl;
    cout<<"Name: History;    CreditHour: 3;    Grade: B;"<<endl;
    readFile(stu);
    int op;
    cout<<"choose which class? press 0 to quit;"<<endl;
    bool key=1;
    while(key)
    {
        try
        {
            cin>>op;
            if(cin.fail())
                throw myException();
        }
        catch(myException ex)
        {
            cin.clear();
            cin.ignore();
            cout<<"Error: "<<ex.courseException();
            continue;
        }
        if(op>3||op<-1)
        {
            cout<<"Error: Course Error!"<<endl;
            continue;
        }
        //if(op==-1)
            //break;
        stu.addCourse(choose[op]);
        cout<<"Choose successfully!"<<endl;
        cout<<"Enter 1 to continue, 0 to quit."<<endl;
        cin>>key;
        if(key==0)
            break;
        //cout<<"choose which class? press -1 to quit;"<<endl;
    }
    try
    {
        stu.setFenshu();
        /*
        for(int i=0;i<stu.getNumber();i++)
        {
            bool judgeo=true;
            bool judgee=true;
            if(typeid(stu.getCourse(i))==typeid(obligatoryCourse))
            {
                cout<<"It's an obligatory course, please input a mark;"<<endl;
                int mark;
                try
                {
                    cin>>mark;
                    if(mark<0||mark>100)
                    {
                        judgeo=false;
                        throw myException();
                    }
                }
                catch(myException ex)
                {
                    cout<<"Error: "<<ex.fenshuException();
                    cout<<"The score has been set to 95;"<<endl;
                    stu.getCourse(i)->setMark(95);
                }
                if(judgeo)
                    stu.getCourse(i)->setMark(mark);
                else
                    judgeo=false;
            }
            if(typeid(stu.getCourse(i))==typeid(electiveCourse))
            {
                cout<<"It's an elective course, please input a grade;"<<endl;
                char grade;
                try
                {
                    cin>>grade;
                    if(grade<'A'||grade>'E')
                    {
                        judgee=false;
                        throw myException();
                    }
                }
                catch(myException ex)
                {
                    cout<<"Error: "<<ex.fenshuException();
                    cout<<"The score has been set to 95;"<<endl;
                    stu.getCourse(i)->setGrade('A');
                }
                if(judgee)
                    stu.getCourse(i)->setGrade(grade);
            }
        }
        */
    }
    catch(myException ex)
    {
        cout<<"Error: "<<ex.fenshuException();
        cout<<"The FenShu has been set to 95;"<<endl;
    }
    //cout<<"Now the student's information:"<<endl;
    //cout<<stu;
    createFile(stu);
    cout<<"The student's credit is:"<<endl;
    cout<<stu.calcCredit()<<endl;
    int opp;
    cout<<"choose which class to remove? press 0 to quit;"<<endl;
    bool keyy=1;
    while(keyy)
    {
        try
        {
            cin>>opp;
            if(cin.fail())
                throw myException();
        }
        catch(myException ex)
        {
            cin.clear();
            cin.ignore();
            cout<<"Error: "<<ex.courseException();
            continue;
        }
        if(opp>3||opp<-1)
        {
            cout<<"Error: Course Error!"<<endl;
            continue;
        }
        if(opp==-1)
            break;
        stu.removeCourse(opp);
        cout<<"Remove successfully!"<<endl;
        cout<<"Enter 1 to continue, 0 to quit."<<endl;
        cin>>keyy;
        if(keyy==0)
            break;
        //cout<<"choose which class? press -1 to quit;"<<endl;
    }
    cout<<"Now the student's information:"<<endl;
    cout<<stu;
}
