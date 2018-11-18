#include "Myexception.h"

Myexception::Myexception()
{
    //ctor
}

Myexception::~Myexception()
{
    //dtor
}
void Myexception::datewrong(student* s)
{
    cout<<"the date you submit is wrong, please write a right date:"<<endl;
    int y,m,d;
    cin>>y>>m>>d;
    try
    {
        s->setdate(y,m,d);
    }
    catch(Myexception ex)
    {
        ex.datewrong(s);
    }
}
void Myexception::setgradewrong()
{
    cout<<"set right grade:"<<endl;
}
void Myexception::counumwrong()
{
    cout<<"please write right coursenumber:"<<endl;
}
