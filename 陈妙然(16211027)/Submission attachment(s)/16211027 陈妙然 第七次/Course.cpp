#include "Course.h"
#include <string>
#include <iostream>
using namespace std;
Course::Course()
{

}


Course::Course(string mingzi,int xuefen,int score)
{
    //ctor
    setname(mingzi);
    setcredit(xuefen);
}

void Course::setname(string mingzi)
{
    name=mingzi;
}
string Course::getname() const
{
    return name;
}
void Course::setcredit(int xuefen)
{
    creditHour=xuefen;
}

int Course::getscore()
{
    return 1;
}
int Course::getcredit()
{
    return creditHour;
}
 void Course::printcourseinfor()
{
        cout<<"the course is:"<<getname()<<endl;
    cout<<"the creditHour is:"<<getcredit()<<endl;
}
ostream &operator <<(ostream &output, Course &kecheng)
{

    output<<kecheng.getname()<<"  "<<kecheng.getcredit()<<endl;
    return output;
}
int Course::getmyscore()
{
    if(myscore>100)
    {
        return 0;
    }
    return myscore;

}
 void Course::printcourseinforfu()
 {
        cout<<"the course is:"<<getname()<<endl;
    cout<<"the creditHour is:"<<getcredit()<<endl;
    cout<<"the score is:"<<getmyscore()<<endl;
}

Course::~Course()
{
    //dtor
}
