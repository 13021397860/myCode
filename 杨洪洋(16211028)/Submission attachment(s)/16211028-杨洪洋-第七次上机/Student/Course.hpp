//
//  Course.hpp
//  Student
//
//  Created by apple on 2017/4/11.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef Course_hpp
#define Course_hpp

#include<string>
using namespace std;
class Course
{
    friend ostream& operator <<(ostream &,Course &);
public:
    virtual int getScore()=0;
    Course();
    Course(const string name,int creditHour);
    void setname(const string &n);
    void setCreditHour(const int &ch);
    string getname();
    int getCreditHour();
    virtual void print();
    virtual ~Course();
private:
    string coursename;
    int creditHour;
};
#endif /* Course_hpp */
