#include "MyException.h"
#include "Date.h"
MyException::MyException()
{

}

void MyException::testdate(Date riqi)
{
    if(riqi.legis()==0)
    {
        throw riqi;
    }

}
void MyException::testunder(int number)
{
    if(number<=0||number>5)
    {
        throw number;
    }
}

void MyException::testsc(int score)
{
    if(score<0||score>100)
        throw score;
}

void MyException::testgrade(char grade)
{
    if(grade<'A'||grade>'E')
        throw grade;

}
MyException::~MyException()
{
    //dtor
}
