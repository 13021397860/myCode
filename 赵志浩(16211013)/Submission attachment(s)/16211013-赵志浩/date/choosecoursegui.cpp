#include "choosecoursegui.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <typeinfo>
#include <sstream>
#include <climits>
using namespace std;
ChooseCourseGUI::ChooseCourseGUI()
{
    this->is_Course_Loaded=false;
}
bool ChooseCourseGUI::judgeCin()
{
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        throw MyException(InputError);
        return false;
    }
    return true;
}
void ChooseCourseGUI::loadCourse()
{
    fstream ofile,efile;
    ofile.open("obligatorycourse.txt",ios::in);
    efile.open("electivecourse.txt",ios::in);
    if(ofile.bad()||efile.bad())
    {
        cerr<<"File is fail to open"<<endl;
        return;
    }
    string name;int cre,cnt=0;
    while(!ofile.eof())
    {
        ofile>>name;
        ofile>>cre;
        ObligatoryCourseList.push_back(ObligatoryCourse(name,cre));

    }
    while(!efile.eof())
    {
        efile>>name;
        efile>>cre;
        ElectiveCourseList.push_back(ElectiveCourse(name,cre));
    }
    is_Course_Loaded=true;
}
void ChooseCourseGUI::addCourse(student &s)
{
    if(!is_Course_Loaded)
        loadCourse();
    cout<<"ObligatoryCourses are:"<<endl;
    for (int i=0;i<ObligatoryCourseList.size();i++)
        cout<<"class "<<i+1<<":"<<ObligatoryCourseList[i]<<endl;
    cout<<endl<<"ElectiveCourses are:"<<endl;
    for (int i=0;i<ElectiveCourseList.size();i++)
        cout<<"class "<<i+1<<":"<<ElectiveCourseList[i]<<endl;
    cout<<endl;
    int cmd=0;bool flag=true;
    while(flag)
    {
        cout<<"input 1 to choose obligatory course"<<endl;
        cout<<"input 2 to choose elective course"<<endl;
        cin>>cmd;
        try
        {
            if(judgeCin())
            {
                int num;
                cout<<"please input the number of the class"<<endl;
                cin>>num;
                if(judgeCin())
                {
                    switch (cmd)
                    {
                        case 1 :
                        {
                            if(num>ObligatoryCourseList.size()) throw MyException(OutOfRange);
                            else
                            {
                                s.addObligatoryCourse(ObligatoryCourseList[num-1].getName(),ObligatoryCourseList[num-1].getCredictHour());
                                vector <ObligatoryCourse>::iterator it=ObligatoryCourseList.begin()+num-1;
                                ObligatoryCourseList.erase(it);
                                flag=false;
                                cout<<"succeed to add course"<<endl;
                            }
                            break;
                        }
                        case 2 :
                        {
                            if(num>ElectiveCourseList.size()) throw MyException(OutOfRange);
                            else
                            {
                                s.addElectiveCourse(ElectiveCourseList[num-1].getName(),ElectiveCourseList[num-1].getCredictHour());
                                vector <ElectiveCourse>::iterator it=ElectiveCourseList.begin()+num-1;
                                ElectiveCourseList.erase(it);
                                flag=false;
                                cout<<"succeed to add course"<<endl;
                            }
                            break;
                        }
                        default:
                            throw MyException(OutOfRange);
                    }
                }
            }
        }
        catch(MyException &ex)
        {
            cout<<ex.what()<<endl;
        }
    }
}
void ChooseCourseGUI::showCourse(student &s)
{
    cout<<s;
    int tmp;bool flag=true;
    while(flag)
    {
        cout<<"input 1 to remove course"<<endl<<"input 2 to change the name of student"<<endl<<"input 3 to change the birth date"<<endl;
        cout<<"input 4 to set score for course"<<endl<<"input 5 to exit"<<endl;
        cin>>tmp;
        try
        {
            if(judgeCin())
                switch (tmp)
                {
                    case 1:
                    {
                        int re;
                        cout<<s<<endl;
                        cout<<"please input which number of course do you want to remove, input -1 to exit"<<endl;
                        cin>>re;
                        if(judgeCin())
                        {
                            if(re==-1)
                            {}
                            else if(s.removeCourse(re))
                                cout<<"remove successfully"<<endl;
                            else
                                throw MyException(OutOfRange);
                        }
                        break;
                    }
                    case 2:
                    {
                        string nam;
                        cout<<"please input the name"<<endl;
                        cin>>nam;
                        s.setName(nam);
                        break;
                    }
                    case 3:
                    {
                        int y,m,d;
                        cout<<"please input the year,month and day"<<endl;
                        cin>>y>>m>>d;
                        if(judgeCin())
                            if(!s.setBirthDate(m,d,y))
                                throw MyException(InvalidDate);
                        break;
                    }
                    case 4:
                    {
                        int re;
                        cout<<"please input which number of course do you want to add score, input -1 to exit"<<endl;
                        cin>>re;
                        if(re==-1){}
                        else if(re>s.getCourseNumber())
                            throw MyException(OutOfRange);
                        else
                        {
                            cout<<"please input the score"<<endl;
                            int sc;
                            cin>>sc;
                            if(judgeCin())
                                if(!s.setScore(re,sc))
                                    throw(InvalidScore);
                        }
                    }
                    case 5:
                    {
                        flag=false;
                        break;
                    }
                    default:
                        throw MyException(OutOfRange);
                }
            fstream file;
            file.open("student.txt",ios::trunc|ios::out);
            if(file.is_open())
            {
                file<<s;
                file.close();
            }
            cout<<s<<endl;
        }
        catch(MyException &ex)
        {
            cout<<ex.what()<<endl;
        }
    }
}
void ChooseCourseGUI::cmd(student &s)
{
    int tmp;
    while (1)
    {
        cout<<"input 1 to see or edit the information of student"<<endl;
        cout<<"input 2 to add course"<<endl;
        cout<<"input 3 to exit"<<endl;
        cin>>tmp;
        try
        {
            if(judgeCin())
                switch (tmp)
                {
                    case 1:
                    {
                        showCourse(s);
                        break;
                    }
                    case 2:
                    {
                        addCourse(s);
                        break;
                    }
                    case 3:
                    {
                        exit(0);
                        break;
                    }
                    default:
                    {
                        throw MyException(OutOfRange);
                        break;
                    }
                }
        }
        catch(MyException &ex)
        {
            cout<<ex.what()<<endl;
        }
    }
}
ChooseCourseGUI::~ChooseCourseGUI()
{
    //dtor
}
