#include "Course.h"
#include<string>
#include<iostream>
#include<cstring>
using namespace std;

Course::Course()
{
    //ctor
}

Course::~Course()
{
    //dtor
}

ostream& operator <<(ostream& o,const Course& a)  //�������>>���ܼ�const����ΪҪ�޸�ֵ��
{
        o<<"�γ����� "<<a.getClassName()<<" ѧ��: "<<a.getCreditHour()<<" ������ "<<a.getScore();
        return o;//(Ϊ�˿������������
}
