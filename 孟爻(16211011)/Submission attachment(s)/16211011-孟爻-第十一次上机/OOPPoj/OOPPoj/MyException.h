#ifndef __MyException__
#define  __MyException__

#include<iostream>

using namespace std;

class MyException {
public:
	MyException();
	MyException(int);
	~MyException();
	friend ostream& operator<<(ostream&, MyException&);
	int eid;
	void myThrow();
	static const int EXPECTION_UNKNOWN = 0;
	static const int EXPECTION_DATE = 1;
	static const int EXPECTION_NAME = 2;
	static const int EXPECTION_GRADE = 3;
	static const int EXPECTION_OVERFLOW = 4;

};

#endif // !__MyException__
