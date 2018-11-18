#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
using namespace std;
class mystring
{
    public:
        mystring(const char *s="");
        mystring(const mystring &s);
        int getLength() const {return length;};
        const char* getStr() const {return str;};
        mystring& setstring(const char *s);
        void printStr() {cout<<getStr()<<endl;}
        virtual ~mystring();
    protected:
    private:
        int length;
        char* str;
};

#endif // MYSTRING_H
