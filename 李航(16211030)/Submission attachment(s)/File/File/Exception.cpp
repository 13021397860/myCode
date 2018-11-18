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
	std::cout << "����Խ�磡" << std::endl;
}
IOOBException::~IOOBException() {
}
OORException::OORException(int ClassID):MyException(ClassID){
}
OORException::~OORException(){
}
void OORException::show()const {
	std::cout << "���벻�ڷ�Χ�ڣ�" << std::endl;
}
NGException::NGException(int ClassID):MyException(ClassID) {}
NGException::~NGException() {}
void NGException::show()const {
	std::cout << "δ����ȫ���ɼ���" << std::endl;
}
FTUIException::FTUIException(int ClassID):MyException(ClassID) {}
FTUIException::~FTUIException(){}
void FTUIException::show()const {
	std::cout << "�������" << std::endl;
}