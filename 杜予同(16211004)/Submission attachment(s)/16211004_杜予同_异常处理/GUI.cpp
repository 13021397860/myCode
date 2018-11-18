#include "GUI.h"
#include <iostream>
#include "Date.h"
#include "student.h"
#include "Course.h"
#include <string.h>
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include <fstream>
#include "MyException.h"
using namespace std;
GUI::GUI()
{
    //ctor
}

GUI::~GUI()
{
    //dtor
}
int GUI::ui()
{
    ifstream ifile;
    ofstream ofile;
    ifile.open("infile.txt");
    int isObli,creditHour;
    string name;
    /*while(ifile>>isObli>>name>>creditHour)
    {
        Course *temp;

        if(isObli==1)
            temp=new ObligatoryCourse(creditHour,name);
        else
            temp=new ElectiveCourse(creditHour,name);
        cout<<*temp<<endl;
    }*/
    ifile.close();
    cout<<"input student name"<<endl;
    char NAME[20];
    cin>>NAME;
    cout<<"input student birthday"<<endl;
    int nian,yue,ri;


    while(1)
    {
        try{
             cin>>nian>>yue>>ri;
            Date birthday(nian,yue,ri);
            break;
        }
        catch(MyException ex)
        {
            cout<<"ERRor£º"<<ex.what()<<"\n";
            cout<<"input again\n";
        }
    }
    cout<<"1.Student Information\n2.Add Course\n3.Remove Course\n4.setsorce\n5.single score\n6.Save Student Information\n0.exit"<<endl;
    string cz;
    student s(NAME,{nian,yue,ri});
    while(cin>>cz)
    {
       // cout<<cz.length();
        while(cin.fail() or cz.length()!=1 or !(cz[0]<='6' && cz[0]>='0' ))
        {
            cout<<"Error!The date's format is invalid! Please input again!"<<endl;
            cin.clear();
            cin.ignore();
            cin>>cz;
        }
        if(cz=="1")
        {
        cout<<s;
        cout<<"calaCredit:"<<s.calcCredit()<<endl;
        }
        else if(cz=="2")
        {
         s.choseclass();
        }
        else if (cz=="0") return 0;
        else if (cz=="3")
        {
            int tk;
            cin>>tk;
            if(s.removeCourse(tk))
                cout<<"OK"<<endl;
            else
                cout<<"wrong!"<<endl;
        }
        else if(cz=="4")
        {
            int tk;
            cout<<"input:course number"<<endl;
             while(1)
             {
                 try{
                    cin>>tk;
                    if(tk<=0 or tk>s.getCoursenumber()) throw MyException (RANGE_ERROR);
             break;}
             catch(MyException ex)
        {
            cout<<"ERRor£º"<<ex.what()<<"\n";
            cout<<"input again\n";
        }
             }
            if(s.setscore(tk))
                cout<<"YES"<<endl;
            else
                cout<<"WRONG!"<<endl;
        }
        else if(cz=="5")
        {
            int tk;
            cout<<"input:course number"<<endl;
            cin>>tk;
            if(tk<=s.getCoursenumber())
            cout<<s.courselist[tk-1]->getname()<<" "<<s.courselist[tk-1]->getscore()<<endl;
           // cout<<"1.Student Information\n2.Add Course\n3.Remove Course\n4.setsorce\n5.single score\n0.exit"<<endl;
        }
        else if(cz=="6")
        {
            ofile.open("outfile.txt");
            ofile<<s<<"gpa:"<<s.calcCredit();
            ofile.close();
        }
        cout<<"1.Student Information\n2.Add Course\n3.Remove Course\n4.setsorce\n5.single score\n6.Save Student Information\n0.exit"<<endl;
    }

}
