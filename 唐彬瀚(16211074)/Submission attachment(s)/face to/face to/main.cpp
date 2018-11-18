#include<iostream>
#include<cmath>
#include"Course.h"
#include"Student.h"
#include"Date.h"
#include"ElectiveCourse.h"
#include"ObligatoryCourse.h"
#include"Console.h"
using namespace std;
int main(){
	Console c;
	Student s; 
	int op;
	c.load();
	c.initi();
	while(cin>>op){
		if(op==0){
			c.initi();
		}
		else if(op==1){
			c.select(s);
		}
		else if(op==2){
			c.remove(s);
		}
		else if(op==3){
			c.check(s);
		}
		else if(op==4){
			c.setcredit();
		}
		else if(op==5){
			c.getList(s);
		}
		else if(op==6){
			c.check(s);
		}
		else if(op==7){
			c.save(s);
		}
	}
} 

