#include "stdafx.h"
#include"MyException.h"


MyException::MyException() {
	eid = 0;
};

MyException::MyException(int _eid) {
	eid = _eid;
}

MyException::~MyException() {

};

ostream& operator<<(ostream& os, MyException& e) {
	os << "�Ƿ������룡������룺" << e.eid << " ";

	switch (e.eid) {
	case MyException::EXPECTION_UNKNOWN:
		os << "δ֪�Ĵ�������";
		break;
	case MyException::EXPECTION_DATE:
		os << "���ڷǷ�";
		break;
	case MyException::EXPECTION_NAME:
		os << "��������Խ��";
		break;
	case MyException::EXPECTION_GRADE:
		os << "�ɼ����ͷǷ�";
		break;
	case MyException::EXPECTION_OVERFLOW:
		os << "�±�Խ��";
		break;
	}
	os << " �����ԣ�";

	return os;
}

void MyException::myThrow() {
	throw MyException();
}