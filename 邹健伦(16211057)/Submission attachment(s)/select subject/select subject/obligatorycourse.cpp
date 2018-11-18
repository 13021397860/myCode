#include "obligatorycourse.h"
#include"Myexception.h"

obligatorycourse::obligatorycourse(const string &n,const int &c)
{
    setname(n);
    setcred(c);
    mark=0;
}

obligatorycourse::obligatorycourse(const obligatorycourse &o)
{
    name=o.name;
    creditHour=o.creditHour;
    mark=o.mark;
}
void obligatorycourse::setmark(const int &m)
{
    mark=m;
    if(mark<0||mark>100)
        throw Myexception();
}
obligatorycourse::~obligatorycourse()
{
    //dtor
}

ostream& operator<<(ostream& out,const obligatorycourse &x)
{
    out<<"�γ�����"<<x.getname()<<"      "<<"ѧ�֣�"<<x.getcred()<<"      "<<"�ɼ���"<<x.getscore()<<endl;
    return out;
}
