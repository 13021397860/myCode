#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H

class My_Exception
{
    public:
        My_Exception();
        My_Exception( int );
        const char* what() const;
        virtual ~My_Exception();

    protected:

    private:
        int record;
};

#endif // MY_EXCEPTION_H
