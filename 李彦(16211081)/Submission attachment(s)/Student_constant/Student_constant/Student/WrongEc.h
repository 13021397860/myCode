#ifndef WRONGEC_H
#define WRONGEC_H
#include<stdexcept>
using namespace std;
class WrongEc:public runtime_error
{
public:
    WrongEc():runtime_error("attempted to choose a invalid ec"){};
};

#endif // WRONGEC_H
