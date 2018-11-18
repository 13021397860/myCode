#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include<iostream>
#include"Date.h"
#include"Student.h"
using namespace std;
class MyException
{
	public:
		MyException();
		bool checkd(Date);
		bool checkc(int);
		bool checkg(int);
		bool checkg(char);
		bool checkc1(Student , int);
	private:
		
};
#endif
 
