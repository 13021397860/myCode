#include "Console.h"
#include <iomanip>
#include <typeinfo>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
Console::Console()
{
    string s;
    int n;
    Onum = 0;
    Enum = 0;
    /*O[0] = new ObligatorayCourse("mathematics",4);
    O[1] = new ObligatorayCourse("algebra",4);
    O[2] = new ObligatorayCourse("English",4);
    O[3] = new ObligatorayCourse("data structure",4);
    O[4] = new ObligatorayCourse("object oriented",3);
    O[5] = new ObligatorayCourse("physical education",2);
    O[6] = new ObligatorayCourse("physics", 5);

    E[0] = new ElectiveCourse("aerospace introduction", 2);
    E[1] = new ElectiveCourse("ethics", 1);*/
    ifstream in("ObligatoryCourse.txt");
    if( !in.is_open()){
        cout<<"Error opening file ObligatoryCourse.txt!\n";
        exit(1);
    }
    int i=0;
    while(!in.eof()){
        in>>s>>n;
        O[i++] = new ObligatorayCourse(s,n);
    }
    in.close();
    Onum = i;
    i = 0;
    ifstream in2("ElectiveCourse.txt");
    if( !in2.is_open() ){
        cout<<"Error opening file ElectiveCourse.txt!\n";
        exit(1);
    }
    while(!in2.eof()){
        in2>>s>>n;
        E[i++] = new ElectiveCourse(s,n);
    }
    in2.close();
    Enum = i;
}

Console::~Console()
{
    delete []O;
    delete []E;
}
int Console::set_mark(int i,Student &p){
    if(i<=0||i>p.courseNumber){
        throw -3;
    }
    cout<<"\n";
    cout<<"please enter the grade of the course";
    if(typeid(ObligatorayCourse) == typeid(*p.courseList[i-1])){
        cout<<"(0-100): ";
        int _grade;
        cin>>_grade;
        ObligatorayCourse *ptr;
        ptr = dynamic_cast<ObligatorayCourse*>(p.courseList[i-1]);
        ptr->setgrade(_grade);
        cout<<endl;
        cout<<"\nthe grade of "<<ptr->getname()<<" is "<<ptr->getscore()<<endl;
        return 1;
    }
    else if(typeid(ElectiveCourse) == typeid(*p.courseList[i-1])){
        cout<<"(A-E): ";
        char _mark;
        cin>>_mark;
        ElectiveCourse *ptr;
        ptr = dynamic_cast<ElectiveCourse*>(p.courseList[i-1]);
        ptr->setgrade(_mark);
        cout<<endl;
        cout<<"\nthe grade of "<<ptr->getname()<<" is "<<ptr->getscore()<<endl;
        return 1;
    }
    return 0;

}
int Console::run(){
    MyException ex;
    char *_name;
    _name = new char;
    int y,m,d;
    Student p;
    cout<<"load the information before or not\n";
    cout<<"1 to load , other number not\n";
    int i;
    cin>>i;
    if(i == 1){
        ifstream in("student.txt");
        if(!in.is_open()){
            cout<<"Error opening student.txt!\n";
            exit(1);
        }
        char* _name;
        _name = new char;
        int y,m,d;
        in>>_name>>y>>m>>d;
        try{
            p.Set(_name,y,m,d);
        }catch(int t){
            if(t == -3)
                cout<<ex.what_overflow();
            else if(t == -1)
                cout<<ex.what_date();
            else if(t == -2)
                cout<<ex.what_grade();
        }
        string s;
        int h,g;
        string t;
        while(in>>s>>h>>g>>t){

            if(t == "Obligatory"){
                for(int i=0;i<Onum;i++){
                    if(s == O[i]->getname()){
                        p.addCourse(O[i]);
                        O[i]->setgrade(g);
                        ///cout<<"O"<<endl;
                        break;
                    }
                }
            }
            else{
                for(int i=0;i<Enum;i++){
                    if(s == E[i]->getname()){
                        p.addCourse(E[i]);
                        E[i]->setgrade(g);
                        //cout<<"E"<<endl;
                        break;
                    }
                }
            }
        }
        in.close();
    }
    else{
        cout << "please enter your name:";
        cin>>_name;
        cout<< "please enter your birthday like 1998 12 10:";
        cin>>y>>m>>d;
        try{
            p.Set(_name,y,m,d);
        }catch(int t){
            if(t == -3)
                cout<<ex.what_overflow();
            else if(t == -1)
                cout<<ex.what_date();
            else if(t == -2)
                cout<<ex.what_grade();
        }
    }
    while(1){
        cout<<"\n\n";
        cout<<"please choose the function:\n";
        cout<<"the procedure will exit when you put in -1\n";
        //cout<<"1.reset your name\t\t2.reset your birthday\n";
        cout<<"0.print your information\n";
        cout<<"1.add a obligatory course\n";
        cout<<"2.add a Elective course\n";
        cout<<"3.remove a selected course\n";
        cout<<"4.set grade for a selected course\n";
        cout<<"5.get the grade of a course\n";
        cout<<"6.get your GPA\n\n";

        int choice;
        cin>>choice;
        while(cin.fail()){
            cin.clear();
            cin.ignore();
            //while(cin.get()!='\n') continue;
            cout<<"\ninvalid input!\n";
            cin>>choice;
        }
        if(choice == 0){
            cout<<"********************************\n\n\n";
            cout<<p;
            cout<<"\n\n********************************\n";
        }
        else if(choice == 1){
            for(int i=0;i<=6;i++){
                cout<<left<<i+1<<"."<<setw(30)<<O[i]->getname()<<O[i]->getcreditHour()<<"\n";
            }
            cin>>choice;
            if(choice<=7&&choice>=1){
                p.addCourse(O[choice-1]);
                cout<<"\nadd successfully!\n";
            }
            else{
                cout<<"\ninvalid input\n!";
            }
        }
        else if(choice == 2){
            for(int i=0;i<=1;i++){
                cout<<left<<i+1<<"."<<setw(30)<<E[i]->getname()<<E[i]->getcreditHour()<<"\n";
            }
            cin>>choice;  //there may be invalid input!!!
            if(choice<=2&&choice>=1){
                p.addCourse(E[choice-1]);
                cout<<"\nadd successfully!\n";
            }
            else{
                cout<<"\ninvalid input\n!";
            }
        }
        else if(choice == 3){
            cout<<p;
            cout<<"\nplease enter the id of the course: ";
            int n;
            cin>>n;
            try{
                //cout<<"\nremove successfully!\n";
                p.removeCourse(n);
            }catch(int t){
                if(t == -3)
                    cout<<ex.what_overflow();
                else if(t == -1)
                    cout<<ex.what_date();
                else if(t == -2)
                    cout<<ex.what_grade();
            }
            //cout<<"delete the course successfully!\n";
        }
        else if(choice == 4){
            cout<<p;
            cout<<"\nplease enter the id of the course: ";
            int i; cin>>i;
            try{
                set_mark(i,p);
            }catch(int t){
                if(t == -3)
                    cout<<ex.what_overflow();
                else if(t == -1)
                    cout<<ex.what_date();
                else if(t == -2)
                    cout<<ex.what_grade();
            }
        }
        else if(choice == 5){
            cout<<"\nplease enter the id of the course: ";
            int i; cin>>i;
            if(i<=0||i>p.courseNumber){
                cout<<"invalid input!\n";
                break;
            }
            cout<<*p.courseList[i-1]<<endl;
        }
        else if(choice == 6){
            cout<<"\nyour GPA is:\t"<<p.calcCredit()<<"\n";
        }
        else{
            if(choice == -1){
                break;
            }
            cout<<"\ninvalid input!\n";
            continue;
        }
    }
    ofstream out("Student.txt");
    if(!out.is_open()){
        cout<<"Error storing the information of the student!\n";
        exit(1);
    }
    out.clear();
    out<<p;
    out.close();
    return 1;
}
