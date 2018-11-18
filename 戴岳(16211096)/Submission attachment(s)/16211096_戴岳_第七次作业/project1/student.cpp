#include "student.h"
#include "date.h"
#include "cstring"
#include "course.h"
#include "electivecourse.h"
#include "obligatorycourse.h"
#include "myexception.h"
#include <iostream>
#include <iomanip>
#include <typeinfo>
using namespace std;

int Student::count = 0;

Student::Student():birthDate(2000,1,1)
{
    courseNumber=0;
    name=new char[10];
    strcpy(name,"Undefined");
    count++;
}

Student::~Student()
{
    for(int i=0;i<courseNumber;i++)
    {
        delete courseList[i];
    }
    delete []name;
    count--;

}

Student::Student(const char* p,const int y,const int m,const int d):birthDate(y,m,d)
{
    courseNumber=0;

    name = new char[strlen(p)+1];
    strcpy(name,p);
    count++;
}

Student::Student(const Student& stud):birthDate(stud.birthDate)
{
    courseNumber=0;

    name = new char[strlen(stud.name)+1];
    strcpy(name,stud.name);
    count++;
}

void Student::setname(const char*p)
{
    delete []name;
    name = new char[strlen(p)+1];
    strcpy(name,p);
}
char* Student::getname() const
{
   return name;
}

int Student::getcoursenumber()const
{
    return courseNumber;
}
void Student::getbirthDate(Date& d) const
{
    d.setTime(birthDate.getYear(),birthDate.getMonth(),birthDate.getDay());
}

int Student::getcount()
{
    return count;
}

Student& Student::addCourse( Course *course)
{
    if(courseNumber<20)
    {
        courseList[courseNumber++] = course;
    }
    return (*this);
}

/*Student& Student::addCourse(const string & n, int h)
{
    if(courseNumber<20)
    {
        courseList[courseNumber++]=new Course(n,h);
    }
    return (*this);
}*/

bool Student::removeCourse(int n)
{
    if(n<courseNumber&&n>0)
    {
        for(int i=n;i<courseNumber;i++)
        {
            courseList[i]=courseList[i+1];
        }
        courseNumber--;

        return 1;
    }
    else if(n==courseNumber)
    {
        courseNumber--;
    }
    return 0;

}

bool Student::setScore(int n)
{
    n--;
    if(n<=courseNumber&&n>=0)
    {
        if(typeid(*courseList[n])==typeid(ElectiveCourse))
        {
            cout<<"请输入选修课成绩：";
            char x;
            cin>>x;
            while(1)
            {
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout<<"error!"<<endl;
                    cin>>x;
                }
                try
                {
                    if(x<'A'||x>'E')
                    {
                    MyException e(3);
                    throw e;
                    }
                    dynamic_cast<ElectiveCourse*>(courseList[n])->setScore(x);
                    break;

                }
                catch(MyException& error)
                {
                error.what();
                cin>>x;
                }


            }

            return 1;
        }
        else if(typeid(*courseList[n])==typeid(ObligatoryCourse))
        {
            cout<<"请输入必修课成绩：";
            int x;
            cin>>x;
            while(1)
            {
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout<<"error!"<<endl;
                    cin>>x;
                }
                try
                {
                    if(x<0||x>100)
                    {
                    MyException e(3);
                    throw e;
                    }
                    dynamic_cast<ObligatoryCourse*>(courseList[n])->setScore(x);
                    break;

                }
                catch(MyException& error)
                {
                error.what();
                cin>>x;
                }


            return 1;
        }
    }
    else cout<<"不存在该课程"<<endl;
    return 0;
}
}
double Student::calcCredit()const
{
    double sum1=0,sum2=0,credit1=0,credit2=0;
    for(int i=0;i<courseNumber;i++)
    {
        if(typeid(*courseList[i])==typeid(ElectiveCourse))
        {
            Course *p =courseList[i];
            sum1+=(p->getScore()*p->getcreditHour());
            credit1+=p->getcreditHour();
        }
        else if(typeid(*courseList[i])==typeid(ObligatoryCourse))
        {
            Course *p =courseList[i];
            sum2+=(p->getScore()*p->getcreditHour());
            credit2+=p->getcreditHour();
        }
    }
    if(credit1&&credit2)return 0.6*(sum1/credit1)+0.4*(sum2/credit2);
    else if(credit1)return 0.6*(sum1/credit1);
    else if(credit2)return 0.4*(sum2/credit2);
    else return 0;
}

ostream& operator<<(ostream& output, const Student& c)
{
    output<<"姓名："<<c.getname()<<" 出生日期：";
    output<<c.birthDate;
    output<<"，选课信息如下："<<endl;

    for(int i=0;i<c.courseNumber;i++)
    {

        output<<"No."<<setw(4)<<i+1<<*(c.courseList[i])<<endl;
    }
    output<<"学生绩点为:"<<c.calcCredit()<<endl;
    return output;
}
