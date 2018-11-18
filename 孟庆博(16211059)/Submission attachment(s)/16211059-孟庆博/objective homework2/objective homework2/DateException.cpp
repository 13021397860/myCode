#include "stdafx.h"
#include "DateException.h"


DateException::DateException()
{
}

void DateException::out()
{
	printf("您输入的日期非法，请重新输入\n");
}


DateException::~DateException()
{
}
