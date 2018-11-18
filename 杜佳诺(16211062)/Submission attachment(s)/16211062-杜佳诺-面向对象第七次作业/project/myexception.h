#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include<string>
using namespace std;


class MyException
{
    public:
        MyException( string );
        virtual ~MyException();

        static bool DateException( int, int, int);
        static bool CourseListException( int, int );
        static bool OcSetGradeException( int );
        static bool EcSetGradeException( char );

    protected:

    private:
        const string str;

};

#endif // MYEXCEPTION_H
