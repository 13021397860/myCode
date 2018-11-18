#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include<string>
using namespace std;
class MyException
{
    public:
        MyException();
        virtual ~MyException();
        const string what_date() const{
            return date_message;
        }
        const string what_overflow() const{
            return overflow_message;
        }
        const string what_grade() const{
            return grade_message;
        }

    protected:
        const string date_message;
        const string overflow_message;
        const string grade_message;

    private:
};

#endif // MYEXCEPTION_H
