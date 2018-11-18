#include<iostream>
#include<cstring>
#include "TextStudentClass.h"
#include "Date.h"
using namespace std;

ostream &operator<<(ostream &output,const TextStudentClass &student)
{
    output<<"姓名 :"<<student.name<<" "<<"出生日期 :"<<student.birthDate<<", 选课信息如下 :"<<endl;
    for(int i=1;i<=student.courseNumber;i++)
    {
        if(!student.courseList[i])break;

        cout<<*student.courseList[i];
    }

    return output;
}

int TextStudentClass::getcourseList(int i,Course *&temp)
{
    if(courseList[i])
    {
        temp=courseList[i];
    }
}

//string TextStudentClass::Getcou(int i)
//{
 //   return courseList[i];
//}


int TextStudentClass::count=0;

TextStudentClass::TextStudentClass(char* N,const Date &birth):birthDate(birth)
{
    int len=strlen(N);
    name = new char[len+1];
    strcpy(name,N);
    TextStudentClass::count++;

    //ctor
}

TextStudentClass::~TextStudentClass()//Îö¹¹
{
   TextStudentClass::count--;
    delete[] name;
    for(int i=1;i<=courseNumber;i++)
    {
        delete courseList[i];
    }
    //dtor
}

TextStudentClass::TextStudentClass():birthDate(1,1,1)//È±Ê¡¹¹Ôì
{
    name=new char[6];
    strcpy(name,"error");
}

TextStudentClass::TextStudentClass(const TextStudentClass &another):birthDate(another.Getbirth())
{

    name=new char[strlen(another.Getname())+1];
    strcpy(name,another.Getname());
    TextStudentClass::count++;

}

void TextStudentClass::Setstudentname(char* N)
{
    int len=strlen(N);
    name = new char[len+1];
    strcpy(name,N);
}

char *TextStudentClass::Getname() const
{
    return name;
}

void TextStudentClass::Printinformation()
{
    cout<<"The student's name is :"<<name<<endl;
    cout<<birthDate<<endl;
    for(int i=1;i<=courseNumber;i++)
    {
        if(!courseList[i]) break;
        courseList[i]->Getcourse();
        courseList[i]->print();

    }

}


Date TextStudentClass::Getbirth()const
{
    return birthDate;
}

void TextStudentClass::Getstudentnumber()
{
    cout<<"count="<<count<<endl;
}

/*TextStudentClass& TextStudentClass::addCourse(Course *course)
{
    if(courseNumber<MAX_SIZE)
    {
        courseList[++courseNumber] = new Course;
        courseList[courseNumber] = course;
    }
    else
        cout<<"too much course!"<<endl;

        return (*this);
}*/

TextStudentClass& TextStudentClass::addCourse(const std::string &N,int C,int M)//添加课名和学分
{
        if(courseNumber>19)
        {
            throw MyException();
        }
       courseList[++courseNumber] = new ObligatoryCourse(N,C,M);
         return (*this);
}

TextStudentClass& TextStudentClass::addCourse(const std::string &N,int C,char G)//添加课名和学分
{

         if(courseNumber>19)
        {
            throw MyException();
        }
       courseList[++courseNumber] = new ElectiveCourse(N,C,G);
         return (*this);
}

bool TextStudentClass::removeCourse(int i)
{
    if(courseNumber>=0&&courseNumber>=i)
    {
        delete courseList[i];
        for(int k=i+1;k<=courseNumber;k++,i++)
        {
            courseList[i]=courseList[k];
        }
        courseNumber--;
    }
}

int TextStudentClass::getsumcreditO()
{
    int sum=0;
    for(int i=1;i<=courseNumber;i++)
    {
        if(typeid(*courseList[i])==typeid(ObligatoryCourse))
        {
             sum+=courseList[i]->GetcreditHour();
        }
    }
    return sum;
}

int TextStudentClass::getsumcreditE()
{
    int sum=0;
    for(int i=1;i<=courseNumber;i++)
    {
        if(typeid(*courseList[i])==typeid(ElectiveCourse))
        {
             sum+=courseList[i]->GetcreditHour();
        }
    }
    return sum;
}

int TextStudentClass::getsumpeoE()
{
    int sum=0;
    for(int i=1;i<=courseNumber;i++)
    {
        if(typeid(*courseList[i])==typeid(ElectiveCourse))
        {
            sum++;
        }
    }
    return sum;
}

void TextStudentClass::calcCredit()
{
    double sum=0.00;
    for(int i=1;i<=courseNumber;i++)
    {
        if(typeid(*courseList[i])==typeid(ObligatoryCourse))
        {
            sum+=0.6*courseList[i]->Getscore()*courseList[i]->GetcreditHour()/getsumcreditO();
        }
        else if(typeid(*courseList[i])==typeid(ElectiveCourse))
        {
            sum+=0.4*courseList[i]->Getscore()/getsumpeoE();
        }
    }
    cout<<"该学生的绩点成绩为:"<<sum<<endl;
}
