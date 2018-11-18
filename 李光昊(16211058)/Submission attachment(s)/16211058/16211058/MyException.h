#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include<iostream>
#include<string>
using namespace std;
class MyException
{
	public:
		MyException();
		MyException(string);
		virtual ~MyException();
		//string geterror();
		void printerror();

	protected:
		string error;
};

#endif
