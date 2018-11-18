#include "console.h"
#include"course.h"
#include"obligatorycourse.h"
#include"electivecourse.h"
#include<fstream>
#include"exception.h"
Console::Console()
{
    //ctor
}

Console::~Console()
{
    //dtor
}
void Console::ccs(Student s)
{
    cout<<"the name of the student is :"<<endl;
    char nam[12];
    cin>>nam;
    s.setStudentName(nam);
    cout<<"the birthday of the student is :"<<endl;
    int y,m,d;
    cin>>y>>m>>d;
    s.setStudentBirthDate(y,m,d);
    ObligatoryCourse ob[3];
    ob[0].setName("math");ob[0].setCreditCard(1);
    ob[1].setName("english");ob[1].setCreditCard(2);
    ob[2].setName("others");ob[2].setCreditCard(3);
    ofstream oblist("oblist.txt",ios::out);
    for(int i=1;i<=3;i++)
    oblist<<i<<" "<<ob[i-1].getName()<<endl;

    ifstream in("oblist.txt");
    for(string tem;in>>tem;)
    {
        cout<<tem<<endl;
    }
    in.close();
    //for(int i=1;i<=3;i++)
        //cout<<i<<" "<<ob[i-1].getName()<<endl;
        int t;

        while(1)
        {
             cout<<"input the number to choose ob course or -1 for end"<<endl;
             cin>>t;
            if(t!=-1)
            {
                s.addCourse(&ob[t-1]);
                s.obno++;
                cout<<"set the score"<<endl;
                int x;
                cin>>x;
                try
                {
                    if(x<0||x>100)
                    throw Illegal_OC_Score_Exception();
                }
                catch(Exception &x)
                {
                    cout<<x.what()<<endl;
                    return;
                }

                s.courseList[s.courseNumber-1]->setMark(x);
            }
            else break;
        }
        ElectiveCourse el[3];
        el[0].setName("aaa");el[0].setCreditCard(1);
        el[1].setName("abb");el[1].setCreditCard(2);
        el[2].setName("abc");el[2].setCreditCard(3);
        ofstream ellist("ellist.txt",ios::out);
           for(int i=1;i<=3;i++)
        ellist<<i<<" "<<el[i-1].getName()<<endl;
        ifstream ina("ellist.txt");
    for(string tem;ina>>tem;)
    {
        cout<<tem<<endl;
    }
    in.close();
        //for(int i=1;i<=3;i++)
        //cout<<i<<" "<<el[i-1].getName()<<endl;

        while(1)
        {
            cout<<"input the number to choose el course or -1 for end"<<endl;
            cin>>t;
            if(t!=-1)
            {
                s.addCourse(&el[t-1]);
                cout<<"set the score"<<endl;
                char x;
                cin>>x;
                try
                {
                    if(x<'A'||x>'Z')
                    throw Illegal_OC_Score_Exception();
                }
                catch(Exception &x)
                {
                    cout<<x.what()<<endl;
                    return;
                }
                s.courseList[s.courseNumber-1]->setGrade(x);
            }
        else break;
        }
        s.print();
        cout<<"the calcCredit is "<<s.calcCredit()<<endl;
        for(int i=0;i<s.courseNumber;i++)
        {
            cout<<"the score of "<<s.courseList[i]->getName()<<" is ";
            cout<<s.courseList[i]->getScore()<<endl;
        }
        ofstream student("student.txt",ios::out);
        student<<"name: "<<s.getStudentName()<<" "<<endl;
        student<<"birthdate: "<<s.getStudentBirthYear()<<"-"<<s.getStudentBirthMonth()<<"-"<<s.getStudentBirthDay()<<endl;
        student<<"所选课程有："<<endl;
        for(int i=0;i<s.courseNumber;i++)
    {
        student<<"name :"<<s.courseList[i]->getName()<<endl;
        student<<"creditHour :"<<s.courseList[i]->getCreditHour()<<endl;
        }
}
