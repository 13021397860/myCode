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
	os << "非法的输入！错误代码：" << e.eid << " ";

	switch (e.eid) {
	case MyException::EXPECTION_UNKNOWN:
		os << "未知的错误类型";
		break;
	case MyException::EXPECTION_DATE:
		os << "日期非法";
		break;
	case MyException::EXPECTION_NAME:
		os << "姓名长度越界";
		break;
	case MyException::EXPECTION_GRADE:
		os << "成绩类型非法";
		break;
	case MyException::EXPECTION_OVERFLOW:
		os << "下标越界";
		break;
	}
	os << " 请重试！";

	return os;
}

void MyException::myThrow() {
	throw MyException();
}