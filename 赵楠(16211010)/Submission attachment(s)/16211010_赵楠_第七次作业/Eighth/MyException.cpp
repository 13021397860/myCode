#include "MyException.h"

MyException::MyException(Type et):Etype(et)
{
	
}

MyException::~MyException()
{
	
}

const char* MyException::what()const
{
	switch(Etype)
	{
		case Date_Invalid:
		    return "The date is invalid!";
	    case Range_Error:
	        return "The subscript is out of range!";
	    case Score_Invalid:
	        return "The score is invalid!";
	    default:
	        return "Else";
	}
}
