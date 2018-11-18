#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

class MyException
{
	public:
		MyException();
		~MyException();

		const char* BirthdayError() const
		{
			return BEmessage;
		}
		const char* CourseError() const
		{
			return CEmessage;
		}
		const char* GradeError() const
		{
			return GEmessage;
		}
	protected:

	private:
		const char *BEmessage;
		const char *CEmessage;
		const char *GEmessage;
};

#endif
