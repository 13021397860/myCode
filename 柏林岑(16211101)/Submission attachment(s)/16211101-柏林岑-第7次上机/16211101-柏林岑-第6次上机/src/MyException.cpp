#include "MyException.h"
#include<string>
using namespace std;
MyException::MyException()
{
	exception=0;
}
MyException::MyException(int exc){
     exception=exc;
}
string MyException::message()const{
      return _exception[exception];
}
MyException::~MyException()
{
	//dtor
}
