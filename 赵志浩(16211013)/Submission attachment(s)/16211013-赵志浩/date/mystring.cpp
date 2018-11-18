#include "mystring.h"
#include <cstring>
mystring::mystring(const char* s)
{
    str=NULL;
    setstring(s);
}

mystring::mystring(const mystring &s)
{
    str=NULL;
    setstring(s.str);
}
mystring& mystring::setstring(const char* s)
{
    if(str) delete[] str;
    length=strlen(s);
    str=new char[length+1];
    strcpy(str,s);
    return *this;
}
mystring::~mystring()
{
    delete[] str;
}
