#ifndef EXCEPTION_H
#define EXCEPTION_H

class Exception
{
    public:
        Exception();
        virtual ~Exception();

        virtual const char* what() const = 0;
};

class Illegal_Date_Exception : public Exception
{
    public:
        virtual const char* what() const
        {
            return "Illegal date!";
        }
};

class Course_List_Full_Exception : public Exception
{
    public:
        virtual const char* what() const
        {
            return "Your course list is full!";
        }
};

class Course_Existent_Exception : public Exception
{
    public:
        virtual const char* what() const
        {
            return "Your had chosen this course!";
        }
};

class Course_List_Empty_Exception : public Exception
{
    public:
        virtual const char* what() const
        {
            return "You have no course!";
        }
};

class Illegal_OC_Score_Exception : public Exception
{
    public:
        virtual const char* what() const
        {
            return "Illegal Score£¡!";
        }
};

class Illegal_EC_Score_Exception : public Exception
{
    public:
        virtual const char* what() const
        {
            return "Illegal Score!";
        }
};

class NonExistent_Option_Exception : public Exception
{
    public:
        virtual const char* what() const
        {
            return "Non-existent option!";
        }
};

#endif // EXCEPTION_H
