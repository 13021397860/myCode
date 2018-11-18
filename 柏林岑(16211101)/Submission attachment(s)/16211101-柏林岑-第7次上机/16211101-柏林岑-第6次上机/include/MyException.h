#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include<string>
using namespace std;
class MyException
{
	public:
		MyException();
		MyException(const int);
		string message()const;
		virtual ~MyException();

	protected:
		int exception;
		string _exception[3]={"Invaild birthday Input!","Access violation!","Invaild Grade Input!",};

	private:
};

#endif // MYEXCEPTION_H
