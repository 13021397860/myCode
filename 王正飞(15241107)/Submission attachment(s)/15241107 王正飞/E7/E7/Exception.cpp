#include <string>
#include <iostream>

#include "Exception.h"

using namespace std;

Exception::Exception(const string &exception) :message(exception) {}

const string Exception::what() const
{
	if (message == "TIME") return "Wrong time eneterd\nTry again:\n";
	else if (message == "OPTION") return "Wrong option entered\n";
	else if (message == "GRADE") return "Wrong grade entered\n";
	else return message;
}