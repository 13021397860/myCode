#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <iostream>
#include<vector>
#include"course.h"
#include"date.h"
#include"stu.h"
#include<fstream>
#define Max 1000
#include<string>
class myexception
{
	public:
		myexception();
		myexception(string _m)
		{
			message=_m;
		}
		const string getmessage()const
		{
			return message;
		}
		virtual ~myexception();
	protected:
		string message;
};

#endif
