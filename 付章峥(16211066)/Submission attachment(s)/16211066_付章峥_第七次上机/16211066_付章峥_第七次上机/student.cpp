#include "student.h"
#include "date.h"
#include "course.h"
#include "obligatorycourse.h"
#include "electivecourse.h"
#include<cstring>
#include<typeinfo>
#include<iomanip>
#include<cstdlib>
#include "myexception.h"

#define MAX_SIZE 10

int Student::count=0;//Initial value of count

//Student constructor
Student::Student(const char*const n,const int m,const int d,const int y)//ctor
{
    Student::setName(n);//set name
    Student::setBirthDate(m,d,y);//set birthDate
    courseNumber=0;//set courseNumber
    count++;//add an new element
    calcCredit=0;
}//end construct Student

//copy constructor
Student::Student(const Student& other)//copy ctor
{
    strcpy(other.name,name);//copy name

    birthDate = other.birthDate;//copy birthDate
}//end copy

//set value of name
void Student::setName(const char*const n)
{
    if(name)delete []name;//reset
    name =new char;//distribute space to name
    strcpy(name,n);//validate value of name
}//end function setName

//set value of birthDate
void Student::setBirthDate(const int m,const int d,const int y)
{
    birthDate.setDate(m,d,y);//validate of birthDate
}//end function setBirthDate

//get value of name
char* Student::getName()
{
    return name;
}//end function getName

Date& Student::getDate()
{
    return birthDate;
}

//return month value
int Student::getBirthMonth()
{
    return birthDate.getMonth();
}//end function getBirthMonth

//return day value
int Student::getBirthDay()
{
    return birthDate.getDay();
}//end function getBirthDay

//return year value
int Student::getBirthYear()
{
    return birthDate.getYear();
}//end function getBirthYear

//return count
int Student::getCount()
{
    return count;
}//end function setCount

//add a course
Student& Student::addCourse(Course *course)
{
    if(courseNumber==MAX_SIZE){}//check if there is space
    else{
        courseList[courseNumber] = course;
        courseNumber++;
    }
    return *this;
}//end function addCourse

//add a course in another way
/*Student& Student::addCourse(const string &courseName,const int creditHour)
{
    if(courseNumber==MAX_SIZE){}//check if there is space
    else{
        if(OoE==0)courseList[courseNumber] =new ObligatoryCourse(courseName,creditHour);
        else courseList[courseNumber] =new ElectiveCourse(courseName,creditHour);
        courseNumber++;
    }
    return *this;
}//end function addCourse
*/
int Student::getcourseNumber()
{
    return courseNumber;
}

string Student::getcourseName(int i)
{
    return courseList[i]->getName();
}

bool Student::removeCourse(int i)
{
    if(i<1||i>courseNumber)
        return 0;
    else
    {
        i--;
        for(int j=i;j<courseNumber-1;j++)
        {
            courseList[j]=courseList[j+1];
        }
        courseNumber--;
        return 1;
    }
}

void Student::setgrade(int i)
{
    if(typeid(ObligatoryCourse)==typeid(*courseList[i-1]))
    {
        cout<<"本课程：\n\n"<<"    "<<courseList[i-1]<<"\n\n"<<"为必修课程  成绩范围(0-100)\n"<<endl;
        cout<<"输入：";
        int s;
        cin>>s;
        if(cin.fail())
            {system("cls");cerr<<"\n非法输入\n"<<endl;system("pause");}
        e.excCrsO(s);
        if(!e.ob)
        //else if(s<=100&&s>=0)
            dynamic_cast<ObligatoryCourse&>(*courseList[i-1]).setMark(s);
        else e.ob=0;
            //{system("cls");cerr<<"\n非法输入\n"<<endl;system("pause");}
        cin.clear();
        cin.sync();
    }
    else
    {
        cout<<"本课程：\n\n"<<"    "<<courseList[i-1]<<"\n\n"<<"为选修课程  成绩范围(A-E)\n"<<endl;
        cout<<"输入：";
        char s;
        cin>>s;
        if(cin.fail())
            {system("cls");cerr<<"\n非法输入\n"<<endl;system("pause");}
        e.excCrsE(s);
        if(!e.el)
        //else if(s<='E'&&s>='A')
            dynamic_cast<ElectiveCourse&>(*courseList[i-1]).setGrade(s);
        else e.el=0;
            //{system("cls");cerr<<"\n非法输入\n"<<endl;system("pause");}
        cin.clear();
        cin.sync();
    }
}

void Student::newG()
{
    calcCredit=0;
    double Om=0,Em=0,GO=0,GE=0;
    for(int i=0;i<courseNumber;i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
        {
            GO+=0.6*(double)(courseList[i]->getScore())*(double)(courseList[i]->getCredit());
            Om+=courseList[i]->getCredit();
        }
        else
        {
            GE+=0.4*(double)(courseList[i]->getScore());
            Em++;
        }
    }
    if(Om!=0)calcCredit+=GO/Om;
    if(Em!=0)calcCredit+=GE/Em;
}

const Course& Student::operator[](int i)
{
    if(i<0||i>=courseNumber)
    {
        cerr<<"ERROR";
        exit(1);
    }
    else
        return *courseList[i];
}

ostream &operator<<(ostream &opt,const Student &s)
{
    opt <<"姓名："
    <<left<<setw(10)<<s.name<<"出生日期："<<s.birthDate<<endl<<endl
    <<"  已选课程量："<<s.courseNumber<<"\n"<<endl
    <<"  积点成绩："<<s.calcCredit<<"\n"<<endl;
    for(int i=0;i<s.courseNumber;i++)
    {
        opt <<"    "<<i+1<<")"<<s.courseList[i]<<endl<<endl;
    }
    return opt;
}

//set destructor
Student::~Student()//dtor
{
    for(int i=0;i<courseNumber;i++)
        delete courseList[i];
    delete[]name;//delete char*name
    count--;//delete an element
}//end destructor

