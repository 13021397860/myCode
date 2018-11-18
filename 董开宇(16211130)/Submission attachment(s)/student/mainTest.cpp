#include "mainTest.h"
#include <fstream>
#include <cstdlib>
#include "MyException.h"
mainTest::mainTest()
{
    //ctor
}

void mainTest::test()
{
    cout<<"Please enter the student's name: ";
    char name[10];
    cin>>name;
    cout<<endl;
    cout<<"Please enter the student's birthday (year month day): ";
    int year,month,day;
    try
    {
        cin>>year>>month>>day;
        Date birth(year,month,day);
    }
    catch(MyException k)
    {
        cout<<"Error: "<<k.DateError()<<endl;
        year=1;
        month=1;
        day=1;
    }

    Date birth(year,month,day);
    //cin>>year>>month>>day;
    Date birthday(month,day,year);
    cout<<birthday<<endl;
    cout<<birthday++<<endl;
    cout<<birthday<<endl;
    cout<<++birthday<<endl;
    student dky(name,birthday);
    cout<<endl;
    ifstream in_file( ".\\course.txt" );
    if( ! in_file )
    {
        cerr << "Error!" << endl;
        return;
    }
    char c_name[12];
    int c_hour;
    bool is_elective;
    int c_num=1;
    while( in_file >> c_name >> c_hour >> is_elective )
    {
        if(is_elective)
        {
            a[c_num]=new ElectiveCourse;
            a[c_num]->setName(c_name);
            a[c_num]->SetCreditHour(c_hour);
            cout<<c_num<<": "<<*a[c_num]<<endl;
            c_num++;
        }
        else
        {
            a[c_num]=new ObligatoryCourse;
            a[c_num]->setName(c_name);
            a[c_num]->SetCreditHour(c_hour);
            cout<<c_num<<": "<<*a[c_num]<<endl;
            c_num++;
        }
    }
    in_file.close();
    c_num--;
    cout<<"Enter the number to choose the course: (-1 to quit)"<<endl;
    int k=1;
    int num;
    while(k)
    {
        try
        {
            cin>>num;
            if(cin.fail())
            {
                throw MyException();
            }
        }
        catch(MyException p)
        {
            cin.clear();
            cin.ignore();
            cout<<"Error: "<<p.CourseError()<<endl;
            continue;
        }
        if(num>c_num||num<-1)
        {
            cout<<"Error: Course Error!"<<endl;
            continue;
        }
        dky.addCourse(a[num]),cout<<"Choose successfully!"<<endl;
        cout<<"Enter any number to continue, -1 to quit."<<endl;
        cin>>k;
        if(k==-1) break;
    }
    cout<<"Enter the number to choose the course: from 0 to "<<dky.getCourseNumber()-1<<" (-1 to quit)"<<endl;
    k=1;
    while(k)
    {
        try
        {
            int num;
            cin>>num;
            if(num>dky.getCourseNumber()-1||num<0)
            {
                throw MyException();
            }
        }
        catch(MyException k)
        {
            cout<<"Error: "<<k.CourseError()<<endl;
            cout<<"Now num is 0!"<<endl;
            num=0;
        }

        if(num>dky.getCourseNumber()-1||num<-1)
        {
            cout<<"Error: CourseError!"<<endl;
            continue;
        }
        if(num<dky.getCourseNumber())
        {
            dky.removeCourse(num);
        }
        cout<<"\nEnter any number to continue, -1 to quit."<<endl;
        cin>>k;
        if(k==-1) break;
    }
    cout<<endl;
    cout<<dky;
    cout<<endl;
    cout<<"Please enter the grade:\n";
    dky.setFenshu();
    dky.printScore();
    cout<<endl;
    cout<<"Your GPA is: "<<dky.calcCredit()<<endl;

    ofstream outfile("student.txt",ios::out);
    if(!outfile)
    {
        cerr<<"Failed!"<<endl;
        exit(1);
    }
    outfile<<"Name:"<<dky.getName()<<"    "<<"Birthday:"<<dky.getBirthDate()<<endl;
    Course *temp;
    for(int i=0; i<dky.getCourseNumber(); i++)
    {
        dky.getCourseList(i,temp);
        outfile<<*temp<<endl;
    }
    outfile.close();


}

mainTest::~mainTest()
{
    //dtor
}
