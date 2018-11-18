#include "console.h"
#include "student.h"
#include "obligatory_course.h"
#include "elective_course.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
using namespace std;
void Console::run()
{
    fstream ob_file("ObligatoryCourse.txt", ios::out);
    fstream ele_file("ElectiveCourse.txt", ios::out);
    ob_file << "Math" << ' ' << 5 << endl;
    ele_file << "Gym" << ' ' << 2 << endl;
    ob_file.close();
    ele_file.close();
    char name[50];
    string courseName;
    cout << "Please enter your name: ";
    cin >> name;
    int year, month, day, choice, len = 0, creditHour;
    cout << "Please enter your birth date(year/month/day): ";
    while (cin >> year >> month >> day)
    {
        try
        {
            date test(year, month, day);
        }
        catch(MyException ex)
        {
            cout << ex.what() << " Please enter again: ";
            continue;
        }
        break;
    }
    student x(name, year, month, day);
    showmenu();
    cin >> choice;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore();
    }
    Course * courseList[10];
    while (choice != 6)
    {
        if (choice == 1)
        {
            cout << "Enter 1 for obligatory courses, 2 for elective courses: ";
            cin >> choice;
            if (choice == 1)
            {
                ob_file.open("ObligatoryCourse.txt", ios::in);
                cout << "1) Math\n";
                cin >> choice;
                ob_file >> courseName;
                ob_file >> creditHour;
                ob_file.close();
                ObligatoryCourse * p = new ObligatoryCourse(courseName, creditHour);
                courseList[len] = p;
                x.addCourse(p);
                ++len;
            }
            else if (choice == 2)
            {
                ele_file.open("ElectiveCourse.txt", ios::in);
                cout << "1) Gym\n";
                cin >> choice;
                ele_file >> courseName;
                ele_file >> creditHour;
                ele_file.close();
                ElectiveCourse * p = new ElectiveCourse(courseName, creditHour);
                courseList[len] = p;
                x.addCourse(p);
                ++len;
            }
        }
        else if (choice == 2)
        {
            cout << "Enter the number of the course: ";
            while (cin >> choice)
            {
                try
                {
                    x.removeCourse(choice);
                }
                catch (MyException ex)
                {
                    cout << ex.what() << " Please enter again: ";
                    continue;
                }
                break;
            }
            for (int j = choice; j < len; ++j)
                courseList[j - 1] = courseList[j];
            --len;
        }
        else if (choice == 3)
            cout << x;
        else if (choice == 4)
        {
            cout << "Enter the number of course: ";
            cin >> choice;
            if (typeid(*courseList[choice - 1]) == typeid(ObligatoryCourse))
            {
                int score;
                ObligatoryCourse * p = dynamic_cast<ObligatoryCourse*>(courseList[choice - 1]);
                cout << "Score: ";
                while (cin >> score)
                {
                    try
                    {
                        p->setScore(score);
                    }
                    catch (MyException ex)
                    {
                        cout << ex.what() << " Please enter again: ";
                        continue;
                    }
                    break;
                }
                cin >> score;
                p->setScore(score);
            }
            else if (typeid(*courseList[choice - 1]) == typeid(ElectiveCourse))
            {
                char grade;
                cout << "Grade: ";
                ElectiveCourse * p = dynamic_cast<ElectiveCourse*>(courseList[choice - 1]);
                while (cin >> grade)
                {
                    try
                    {
                        p->setScore(grade);
                    }
                    catch (MyException ex)
                    {
                        cout << ex.what() << " Please enter again: ";
                        continue;
                    }
                    break;
                }
                cin >> grade;
                p->setScore(grade);
            }
        }
        else if (choice == 5)
        {
            for (int i = 0; i < len; ++i)
                cout << '(' << i + 1 << ')' << *courseList[i] << endl;
            cout << "Credit:" << x.calcCredit() << endl;
        }
        showmenu();
        cin >> choice;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cin >> choice;
        }
    }
    ofstream out("student.txt", ios::out);
    out << x;
    out.close();
    cout << "Bye!";
}
void Console::showmenu()
{
    cout << "\nPlease enter 1, 2, 3, 4, 5 or 6:\n"
            "1)choose course         2)drop course\n"
            "3)query info            4)set grade\n"
            "5)query grade           6)quit\n";
}
