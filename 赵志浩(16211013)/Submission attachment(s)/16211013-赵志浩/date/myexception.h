#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <exception>
using namespace std;
class MyException
{
    public:
        MyException(int id=1):ErrorId(id){};
        const char* what() const
        {
            if(ErrorId==1)
                return "Input error";
            else if(ErrorId==2)
                return "Invalid Date";
            else if(ErrorId==3)
                return "Out of Range";
            else if(ErrorId==4)
                return "Invalid Score";
        }
        virtual ~MyException();
    protected:
    private:
        int ErrorId;
};

#endif // MYEXCEPTION_H
