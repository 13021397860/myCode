#include "Interface.h"

Interface::Interface()
{
    char *n = new char[20];
    cout << "Please enter your name£º";
    cin >> n;

    Date b;
    b.getDate();

    s = new Student(n,b);
}

void Interface::menu()
{
    cout << "1.Select course     ";
    cout << "2.Add mark/grade     ";
    cout << "3.Remove course     ";
    cout << "4.Print" << endl;
    operate();
}

void Interface::operate()
{
    int i;
    cout << "Please enter the number of operation:";
    cin >> i;
    switch(i)
    {
    case 1:
        selectCourse();
        break;
    case 2:
        addMG();
        break;
    case 3:
        removeCourse();
        break;
    case 4:
        print();
        break;
    }
    operate();
}

void Interface::selectCourse()
{
    string cn;
    int c,f;
    cout << "1.Obligatory course  2.Elective course  3.Finish" << endl;
    cout << "You want to select:";
    while(cin >> f)
    {
        if(f == 1)
        {
            cout << "Please enter the name of course:";
            cin >> cn;
            cout << "Please enter the credit hour£º";
            cin >> c;
            s->addCourse(cn,c,1);
            cout << "You want to select:";
        }
        else if(f == 2)
        {
            cout << "Please enter the name of course:";
            cin >> cn;
            cout << "Please enter the credit hour£º";
            cin >> c;
            s->addCourse(cn,c,'A');
            cout << "You want to select:";
        }
        else
            break;
    }
}

void Interface::addMG()
{
    s->flag = 1;
    for(int i = 0; i < s->getCourseNumber(); i++)
    {
        Course *courseList = s->getCourseList(i);
        ObligatoryCourse *ob = dynamic_cast<ObligatoryCourse*>(courseList);
        if(ob != NULL)
        {
            cout << "\"" << courseList->getName() << "\"" << " is an Obligatory Course,please enter its mark: ";
            int mark;
            cin >> mark;
            string name = courseList->getName();
            int creditHour = courseList->getCreditHour();
            courseList->setCourse(name,creditHour,mark);
        }
        else
        {
            cout << "\"" << courseList->getName() << "\"" << " is an Elective Course,please enter its grade: ";
            char grade;
            cin >> grade;
            string name = courseList->getName();
            int creditHour = courseList->getCreditHour();
            courseList->setCourse(name,creditHour,grade);
        }
    }
}

void Interface::removeCourse()
{
    cout << "Please enter the number of course to remove:";
    int i;
    cin >> i;
    if(s->removeCourse(i))
        cout << "The course is removed" << endl;
    else
        cout << "Error£¡" << endl;
}

void Interface::print() const
{
    cout << *s;
}

Interface::~Interface()
{
    //dtor
}
