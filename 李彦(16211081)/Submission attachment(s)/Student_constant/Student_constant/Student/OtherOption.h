#ifndef OTHEROPTION_H
#define OTHEROPTION_H
#include<stdexcept>
using namespace std;

class OtherOption:public runtime_error
{
public:
    OtherOption():runtime_error("attempted to choose an inva num"){};
};

#endif // OTHEROPTION_H
