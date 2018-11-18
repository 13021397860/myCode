#include "Exception.h"
#include <iostream>
MyException::MyException(int ClassID):TypeID(ClassID)
{
}
MyException::~MyException()
{
}
int MyException::getExClassID() const {
	return TypeID;
}
IOOBException::IOOBException(int ClassID):MyException(ClassID) {
}
void IOOBException::show() const {
	std::cout << "输入越界！" << std::endl;
}
IOOBException::~IOOBException() {
}
OORException::OORException(int ClassID):MyException(ClassID){
}
OORException::~OORException(){
}
void OORException::show()const {
	std::cout << "输入不在范围内！" << std::endl;
}
NGException::NGException(int ClassID):MyException(ClassID) {}
NGException::~NGException() {}
void NGException::show()const {
	std::cout << "未设置全部成绩！" << std::endl;
}
FTUIException::FTUIException(int ClassID):MyException(ClassID) {}
FTUIException::~FTUIException(){}
void FTUIException::show()const {
	std::cout << "输入错误！" << std::endl;
}