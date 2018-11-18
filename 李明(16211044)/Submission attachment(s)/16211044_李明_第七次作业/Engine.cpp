#include "Engine.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <typeinfo>
#include <string>
#include <windows.h>
//#include <conio.h>
//#include <wchar.h>
//#include <locale.h>

#define NONE    0
#define STUDENT 1
#define TEACHER 2

#define QUIT    0
#define SELECT  1
#define REMOVE  2
#define GPA     3

using namespace std;

Engine::Engine()
{
    cout << "loading..." << endl;
    Sleep(1000);

    isEnd = false;
    studentList = NULL;
    studentNumber = 0;
    OC = NULL;
    OCNumber = 0;
    EC = NULL;
    ECNumber = 0;

/*--------------------------------------------------------------------------------------
------------------------------开始文件输入----------------------------------------------
---------------------------------------------------------------------------------------*/
    ifstream* inOC = new ifstream("ObligatoryCourseList.txt", ios::in);
    ifstream* inEC = new ifstream("ElectiveCourseList.txt", ios::in);
    //ifstream* inStu = new ifstream("StudentList.txt", ios::in);
    string opr;
    string name;
    Date date;
    int hour;
    int score;
    char grade;
    int i;

    *inOC >> OCNumber;
    if(OCNumber != NONE)
    {
        OC = new ObligatoryCourse* [OCNumber];
    }
    i = 0;
    while(*inOC >> opr)
    {
        if(opr == "Course")
        {
            *inOC >> opr;
            *inOC >> name;
        }
        else if(opr == "Credit")
        {
            *inOC >> opr;
            *inOC >> hour;
            OC[i++] = new ObligatoryCourse(name,hour);
            cout << "course loaded" << endl;
        }
        else
        {
            name += " " + opr;
        }
    }
    OCNumber = i;

    *inEC >> ECNumber;
    if(ECNumber != NONE)
    {
        EC = new ElectiveCourse* [ECNumber];
    }
    i = 0;
    while(*inEC >> opr)
    {
        if(opr == "Course")
        {
            *inEC >> opr;
            *inEC >> name;
        }
        else if(opr == "Credit")
        {
            *inEC >> opr;
            *inEC >> hour;
            EC[i++] = new ElectiveCourse(name,hour);
            cout << "course loaded" << endl;
        }
        else
        {
            name += " " + opr;
        }
    }
    ECNumber = i;

//    *inStu >> studentNumber;
//    if(studentNumber != NONE)
//    {
        studentList = new Student* [studentNumber+10];
//    }
//    i = 0;
//    while(*inStu >> opr)
//    {
//        if(opr == "Name:")
//        {
//            *inStu >> name;
//            while(*inStu >> opr)
//            {
//                if(opr == "Birthday:")
//                {
//                    *inStu >> date;
//                    studentList[i] = new Student(name.c_str(),date);
//                    *inStu >> opr; // "Selected"
//                    break;
//                }
//                else
//                {
//                    name += " " + opr;
//                }
//            }
//        }
//        if(opr == "Selected")
//        {
//            *inStu >> opr; // "lesson:"
//            *inStu >> opr;
//            if(opr != "None")
//            {
//                while(*inStu >> opr)
//                {
//                    if(opr == "END")
//                    {
//                        break;
//                    }
//                    else if(opr == "Course")
//                    {
//                        *inStu >> opr; // "name:"
//                        *inStu >> name;
//                    }
//                    else if(opr == "Credit")
//                    {
//                        *inStu >> opr; // "hour:"
//                        *inStu >> hour;
//                    }
//                    else if(opr == "Score:")
//                    {
//                        *inStu >> score;
//                        *inStu >> opr;
//                        if(opr == "OC")
//                        {
//                            studentList[i]->addCourse(new ObligatoryCourse(name,hour,score));
//                        }
//                        else
//                        {
//                            switch(score)
//                            {
//                            case 95:
//                                grade = 'A';
//                                break;
//                            case 85:
//                                grade = 'B';
//                                break;
//                            case 75:
//                                grade = 'C';
//                                break;
//                            case 65:
//                                grade = 'D';
//                                break;
//                            case 55:
//                                grade = 'E';
//                                break;
//                            }
//                            studentList[i]->addCourse(new ElectiveCourse(name,hour,grade));
//                        }
//                        break;
//                    }
//                    else
//                    {
//                        name += " " + opr;
//                    }
//                }
//            }
//        }
//        *inStu >> opr; // a number
//        ++i;
//        cout << "student loaded" << endl;
//    }
//    studentNumber = i;

    inOC->close();
    inEC->close();
    //inStu->close();

    delete inOC;
    delete inEC;
    //delete inStu;
/*--------------------------------------------------------------------------------------
------------------------------结束文件输入----------------------------------------------
---------------------------------------------------------------------------------------*/

    cout << "System start!" << endl;
    Sleep(1000);
}

Engine::~Engine()
{
    system("cls");

/*--------------------------------------------------------------------------------------
------------------------------开始文件输出----------------------------------------------
---------------------------------------------------------------------------------------*/
    ofstream* outOC = new ofstream("ObligatoryCourseList.txt", ios::out|ios::ate);
    ofstream* outEC = new ofstream("ElectiveCourseList.txt", ios::out|ios::ate);
    ofstream* outStu = new ofstream("StudentList.txt", ios::out|ios::ate);

    *outOC << OCNumber << endl;
    for(int i = 0; i < OCNumber; ++i)
    {
        *outOC << *OC[i] << endl;
    }
    *outEC << ECNumber << endl;
    for(int i = 0; i < ECNumber; ++i)
    {
        *outEC << *EC[i] << endl;
    }
    *outStu << studentNumber << endl;
    for(int i = 0; i < studentNumber; ++i)
    {
        *outStu << *studentList[i] << endl;
        *outStu << "END " << i+1 << endl << endl;
    }

    outOC->close();
    outEC->close();
    outStu->close();

    delete outOC;
    delete outEC;
    delete outStu;
/*--------------------------------------------------------------------------------------
------------------------------结束文件输出----------------------------------------------
---------------------------------------------------------------------------------------*/

    delete studentList;
    delete OC;
    delete EC;
    cout << "System shutdown!" << endl;;
}

bool Engine::exit() const
{
    return isEnd;
}

void Engine::start()
{
    int userID;
    do
    {
        system("cls");
        cin.sync();
        cout << "Please choose a entrance" << endl
            << "1    student" << endl
            << "2    teacher" << endl
            << "0    quit system" << endl;
        try
        {
//------------------------start try----------------------------
        cin >> userID;
        while(cin.fail())
        {
            cin.clear();
            cin.sync();
            cout << "Wrong input!" << endl;
            cin >> userID;
        }
        switch(userID)
        {
        case STUDENT:
            studentMenu(NULL);
            break;
        case TEACHER:
            teacherMenu();
            break;
        case NONE:
            isEnd = true;
            break;
        default:
            throw Option_NonExistent_Exception();
            break;
        }
//---------------------------end try--------------------------
        }
        catch(Exception& e)
        {
            cout << e.what() << endl;
            Sleep(1000);
        }
    }while(userID != NONE);
}

void Engine::studentMenu(Student* stu)
{
    system("cls");
    cin.sync();
    cout << "Welcome to student system" << endl;

    int student;
    cout << "Choose a student to login or input 1 to create a NEW student" << endl;
    cout << "1    NEW student" << endl;
    for(int i = 0; i < studentNumber; ++i)
    {
        cout << i+2 << "    " << studentList[i]->getName() << endl;
    }
    cout << "0    quit" << endl;
    do
    {
        cin.sync();
        try
        {
//------------------------start try----------------------------
        cin >> student;
        while(cin.fail())
        {
            cin.clear();
            cin.sync();
            cout << "Wrong input!" << endl;
            cin >> student;
        }
        if(student == QUIT)
        {
            return;
        }
        else if(student == 1)
        {
            stu = createStudent();
            break;
        }
        else if(student > studentNumber)
        {
            throw Student_NonExistent_Exception();
        }
        else
        {
            stu = studentList[student-1];
            break;
        }
//---------------------------end try--------------------------
        }
        catch(Exception& e)
        {
            cout << "Login in failed:" << e.what() << endl;
            Sleep(1000);
        }
    }while(true);
    cout << "Login successfully!" << endl;

    int opreation;
    do
    {
        system("cls");
        cin.sync();
        cout << *stu << endl;
        cout << "what do you want to do?" << endl
            << "1    select lesson" << endl
            << "2    remove lesson" << endl
            << "3    get GPA" << endl
            << "0    quit student system" << endl;
        try
        {
//------------------------start try----------------------------
        cin >> opreation;
        while(cin.fail())
        {
            cin.clear();
            cin.sync();
            cout << "Wrong input!" << endl;
            cin >> opreation;
        }
        switch(opreation)
        {
        case SELECT:
            selectCourse(stu);
            break;
        case REMOVE:
            removeCourse(stu);
            break;
        case GPA:
            calcCredit(stu);
        case QUIT:
            break;
        default:
            throw Option_NonExistent_Exception();
            break;
        }
//---------------------------end try--------------------------
        }
        catch(Exception& e)
        {
            cout << e.what() << endl;
            Sleep(1000);
        }
    }while(opreation != QUIT);
}

void Engine::teacherMenu()
{
    system("cls");
    cin.sync();
    int no;
    int course;
    int mark;
    char grade;
    Student* stu;
    cout << "Score setting system" << endl;
    if(studentNumber != 0)
    {
        for(int i = 0; i < studentNumber; ++i)
        {
            cout << i+1 << "    " << studentList[i]->getName() << endl;
        }
        do
        {
            cin.sync();
            cout << "Input a number to select the student (Input 0 to quit)" << endl;
            cin >> no;
            while(cin.fail())
            {
                cin.clear();
                cin.sync();
                cout << "Wrong input!" << endl;
                cin >> no;
            }
            if(no == QUIT)
            {
                break;
            }
            if(no > studentNumber)
            {
                cout << "Wrong input!" << endl;
                cin.sync();
            }
            else
            {
                stu = studentList[no-1];
                do
                {
                    cin.sync();
                    system("cls");
                    cout << *stu << endl
                        << "     GPA: " << stu->calcCredit() << endl;
                    cout << "Select a lesson whose score you want to set (Input 0 to quit)" << endl;
                    try
                    {
//------------------------start try------------------------------------------------------------
                    cin >> course;
                    while(cin.fail())
                    {
                        cin.clear();
                        cin.sync();
                        cout << "Wrong input!" << endl;
                        cin >> course;
                    }
                    if(course != QUIT)
                    {
                        if(course > stu->getCourseNumber())
                        {
                            throw Student_NonExistent_Exception();
                        }
                        else
                        {
                            if(typeid(ObligatoryCourse&) == typeid(*stu->courseList[course-1]))
                            {
                                cout << "It's an obligatory course, its score should be in the range (0 ~ 100)" << endl;
                                cout << "The score is : " << endl;
                                cin >> mark;
                                while(cin.fail())
                                {
                                    cin.clear();
                                    cin.sync();
                                    cout << "Wrong input!" << endl;
                                    cin >> mark;
                                }
                                if((dynamic_cast<ObligatoryCourse*>(stu->courseList[course-1]))->setMark(mark))
                                {
                                    cout << "Successfully!" << endl;
                                }
                            }
                            else
                            {
                                cout << "It's an elective course, its score should be in the range (A,B,C,D,E)" << endl;
                                cout << "The score is : " << endl;
                                cin >> grade;
                                while(cin.fail())
                                {
                                    cin.clear();
                                    cin.sync();
                                    cout << "Wrong input!" << endl;
                                    cin >> grade;
                                }
                                if((dynamic_cast<ElectiveCourse*>(stu->courseList[course-1]))->setGrade(grade))
                                {
                                    cout << "Successfully!" << endl;
                                }
                            }
                        }
                    }
//----------------------------------end try-----------------------------------------------------------
                    }
                    catch(Exception& e)
                    {
                        cout << "Failed:" << e.what() << endl;
                        Sleep(1000);
                    }
                }while(course != QUIT);
            }
        }while(no != QUIT);
    }
    else
    {
        cout << "No student. Please input anything to quit" << endl;
        cin.get();
    }
}

Student* Engine::createStudent()
{
    cin.sync();
    char* nawa = new char[100];
    Date* birthday = new Date;

    cout << "Name: ";
    cin >> nawa;
    bool completed = false;
    while(!completed)
    {
        try
        {
        completed = true;
        cin.sync();
        cout << "Birthday (for example, 1998-1-8) : ";
        cin >> *birthday;

        }
        catch(Exception& e)
        {
            completed = false;
            cout << e.what() << "  Please input birthday again!"<< endl;
        }
    }

    studentList[studentNumber] = new Student(nawa,*birthday);

    delete nawa;
    delete birthday;

    return studentList[studentNumber++];
}

Student* Engine::selectCourse(Student* stu)
{
    int type;
    do
    {
        system("cls");
        cin.sync();
        cout << "1    Obligatory course" << endl
            << "2    Elective course" << endl
            << "0    quit" << endl;

        try
        {
//-----------------------------------------------------------------------------------
        cin >> type;
        while(cin.fail())
        {
            cin.clear();
            cin.sync();
            cout << "Wrong input!" << endl;
            cin >> type;
        }
        switch(type)
        {
        case 1:
            {
                system("cls");
                for(int i = 0; i < OCNumber; ++i)
                {
                    cout << i+1 << "    " << *OC[i] << endl;
                }
                cout << "Input the number before the course you want to select (0 to quit)" << endl;
                int no;
                do
                {
                    cin.sync();
                    try
                    {
//---------------------------------------------------------------------------
                    cin >> no;
                    while(cin.fail())
                    {
                        cin.clear();
                        cin.sync();
                        cout << "Wrong input!" << endl;
                        cin >> no;
                    }
                    if(no == QUIT)
                    {
                        break;
                    }
                    else if(no > OCNumber || no < 0)
                    {
                        throw Option_NonExistent_Exception();
                    }
                    else
                    {
                        stu->addCourse(new ObligatoryCourse(*OC[no-1]));
                        cout << "Select successfully" << endl;
                    }
//-----------------------------------------------------------------------------
                    }
                    catch(Exception& e)
                    {
                        cout << e.what() << endl;
                    }
                }while(no != QUIT);
            }
            break;
        case 2:
            {
                system("cls");
                cin.sync();
                for(int i = 0; i < ECNumber; ++i)
                {
                    cout << i+1 << "    " << *EC[i]<< endl;
                }
                cout << "Input the number before the course you want to select (0 to quit)" << endl;
                int no;
                do
                {
                    cin.sync();
                    try
                    {
//---------------------------------------------------------------------------
                    cin >> no;
                    while(cin.fail())
                    {
                        cin.clear();
                        cin.sync();
                        cout << "Wrong input!" << endl;
                        cin >> no;
                    }
                    if(no == QUIT)
                    {
                        break;
                    }
                    else if(no > ECNumber || no < 0)
                    {
                        throw Option_NonExistent_Exception();
                    }
                    else
                    {
                        stu->addCourse(new ElectiveCourse(*EC[no-1]));
                        cout << "Select successfully" << endl;
                    }
//-----------------------------------------------------------------------------
                    }
                    catch(Exception& e)
                    {
                        cout << e.what() << endl;
                    }
                }while(no != QUIT);
            }
            break;
        case QUIT:
            break;
        default:
            throw Option_NonExistent_Exception();
            break;
        }
//------------------------------------------------------------------------------------------------------
        }
        catch(Exception& e)
        {
            cout << e.what() << endl;
            Sleep(1000);
        }
    }while(type != QUIT);
    return stu;
}

Student* Engine::removeCourse(Student* stu)
{
    system("cls");
    cin.sync();

    int no;
    do
    {
        system("cls");
        cin.sync();
        cout << *stu << endl;
        cout << "Input the number before the course you want to remove (input 0 to quit)" << endl;
        try
        {
//--------------------------------------------------------------------------------
        cin >> no;
        while(cin.fail())
        {
            cin.clear();
            cin.sync();
            cout << "Wrong input!" << endl;
            cin >> no;
        }
        if(no == QUIT)
        {
            break;
        }
        if(stu->removeCourse(no))
        {
            cout << "Remove successfully!" << endl;
        }
//-------------------------------------------------------------------------------------
        }
        catch(Course_List_Empty_Exception& e)
        {
            cout << "Remove failed: " << e.what() << endl;
        }
        Sleep(1000);
    }while(no != QUIT);

    return stu;
}

Student* Engine::calcCredit(Student* stu)
{
    cout << "your GPA is: " << stu->calcCredit() << endl;
    Sleep(2000);
    return stu;
}
