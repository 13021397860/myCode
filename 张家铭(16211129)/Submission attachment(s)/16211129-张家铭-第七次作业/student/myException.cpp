#include "myException.h"

myException::myException():message("Unknown Error!")
{

}
const char *myException::dateException()
{
    return "Date Error!\n";
}
const char *myException::courseException()
{
    return "Course Not Found!\n";
}
const char *myException::fenshuException()
{
    return "FenShu error!\n";
}
