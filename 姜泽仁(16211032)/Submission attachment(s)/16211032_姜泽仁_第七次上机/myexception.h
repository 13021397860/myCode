#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

enum ExceptionType {DATE_INVALID, RANGE_ERROR, SCORE_INVALID};
// No description
class MyException
{
	// private section
	public:
		// class constructor
		MyException(ExceptionType);
		// class destructor
		~MyException();
		const char* what()const;
	protected:
		ExceptionType exceptionType;
};

#endif // MYEXCEPTION_H

