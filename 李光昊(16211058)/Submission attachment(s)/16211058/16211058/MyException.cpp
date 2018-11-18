#include "MyException.h"

#include <iostream>
#include <string>
using namespace std;

MyException::MyException()
{
}

MyException::MyException(string ae)
{
	error=ae;
}

MyException::~MyException()
{
}



/*
string MyException::geterror()
{
	return error;
}
*/

void MyException::printerror()
{
	cout<<"Òì³£Ô­Òò£º"<<error<<"\n";
}
