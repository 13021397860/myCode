#include "MyException.h"

MyException::MyException()
{
    //ctor
}

MyException::~MyException()
{
    //dtor
}
const char *MyException::Daterror()const
{
    return Datemessage;
}
const char *MyException::Scorerror()const
{
    return Scouremessage;
}
const char *MyException::Courserror()const
{
    return Coursemessage;
}
const char *MyException::Seceterror()const
{
    return Secetmessage;
}
const char *MyException::Removerror()const
{
    return Removemessage;
}
/*char MyException::Daterror()
{
    cout<<"wrong date!"<<endl;
}
char MyException::Scorerror()
{
    cout<<"wrongt score!"<<endl;
}
char MyException::Courserror()
{
    cout<<"wrong course!"<<endl;
}*/
