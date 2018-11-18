#include<iostream>
#include"Student.h"
#include"Console.h"
#include<cstring>
using std::cout;
using std::string;
using std::endl;
using std::cin;

int main()
{
    Console console;
    int result=console.run();
    return result;

    int y,m,d;
    string str4;
        Student a(1998,8,20,"jack");
        a.addCourse3(new ObligatoryCourse("english",4,100));//吧一个oblicourse的指针传给student的courselist作为指针数组元素；
        a.addCourse2("cplusplus",4,'A');//在里面形成指针；
        cout<<a<<endl;
        cout<<"after writeCJ:"<<endl;
        a.WriteCJ();
        cout<<a<<endl;
        cout<<"after remove cplusplus"<<endl;
        a.removeCourse(1);
        cout<<a;
        /*a.addCourse2("linear algebra",4,'A');
        cout<<"add 2"<<endl;
        a.printStu();
        cout<<"main end"<<endl;*/
}
/*

int main()
{
    Console console;
    console.run();
    return 0;
}*/

