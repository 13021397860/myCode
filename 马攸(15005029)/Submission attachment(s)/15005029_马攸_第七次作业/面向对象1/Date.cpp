#include "Date.h"
#include "MyException.h"
#include<iostream>
using namespace std;

Date::Date(int y,int m,int d)
{
	setDate(y,m,d);
}
Date::Date(Date&t)
{
	year=t.year;
	month=t.month;
	day=t.day;
}
int Date::getYear() const
{
    return year;
}
int Date::getMonth() const
{
    return month;
}

int Date::getDay() const
{
    return day;
}
void Date::setDate(int y,int m,int d)
{
    year=y;
    month=m;
    day=d;
    if(judge()==false)
    {
    	throw MyException(DATE_INVALID);
	}

}
bool Date::judge()
{
    int y,m,d;
    y=year;m=month;d=day;
	if(d>0&&d<32&&y>0&&m>0&&m<13){
        if(((y%4==0)&&(y%100!=0)||(y%400==0))){
            if(m==2){
                if(d<=29){
                    return true;
                }
                else{
                    return false;
                }
            }
            if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
                if(d<=31){
                    return true;
                }
                else{
                    return false;
                }
            }
            if(m==4||m==6||m==9||m==11){
                if(d<=30){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        else{
        	if(m==2){
                if(d<=28){
                    return true;
                }
                else{
                    return false;
                }
            }
            if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
                if(d<=31){
                    return true;
                }
                else{
                    return false;
                }
            }
            if(m==4||m==6||m==9||m==11){
                if(d<=30){
                    return true;
                }
                else{
                    return false;
                }
            }

        }
    }
    else{
        return false;
    }
}

bool Date::isLeapYear()
{
	if(((year%4==0)&&(year%100!=0)||(year%400==0))){
		return true;
	}
	else{
		return false;
	}
}
void Date::nextDay()
{
	int y,m,d;
	y=year;m=month;d=day;
	if(judge()==true){
		if(((y%4==0)&&(y%100!=0)||(y%400==0))){
			if(m==2){
				if(d<29){
					day=d+1;
				}
				else if(d==29){
					day=1;
					month=m+1;
				}
			}
			else if(m==1||m==3||m==5||m==7||m==8||m==10){
				if(d<31){
					day=d+1;
				}
				else if(d==31){
					day=1;
					month=m+1;
				}
			}
			else if(m==4||m==6||m==9||m==11){
				if(d<30){
					day=d+1;
				}
				else if(d==30){
					day=1;
					month=m+1;
				}
			}
			else if(m==12){
				if(d<31){
					day=d+1;
				}
				else if(d==31)
				{
					day=1;
					month=1;
					year=y+1;
				}
			}
		}
		else{
			if(m==2){
				if(d<28){
					day=d+1;
				}
				else if(d==28){
					day=1;
					month=m+1;
				}
			}
			else if(m==1||m==3||m==5||m==7||m==8||m==10){
				if(d<31){
					day=d+1;
				}
				else if(d==31){
					day=1;
					month=m+1;
				}
			}
			else if(m==4||m==6||m==9||m==11){
				if(d<30){
					day=d+1;
				}
				else if(d==30){
					day=1;
					month=m+1;
				}
			}
			else if(m==12){
				if(d<31){
					day=d+1;
				}
				else if(d==31)
				{
					day=1;
					month=1;
					year=y+1;
				}
			}
			
		}
	}
}
ostream& operator<<(ostream& output,const Date& c)
{
   output<<c.getYear()<<"-"<<c.getMonth()<<"-"<<c.getDay()<<endl;
   return output;
}
Date& Date::operator++()//++a 
{
	if(((this->year%4==0)&&(this->year%100!=0)||(this->year%400==0)))
	{
		if(this->month==2)
		{
			if(this->day<29)
			{
				this->day++;
			}
			else if(this->day==29)
			{
				this->day=1;
				this->month++;
			}
		}
		else if(this->month==1||this->month==3||this->month==5||this->month==7||this->month==8||this->month==10)
		{
			if(this->day<31)
			{
				this->day++;
			}
			else if(this->day==31)
			{
				this->day=1;
				this->month++;
			}
		}
		else if(this->month==4||this->month==6||this->month==9||this->month==11)
		{
			if(this->day<30)
			{
				this->day++;
			}
			else if(this->day==30)
			{
				this->day=1;
				this->month++;
			}
		}
		else if(this->month==12)
		{
			if(this->day<31)
			{
				this->day++;
			}
			else if(this->day==31)
			{
				this->day=1;
				this->month=1;
				this->year++;
			}
		}
	}
	else
	{
		if(this->month==2)
		{
			if(this->day<28)
			{
				this->day++;
			}
			else if(this->day==28)
			{
				this->day=1;
				this->month++;
			}
		}
		else if(this->month==1||this->month==3||this->month==5||this->month==7||this->month==8||this->month==10)
		{
			if(this->day<31)
			{
				this->day++;
			}
			else if(this->day==31)
			{
				this->day=1;
				this->month++;
			}
		}
		else if(this->month==4||this->month==6||this->month==9||this->month==11)
		{
			if(this->day<30)
			{
				this->day++;
			}
			else if(this->day==30)
			{
				this->day=1;
				this->month++;
			}
		}
		else if(this->month==12)
		{
			if(this->day<31)
			{
				this->day++;
			}
			else if(this->day==31)
			{
				this->day=1;
				this->month=1;
				this->year++;
			}
		}
	}
    return *this;
}
Date& Date::operator++(int)//a++ 
{
	Date pdd(*this);
	if(((this->year%4==0)&&(this->year%100!=0)||(this->year%400==0)))
	{
		if(this->month==2)
		{
			if(this->day<29)
			{
				this->day++;
			}
			else if(this->day==29)
			{
				this->day=1;
				this->month++;
			}
		}
		else if(this->month==1||this->month==3||this->month==5||this->month==7||this->month==8||this->month==10)
		{
			if(this->day<31)
			{
				this->day++;
			}
			else if(this->day==31)
			{
				this->day=1;
				this->month++;
			}
		}
		else if(this->month==4||this->month==6||this->month==9||this->month==11)
		{
			if(this->day<30)
			{
				this->day++;
			}
			else if(this->day==30)
			{
				this->day=1;
				this->month++;
			}
		}
		else if(this->month==12)
		{
			if(this->day<31)
			{
				this->day++;
			}
			else if(this->day==31)
			{
				this->day=1;
				this->month=1;
				this->year++;
			}
		}
	}
	else
	{
		if(this->month==2)
		{
			if(this->day<28)
			{
				this->day++;
			}
			else if(this->day==28)
			{
				this->day=1;
				this->month++;
			}
		}
		else if(this->month==1||this->month==3||this->month==5||this->month==7||this->month==8||this->month==10)
		{
			if(this->day<31)
			{
				this->day++;
			}
			else if(this->day==31)
			{
				this->day=1;
				this->month++;
			}
		}
		else if(this->month==4||this->month==6||this->month==9||this->month==11)
		{
			if(this->day<30)
			{
				this->day++;
			}
			else if(this->day==30)
			{
				this->day=1;
				this->month++;
			}
		}
		else if(this->month==12)
		{
			if(this->day<31)
			{
				this->day++;
			}
			else if(this->day==31)
			{
				this->day=1;
				this->month=1;
				this->year++;
			}
		}
	}
    return pdd;
}
Date::~Date()
{
    //dtor
}
