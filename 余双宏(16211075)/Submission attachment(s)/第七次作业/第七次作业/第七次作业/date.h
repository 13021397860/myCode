#ifndef DATE_H_
#define DATE_H_
#include<iostream>
class date
{
private:
	int year, month, day;
public:
	bool judge() const;
	void judge1()const;
	date();
	date(int y, int m, int d);
	date(const date & t);
	~date();
	int getyear() const;
	int getmonth() const;
	int getday() const;
	date get() const;
	void set(int y,int m,int d);
	bool isLeapYear() const;
	date& nextDay();
	//void print() const;
	friend std::ostream & operator<<(std::ostream & os,const date &t);
	friend std::istream & operator>>(std::istream & is, date& t);
	date& operator++() { return nextDay(); }
	date operator++(int) { date tmp = *this; ++(*this); return tmp; }
	date& operator+(int x) { for (int i = 0; i < x; ++i) (*this)++; return *this; }
	date & operator=(const date &a);
};
#endif // !1
