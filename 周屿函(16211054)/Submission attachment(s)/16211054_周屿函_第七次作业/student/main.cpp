#include<iostream>
#include<stdlib.h>
#include"date.h"
#include"Student.h"
#include"Course.h"
#include "Console.h"
#include"Exception.h"

using namespace std;
int main()
{
    Console console;    //构造控制台界面
    int result=console.run();      //运行控制台
    return result;
}
