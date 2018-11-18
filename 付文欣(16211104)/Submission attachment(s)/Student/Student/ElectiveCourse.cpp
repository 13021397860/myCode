#include "ElectiveCourse.h"
#define Score(j) ((j=='A')?95:((j=='B')?85:((j=='C')?75:((j=='D')?65:55))))

ElectiveCourse::ElectiveCourse(const string &s,int cre,const char g):Course(s,cre){
    setScore(g);
}

void ElectiveCourse::setScore(const char &s){
    grade=s;
}

int ElectiveCourse::getScore()const{
    return Score(grade);
}

bool ElectiveCourse::is_haveScore()const{
    return (grade=='0')?false:true;
}
