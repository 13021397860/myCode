#include<iostream>
#include<iomanip>
#include "student .h"
#include "Date.h"
student ::student ()
{
    //ctor
}

void student::setName(char *n){

    strcpy(name.n);

}
void student::setbrithdy(int y,int m.int d){
    Date::setDate();
    Date::isLeepYear();
    Date::cheakDate();
}
void student::cheakName(){
    int p=strlen(name);
    if(p>20){
        name="xxxxx?";
    }

}


void student::printname(){
    cout<<name<<endl;
}
student ::~student ()
{
    //dtor
}
