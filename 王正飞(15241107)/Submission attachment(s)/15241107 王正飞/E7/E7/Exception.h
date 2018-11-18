#pragma once

#include <string>

class Exception
{
public:
	Exception(const std::string &exception);
	const std::string what() const;
private:
	std::string message;
};