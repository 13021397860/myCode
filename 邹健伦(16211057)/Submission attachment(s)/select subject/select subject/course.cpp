#include "course.h"
#include<iostream>
#include<string>
using namespace std;

course::course()
{

}
//course::course(const course &co)
//{
//    name=co.name;
//    creditHour=co.creditHour;
//}
course::course(const string &n,const int &c)
{
    setname(n);//ctor
    setcred(c);
}

void course::setname(const string &n)
{
    name=n;
}

void course::setcred(const int &c)
{
    creditHour=c;
}

course::~course()
{
    //dtor
}

ostream& operator<<(ostream& out,const course &x)
{
    out<<"�γ�����"<<x.getname()<<"      "<<"ѧ�֣�"<<x.getcred()<<"      "<<"�ɼ���"<<x.getscore()<<endl;
    return out;
}

