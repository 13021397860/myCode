#include "MyException.h"
#include <fstream>
#include "Date.h"
#include "Students.h"
MyException::MyException()
{
}
void MyException::MyExceptionOfDate(int y, int m, int d,char *s)
{
	ofstream *outClientFile;
	outClientFile=new ofstream("MyExceptionOfDate.txt",ios::app);//Ĭ�ϵ�ios::out����д�ļ���ÿ�� 
	if(!outClientFile) cout<<"filed"<<endl;						// ����֮ǰ����ļ� 
	(*outClientFile)<<s<<"("<<y<<"-"<<m<<"-"<<d<<")"<<endl;//���ı��������������� 			//app׷�Ӵ��ļ� 
	outClientFile->close();
 } 
void MyException::MyExceptionOfStud(int i)
{
	ofstream *outClientFile;
	outClientFile=new ofstream("MyExceptionOfStud.txt",ios::app);
	if(!outClientFile) cout<<"filed"<<endl;
	(*outClientFile)<<"�������õĿγ������±����"<<"("<<i<<")"<<endl;//���ı����������Ŀγ������±� 
	outClientFile->close();
}
void MyException::MyExceptionOfOCS(int i)
{
	ofstream *outClientFile;
	outClientFile=new ofstream("MyExceptionOfOCS.txt",ios::app);
	if(!outClientFile) cout<<"filed"<<endl;
	(*outClientFile)<<"�������õı��޿γɼ�����"<<"("<<i<<")"<<endl;//���ı����������ı��޿γɼ� 
	outClientFile->close();
}
void MyException::MyExceptionOfOES(char c)
{
	ofstream *outClientFile;
	outClientFile=new ofstream("MyExceptionOfOES.txt",ios::app);
	if(!outClientFile) cout<<"filed"<<endl;
	(*outClientFile)<<"�������õ�ѡ�޿γɼ�����"<<"("<<c<<")"<<endl;//���ı�����������ѡ�޿γɼ� 
	outClientFile->close();
 } 
MyException::~MyException()
{
}
