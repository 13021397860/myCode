#include "MyException.h"
#include <iostream>
using namespace std;
MyException::MyException(string s)
{
    message=s;
    //ctor
}

MyException::~MyException()
{
    //dtor
}

void MyException::what(){
    switch(message[8]){
        case 'D':cout<<"\n����������Ϣ�쳣��\n���������룡"<<endl;break;
        case 'C':cout<<"\n����γ̱���쳣��\n���������룡"<<endl;break;
        case 'S':cout<<"\n����γ̳ɼ��쳣��\n���������룡"<<endl;break;
        default:cout<<"\nδ֪�������ͣ�\n���������룡"<<endl;break;
    }
}
