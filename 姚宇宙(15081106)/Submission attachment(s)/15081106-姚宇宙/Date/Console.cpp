#include "Console.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <iomanip>
#include "Student.h"
#include "MyException.h"

using namespace std;

Console::Console()
{
    s = NULL;
    courseNum = 0;
}

Console::Console(Student &_s)
{
    s = &_s;
    courseNum = 0;
}

Console::~Console()
{
    //dtor
}

void Console::runInstance()
{
    if(!s)
    {
        cout << "No student selected!" << endl;
        return;
    }
    int operationNum;
    ifstream infile;
    infile.open("Course.txt");
    while(getline(infile, className[courseNum]))
    {
        (infile >> creditHour[courseNum] >> isObligatory[courseNum]).get();
        courseNum++;
    }
    infile.close();

    displayWelcomeInfor();
    cout << endl;

    while(1)
    {
        cout << "Enter the option: ";
        cin >> operationNum;
        if(!cin.good() or operationNum < 0 or operationNum > 7)
        {
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        try
        {
            if(operationNum == 0) break;
            else if(operationNum == 1) cout << *s;
            else if(operationNum == 2) selectCourse();
            else if(operationNum == 3) setCourseScore();
            else if(operationNum == 4) getStudentCredit();
            else if(operationNum == 5) writeStudentInformation();
            else if(operationNum == 6) editStudentInformation();
            else if(operationNum == 7) removeCourse();
            cout << endl;
        }
        catch(MyException e)
        {
            cout << "### Exception: " << e.what() << "! ###" << endl;
        }
    }
}

void Console::displayWelcomeInfor()
{
    cout << "Welcome! Please enter number" << endl;
    cout << "1 for student information," << endl;
    cout << "2 for adding a class," << endl;
    cout << "3 for editing the score of a class," << endl;
    cout << "4 for showing the credit score of the student," << endl;
    cout << "5 for writing the student information," << endl;
    cout << "6 for editing the student information," << endl;
    cout << "7 for removing a class of the student," << endl;
    cout << "or 0 to exit the program." << endl;
}

void Console::selectCourse()
{
    /*cout << "Enter 1 for obligatory class, or 2 for elective one: ";
    (cin >> j).get();
    cout << "Enter the class name: " ;
    getline(cin, classname);
    cout << "Enter the credit hour of the class: ";
    cin >> credithour;
    if(j == 1) s -> addCourse(classname, credithour, true);
    else s -> addCourse(classname, credithour, false);*/
    int i;
    cout << "Select a course from the list below:" << endl;
    for(i = 0; i < courseNum; i++)
    {
        cout << "#" << i + 1 << " " << left << setw(32) << className[i] << " " << creditHour[i] << "   " << (isObligatory[i] ? "Yes" : "No") << endl;
    }
    cout << "Enter the course code: " << endl;
    cin >> i;
    if(i < 1 or i > courseNum) throw MyException("class not existed in the list");
    else
    {
        s -> addCourse(className[i - 1], creditHour[i - 1], isObligatory[i - 1]);
        cout << "Successful!" << endl;
    }
}

void Console::setCourseScore()
{
    if(!s -> getCourseNumber())
    {
        cout << "No class to operate!" << endl;
        return;
    }
    int i, j;
    cout << s -> getCourseNumber() << " classes in total:" << endl;
    s -> printCourseList();
    for(i = 0; i < s -> getCourseNumber(); i++)
    {
        cout << "Enter the score for class #" << i + 1 << ": ";
        cin >> j;
        s -> setCourseScore(i + 1, j);
        cout << "Successful!" << endl;
    }
}

void Console::buildStudent(Student &_s)
{
    s = &_s;
}

void Console::getStudentCredit() const
{
    cout << "Student " << s -> getName() << "'s credit score is " << s -> calcCredit() << "." << endl;
}

void Console::writeStudentInformation()
{
    ofstream outfile;
    outfile.open("Student.txt");
    if(!outfile) cout << "Failed!" << endl;
    else
    {
        outfile << *s;
        cout << "Successful!" << endl;
    }
    outfile.close();
}

void Console::editStudentInformation()
{
    int y, m, d;
    cout << "Please input the birthday of " << s -> getName() << endl;
    cout << "Year: ";
    cin >> y;
    cout << "Month: ";
    cin >> m;
    cout << "Day: ";
    cin >> d;
    s -> setBirthDate(y, m, d);
}

void Console::removeCourse()
{
    int i;
    cout << *s;
    cout << "Please input the number of the course to be removed: ";
    cin >> i;
    s -> removeCourse(i);
}

