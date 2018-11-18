#include "Student.h"
#include "Date.h"
#include "Course.h"
#include "Console.h"
#include "MyException.h"
#include <cstring>
#include <iostream>
#include <typeinfo>
#define MAX_SIZE 3
using namespace std;

int Student::Scount=0;
Student::Student():birthDate(2017,3,21)
{
    name=NULL;
    char *n="empty";
    setname(n);
    ++Scount;
    courseNumber = 0;
}
Student::Student(const Student &n):birthDate(n.birthDate)
{
    setname(n.name);
        ++Scount;
        courseNumber=n.courseNumber;
}
Student::~Student()
{
    int i=courseNumber-1;	//释放课程信息
	while(i>0)
    {
		if (removeCourse(i)) i--;
	}
   delete[] name;
   --Scount;
}

void Student::setcourseNumber()
{
    courseNumber=0;
}
void Student::setbirthDate(int y,int m,int d)
{
    birthDate.setdate(y,m,d);
}
char* Student::getname() const
{
    return name;
}
void Student::setname(const char *n){
	if (name)
    delete[] name;
	length=strlen(n);
	name=new char[length+1];
	strcpy(name,n);
}

int Student::getbirthDateyear() const
{
    return birthDate.getyear();
}

int Student::getbirthDatemonth() const
{
    return birthDate.getmonth();
}

int Student::getbirthDateday() const
{
    return birthDate.getday();
}

int Student::getcourseNumber()const
{
    return courseNumber;
}
int Student::getCount()
{
    return Scount;
}


Student& Student::addcourse(Course *course)
{
    if(courseNumber <MAX_SIZE)
    {
        if(dynamic_cast<ObligatoryCourse*>(course))
        {
             courseList[courseNumber] = new ObligatoryCourse;
        }
        else if(dynamic_cast<ElectiveCourse*>(course))
        {
             courseList[courseNumber] = new ElectiveCourse;
        }
        courseList[courseNumber] = course;
        courseNumber++;
        //指针
    }
    else
    {
        throw MyException(RANGE_ERROR);
    }
    return (*this);
}
ostream& operator<<(ostream& output, const Student& s){
	output<<"name:\n"<<s.getname()<<"\nbirthdate:\n"<<s.birthDate<<"The selected course information is as follows :\n";
	for(int i=0;i<s.courseNumber;i++)
    {
		output<<(*s.courseList[i]);
	}
	return output;
}
const Course& Student::operator[](int sub) const
{
	if (sub < 0 || sub >=courseNumber ){
	   //cerr <<"下标越界: " << subscript << endl;
	   //exit( 1 ); // 访问越界，退出程序
	   throw MyException(RANGE_ERROR);
	}
	return (*courseList[sub]);
}

//怎么就没有多态性呢呢呢呢呢呢呢呢
/*bool Student::setCourseScore(int di)
{
    if(typeid(ObligatoryCourse)==typeid([di-1]))
    {
        cout<<"Please input your ObligatoryCourse's mark:";
        int marks;
        cin>>marks;
        dynamic_cast<ObligatoryCourse&>([di-1])->setmark(marks);
        cout<<"courseScore:"<<dynamic_cast<ObligatoryCourse&>([di-1])->getmark();
        return true;
    }
    else if(typeid(ElectiveCourse)==typeid([di-1]))
    {
         cout<<"Please input your ElectiveCourse's grade(A-E):";
         char grades;
         cin>>grades;
         dynamic_cast<ElectiveCourse&>([di-1])->setgrade(grades);
         cout<<"courseScore:"<<dynamic_cast<ElectiveCourse&>(s[di-1])->getmark();
         return true;
    }
    else
    {
        return false;
    }
}*/
bool Student::setCourseScore(int di)
{
    if(di<=courseNumber)
    {
        if(typeid(ObligatoryCourse)==typeid(*courseList[di-1]))
        {
            cout<<"Please input your ObligatoryCourse's mark:";
            while(1)
            {

                try
                {
                    cin>>marks;
                    inscoretf(marks);
                    break;
                }
                catch(MyException ex)
                {
                    cout<<"输入异常："<<ex.errinfo()<<"\n";
                    cout<<"请重新输入成绩：";
                }
            }
            dynamic_cast<ObligatoryCourse*>(courseList[di-1])->setmark(marks);
            cout<<"courseScore:"<<marks<<"\n";
            return true;
        }
        else if(typeid(ElectiveCourse)==typeid(*courseList[di-1]))
        {
             cout<<"Please input your ElectiveCourse's grade(A-E):";
             while(1)
            {

                try
                {
                    cin>>grades;
                    inscoretf(grades);
                    break;
                }
                catch(MyException ex)
                {
                    cout<<"输入异常："<<ex.errinfo()<<"\n";
                    cout<<"请重新输入成绩：";
                }
            }
             dynamic_cast<ElectiveCourse*>(courseList[di-1])->setgrade(grades);
             cout<<"courseScore:"<<grades<<"\n";
             return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        throw MyException(RANGE_ERROR);
    }
}
bool Student::inscoretf(int m)
{
    if(m<0 || m>100)
    {
        throw MyException(SCORE_INVALID);
    }
}
bool Student::inscoretf(char c)
{
    if(c<'A' || c>'E')
    {
        throw MyException(SCORE_INVALID);
    }
}
bool Student::removeCourse(int i){
    if(i<courseNumber)
    {
        delete courseList[i];
        for(int j=i;j<courseNumber-1;j++)
        {
            courseList[j]=courseList[j+1];
        }
        courseNumber--;	//将选课门数-1
        return true;
    }
    else
    {
        throw MyException(RANGE_ERROR);
        return false;
    }
}
double Student::calcCredit()
{
    double obsum=0;
    double obcredit=0;
    int elmengshu=0;
    double elsum=0;
    double calccredit=0;
    if(courseNumber==0)
    {
        return 0;
    }
    for(int i=0;i<=courseNumber-1;i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
        {
            obsum=obsum+(double)(courseList[i]->getcreditHour())*(double)(courseList[i]->getScore());
            obcredit=obcredit+(courseList[i]->getcreditHour());
        }
        else if(typeid(ElectiveCourse)==typeid(*courseList[i]))
        {
            elsum=elsum+(courseList[i]->getScore());
            elmengshu++;
        }
    }
    /*cout<<"总共：obsum: "<<obsum<<"\n";
    cout<<"obcredit: "<<obcredit<<"\n";
    cout<<"elsum: "<<elsum<<"\n";
    cout<<"elmengshu: "<<elmengshu<<"\n";
    cout<<"calccredit: "<<calccredit<<"\n";
    cout << elsum/ elmengshu << "\n";
    cout << obsum / obcredit ;*/
    /*obsum=6*obsum;
    obcredit=10*obcredit;
    elsum=4*elsum;
    elmengshu=10*elmengshu;*/
    calccredit=calccredit+0.6*(double)(obsum/obcredit);
    calccredit=calccredit+0.4*(double)(elsum/elmengshu);
    return calccredit;
}
void Student::sprint(Student &stu) const
{
    cout<<stu.getname()<<"  "<<stu.getbirthDateyear()<<"/"<<stu.getbirthDatemonth()<<"/"<<stu.getbirthDateday()<<"/"<<"\n";
}



