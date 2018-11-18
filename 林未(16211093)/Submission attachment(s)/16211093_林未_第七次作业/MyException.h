#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <string>
using namespace std;

class MyException
{
	public:
   		MyException(const string);
    	const string what() const {return message;}
    	~MyException();
    	
	protected:
    	const string message;
};

#endif
