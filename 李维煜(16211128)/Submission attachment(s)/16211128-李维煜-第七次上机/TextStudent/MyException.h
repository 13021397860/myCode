#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include<iostream>
using namespace std;

class MyException
{
    public:
        MyException();
        virtual ~MyException();
        const char *Daterror()const;
        const char *Courserror()const;
        const char *Scorerror()const;
        const char *Seceterror()const;
        const char *Removerror()const;
        //char Daterror();
        //char Courserror();
        //char Scorerror();
    protected:

    private:
        const char *Datemessage="输入了错误日期";
        const char *Coursemessage="课程总数超出限制";
        const char *Scouremessage="输入了错误分数";
        const char *Secetmessage="请按照提示输入正确序号";
        const char *Removemessage="请输入范围内的序号";
};

#endif // MYEXCEPTION_H
