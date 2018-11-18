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
class IOOBException ://����Խ��IndexOutOfBounds
	public MyException
{
public:
	IOOBException(int ClassID);
	virtual void show() const;
	virtual ~IOOBException();
};
class OORException ://����������OutOfRange
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
class FTUIException ://��������
	public MyException
{
public:
	FTUIException(int ClassID);
	virtual void show()const;
	virtual ~FTUIException();
};