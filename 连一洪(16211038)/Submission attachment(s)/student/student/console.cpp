#include "console.h"
#include <cstdio>
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#include "date.h"
#include "student.h"
#include <fstream>
using std::ostream;
console::console()
{
    //ctor
}

console::~console()
{
    //dtor
}

//ofstream fout("f:\2017project\student\Student.txt",ios::out);
console& console::buildcourse(){
    string s;
    int n;
    int i=0,j=0;
    fstream fcinName,fcinCredit;
    fcinName.open("ObligatoryCourse_data.txt");
    fcinCredit.open("ElectiveCourse_data.txt");
    if(fcinName){
        while(fcinName>>s>>n){
            oc[i]=new ObligatoryCourse(s,n);
            i++;
        }
    }
    fcinName.close();
    if(fcinCredit){
        while(fcinCredit>>s>>n){
            ec[j]=new ElectiveCourse(s,n);
            j++;
        }
    }
    fcinCredit.close();

    return (*this);


}
console& console::buildstudent(){
    s.setcoursenumber();
    cout<<"YOUR NAME:  ";
    cin>>studentname;
    s.setName(studentname);
    cout<<"YOUR BIRTH DATE:  ";
    while(1){
        try{
            cin>>year>>month>>day;
            s.setbirthdate(year, month, day);
            break;
        }catch(Date_exception de){
            cout<<de.what()<<endl;
            cout<<"Please input your date again!\n";
        }
    }

    return (*this);
}
int console::displayMenu()const{
    cout<<"++++++++++Now welcome to the menu!!++++++++++\n"
                  ">_<  Input 1 to select the obligatory course;\n"
                  ">_<  Input 2 to select the elective course;\n"
                  ">_<  Input 3 to check your information;\n"
                  ">_<  Input 4 to remove your course;\n"
                  ">_<  Input 5 to reset your course marks;\n"
                  ">_<  Input 6 to check your calc credit;\n"
                  ">_<  Input 0 to quit;\n";
    int rundoor=7;
    cin>>rundoor;

    return rundoor;


}
int console::run(){

    cout<<"\n **********Welcome to the course selection system!!!**********\n\n";

    buildcourse();
    buildstudent();

    cout<<"Please input 1 to continue, or 0 to quit.\n";
    int key;
    cin>>key;
    if(key!=0&&key!=1){
        cin.clear();
        cin.ignore();
        cout<<"You input the wrong key, please input again: \n";
        cin>>key;
    }
    else if(key==1){
        int door=7;
        while(door){
            door=displayMenu();
            if(cin.fail()){
                cin.clear();
                cin.ignore();
                cout<<"You input the wrong door, please input again: \n";
                door=7;
                continue;
            }
            else if(door<0||door>7){
                cin.clear();
                cin.ignore();
                cout<<"You input the wrong door, please input again: \n";
                door=7;
                continue;
            }

            else if(door==1){
                int ocwall=1;
                if(ocwall==0) cout<<"You have already selected the obligatory course!!\n";
                else{
                   /* if(s.getcoursenumber()>4){
                        coursenumber--;
                        cout<<"FULL!\n";
                        ocwall=1;
                    }
                    else{*/
                        int no=-1;
                        cout<<"You can select 3 obligatory courses.\n";
                        cout<<"+_+  Input 0 for Advanced Mathematics;\n"
                              "+_+  Input 1 for Theoretical Physics; \n"
                              "+_+  Input 2 for Data Structure; \n";
                        for(int i=0; i<ocNum; i++){
                            cin>>no;
                            if(no<0 || no>2){
                                cin.clear();
                                cin.ignore();
                                cout<<"No such course! Please input again!\n";
                                i--;
                            }
                            else if(cin.fail()){
                                cin.clear();
                                cin.ignore();
                                cout<<"No such course! Please input again!\n";
                                i--;
                            }
                            else{
                                s.addCourse(oc[no]);
                                cout<<"Select successfully!\n";
                            }

                        }
                        ocwall=0;
                        cout<<"You have selected the obligatory course!\n";
                        cout<<"\n";
                    //}
                }
            }
            else if(door==2){
                int ecwall=1;
                if(ecwall==0) cout<<"You have already selected the elective course!!\n";
                else{
                   /* if(coursenumber>4){
                        coursenumber--;
                        cout<<"FULL!\n";
                        ecwall=1;
                    }
                    else{*/
                        int no =-1;
                        cout<<"You can select 2 elective courses.\n";
                        cout<<"+_+  Input 0 for Information Retrieval; \n"
                              "+_+  Input 1 for Martial Arts; \n"
                              "+_+  Input 2 for Spoken English; \n";
                        for(int i=0; i<ecNum; i++){
                            cin>>no;
                            if(no<0 || no>2){
                                cin.clear();
                                cin.ignore();
                                cout<<"No such course! Please input again!\n";
                                i--;
                            }
                            else if(cin.fail()){
                                cin.clear();
                                cin.ignore();
                                cout<<"No such course! Please input again!\n";
                                i--;
                            }
                            else{
                                s.addCourse(ec[no]);
                                cout<<"Select successfully!\n";
                            }

                        }
                        ecwall=0;
                        cout<<"You have selected the elective course!\n";
                        cout<<"\n";
                   // }
                }
            }
            else if(door==3){
                ofstream fout;
                fout.open("Student.txt",ios::app);
                if(!fout) cout<<"No such file!!!\n";
                fout<<s<<endl;
                fout<<"\n";
                fout.close();
                cout<<"You have write your information into the file.\n";
            }
            else if(door==4){
                int removeNumber;
                cout<<"Please input the course number you want remove:\n";
                while(1){
                    try{
                        cin>>removeNumber;
                        //cout<<*(s.courseList[removeNumber-1])<<endl;
                        //s.removeCourse(removeNumber-1);
                        //cout<<*(s.courseList[removeNumber-1])<<endl;
                        if(s.removeCourse(removeNumber-1)){
                            cout<<"Succeed!\n";
                        }
                        break;
                    }catch(Course_exception ce){
                        cout<<ce.what()<<endl;
                        cout<<"Please input again!\n";
                    }
                }
               /* else{
                    cout<<"You can't do that!\n";
                }*/
                cout<<"\n";
            }
            else if(door==5){
                int resetNumber;
                cout<<"Please input the course number you want reset:\n";
                while(1){
                    try{
                        cin>>resetNumber;
                        if(s.setCourseScore(resetNumber)){
                            cout<<"Succeed!\n";
                        }
                        break;
                    }catch(Course_exception ce){
                        cout<<ce.what()<<endl;
                        cout<<"Please input the course number again!\n";
                    }catch(Mark_exception me){
                        cout<<me.what()<<endl;
                        cout<<"Please input the course number again!\n";
                    }

                }
                cout<<"\n";
            }
            else if(door==6){
                cout<<"Your calc credit is: ";
                int calc;
                calc=s.calcCredit();
                cout<<calc<<endl;
            }
            else if(door==0) break;
            }
            return 0;
        }
    else
        return 0;
}

