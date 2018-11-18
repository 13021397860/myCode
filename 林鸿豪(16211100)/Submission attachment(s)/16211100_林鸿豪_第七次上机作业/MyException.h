#include <iostream>
using namespace std;
#ifndef MYEXECPTION_H
class MyException{
public:
   MyException(char*a)
      :message(a){ };
    const char* what() const {return message;};
private:
    const char *message;
};

#define MYEXCEPTION_H
#endif // MYEXECPTION_H

