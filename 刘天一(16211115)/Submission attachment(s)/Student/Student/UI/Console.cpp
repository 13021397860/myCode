#include "Console.h"
#include <cstdio>
#include <typeinfo>
UI::UI()
{

}
UI::~UI()
{
    //dtor
}

void UI::printfMainInterface()
{
    cout<<"************* welcome to jiaowu.buaa.edu.cn !*************\n";
    cout<<"\t1. add in ObligatoryCourse\n";
    cout<<"\t2. add in ElectiveCourse\n";
    cout<<"\t3. drop a course\n";
    cout<<"\t4. set grade\n";
    cout<<"\t5. scan grade\n";
    cout<<"\t6. save data\n";
    cout<<"\t0. exit jiaowu\n";
}
void UI::run()
{
    inputStudent();
    buildCourse();
    printfMainInterface();
    cin>>choice;
    while (cin.fail()){
        cin.clear();
        cin.ignore();
        cout<<"Import data format error , please import again :\n";
        cin>>choice;
    }
    while(choice<0 || choice>6)
    {
        cout<<"you must choose a number from 0 to 6 ,try again :\n";
        cin>>choice;
        while (cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"Import data format error , please import again :\n";
            cin>>choice;
        }
    }
    while(choice)
    {
        option();
        printfMainInterface();
        cin>>choice;
    }
}
void UI::inputStudent()
{
    s=new Student;
    cout<<"your name?\n";
    string name;
    cin>>name;
    s->setName(name.c_str());
    cout<<"your birthday?\n";
    Date d;
    while(1)
    {
        try {
            cin>>d;
            break;
        }
        catch(MyException et){
            cout<<"EXCEPTION! "<<et.what()<<endl<<"Please try again: \n";
        }
    }
}
void UI::option()
{
    switch(choice)
    {
        case 1: addObligatoryCourse();break;
        case 2: addElectiveCource();break;
        case 3: dropCourse();break;
        case 4: setGrade();break;
        case 5: scanGrade();break;
        case 6: saveData();break;
        case 0: break;
        default: break;
    }
}
void UI::saveData()
{
    char fileName[100];
    ofstream *ofile;
    cout<<"Please key in the file name you want to save:\n";
    cin>>fileName;
    ofile=new ofstream(fileName);
    if(!ofile) {
        cerr<<"can't establish file\n";
    }
    *ofile<<*s;
    ofile->close();
    delete ofile;
}
void UI::addObligatoryCourse()
{
    cout<<"please choose the course you want to add in:\n";
    for(int i=0;i<Course_num;i++)
        cout<<i+1<<". "<<ObliCourse[i]->getName()<<" "<<ObliCourse[i]->getCreditHour()<<endl;
    int optionnum;
    cin>>optionnum;
    if(optionnum<1||optionnum>Course_num)
    {
        cout<<"bad choice!\n";return ;
    }
    ObligatoryCourse *obliCourse=new ObligatoryCourse(*ObliCourse[optionnum-1]);
    obliCourse->setMark(-1);
    s->addCourse(obliCourse);
    cout<<"good choice!\n";
}
void UI::addElectiveCource()
{
    cout<<"please choose the course you want to add in:\n";
    for(int i=0;i<Course_num;i++)
        cout<<i+1<<". "<<ElecCourse[i]->getName()<<" "<<ElecCourse[i]->getCreditHour()<<endl;
    int optionnum;
    cin>>optionnum;
    if(optionnum<1||optionnum>Course_num)
    {
        cout<<"bad choice!\n";return ;
    }
    ElectiveCourse *elecCourse=new ElectiveCourse(*ElecCourse[optionnum-1]);
    elecCourse->setGrade('\0');
    s->addCourse(elecCourse);
    cout<<"good choice!\n";
}
void UI::dropCourse()
{
    int Coursenum=s->getCourseNumber();
    s->print();
    cout<<"please choose the course you want to drop:\n";
    int optionnum;
    while(1) {
        try{
            cin>>optionnum;
            if(optionnum==0) return ;
            s->removeCourse(optionnum);
            break;
        }
        catch(MyException et){
            cout<<"bad choice!  "<<et.what()<<"Please try again: "<<endl;
        }
    }

    cout<<"dropping succeed!\n";return ;
}
void UI::setGrade()
{
    int Coursenum=s->getCourseNumber();
    s->print();
    cout<<"please choose the course you want to set grade:\n";
    int optionnum;
    while(1) {
        try{
            cin>>optionnum;
            if(optionnum==0) return ;
            s->getcourse(optionnum);
            break;
        }
        catch(MyException et){
            cout<<"bad choice!  "<<et.what()<<"Please try again: "<<endl;
        }
    }
    if(typeid(*s->getcourse(optionnum))==typeid(ObligatoryCourse))
    {
        int mark;
        cout<<"please key in its mark(0-100):\n";
        ObligatoryCourse* courseptr1=dynamic_cast<ObligatoryCourse*>(s->getcourse(optionnum));
        while(1) {
            try{
                cin>>mark;
                courseptr1->setMark(mark);
                break;
            }
            catch(MyException et) {
                cout<<et.what()<<" must be 0-100 . Please try again :\n";
            }
        }

    }
    else
    {
        char grade;
        cout<<"please key in its grade(A/B/C/D/E):\n";
        ElectiveCourse* courseptr2=dynamic_cast<ElectiveCourse*>(s->getcourse(optionnum));
        while(1) {
            try {
                cin>>grade;
                courseptr2->setGrade(grade);
                break;
            }
            catch (MyException et) {
                cout << et.what() << " must be A/B/C/D/E . Please try again :\n";
            }
        }
    }
}
void UI::scanGrade() {
    s->print();
    int i;
    cin>>i;
}
void UI::buildCourse()
{
    char fileName[]="..\\courseList";
    ifstream ifile(fileName);
    if(!ifile) cerr<<"error!\n";
    int catalog,cHour,oNum=0,eNum=0;
    string cName;
    while(ifile>>catalog>>cName>>cHour) {
        switch(catalog) {
            case 1:ObliCourse[oNum++]=new ObligatoryCourse(cName,cHour);break;
            case 2:ElecCourse[eNum++]=new ElectiveCourse(cName,cHour);break;
        }
    }
    ifile.close();
}
