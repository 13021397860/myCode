#include "ObligatoryCourse.h"
#include<bits/stdc++.h>
#include "MyException.h"
using namespace std;

ObligatoryCourse::ObligatoryCourse()
{
	mark = 0;
}

ObligatoryCourse::ObligatoryCourse(string name,int creditHour):Course(name,creditHour)
{
    mark=mark;
}

/*ObligatoryCourse::ObligatoryCourse(ObligatoryCourse &o)
{
    mark=o.mark;
}

ObligatoryCourse::ObligatoryCourse(Course &o)
{
    mark=0;
}*/

void ObligatoryCourse::setmark(int _mark)
{
    while(true)
    {
        try
        {
            if(_mark<0||_mark>100) throw MyException();
            break;
        }
        catch(MyException GE)
        {
            cout<<GE.GradeError()<<endl;
            cin>>_mark;
        }
    }
    mark=_mark;
}

int ObligatoryCourse::getScore()
{
    return mark;
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}

ostream& operator<<(ostream& output,const ObligatoryCourse& c)
{
	output << "�γ�����"<<c.name<< " " << "ѧ�֣�" << c.creditHour << " " << "�ɼ���" << c.mark;
	return output;
}
