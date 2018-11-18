#include "Console.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include <fstream>
#include <cctype>
#include <sstream>

Console::Console()
{
    //ctor
}

int Console::run()
{
    buildStudent();
    buildCourseList();
    while(1){
        try{
            int choose=displayMenu();
            if(choose==0){
                cout<<endl;
                cout<<"Thanks for your participation. Have a nice school life."<<endl;
                cout<<"------------------------Goodbye------------------------"<<endl;
                break;
            }
            else if(choose==1){
                cout<<endl<<*student;
            }
            else if(choose==2){
                buildCourse();
            }
            else if(choose==3){
                setCourseScore();
            }
            else if(choose==4){
                removeCourse();
            }
            else if(choose==5){
                showCourseScore();
            }
            else if(choose==6){
                showCalcCredit();
            }
            else if(choose==7){
                showCourseMessage();
            }
            else if(choose==8){
                safeStudentMessage();
            }
            else if(choose==9){
                readStudentMessage();
            }
            else if(choose==10){
                setMessageByFile();
            }
        }
        catch(MyException &e){
            cout<<e.what()<<endl;
        }
        catch(...){
            cout<<"Unknown mistake!"<<endl;
        }
    }
    return 0;
}

int Console::displayMenu()
{
    cout<<endl;
    cout<<"Input '1' to show the student's message             wwwwwwwwwww  wwwwwwwwwwwww"<<endl;
    cout<<"Input '2' to add a course                           wwwwwwwwwww  wwwwwwwwwwwww"<<endl;
    cout<<"Input '3' to set score for a course                          ww  www        ww"<<endl;
    cout<<"Input '4' to remove a course                                 ww  www        ww"<<endl;
    cout<<"Input '5' to search the score of a course           wwwwwwwwwww  www        ww        Designed"<<endl;
    cout<<"Input '6' to search the calCredit                   wwwwwwwwwww  www        ww           by"<<endl;
    cout<<"Input '7' to read all the courses you can choose             ww  www     ww ww          Andy~~"<<endl;
    cout<<"Input '8' to safe the student's message                      ww  www      wwww"<<endl;
    cout<<"Input '9' to read the student's message from a file          ww  www        www"<<endl;
    cout<<"Input '10' to set the student's message from a file wwwwwwwwwww  wwwwwwwwwwwwwww  "<<endl;
    cout<<"Input '0' to exit                                   wwwwwwwwwww  wwwwwwwwwwwww  ww"<<endl;
    cout<<endl;
    string choose;
    cin>>choose;
    stringstream ss(choose);
    int x;
    ss>>x;
    if(!isdigit(choose[0])){
        throw MyException(NOT_DIGIT);
    }
    else if(x<0||x>10){
        throw MyException(RANGE_ERROR);
    }
    return x;
}

Console& Console::buildStudent()
{
    char name[20];
    cout<<"Please input your name:";
    cin.getline(name,20);
    cout<<"Please input your birthday:";
    Date birthday;
    cin>>birthday;
    student=new Student(name,birthday);
    return *this;
}

Course* Console::selectCourse(int op)
{
    Course *cPtr;
    if(op==1){
        cPtr=new ObligatoryCourse();
    }
    else if(op==2){
        cPtr=new ElectiveCourse();
    }
    return cPtr;
}

Console& Console::buildCourse()
{
    cout<<endl;
    cout<<"Input '1' to add an obligatory course by yourself"<<endl;
    cout<<"Input '2' to add an elective course by yourself"<<endl;
    cout<<"Input '3' to choose a recommended obligatory course"<<endl;
    cout<<"Input '4' to choose a recommended elective course"<<endl;
    cout<<endl;
    int op;
    cin>>op;
    if(op==1||op==2){
        Course *cPtr=selectCourse(op);
        cout<<endl;
        cout<<"Input your courseName and credit: ";
        string courseName;
        int creditHour;
        cin>>courseName>>creditHour;
        cout<<endl;
        cPtr->setName(courseName);
        cPtr->setCreditHour(creditHour);
        student->addCourse(cPtr);
    }
    else if(op==3){
        student->readObligatoryCourseMessage();
        cout<<endl<<"Input the number you want to choose: ";
        while(1){
            try{
                cin>>op;
                cout<<endl;
                if(op<1||op>oblNum){
                    throw MyException(RANGE_ERROR);
                }
                else{
                    student->addCourse(oblPtr[op-1]);
                    break;
                }
            }
            catch(MyException &e){
                cout<<e.what()<<endl;
            }
            catch(...){
                cout<<"Unknown mistake!"<<endl;
            }
            cout<<"Please input again: ";
        }
    }
    else if(op==4){
        student->readElectiveCourseMessage();
        cout<<endl<<"Input the number you want to choose: ";
        while(1){
            try{
                cin>>op;
                cout<<endl;
                if(op<1||op>eleNum){
                    throw MyException(RANGE_ERROR);
                }
                else{
                    student->addCourse(elePtr[op-1]);
                    break;
                }
            }
            catch(MyException &e){
                cout<<e.what()<<endl;
            }
            catch(...){
                cout<<"Unknown mistake!"<<endl;
            }
            cout<<"Please input again: "<<endl;
        }
    }
    return *this;
}

void Console::buildCourseList()
{
    oblNum=0;
    ifstream inFile1("obligatoryCourseMessage.dat", ios::in);
    if(inFile1){
        string line;
        stringstream ss;
        string name;
        int x,y;
        getline(inFile1,line);
        while(getline(inFile1,line)){
            ss<<line;
            ss>>x;
            oblPtr[x-1]=new ObligatoryCourse();
            ss>>name>>y;
            oblPtr[x-1]->setName(name);
            oblPtr[x-1]->setCreditHour(y);
            ss.clear();
            oblNum++;
        }
    }
    inFile1.close();
    eleNum=0;
    ifstream inFile2("electiveCourseMessage.dat", ios::in);
    if(inFile2){
        string line;
        stringstream ss;
        string name;
        int x,y;
        getline(inFile2,line);
        while(getline(inFile2,line)){
            ss<<line;
            ss>>x;
            elePtr[x-1]=new ElectiveCourse();
            ss>>name>>y;
            elePtr[x-1]->setName(name);
            elePtr[x-1]->setCreditHour(y);
            ss.clear();
            eleNum++;
        }
    }
    inFile2.close();
}

bool Console::setCourseScore()
{
    cout<<endl;
    cout<<"Input the course number you want to choose and the score you want to set: ";
    int num,score;
    while(1){
        try{
            cin>>num>>score;
            cout<<endl;
            if(num<1||num>student->getCourseNumber()){
                if(student->getCourseNumber()==0){
                    cout<<"You haven't choosen any course."<<endl;
                    break;
                }
                throw MyException(RANGE_ERROR);
            }
            else if(score<0||score>100){
                throw MyException(SCORE_INVALID);
            }
            else{
                student->setCourseScore(num,score);
                cout<<"Congratulations!"<<endl;
                return true;
            }
        }
        catch(MyException &e){
            cout<<e.what()<<endl;
        }
        catch(...){
            cout<<"Unknown mistake!"<<endl;
        }
        cout<<"Please input again: ";
    }
    return false;
}

bool Console::removeCourse()
{
    cout<<endl;
    cout<<"Input the course number you want to remove: ";
    int num;
    while(1){
       try{
            cin>>num;
            cout<<endl;
            int judge=student->removeCourse(num);
            if(!judge){
                if(student->getCourseNumber()==0){
                    cout<<"You haven't choosen any course."<<endl;
                    break;
                }
                throw MyException(RANGE_ERROR);
            }
            else{
                cout<<"Congratulations!"<<endl;
                return true;
            }
        }
        catch(MyException &e){
            cout<<e.what()<<endl;
        }
        catch(...){
            cout<<"Unknown mistake!"<<endl;
        }
        cout<<"Please input again: ";
    }
    return false;
}

void Console::showCourseScore() const
{
    cout<<endl;
    cout<<"Input the course number you want to search: ";
    int num;
    while(1){
       try{
            cin>>num;
            cout<<endl;
            if(num<1||num>student->getCourseNumber()){
                if(student->getCourseNumber()==0){
                    cout<<"You haven't choosen any course."<<endl;
                    break;
                }
                throw MyException(RANGE_ERROR);
            }
            else{
                student->getCourseScore(num);
                break;
            }
        }
        catch(MyException &e){
            cout<<e.what()<<endl;
        }
        catch(...){
            cout<<"Unknown mistake!"<<endl;
        }
        cout<<"Please input again: ";

    }
    cin>>num;
    cout<<endl;

}

void Console::showCalcCredit() const
{
    cout<<endl;
    cout<<"Your calcCredit is ";
    cout<<student->calcCredit()<<endl;
}

void Console::showCourseMessage() const
{
    cout<<endl;
    student->readCourseMessage();
    cout<<endl;
}

void Console::safeStudentMessage() const
{
    student->safeMessage();
}

void Console::readStudentMessage() const
{
    ifstream inFile("studentMessage.txt", ios::in);
    if(inFile){
        string line;
        while(getline(inFile,line)){
            cout<<line<<endl;
        }
    }
    else{
        cout<<"There are some errors when open the file."<<endl;
    }
    inFile.close();
}


void Console::setMessageByFile()
{
    ifstream inFile("buildStudent.dat", ios::in);
    if(inFile){
        string line;
        stringstream ss;
        int x,y;
        string nameOfCourse;
        while(getline(inFile,line)){
            ss<<line;
            ss>>x;
            if(x==2){
                ss>>x;
                Course *cPtr=selectCourse(x);
                ss>>nameOfCourse;
                cPtr->setName(nameOfCourse);
                ss>>x;
                cPtr->setCreditHour(x);
                student->addCourse(cPtr);
            }
            else if(x==3){
                ss>>x;
                ss>>y;
                try{
                    if(x<1||x>student->getCourseNumber()){
                        if(student->getCourseNumber()==0){
                            cout<<"You haven't choosen any course."<<endl;
                            break;
                        }
                        else{
                            throw MyException(RANGE_ERROR);
                        }
                    }
                    else if(y<0||y>100){
                        throw MyException(SCORE_INVALID);
                    }
                    else{
                        student->setCourseScore(x,y);
                        cout<<"Congratulations!"<<endl;
                    }
                }
                catch(MyException &e){
                    cout<<e.what()<<endl;
                }
                catch(...){
                    cout<<"Unknown mistake!"<<endl;
                }
            }
            else if(x==4){
                ss>>x;
                try{
                    int judge=student->removeCourse(x);
                    if(!judge){
                        if(student->getCourseNumber()==0){
                            cout<<"You haven't choosen any course."<<endl;
                        }
                        throw MyException(RANGE_ERROR);
                    }
                    else{
                        cout<<"Congratulations!"<<endl;
                    }
                }
                catch(MyException &e){
                    cout<<e.what()<<endl;
                }
                catch(...){
                    cout<<"Unknown mistake!"<<endl;
                }
            }
            ss.clear();
        }
    }
    else{
        cout<<"There are some errors when open the file."<<endl;
    }
    inFile.close();
}

Console::~Console()
{
    delete student;
    //dtor
}
