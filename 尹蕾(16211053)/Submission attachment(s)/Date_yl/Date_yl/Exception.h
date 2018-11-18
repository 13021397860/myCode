#ifndef EXCEPTION_H
#define EXCEPTION_H

enum ExceptionType {DATE_INVALID, RANGE_ERROR, SCORE_INVALID};

class Exception
{
    public:
        Exception(ExceptionType et);
        virtual ~Exception();

        char* what() const;

    protected:
    private:
        ExceptionType exceptionType;
};

#endif // EXCEPTION_H
