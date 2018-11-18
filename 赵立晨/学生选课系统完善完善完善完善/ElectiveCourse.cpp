#include "ElectiveCourse.h"
#include "MyException.h"
ElectiveCourse::ElectiveCourse():grade('F')
{
    //ctor
}
ElectiveCourse::ElectiveCourse(const ElectiveCourse& other):Course(other)
{
    grade=other.grade;
    //ctor
}
ElectiveCourse::ElectiveCourse(const ElectiveCourse& other,char _grade):Course(other)
{
    setGrade(_grade);
    //ctor
}
ElectiveCourse::ElectiveCourse(const string& _name,int _creditHour):Course(_name,_creditHour),grade('F')
{
    //ctor
}
ElectiveCourse::ElectiveCourse(const string& _name,int _creditHour,char _grade):Course(_name,_creditHour)
{
    setGrade(_grade);
    //ctor
}
void ElectiveCourse::printCourse()const{
    cout<<"课程名:(选修) "<<getName()
        <<"  学分: "<<getCreditHour();
    if (getScore()!=-1)
    cout<<"  得分: "<<getScore();
}
bool ElectiveCourse::setGrade(char _grade) throw(MyException)
{
    if (_grade<'A'||_grade>'E') throw SCORE_INVALID;
    grade=_grade;
    return 0;
}
int ElectiveCourse::getScore()const
{
    switch (grade){
        case 'A':return 95;
        case 'B':return 85;
        case 'C':return 75;
        case 'D':return 65;
        case 'E':return 55;
        default:return -1;
    }
    return 0;
}
ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
