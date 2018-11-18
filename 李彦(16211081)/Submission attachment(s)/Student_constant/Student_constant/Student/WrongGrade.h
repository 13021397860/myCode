#ifndef WRONGOC_H
#define WRONGOC_H
#include<stdexcept>
using namespace std;
class WrongGrade:public runtime_error
{
public:
    WrongGrade():runtime_error("attempted to set an invalid grade"){};
};
#endif // WRONGOC_H
