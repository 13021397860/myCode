#include <iostream>
#include "obligatoryCourse.h"
#include "course.h"
#include <string>
using namespace std;
obligatoryCourse::obligatoryCourse()
{

}
obligatoryCourse::obligatoryCourse(const string _name,const int _hour)
{
    this->setName(_name);
    this->setHour(_hour);
}
void obligatoryCourse::setMark(const int _mark)
{
    mark=_mark;
}
int obligatoryCourse::getScore()
{
    return mark;
}
