#include "MyExpection.h"

MyExpection::MyExpection(char *string)
:message(string)
{
}

const char *MyExpection::what()const
{
	return message;
}

char * MyExpection::time(int i,int j,int k)
{
	if(i<=0||j<=0||k<=0||j>=13||k>=32)
	{
		throw MyExpection(message);
	}
	else
	{
		cout<<i<<"-"<<j<<"-"<<k<<"  ";
		return ("��ȷ");
	}
}

char * MyExpection::biao(char i)
{
	if(i!='1'&&i!='2'&&i!='3'&&i!='4'&&i!='5'&&i!='6')
	{
		throw MyExpection(message);
	}
	else
	{
		cout<<"����ѯ��Ŀ�����:"<<i<<endl; 
		return ("��������");
	}
}
char *MyExpection::ograde(int i)
{
	if(i<=0||i>=101)
	{
		throw MyExpection(message);
	}
	else
	{
		cout<<"����ĳɼ���"<<i<<endl;
		return("��������");
	}
}
char *MyExpection::egrade(char i)
{
	if(i<'A'||i>'E')
	{
		throw MyExpection(message);
	}
	else
	{
		cout<<"����ĵȼ���"<<i<<endl;
		return("��������");
	}
}
MyExpection::~MyExpection()
{
	
}
