#include "MyException.h"

void MyException::wtfOfDate()const{
    printf("%sdate information does not exist!\n",s);
}

void MyException::wtfOfCourse()const{
    printf("%scourse information does not exist!\n",s);
}

void MyException::wtfOfGrade()const{
    printf("%sgrade is wrong!\n",s);
}
