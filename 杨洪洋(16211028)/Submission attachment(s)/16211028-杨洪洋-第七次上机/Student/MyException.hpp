//
//  MyException.hpp
//  Student
//
//  Created by apple on 2017/6/5.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef MyException_hpp
#define MyException_hpp

#include <stdio.h>
#include <iostream>
#include<cstdlib>
#include "Date.hpp"
#include "Student.hpp"
#include "Course.hpp"
using namespace std;
class MyException
{
public:
    //构造函数，参数为错误代码
    MyException();
    MyException(int errorid)
    {
        m_errorid=errorid;
    }
    MyException(int y,int m,int d)
    {
        errory=y;
        errorm=m;
        errord=d;
    }
    MyException(int errorsc,char a)
    {
        errorscore=errorsc;
    }
    MyException(MyException &myExp)
    {
        this->m_errorid=myExp.m_errorid;
    }
    MyException(char *errorgr)
    {
        errorgrade=errorgr;
    }
    ~MyException()
    {
    }
     int getErrorid()
    {
        return m_errorid;
    }
    void getErrordate()
    {
        cout<<errory<<" "<<errorm<<" "<<errord<<endl;
    }
    void geterrorgrade()
    {
        cout<<errorgrade<<endl;
    }
    void geterrorscore()
    {
        cout<<errorscore<<endl;
    }

private:
    int m_errorid;
    int errory,errorm,errord;
    char *errorgrade;
    int errorscore;
};
#endif /* MyException_hpp */
