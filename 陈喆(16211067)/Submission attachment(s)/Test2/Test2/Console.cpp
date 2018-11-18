#include "Console.h"
#include <typeinfo>

//ifstream cin;
ifstream coursefile;
//ofstream cout;

Console::Console()
{

    coursefile.open("Course_information.txt");
    if(!coursefile)
    {
        cout<<"opening error!"<<endl;
        throw(0);
    }

    char* CourseName= new char[150];
    int CourseCredit;
    coursefile>>OcNum;
    coursefile>>EcNum;
    for(int i=1;i<=OcNum;i++)
    {
        Oc[i]=new ObligatoryCourse;
        coursefile>>CourseCredit;
        coursefile>>CourseName;
        Oc[i]->SetName(CourseName);
        Oc[i]->SetCreditHour(CourseCredit);
    }
    for(int i=1;i<=EcNum;i++)
    {
        Ec[i]=new ElectiveCourse;
        coursefile>>CourseCredit;
        coursefile>>CourseName;
        Ec[i]->SetName(CourseName);
        Ec[i]->SetCreditHour(CourseCredit);
    }
    coursefile.close();
    /*
    OcNum=6;
    EcNum=2;
    for(int i=1;i<=6;i++)
        Oc[i]= new ObligatoryCourse;
    for(int i=1;i<=2;i++)
        Ec[i]= new ElectiveCourse;
    Oc[1]->SetName("mathematics");Oc[1]->SetCreditHour(4);
    Oc[2]->SetName("algebra");Oc[2]->SetCreditHour(4);
    Oc[3]->SetName("English");Oc[3]->SetCreditHour(4);
    Oc[4]->SetName("data structure");Oc[4]->SetCreditHour(3);
    Oc[5]->SetName("physical education");Oc[5]->SetCreditHour(2);
    Oc[6]->SetName("physics");Oc[6]->SetCreditHour(5);

    Ec[1]->SetName("aerospace introduction");Ec[1]->SetCreditHour(2);
    Ec[2]->SetName("ethics");Ec[2]->SetCreditHour(1);
    */
    //ctor
}

Console::~Console()
{
    //dtor
}
void Console::printWelcome()
{
    cout<<"******* welcome to my system for student *******\n";
    return;
}
void Console::printIntroduction_Indicator()
{
    cout<<"\n";
    cout<<"******* the introduction of indicator*******\n";
    cout<<"******* 0 : finish operating         *******\n";
    cout<<"******* 1 : select obligatory course *******\n";
    cout<<"******* 2 : select elective course   *******\n";
    cout<<"******* 3 : remove course            *******\n";
    cout<<"******* 4 : show the selected course *******\n";
    cout<<"******* 5 : set course grade         *******\n";
    cout<<"******* 6 : show grade               *******\n";
    cout<<"******* others : input again         *******\n";
    cout<<"********************************************\n";
    cout<<"\n";
    return;
}

void Console::printIntroduction_ObligatoryCourse()
{
    cout<<"\n";
    cout<<"*******      Obligatory course       *******\n";
    for(int i=1;i<=OcNum;i++)
    {
        cout<<"*******      "<<i<<" : ";
        cout<<setw(20)<<setfill(' ')<<left<<Oc[i]->GetName();
        cout<<"*******\n";
    }
    cout<<"********************************************\n";
    cout<<"\n";
}

void Console::printIntroduction_ElectiveCourse()
{
    cout<<"\n";
    cout<<"*******      Elective course            *******\n";
    for(int i=1;i<=EcNum;i++)
    {
        cout<<"*******      "<<i<<" : ";
        cout<<setw(23)<<setfill(' ')<<left<<Ec[i]->GetName();
        cout<<"*******\n";
    }
    cout<<"***********************************************\n";
    cout<<"\n";
}

ObligatoryCourse* Console::getOc(const int num)
{
    return Oc[num];
}
ElectiveCourse* Console::getEc(const int num)
{
    return Ec[num];
}

void Console::select_ObligatoryCourse(Student &student)
{
    printIntroduction_ObligatoryCourse();
    int courseNum;
    cout<<"Please input the course number: ";
    cin>>courseNum;
    if(courseNum>0&&courseNum<=OcNum)
    {
    ObligatoryCourse* AObligatoryC=new ObligatoryCourse;
    AObligatoryC->SetName(Console::getOc(courseNum)->GetName());
    AObligatoryC->SetCreditHour(Console::getOc(courseNum)->GetCreditHour());
    student.addCourse(AObligatoryC);
    }
    else
        throw(MyException ("what you choose (OC) is not existed!"));
}

void Console::select_ElectiveCourse(Student &student)
{
    int courseNum;
    printIntroduction_ElectiveCourse();
    cout<<"Please input the course number: ";
    cin>>courseNum;
    if(courseNum>0&&courseNum<=EcNum)
    {
    ElectiveCourse* AElectiveC=new ElectiveCourse;
    AElectiveC->SetName(Console::getEc(courseNum)->GetName());
    AElectiveC->SetCreditHour(Console::getEc(courseNum)->GetCreditHour());
    student.addCourse(AElectiveC);
    }
    else
        throw(MyException("what you choose (EC) is not existed!"));
}

void Console::removeCourse(Student &student)
{
    cout<<student;
    int needRemoved;
    cout<<"Please input the course number: ";
    cin>>needRemoved;
    bool IsRemovingSucess;
    IsRemovingSucess=student.removeCourse(needRemoved-1);
    if(IsRemovingSucess)
        cout<<"Have removed the course."<<endl;
    else
        throw (MyException("Failure of removing!"));
}

void Console::set_courseGrade(Student &student)
{
    cout<<student;
    int needSet;
    cout<<"Please input the course number: ";
    cin>>needSet;
    //cout<<typeid(*student.getCourse(needSet-1)).name()<<endl;
    //cout<<typeid(ObligatoryCourse).name()<<endl;
    if(needSet<=student.Get_courseNumber())
    {
    if(typeid(*student.getCourse(needSet-1))==typeid(ObligatoryCourse))
    {
        ObligatoryCourse* tmp_Oc=dynamic_cast<ObligatoryCourse*>(student.getCourse(needSet-1));
        int settingMark;
        cout<<"Please give a number(0~100): ";
        int settingMarkFlag=1;
        while(settingMarkFlag)
        {
            try{
                cin>>settingMark;
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    throw(MyException("illegal input!"));
                }
                else if(settingMark>100||settingMark<0)
                    throw(MyException("wrong grade!"));
                else
                {
                    tmp_Oc->SetMark(settingMark);
                    settingMarkFlag=0;
                }
            }
            catch(MyException& E)
            {
                cout<<E<<endl;
                cout<<"Please input proper grade"<<endl;
            }
        }
        /*
        while(settingMark>100&&settingMark<0)
        {
            //cin.clear();
            cin.ignore();
            cout<<"please input again(using correct type)\n";
            cin>>settingMark;
        }
        tmp_Oc->SetMark(settingMark);
        */
    }
    else if(typeid(*student.getCourse(needSet-1))==typeid(ElectiveCourse))
    {
        ElectiveCourse* tmp_Ec=dynamic_cast<ElectiveCourse*>(student.getCourse(needSet-1));
        char settingMark;
        cout<<"Please give a capital letter(A~E): ";
        int settingMarkFlag=1;
        while(settingMarkFlag)
        {
            try{
                cin>>settingMark;
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    throw(MyException("illegal input!"));
                }
                else if(settingMark>'E'||settingMark<'A')
                    throw(MyException("wrong character!"));
                else
                {
                    tmp_Ec->SetMark(settingMark);
                    settingMarkFlag=0;
                }
            }
            catch(MyException& E)
            {
                cout<<E<<endl;
                cout<<"Please input proper grade"<<endl;
            }
        }
        /*
        while(cin.fail()||(settingMark>'E'||settingMark<'A'))
        {
            cin.clear();
            cin.ignore();
            cout<<"please input again(using correct type)\n";
            cin>>settingMark;
        }
        tmp_Ec->SetMark(settingMark);
        */
    }
    else
        cout<<"an error happened when setting grades!"<<endl;
    }
    else
        throw(MyException("what you choose(course) is not existed!"));
}

void Console::out_information(Student& student,char* str)
{
    ofstream student_information(str);
    student_information<<student;
    student_information<<flush;
    student_information.close();
}
void Console::run()
{
    //cin.open("D:\\mine\\code and common software\\codeblocks store\\select_course.txt");
    //if(!cin)
    //{
        //cout<<"opening error!"<<endl;
        //throw(0);
    //}
    //cout.open("D:\\mine\\code and common software\\codeblocks store\\information_back.txt");


    cout<<"Please input the student's name:";
    char* name;
    int Tyear;
    int Tmonth;
    int Tday;
    char Tname[20];
    name=Tname;
    cin>>Tname;
    cout<<"Please input the student's birthday:  for example(1999 9 9)"<<endl;
    cin>>Tyear>>Tmonth>>Tday;
    Student first(name);
    try{
        first.SetBirthDate(Tyear,Tmonth,Tday);
    }
    catch(MyException &E)
    {
        cout<<E<<endl;
    }
    int indicator(-1);
    while(indicator)
    {
        printIntroduction_Indicator();
        cout<<"Please input the indicator (number): ";
        cin>>indicator;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout<<"error\n";
            cin>>indicator;
        }
        if(indicator==0)
        {
            break;
        }
        else if(indicator==1)
        {
            try{
                select_ObligatoryCourse(first);
            }
            catch(MyException &E)
            {
                cout<<E<<endl;
            }
        }
        else if(indicator==2)
        {
            try{
                select_ElectiveCourse(first);
            }
            catch(MyException &E)
            {
                cout<<E<<endl;
            }
        }
        else if(indicator==3)
        {
            try{
                removeCourse(first);
            }
            catch(MyException &E)
            {
                cout<<E<<endl;
            }
        }
        else if(indicator==4)
        {
            first.ShowSelectedCourse();
        }
        else if(indicator==5)
        {
            try{
            set_courseGrade(first);
            }
            catch(MyException &E)
            {
                cout<<E<<endl;
            }
        }
        else if(indicator==6)
        {
            cout<<first.calcCredit();
        }
        else
            continue;
    }
    //cout<<flush;
    //cout.close();
    //cin.close();
    char a[]="student_information.txt";
    out_information(first,a);
}
