#include "Student.h"
#include "Date.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <typeinfo>
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
using namespace std;

int Student::count=0;

Student::Student()
{
    courseNumber=0;
    count++;
    name=new char[10];
    name="³ðÉÆÕÙ";
    birthdate.setDate(1997,11,04);//ctor
}
Student::Student(const Student &a)
{

    count++;
    name=a.name;
    birthdate=a.birthdate;
    courseNumber=a.courseNumber;
}
Date Student::getdate() const
{
    return birthdate;
}
char* Student::getname() const
{

    return name;
}

int Student::getcount()
{
    return count;
}
void Student::setName( char* n )
{
    if ( name )
    delete []name;
    if ( n==NULL )
        {
             name= new char[1];
             strcpy( name, "empty\n");
        }
   else {
            name= new char [strlen(n)+1];
            strcpy( name, n );
        }

}
void Student::setDate( Date a )
{
     birthdate=a;
}
/*void Student::print()
{
    cout<<"the student name is: "<<name<<endl;
    cout<<"the student birthday is: ";
    cout<<birthdate<<endl;
}*/

/*void Student::printcourse()
{
    for ( int i=0; i<courseNumber; i++)
        cout<<*courseList[i]<<endl;
}
*/
ostream &operator << ( ostream &output, const Student& a )
{
   output<<"Name: "<<a.getname()<<"  Birthday:"<<a.getdate()<<" GPA:"<<a.calcCredit()<<"\nCourse List:"<<endl;
    for ( int i=0; i<a.courseNumber; i++)
        output<<*(a.courseList[i]);
        return output;
}
Student& Student::addCourse(Course* course)
{

    if (  courseNumber < MAX_SIZE && course!=NULL )

         {
             courseList[courseNumber] = course;
             courseNumber++;
         }

     else {
         cout<<" error!"<<endl;
     }
    return (*this);
}

int Student::calElectivenum() const
{
    int num=0;
    for ( int i=0; i<courseNumber; i++)
    {
        if (  typeid(ElectiveCourse)==typeid((*courseList[i])))
            num++;
    }
    return num;
}

int Student::calObligatoryCredit()const
{
    int credit=0;
    for ( int i=0; i<(*this).courseNumber; i++)
    {
        if  ( typeid(ObligatoryCourse)==typeid(*courseList[i]))
            credit+=(*this).courseList[i]->getHour();
    }
    return credit;
}

double Student::calcElectiveCourse() const
{
    double gpa=0;
    int num=(*this).calElectivenum();
    if ( num==0 )
        return 0;
    double grade=0;
    for ( int i=0; i<(*this).courseNumber; i++)
    {
        if ( typeid(ElectiveCourse)==typeid(*courseList[i]))
            grade+=(*this).courseList[i]->getScore();
    }
    gpa=(grade/num)*0.4;
    return gpa;
}

double Student::calcObligatoryCourse()const
{
    double gpa=0;
    int num=(*this).calObligatoryCredit();
    double grade=0;
    if ( num==0 )
        return 0;
    for  ( int i=0; i<(*this).courseNumber; i++)
    {
        if  ( typeid(ObligatoryCourse)==typeid(*courseList[i]))
        {
            grade+=(*this).courseList[i]->getScore()*(*this).courseList[i]->getHour();
        }
    }
    gpa=(grade/num)*0.6;
    return gpa;
}

double Student::calcCredit() const
{

   return (calcElectiveCourse()+calcObligatoryCourse());

}

bool Student::removeCourse(int i)
{
    i--;
    if ( i<0 || i>=courseNumber)
        return 0;
    delete courseList[i];

    for ( int j=i; j<courseNumber-1; j++)
    {
        courseList[j]=courseList[j+1];
    }
    courseNumber--;
    return 1;

}

Student::~Student()
{
    count--;
    delete []name;//dtor
    for ( int i=0; i<courseNumber; i++)
        delete courseList[i];

}
