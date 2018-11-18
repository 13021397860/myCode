#ifndef INPUTEXCEPTION_H
#define INPUTEXCEPTION_H
#include <cstdio>

class InputException
{
    public:
        InputException():
        message("input error number!\n"){};
        void wtf(){
            printf("%s\n",message);
        }
    private:
        const char* message;
};

#endif // INPUTEXCEPTION_H
