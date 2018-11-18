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

class Course_List_Empty_Exception : public Exception
{
    public:
        virtual const char* what() const
        {
            return "You have no course!";
        }
};

class Course_NonExistent_Exception : public Exception
{
    public:
        virtual const char* what() const
        {
            return "You have no such a course!";
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

class Illegal_OC_Score_Exception : public Exception
{
    public:
        virtual const char* what() const
        {
            return "Illegal Score, it should be in the range(0~100)!";
        }
};

class Illegal_EC_Score_Exception : public Exception
{
    public:
        virtual const char* what() const
        {
            return "Illegal Score, it should be in the range(E~A)!";
        }
};

class Option_NonExistent_Exception : public Exception
{
    public:
        virtual const char* what() const
        {
            return "No such a option!";
        }
};

class Student_NonExistent_Exception : public Exception
{
    public:
        virtual const char* what() const
        {
            return "No such a student!";
        }
};

#endif // EXCEPTION_H
