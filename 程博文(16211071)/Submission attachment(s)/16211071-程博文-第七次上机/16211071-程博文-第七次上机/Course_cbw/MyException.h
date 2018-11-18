#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

enum Exception{InvalidDate=0,OutOfRange,InvalidGrade};

class MyException
{
    public:
        MyException();
        virtual ~MyException();
        int InvalidDate()
        {
            message="Invalid date input";
            return 0;
        }
        int OutOfRange()
        {
            message="Visit out of range";
            return 0;
        }
        int InvalidGrade()
        {
            message="Invalid mark input";
            return 0;
        }
        const char* what() const
        {
            return message;
        }
    protected:

    private:
        const char* message;
};

#endif // MYEXCEPTION_H
