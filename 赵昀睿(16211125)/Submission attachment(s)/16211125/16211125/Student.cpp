#include "Student.h"
#include <iostream>
#include <cstring>
#include <typeinfo>
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"

#define pre 0.6

using namespace std;

int Student::stu_count = 0;

Student::Student():birthDate( 1, 1, 1997 )
{
    name = new( char[ 6 ] );
    strcpy( name, "error" );
    //
    courseNumber = 0;
    //stu_count ++;
}

Student::Student( const char *na, const Date &birth ):birthDate( birth )
{
    name = new( char[ strlen( na ) + 1 ] );
    strcpy( name, na );
    stu_count ++;
    //
    courseNumber = 0;
}

Student::Student( const Student &stu ):birthDate( stu.getBirth() )
{
    name = new( char[ sizeof( stu.getName() ) ] );
    strcpy( name, stu.getName() );
    stu_count ++;
    //
    courseNumber = 0;
}

Student::~Student()
{
    delete []name;
    stu_count --;
    //
    /*for( int i = 0; i < courseNumber; i ++ )
    {
        delete courseList[ i ];
    }*/
}

char *Student::getName()const
{
    return name;
}

Date Student::getBirth()const
{
    return birthDate;
}

int Student::getCount()
{
    return stu_count;
}
//
Student &Student::addCourse( Course *course )
{
    if( courseNumber < MAX_SIZE )
    {
        courseList[ courseNumber ] = course;
        courseNumber ++;
    }
    else
    {
        throw OutArray();
    }
    return *this;
}

/*Student &Student::addCourse( const string &courseName, int creditHour )
{
    if( courseNumber < MAX_SIZE )
    {
        Course *newCourse = new Course(courseName,creditHour);
        courseList[ courseNumber ] = newCourse;
        courseNumber ++;
    }
    return *this;
}*/

int Student::getCourseNumber()const
{
    return courseNumber;
}

Course *Student::getCourse( int i )const
{
    return courseList[ i - 1 ];
}

ostream& operator<<( ostream &os, Student &s )
{
    os << "姓名：" << s.getName() << "   出生日期：" << s.getBirth() << "，选课信息如下：" << endl;
    int Cn = s.getCourseNumber();
    for( int i = 1; i <= Cn; i++ )
    {
        os << *s.getCourse( i ) <<  endl;
        os << "成绩：" << s.getCourse( i ) -> getScore() << endl;
    }
    return os;
}

void Student::removeCourse( int i )
{
    if( i <= 0 || i > courseNumber || courseNumber <= 0 )
    {
        throw OutArray();
    }
    else
    {
        int j = i - 1;
        //delete courseList[j];
        courseNumber --;
        for(; j < courseNumber ; j++ )
        {
            courseList[ j ] = courseList[ j + 1 ];
        }
    }
}

double Student::calcCredit()
{
    double credit=0;
    double sum1 = 0,sum2 = 0;
    int cred1 = 0,cred2 = 0;
    for( int i = 0; i < courseNumber; i++ )
    {
        if( typeid( *courseList[i] ) == typeid(ObligatoryCourse) )
        {
            sum1 += courseList[i] -> getScore();
            cred1 += courseList[i] -> getCreditHour();
        }
        else
        {
            sum2 += courseList[i] -> getScore();
            cred2 ++;
        }
    }

    if( cred1 )
    {
        credit += pre * ( sum1 / cred1 );
    }
    if( cred2 )
    {
        credit += ( 1 - pre ) * ( sum2 / cred2 );
    }

    return credit;
}
