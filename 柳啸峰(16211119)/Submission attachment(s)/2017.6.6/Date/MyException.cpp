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
	outClientFile=new ofstream("MyExceptionOfDate.txt",ios::app);//默认的ios::out是重写文件，每次 
	if(!outClientFile) cout<<"filed"<<endl;						// 运行之前清空文件 
	(*outClientFile)<<s<<"("<<y<<"-"<<m<<"-"<<d<<")"<<endl;//在文本中输出错误的日期 			//app追加打开文件 
	outClientFile->close();
 } 
void MyException::MyExceptionOfStud(int i)
{
	ofstream *outClientFile;
	outClientFile=new ofstream("MyExceptionOfStud.txt",ios::app);
	if(!outClientFile) cout<<"filed"<<endl;
	(*outClientFile)<<"你所调用的课程数组下标错误"<<"("<<i<<")"<<endl;//在文本中输出错误的课程数组下标 
	outClientFile->close();
}
void MyException::MyExceptionOfOCS(int i)
{
	ofstream *outClientFile;
	outClientFile=new ofstream("MyExceptionOfOCS.txt",ios::app);
	if(!outClientFile) cout<<"filed"<<endl;
	(*outClientFile)<<"你所设置的必修课成绩错误"<<"("<<i<<")"<<endl;//在文本中输出错误的必修课成绩 
	outClientFile->close();
}
void MyException::MyExceptionOfOES(char c)
{
	ofstream *outClientFile;
	outClientFile=new ofstream("MyExceptionOfOES.txt",ios::app);
	if(!outClientFile) cout<<"filed"<<endl;
	(*outClientFile)<<"你所设置的选修课成绩错误"<<"("<<c<<")"<<endl;//在文本中输出错误的选修课成绩 
	outClientFile->close();
 } 
MyException::~MyException()
{
}
