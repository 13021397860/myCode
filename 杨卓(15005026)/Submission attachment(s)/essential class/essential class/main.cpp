#include <iostream>
#include <cstdio>
#include "Date.h"
#include "student.h"
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#include <cstdlib>
#include "Runer.h"
using namespace std;

int main()
{
    /*Date date;
    student stu;
    ObligatoryCourse obl;
    ElectiveCourse ele;
    Course cour;
    int y,m,d,year,month,day;
    cout<<"write the first student's name and brithday directly:";
    char *name1;
    name1=new char[100];
    cin>>name1;
    stu.setName(name1);
    cin>>y>>m>>d;
    stu.setBirthday(y,m,d);
    stu.cheakName();
    int k=1;
    Course *cptr1=new ElectiveCourse();
    Course *cptr2=new ObligatoryCourse();
    while(k)
    {
        int kk=1;
        cout<<"输入1进入选课系统，输入0退出选课系统->";
        cin>>kk;
        if(kk==0)
        {
            break;
        }
        int kkk=0;
        cout<<"输入1,选择必修课，输入2，选择选修课->";
        cin>>kkk;
        if(kkk==2)
        {
            Course *cptr1=new ElectiveCourse();
            cout<<"write the  electivecourse's name: ";
            char *course1;
            course1=new char[100];
            cin>>course1;
            cptr1->setcoursename(course1);
            cout<<"set the grade for this one: ";
            char grade1;
            cin>>grade1;
            cptr1->setgrade(grade1);
            cout<<"set the creditHour for this one:";
            int ch;
            cin>>ch;
            cptr1->setcredithour(ch);
            stu.addCourse(cptr1);
        }

        else
        {
            Course *cptr2=new ObligatoryCourse();
            cout<<"write the obligatorycourse's name: ";
            char *course2;
            course2=new char[100];
            cin>>course2;
            cptr2->setcoursename(course2);

            cout<<"set the mark for this one: ";
            int mmm;
            cin>>mmm;
            cptr2->setmark(mmm);
            cout<<"set the creditHour for this one:";
            int ch1;
            cin>>ch1;
            cptr2->setcredithour(ch1);


            stu.addCourse(cptr2);
        }
    }*/

    /*int ff=stu.getnum();
    if(ff!=0)
    cout<<"选课成功！"<<endl;
    if(ff==0)
    cout<<"选课失败！"<<endl;
    cout<<"the student's name and brithday is:"<<endl;
    cout<<stu.getName()<<endl;
    stu.getBirthday();
    stu.printBirthday();

    for(int i=0;i<ff;i++){
    cout<<"the course"<<i+1<<" and score are:"<<endl;;
    stu.printcourseList(i);}*/
    /*cout<<endl;
    cout<<"**************************************"<<endl;
    cout<<endl;
    cout<<stu;
    cout<<"**************************************"<<endl;
    cout<<endl;
    cout<<"人数count是："<<student::count<<endl;
    cout<<"the student's number of course is:"<<stu.getnum()<<endl;*/
    Runer rrrr;
    rrrr.start();
    system("pause");
    return 0;
}
