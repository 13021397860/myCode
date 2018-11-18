#include "Date.h"
#include "MyException.h"
#include<iostream>
#include<cstring>
using namespace std;
int month_day[13]= {0,31,28,31,30,31,30,31,30,31,30,31,30};
Date::Date() {
    year=1;
    month=1;
    day=1;
}
Date::Date(const int y,const int m,const int d) {
    setDate(y,m,d);
}
Date::Date(const Date& a) {
    year=a.year;
    month=a.month;
    day=a.day;
}
Date::~Date() {

}
int Date::getDay() const{
    return day;
}
int Date::getMonth()const {
    return month;
}
int Date::getYear()const {
    return year;
}
bool Date::isLeapYear()const {
    if((year%100!=0&&year%4==0)||year%400==0)
        return true;
    else return false;
}
bool Date::validDate(int y,int m,int d) const{
    month_day[2]=28;
    if(isLeapYear()==1)month_day[2]++;
    if(y>0&&m<13&&m>0&&d<=month_day[m]&&d>0)return true;
    else return false;
}
bool Date::setDate(int y,int m,int d) {
	try{
    setYear(y);
    setMonth(m);
    setDay(d);
    if(!validDate(year,month,day)) {
        throw MyException(0);
    }
	}
	catch(MyException ex){
		cout<<ex.message()<<endl;
		return 0;
	}
	return 1;
}

void Date::nextDay() {
    month_day[2]=28;
    if(isLeapYear()==1)month_day[2]++;
    if(day+1>month_day[month]) {
        month++;
        day=1;
    } else {
        day++;
    }
    if(month>12) {
        year++;
        month=1;
    }
}
void Date::setYear(int y) {
    year=y;
}
void Date::setMonth(int m) {
    month=m;
}
void Date::setDay(int d) {
    day=d;
}
void Date::Datecpy(Date &b,const Date& a){
    b.year=a.year;
    b.month=a.month;
    b.day=a.day;
}
ostream& operator << (ostream& output,Date a){
    output<<a.year<<"-"<<a.month<<"-"<<a.day;
    return output;
}
istream& operator >> (istream& input,Date &a){
    int y,m,d;
    input>>y>>m>>d;
    while(!a.setDate(y,m,d)){cout<<"Set birthday again!\n";
		input>>y>>m>>d;}

    return input;
}
Date& Date::operator ++ () {    //ǰ��
     nextDay();
	 return *this;
}
Date Date::operator ++ (int){  //����
      Date a(*this);
      nextDay();
      return a;
}
Date Date::operator + (int daytime){
    int leapyear=1;
	int sum=0;//�����N���
	Date tmp=*this;
	sum=daytime+tmp.day;//��ǰ������N�����
      while(sum>month_day[tmp.month])
      {
        if(tmp.month==2)//�жϵ����ǲ��Ƕ��·�
          {
          month_day[month]+=leapyear;}
        if(sum>month_day[tmp.month])
        {
          sum-=month_day[tmp.month];
          tmp.month++;//����������������һ����
          if(tmp.month==13)//���·ݳ���12��ʱ�����·���1��
          {tmp.year++;
            //��һ��
            if(tmp.year%400==0||(tmp.year%4==0&&tmp.year%100!=0))//�жϼ�һ����ǲ�������
              {
              leapyear=1;}
            else
              {leapyear=0;}//����������Ϊ0
            tmp.month=1;//��Ϊ12�µ���һ������1��
          }
          if(month_day[2]>28){month_day[2]=28;
          }
       }
      }
      tmp.day=sum;
	return tmp;
}
