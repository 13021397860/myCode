#include "MyException.h"
void MyException::catchDate(bool x)
{
	try{
		if (!x)
			throw exception();
	}
	catch (exception&exception1)
	{
		
		cout<<"exception caught:"<<exception1.what()<<endl;
		cout<<"请重新输入"<<endl;
	}
}

bool MyException::catchElGrade(char mark)
{
	try{
		if (mark!='A'&&mark!='B'||mark!='C'||mark!='D'||mark!='E'||mark!='F')
			throw exception();
	}
	catch (exception&exception1)
	{
		
		cout<<"exception caught:"<<exception1.what()<<endl;
		cout<<"请重新输入"<<endl;
		return false;
	}
	return true;
}
bool MyException::catchObGrade(int mark)
{
	try{
		if (mark<0||mark>100)
			throw exception();
	}
catch (exception&exception1)
	{
		
		cout<<"exception caught:"<<exception1.what()<<endl;
		cout<<"请重新输入"<<endl;
		return false;
	}
	return true;
}
