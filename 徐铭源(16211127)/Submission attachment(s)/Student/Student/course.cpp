#include "course.h"

Course::Course(const string tname,const int tcreditHour)
{
	name=tname;
	creditHour=tcreditHour;
}
Course::Course()
{
	
}
Course::Course(const Course &C)
{
	name=C.name;
	creditHour=C.creditHour;
}
string Course::getName()const
{
	return name;
}
int Course::getCreditHour()const
{
	return creditHour;
}
string Course::setName(string _name)
{
	name=_name;
}
int Course::setCreditHour(int _creditHour)
{
	creditHour=_creditHour;
}
ostream &operator <<(ostream&out,const Course &C)
{
	string _name=C.getName();
	int _creditHour=C.getCreditHour();
    out<<"<"<<_name<<"> "<<"ังทึ"<<":"<<_creditHour<<endl; 
    return out;
}
Course::~Course()
{

}
