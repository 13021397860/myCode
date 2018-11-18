#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H


class MyException
{
    public:
        MyException();
        const char *DateError();
        const char *CourseError();
        const char *ScoreError();
        virtual ~MyException();

    protected:
    private:
};

#endif // MYEXCEPTION_H
