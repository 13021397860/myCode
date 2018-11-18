#include "ElectiveCourse.h"
#include <string>
using namespace std;
ElectiveCourse::ElectiveCourse()
{
    Setcourse("null",0);
    grade='e';
    //ctor
}

ElectiveCourse::ElectiveCourse(std::string N,int C ,char G):Course(N, C)
{
        grade=G;
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
void ElectiveCourse::SetGrade(char k)
{
    //try
   // {
        if(k>69||k<65)
        {
            throw MyException();
        }
   // }
   // catch(MyException x)
    //{
    //    cout<<"输入成绩异常："<<x.Scorerror()<<endl;
    //    k='D';
    //    cout<<"已将成绩设置为及格(D)"<<endl;
    //}
    grade=k;

}

int ElectiveCourse::Getscore()const
{
    int score;
    if(grade=='A')
    {
        score=95;
        return score;
    }
    else if(grade=='B')
    {
        score=85;
        return score;
    }
    else if(grade=='C')
    {
        score=75;
        return score;
    }
    else if(grade=='D')
    {
        score=65;
        return score;
    }
    else
    {
        score=55;
        return score;
    }
}
