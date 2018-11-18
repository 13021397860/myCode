#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include<string>
using std::string;
class MyException
{
public:
    MyException();
    MyException(int t)
    {
        i=t;
    }
    string mymessages()
    {
        if(i==1)
            mess="wrong date,please try again";
        else if(i==2)
            mess="wrong number of course";
        else  if(i==3)
            mess="wrong score";
        else
            mess="other error,please try latter";
            return mess;
    }
    virtual ~MyException();

protected:

private:
    int i;
    string mess;
};

#endif // MYEXCEPTION_H
