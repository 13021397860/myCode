#include"stdafx.h"
#include"ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse(string _name, int _creditHour) :Course(_name, _creditHour) {
	//TAG = "ObligatoryCourse";
	score = 0;
};

ObligatoryCourse::~ObligatoryCourse(){

};

void ObligatoryCourse::setScore(int _score) {
	score = _score;
};

int ObligatoryCourse::getScore(void)const {
	return score;
}
