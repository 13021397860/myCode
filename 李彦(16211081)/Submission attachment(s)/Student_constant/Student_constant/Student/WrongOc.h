#ifndef WRONGOC_H
#define WRONGOC_H
#include<stdexcept>
using namespace std;
class WrongOc:public runtime_error
{
public:
    WrongOc():runtime_error("attempted to choose a invalid oc"){};
};
#endif // WRONGOC_H

