//
//  course.cpp
//  Student
//
//  Created by Pirate Hero on 17/4/17.
//  Copyright © 2017年 mac. All rights reserved.
//

#include "course.hpp"

void course::get()
{
    Name=name;
    CreditHour=creditHour;
}


void course::set()
{
    cin>>name;
    cin>>creditHour;
}


course::course()
{
    name="PE";
    creditHour=2;
    
}

 course::~course()
{
    
}


course::course(const string &n,const int c)
{
    name=n;
    creditHour=c;
}

void course::set(const string& s,int c)
{
    name=s;
    creditHour=c;
    
   
}


void ObligatoryCourse::set()
{
    
        
        for(;;)
        {
            cin>>mark;
            if(mark>100||mark<0)
            {
                cout<<"输入错误,请重新输入"<<endl;
            }
            else
            {
                return;
            }
        }
    
    
}



void ElectiveCourse::set()
{
  
    for(;;)
    {
        cin>>grade;
        int RRR=0;
    switch(grade)
    {
        case 'A':
            mark= 95;
            break;
        case 'B':
            mark= 85;
            break;
        case 'C':
            mark= 75;
            break;
        case 'D':
            mark=65;
            break;
        case 'E':
            mark= 55;
            break;
        default:
            RRR=1;
            cout<<"输入错误,请重新输入"<<endl;
            break;
            
    }
        if(RRR==1)
        {
            continue;
        }
        else
            break;
  
    
        
        }
    
    
}


ostream & operator<<(ostream & out, course & A){
    
    out <<"课程名: "<<A.name<<" 学分: "<<A.creditHour<<endl;
    return out;
}
