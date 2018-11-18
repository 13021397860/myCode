#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

enum Type{Date_Invalid, Range_Error, Score_Invalid}; 

class MyException
{
	public:
		MyException(Type t);
		virtual ~MyException();
		const char* what()const;
	private:
		Type Etype;
};

#endif
