#include "course.h"
using namespace std;



ostream& operator<<(ostream& o, const Course& c) {
	// <�γ�����> ѧ�֣�<ѧ��>�����磺�γ������߼����Գ��� ��� - 2   ѧ�֣�3��
	o  <<"�γ����ƣ�"<< c.getCname()  << "   ѧ�֣�" << c.getCreditHour() <<"  �ɼ���"<<c.getScore()<< std::endl;

	return o;
}




