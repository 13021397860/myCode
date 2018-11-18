#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include<iostream>
using namespace std;

class MyException {
public:
	MyException();
	MyException(int);
	void initMsg();
	string showMsg();
private:
	int exceptionNum;
	string message[3];
};

#endif // MYEXCEPTION_H
