#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <stdexcept>

using namespace std;

class MyException : public runtime_error
{
	public:
		MyException():runtime_error("ÄúµÄÊäÈëÓĞÎó£¡")
		{
		}
};
#endif
