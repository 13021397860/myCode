#include "ObligatoryCourse.h"
#include "MyException.h"
ObligatoryCourse::ObligatoryCourse()
{
    mark=-1;
    //ctor
}
ObligatoryCourse::ObligatoryCourse(const ObligatoryCourse& other):Course(other)
{
    mark=other.mark;
    //ctor
}
ObligatoryCourse::ObligatoryCourse(const ObligatoryCourse& other,int _mark):Course(other)
{
    setMark(_mark);
    //ctor
}
ObligatoryCourse::ObligatoryCourse(const string& _name,int _creditHour,int _mark):Course(_name,_creditHour)
{
    mark=_mark;
    //ctor
}
void ObligatoryCourse::printCourse()const{
    cout<<"课程名:(必修) "<<getName()
        <<"  学分: "<<getCreditHour();
    if (getScore()!=-1)
    cout<<"  得分: "<<getScore();
}
bool ObligatoryCourse::setMark(int _mark) throw(MyException)
{
    if (_mark<0||_mark>100) throw SCORE_INVALID;
    mark=_mark;
    return 0;
}
int ObligatoryCourse::getScore()const
{
    return mark;
}
ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
