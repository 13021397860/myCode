#include "Student.h"
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <typeinfo>
int Student :: count = 0;

Student::Student() :birthDate(birthDate )
{

   SetName("unnamed");
   courseNumber = 0;
   count++;
}

Student::Student(const char *newname, const int y, const int m , const int d) :birthDate(m,d,y)
{

    SetName(newname);
    courseNumber = 0;
    count++;
}

Student::Student(const Student&a) :birthDate(a.birthDate)
{

    SetName(a.name);
    courseNumber = 0;
    count++;
}

Student &Student::addCourse( Course *course, const int CourseType)
{
    for(int i=1; i <= courseNumber; i++)
    {
        if(courseList[i]->GetCoursename() == course->GetCoursename())
        {
            cout << "You have selected this course\n";
            return *this;
        }
    }
    if(CourseType == 1)
    courseList[++courseNumber] = new Obligatory(course->GetCoursename(), course->GetCreditHour());
    else if(CourseType == 2)
    courseList[++courseNumber] = new ElectiveCourse(course->GetCoursename(), course->GetCreditHour());
    return *this;
}


void Student::SetName(const char *newname)
{
    name = new char[strlen(newname)+1];
    strcpy(name,newname);
}


void Student::setStuScore(const int coursetype, const int score, const int ncourse)
{
      if(coursetype == 1) courseList[ncourse]->setScore(score,'A');
      else if(coursetype == 2) courseList[ncourse]->setScore(0,score);
}

 int Student::GetbirthDate() const
{
    return (birthDate.getYear()*10000 + birthDate.getMonth()* 100+ birthDate.getDay());
}

int Student::GetCount()
{
    return count;
}

const int Student::GetCoursenumber()
{
    return courseNumber;
}


float Student::calcCredit() const
{
    Obligatory a;
    ElectiveCourse b;
    int Onum=0, Enum = 0; float sum =0.0, Osum= 0.0, Esum = 0.0;
    for(int i = 1; i <= courseNumber; i++)
    {
        if (typeid(*courseList[i]) == typeid(a))
        {
            Onum++;
            Osum += courseList[i]->getScore();
        }else if(typeid(*courseList[i]) == typeid(b))
        {
            Enum++;
            Esum += courseList[i]->getScore();
        }
    }
    if(Onum > 0) Osum /= Onum;
    if(Enum > 0) Esum /= Enum;
    sum = Osum*0.6 + Esum*0.4;
    return sum;
}
bool Student::removeCourse(const int i)
{
    if(courseNumber == 0) return false;
    if(i <= 0 || i > courseNumber) return false;
    delete courseList[i];
    if(i < courseNumber )
    {
        for(int j = i; j < courseNumber; j++)
         courseList[j] = courseList[j+1];
    }
    courseNumber--;
    return true;
}

Student::~Student()
{
    delete[] name;

    for(int i =1; i <= courseNumber; i++) {delete courseList[i];}
    count--;
}

ostream &operator<<(ostream &output, const  Student& s)
{
  output<< "姓名："<< s.name<< " 出生日期："<< s.birthDate<< " 选课信息如下：\n";
  for(int i =1; i <= s.courseNumber; i++)
  {
      output << (*(s.courseList[i]));
  }
  output << "jidian: "<< s.calcCredit()<<endl;
  return output;
}
