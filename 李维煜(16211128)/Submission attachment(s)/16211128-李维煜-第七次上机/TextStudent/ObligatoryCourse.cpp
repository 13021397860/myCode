#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse()
{
    Setcourse("null",0);
    mark=0;
}

ObligatoryCourse::ObligatoryCourse(std::string N,int C,int M):Course(N,C)
{
    mark=M;
}

ObligatoryCourse::~ObligatoryCourse()
{

    //dtor
}

void ObligatoryCourse::SetMark(int M)
{
  //  try
   // {
        if(M>100||M<1)
        {
            throw MyException();
        }
    //}
   // catch(MyException x)
   // {
    //    cout<<"输入成绩异常: "<<x.Scorerror()<<endl;
    //    M=60;
    //    cout<<"已将成绩设置为及格(60)"<<endl;
//
   // }
    mark=M;
}

int ObligatoryCourse::Getscore()const
{
    return mark;
}
