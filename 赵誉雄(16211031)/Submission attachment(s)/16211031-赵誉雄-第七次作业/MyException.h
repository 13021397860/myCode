#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

enum Etype {INVALID_DATE,OUT_OF_RANGE,INVALID_SCORE};

class MyException {
	public:
		MyException(Etype et)
			:type(et){};
		const char* what() const 
		{	
			switch(type)
			{
				case INVALID_DATE:
					return "Invalid date!";	
					break;
				case OUT_OF_RANGE:
					return "Out of range!";
					break;
				case INVALID_SCORE:
					return "Invalid score!";	
					break;
				default:
					return "Unknown exception!";
			}
		}
		Etype GetType()
		{
			return type;
		}
		~MyException(){} 
	private:
		Etype type;	
};

#endif
