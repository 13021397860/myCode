#include "MyException.h"

MyException::MyException():date_message("invalid date!\n"),
overflow_message("overflow!\n"),
grade_message("invalid grade!\n")
{

}

MyException::~MyException()
{
    //dtor
}
