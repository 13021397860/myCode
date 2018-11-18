#include "Course.h"
#include <string>
#include <cstdio>

using namespace std;
Course::Course()
{
    //ctor
}
Course::Course(string x,int y)
{
    name=x;
    creditHour=y;
}
Course ::~Course()
{
    //dtor
}
string Course:: getName()const
{
    return name;
}
int Course:: getCreditHour()const
{
    return creditHour;
}
void Course:: setName(string n)
{
    name=n;
}
void Course:: setCreditHour(int c)
{
    creditHour=c;
}
void Course:: setGrade(int x)
{
    printf("haha\n");
    return ;
}
void Course:: setGrade(char z)
{
    printf("haha\n");
    return ;
}
//int Course:: getScore() =0;
