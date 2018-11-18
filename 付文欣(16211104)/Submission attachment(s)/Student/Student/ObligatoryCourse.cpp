#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse(const string &s,int cre,int m):Course(s,cre){
    setScore(m);
}

void ObligatoryCourse::setScore(const int &m){
    mark=m;
}

int ObligatoryCourse::getScore()const{
    return mark;
}

bool ObligatoryCourse::is_haveScore()const{
    return (mark==-1)?false:true;
}
