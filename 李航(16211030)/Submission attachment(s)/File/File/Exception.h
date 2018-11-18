#pragma once
#include "Base.h"
class MyException
{
public:
	MyException(int ClassID);
	virtual void show()const=0;
	virtual int getExClassID() const;
	virtual ~MyException();
protected:
	const int TypeID;
private:
};
class IOOBException ://数组越界IndexOutOfBounds
	public MyException
{
public:
	IOOBException(int ClassID);
	virtual void show() const;
	virtual ~IOOBException();
};
class OORException ://超过定义域OutOfRange
	public MyException
{
public:
	OORException(int ClassID);
	virtual void show()const;
	virtual ~OORException();
};
class NGException :
	public MyException
{
public:
	NGException(int ClassID);
	virtual void show()const;
	virtual ~NGException();
};
class FTUIException ://错误输入
	public MyException
{
public:
	FTUIException(int ClassID);
	virtual void show()const;
	virtual ~FTUIException();
};