#include "Course.h"

Course::Course(const string &s,int grade){
    setName(s); steCreditHour(grade);
}

void Course::setName(const string &s){
    name=s;
}

void Course::steCreditHour(int grade){
    creditHour=grade;
}

string Course::getName()const{
    return name;
}

int Course::getCreditHour()const{
    return creditHour;
}

ostream& operator <<(ostream &out,Course &Cc){
    out<<"  the name of course:"<<Cc.getName()<<" credit hour:"<<Cc.getCreditHour();
    return out;
}


Course::~Course()
{
    //dtor
}
