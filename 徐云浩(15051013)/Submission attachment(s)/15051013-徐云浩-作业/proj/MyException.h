#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <string>
using namespace std;
class MyException
{
    public:
        MyException();
        MyException(int t)
        {
            token = t;
        }
        virtual ~MyException();

        const string what()
        {
            if(token == 0)
            {
                message = "Input a wrong date!!! Try again!!";
            }
            else if(token == 1)
            {
                message = "Input a number, try again : ";
            }
            else if(token == 2)
            {
                message = "Invalid choice, try again : ";
            }
            return message;
        }

    protected:

    private:
        int token;
        string message;
};

#endif // MYEXCEPTION_H
