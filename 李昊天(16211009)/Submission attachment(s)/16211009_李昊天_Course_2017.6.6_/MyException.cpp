#include "MyException.h"
#include<iostream>



const char *MyException::what()
{
    switch(e){
    case range:
        return "The number you entered is out of range!";
    case date:
        return "Date over range, and your date is set to default.";
    case score:
        return "The score you enter is out of range, and system will set it to 0!";
    default:
        return "Other Error!";
    }
}
