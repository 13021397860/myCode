#include "MyException.h"

MyException::MyException(ExceptionType et):exceptionType(et)
{
    //ctor
}

MyException::~MyException()
{
    //dtor
}

const char* MyException::what() const
{
    switch(exceptionType){
        case DATE_INVALID:
            return "The date's format is invalid!";
        case RANGE_ERROR:
            return "The subscript is out of range!";
        case SCORE_INVALID:
            return "The score's format is invalid!";
        case NOT_DIGIT:
            return "What you input is not a digit!";
        default:
            return "";
    }
}

//catch(MyException &e){
//    cout<<e.what()<<endl;
//}
//catch(...){
//    cout<<"Unknown mistake!"<<endl;
//}
//cout<<"Please input again: "<<endl;
