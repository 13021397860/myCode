#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
enum ExceptionType {DATE_INVALID,RANGE_ERROR,SCORE_INVALID};
class MyException
{
	public:
		MyException(ExceptionType et);
		virtual const char* what() const;
		virtual ~MyException();
	protected:
	private:
		ExceptionType exceptionType;
};

#endif
