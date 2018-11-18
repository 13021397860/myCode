#include "Console.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Student.h"
#include "Date.h"
#include "MyException.h"
#include<fstream>

Console::Console()
{
    //ctor
}
int Console::run()
{
    char name[20];
    cout<<"name: ";
    cin>>name;
    int m,d,y;
    cout<<"birthday(mm dd yyyy): ";
    while(cin>>m>>d>>y)
    {
        try
        {
            Date::islegal(m,d,y);
            break;
        }catch(MyException &myException)
        {
            cout<<myException.what()<<endl;
        }
        cout<<"birthday(mm dd yyyy): ";
    }
    Date date(m,d,y);
    Student s(name,date);
    ifstream infile("read.txt");
    ofstream outfile("write.txt",ios::out);

    int num;
    while(1)
    {
        cout<<"1 to read student's information, 2 to add courses, 3 to remove courses, 4 to set scores, 5 to exit.\n";
        cin>>num;
        while(infile.fail()||num<1||num>5)
        {
            cin.clear();
            cout<<"wrong input!\n";
            cin.ignore();
            cin>>num;
        }
        switch (num)
        {
        case 1:
            outfile<<s<<endl;
            break;
        case 2:
        {
            string oc,ec;
            int occred,eccred,ocscore;
            char ecscore;
            cout<<"obligatory course you choose: ";
            infile>>oc;
            cout<<"credit of it: ";
            infile>>occred;
            cout<<"score of it: ";
            infile>>ocscore;
            ObligatoryCourse *ocPtr=new ObligatoryCourse(oc,occred,ocscore);
            try
            {
                s.addCourse(ocPtr);
            }catch(MyException &myException)
            {
                cout<<myException.what()<<endl;
            }

            cout<<"elective course you choose: ";
            infile>>ec;
            cout<<"credit of it: ";
            infile>>eccred;
            cout<<"score of it: ";
            infile>>ecscore;
            ElectiveCourse *ecPtr=new ElectiveCourse(ec,eccred,ecscore);
            try
            {
                s.addCourse(ecPtr);
            }catch(MyException &myException)
            {
                cout<<myException.what()<<endl;
            }
            break;
        }
        case 3:
            int j;
            cout<<"number of the course you want to remove: ";
            while(cin>>j)
            {
                try
                {
                    if(!s.removeCourse(j))
                        throw MyException(RANGE_ERROR);
                    break;
                }catch(MyException &myException)
                {
                    cout<<myException.what()<<endl;
                }
                cout<<"number of the course you want to remove: ";
            }
            break;
        case 4:
            s.setCourseScore();
            break;
        default:
            return 0;
            break;
        }
        cout<<endl;
    }
}
Console::~Console()
{
    //dtor
}
