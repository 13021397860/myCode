#include "Console.h"
#include <cstdio>
#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;
Console::Console()
{
    student = NULL;
    ocNum = 0;
    ecNum = 0;
}

Console::~Console()
{
    delete student;
    for(int i = 0; i < ocNum; i++)
        delete oc[i];
    for(int i = 0; i < ecNum; i++)
        delete ec[i];
}

int Console::run()
{
    buildCourse();
    cout << "Welcome to use student course selection system!\n";
    buildStudent();
    int judge;
    while(1)
    {
        displayMenu();
        cin >> judge;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Wrong! Please input again.\n";
            cin >> judge;
        }
        switch(judge)
        {
            case 0: break;
            case 1: buildStudent();
                    break;
            case 2: selectCourse(1);
                    break;
            case 3: selectCourse(2);
                    break;
            case 4: setCourseScore();
                    break;
            case 5: cout << *student;
                    break;
            case 6: askforScore();
                    break;
            case 7: askforGPA();
                    break;
            case 8: if(save())
                        cout << "save successfully\n";
                    else
                        cout << "fail to save\n";
                    break;
            default : cout << "Wrong! Please input again.\n";
                    break;
        }
        if(judge == 0)
            break;
    }
    return 0;
}

int Console::askforScore()const
{
    student->askforScore();
}

int Console::askforGPA()const
{
    cout<< "GPA:" << student->calcCredit() << endl;
}

int Console::displayMenu()const
{
    cout << "Please input\n\"0\" to exit system \nor \"1\" to create a new student \nor \"2\" to select obligatory course \nor \"3\" to select elective course \nor \"4\" to set course score \nor \"5\" to show student's information\nor \"6\" to ask for score\nor \"7\" to ask for GPA\nor \"8\" to save the information of the student\n";
}

int Console::setObCourse(int id)
{
    if(cin.fail()||id > ocNum || id < 1)
    {
        cin.clear();
        cin.ignore();
        throw MyException(RANGE_ERROR);
    }
    student->addCourse(oc[id-1]);
}

int Console::setElCourse(int id)
{
    if(cin.fail()||id > ecNum || id < 1)
    {
        cin.clear();
        cin.ignore();
        throw MyException(RANGE_ERROR);
    }
    student->addCourse(ec[id-1]);
}

Course* Console::selectCourse(int op)
{
    int judge, id;
    if(op == 1)
    {
        string s;
        int h;
        cout << "obligatory course:\n";
        for(int i = 0; i < ocNum; i++)
        {
            oc[i]->getCourse(s,h);
            cout << "id:" << i+1 << " course name:" << s << " credit hour:" << h << "\n";
        }
        cout << "Input \"0\" to exit select obligatory course or input \"1\" and \"id\" to select obligatory course\n";
        for(int u = 0; u < 10; u++)
        {
            cin >> judge;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Wrong! Please input again.\n";
                cin >> judge;
            }
            switch(judge)
            {
                case 0: break;
                case 1: while(1)
                        {
                            cin >> id;
                            try{
                                setObCourse(id);
                                break;
                            }catch(MyException ex)
                            {
                                cout << "system error:" << ex.what() << "\nPlease input course id again\n";
                            }
                        }
                        break;
            }
            if(judge == 0)
                break;
        }
    }
    else if(op == 2)
    {
        string s;
        int h;
        cout << "elective course:\n";
        for(int i = 0; i < ecNum; i++)
        {
            ec[i]->getCourse(s, h);
            cout << "id:" << i+1 << " course name:" << s << " credit hour:" << h << "\n";
        }
        cout << "Input \"0\" to exit select elective course or input \"1\" and \"id\" to select elective course\n";
        for(int u = 0; u < 10; u++)
        {
            cin >> judge;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Wrong! Please input again.\n";
                cin >> judge;
            }
            switch(judge)
            {
                case 0: break;
                case 1:while(1)
                        {
                            cin >> id;
                            try{
                                setElCourse(id);
                                break;
                            }catch(MyException ex)
                            {
                                cout << "system error:" << ex.what() << "\nPlease input course id again\n";
                            }
                        }
                        break;
            }
            if(judge == 0)
                break;
        }
    }
}

bool Console::setCourseScore()
{
    student->setScore();
    return true;
}

bool Console::save()const
{
    char *c = new char(20);
    student->getName(c);
    strcpy(c+strlen(c), ".txt");
    ofstream outfile(c, ios::out|ios::app);
    if(!outfile) return false;
    outfile << *student << "GPA:" << student->calcCredit() << "\n";
    outfile.close();
    return true;
}

Console& Console::buildStudent()
{
    if(student)
        delete student;
    char n[20];
    int y, m, d;
    cout << "Please input name and birth date\n";
    cin >> n;
    while(1)
    {
        cin >> y >> m >> d;
        try{
            student = new Student(n, y, m, d);
            break;
        }catch(MyException ex)
        {
            cout << "system error:" << ex.what() << "\nPlease input birth date again\n";
        }
    }
    return *this;
}

Console& Console::buildCourse()
{
    string s;
    int h;
    ifstream infile("obligatorycourse.txt", ios::in);
    if(infile)
    {
        while(!infile.eof())
        {
            infile >> s >> h;
            oc[ocNum++] = new ObligatoryCourse(s, h);
        }
        infile.close();
    }
    infile.open("electivecourse.txt", ios::in);
    if(infile)
    {
        while(!infile.eof())
        {
            infile >> s >> h;
            ec[ecNum++] = new ElectiveCourse(s, h);
        }
        infile.close();
    }
    return *this;
}

