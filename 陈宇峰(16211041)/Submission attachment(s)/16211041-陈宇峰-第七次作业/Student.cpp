#include <iostream>
#include <cstring>
#include "Student.h"
#include "Myexception.h"
using namespace std;

int Student::StudentCount=0;

Student::Student()
:birthdate(1,1,2000)
{
    StudentCount++;
    courseNumber=0;
    name=new char[7];
    char s[]="student";
    strcpy(name,s);
}

Student::Student(const Student& s)
:birthdate(s.birthdate)
{
    StudentCount++;
    courseNumber=0;
    name=s.name;
}

Student::Student(const char* a,const int m1,const int d1,const int y1)
:birthdate(m1,d1,y1)
{
    StudentCount++;
    courseNumber=0;
    int length=strlen(a);
    name=new char[length+1];
    strcpy(name,a);
}

Student::~Student()
{
    int i=courseNumber-1;
    while (i>0)
    {
        if (removeCourse(i)) i--;
    }
    StudentCount--;
    delete[] name;
}

char* Student::getStudentName()
{
    return name;
}

Date Student::getBirthday()
{
   return birthdate;
}

void Student::getStudentCount()
{
   cout<<"the count of student is "<<Student::StudentCount<<endl;
}

void Student::setName(char* sname)
{
    name=sname;
}

Student& Student::addCourse(Course *course)
{
    for (int i=0;i<courseNumber;i++)
    {
        if (courseList[i]==course)
        {
            cout<<"You have chosen this course before and can't choose it again!"<<endl;
            return *this;
        }
    }
    cout<<"Success!"<<endl;
    if (courseNumber<MAX_SIZE)
    {
        courseList[courseNumber]=course;
        courseNumber++;
    }
    return *this;
}

void Student::printcourselist()
{
    if (courseNumber==0) cout<<"You have choose no course yet!"<<endl;
    for (int i=0;i<courseNumber;i++)
    {
        //cout<<i+1<<"、"<<courseList[i]->getname()<<"   "<<courseList[i]->getcreditHour()<<"学分"<<endl;
        cout<<i+1<<"."<<*courseList[i]<<endl;
    }
    cout<<"\n\n";
}

bool Student::removeCourse(int i)
{
    if (i>=courseNumber)
    if (i<courseNumber)
    {
        courseNumber--;
        for (int k=i;k<courseNumber;k++)
        {
            courseList[k]=courseList[k+1];
        }
        return true;
    }
    else
    {
        throw MyException(RANGE_ERROR);
        return false;
    }
}

ostream& operator<<(ostream& output, const Student& student)
{
    output<<"name : ";
    int i=0;
    while (student.name[i]!='\0')
    {
        output<<student.name[i];
        i++;
    }
    output<<"    birthday :"<<student.birthdate<<"\nthere are the courses you have chosen : "<<endl;
    if (student.courseNumber==0) output<<"You have choose no course yet!"<<endl;
    for (int i=0;i<student.courseNumber;i++)
    {
        //cout<<i+1<<"、"<<courseList[i]->getname()<<"   "<<courseList[i]->getcreditHour()<<"学分"<<endl;
        output<<i+1<<"."<<*student.courseList[i]<<endl;
    }
    output<<"GPA : "<<student.calcCredit()<<endl;
}

bool Student::setCourseScore()
{
    int mark=0;
    char grade='\0';
    if (courseNumber==0)
        cout<<"You have choose no course yet!"<<endl;
    for (int i=0;i<courseNumber;i++)
    {
        if (typeid(ObligatoryCourse)==typeid(*courseList[i]))
        {
            cout<<"the mark(0~100) of obligatory course "<<courseList[i]->getname()<<"is:";
            //cout<<"必修课程”"<<courseList[i]->getname()<<"“的成绩（0~100）为：";
            while (1)
            {
                try{
                    cin>>mark;
                    dynamic_cast<ObligatoryCourse&>(*courseList[i]).setmark(mark);
                    break;
                }catch(MyException ex)
                {
                    cout<<"\nWRONG:"<<ex.what()<<endl;
                    cout<<"please set the mark again:";
                }
            }
        }
        else if (typeid(ElectiveCourse)==typeid(*courseList[i]))
        {
            cout<<"the mark(A~E) of elective course "<<courseList[i]->getname()<<"is:";
            //cout<<"选修课程”"<<courseList[i]->getname()<<"“的成绩（A~E）为：";
            while (1)
            {
                try{
                    cin>>grade;
                    dynamic_cast<ElectiveCourse&>(*courseList[i]).setgrade(grade);
                    break;
                }catch(MyException ex)
                {
                    cout<<"\nWRONG:"<<ex.what()<<endl;
                    cout<<"please set the mark again:";
                }
            }
        }
        else {return false;}
    }
    return true;
}

double Student::calcCredit() const
{
    int ob_credit=0,el_num=0;
    int ObligatoryCredit=0,ElectiveCredit=0;
    double credit=0;
    //定义要用的数据
    for (int i=0;i<courseNumber;i++)
    {
        if (typeid(ObligatoryCourse)==typeid(*courseList[i]))
        {
            ob_credit+=courseList[i]->getcreditHour();
        }
        else if (typeid(ElectiveCourse)==typeid(*courseList[i]))
        {
            el_num++;
        }
    }
    //计算必修课程的总学分和选修课程的数目
    for (int i=0;i<courseNumber;i++)
    {
        if (typeid(ObligatoryCourse)==typeid(*courseList[i]))
        {
            ObligatoryCredit+=courseList[i]->getcreditHour()*courseList[i]->getScore();
        }
        else if (typeid(ElectiveCourse)==typeid(*courseList[i]))
        {
            ElectiveCredit+=courseList[i]->getScore();
        }
    }
    if (el_num!=0)
        credit+=0.4*ElectiveCredit/el_num;
    if (ob_credit!=0)
        credit+=0.6*ObligatoryCredit/ob_credit;
    return credit;
}


