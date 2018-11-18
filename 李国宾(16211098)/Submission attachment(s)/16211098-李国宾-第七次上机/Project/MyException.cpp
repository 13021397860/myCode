#include"MyException.h"

MyException::MyException() {
	exceptionNum=0;
	initMsg();
}
MyException::MyException(int num) {
	exceptionNum=num;
	initMsg();
}
void MyException::initMsg() {
	message[0]="Error! Date Invalid!";
	message[1]="Error! Choice Invalid!";
	message[2]="Error! Grade Invalid!";
}
string MyException::showMsg() {
	return message[exceptionNum];
}
