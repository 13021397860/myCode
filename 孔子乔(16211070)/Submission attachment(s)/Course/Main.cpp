#define UTF8 1
#define GB 0

#ifdef linux
    #include<cstdio>
#endif // linux

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include"Student.h"
#include"Course.h"
#include"Console.h"
#include"MyException.h"

int main()
{
    #ifdef linux
        printf("not supported on linux\n");
        return 0;
    #endif // linux
    Console main(UTF8);
    if(!main.init_course())return 0;
    try{main.login();}catch(MyException &a){a.InfoError();}
    try{main.load_course();}catch(MyException &a){a.LoadError();}
    char select;
    while((select=main.main_page())!='0')
    {
        if(select=='1')try{while(main.select_page());}catch(MyException &a){a.SingleError();}
        else if(select=='2')while(main.remove_page());
        else if(select=='3')try{while(main.grade_page());}catch(MyException &a){a.SingleError();}
        else if(select=='4')main.list_page();
    }
    return 0;
}
