#include "ElectiveCourse.h"
#include"MyException.h"
using namespace std;
 void ElectiveCourse::print()const
{
    cout<<*this;
}

char ElectiveCourse::getGrade()const
{
	return grade;
}
void ElectiveCourse::setGrade(char a)
{
	if(a>='A'&&a<='E')
	   grade =  a ;
	else 
       throw MyException(Grade_wrong);
}
int ElectiveCourse::getScore()const
{
     switch(grade)
     	{
     		case 'A':
     		{
     			return 95;
     			break;
			}
			case 'B':
     		{
     			return 85;
     			break;
			}
			case 'C':
     		{
     			return 75;
     			break;
			}
			case 'D':
     		{
     			return 65;
     			break;
			}
			case 'E':
     		{
     			return 55;
     			break;
			}
			default	:
			{
				break;
			}
		}
}
