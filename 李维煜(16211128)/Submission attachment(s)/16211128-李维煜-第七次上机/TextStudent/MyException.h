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
        const char *Datemessage="�����˴�������";
        const char *Coursemessage="�γ�������������";
        const char *Scouremessage="�����˴������";
        const char *Secetmessage="�밴����ʾ������ȷ���";
        const char *Removemessage="�����뷶Χ�ڵ����";
};

#endif // MYEXCEPTION_H
