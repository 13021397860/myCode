#include "Console.h"

Console::Console()
{
    ocNum=ecNum=0;
}

Console& Console::buildCourse()
{
    ifstream f;
    char data[100], ch[10];
    bool sto=false, ste=false;
    f.open("information about course.txt");
    while(!f.eof()){
        f.getline(data,100);
        if (!strcmp(data, "ObligatoryCourse")) {sto=true;ste=false;f.getline(data, 100);}
        else if (!strcmp(data, "ElectiveCourse")) {sto=false;ste=true;f.getline(data, 100);}
        if (sto){
            f.getline(ch, 10);
            oc[++ocNum]=new ObligatoryCourse(data, ch[0]-48);
        }
        else if (ste){
            f.getline(ch, 10);
            ec[++ecNum]=new ElectiveCourse(data, ch[0]-48);
        }
    }
    f.close();
    return *this;
}

Console& Console::buildStudent()
{
    int y, m, d;
    char n[15];

    cout << "Please input the student's name: ";
    cin >> n;
    while (1){
        try{
            cout << "Please input the student's birthday: ";
            cin >> y >> m >> d;
            stu=new Student(n, y, m, d);
            break;
        }
        catch(MyException ex){
            cout << "\nException:" << ex.what() << endl;
        }
    }
}

void Console::mainMenu()
{
    system("cls");
    cout << "\n-------------------------------------------------------------------" << endl;
    cout << "\n\n**********  Courses Selected System - Main Menu  **********\n";
    cout << "        1. Obligatory course\n";
    cout << "        2. Elective course\n";
    cout << "        3. Information about the course selected\n";
    cout << "        4. Set up grades\n";
    cout << "        5. Drop course\n";
    cout << "        6. expose the information to a file\n";
    cout << "        0. Withdrawal\n";
    cout << "Please input your operation(0~6): ";
    cin >> inp;
    if (cin.fail()){
        cin.clear();
        cin.ignore();
        inp=-1;
    }
    while (inp < 0 || inp > 6){
        cout << "\nInvalid choice, try again:";
        cin >> inp;
        if (cin.fail()){
            cin.clear();
            cin.ignore();
            inp=-1;
        }
    }

    cout << endl;
}

void Console::obCourse()
{
    for (int i=1; i<=ocNum; i++)
        cout << "        "<< i <<".Course name: " << oc[i]->getName() << "    Credit hour: " << oc[i]->getCreditHour() << endl;
    cout << "        0.Back\n";
    cout << "Please input order number of the course that you want: ";
    cin >> inp1;
    if (inp1<0 || inp1>ocNum) throw MyException("Out of range.\n");

    if (inp1==0) return ;
    else {
        if (stu->selected(oc[inp1]))
        {
            stu->addCourse(oc[inp1]);
            cout << "You have selected " << oc[inp1]->getName() << " successfully!\n";
        }
        else cout << "You have selected this course!\n";
    }
}

void Console::elCourse()
{
    for (int i=1; i<=ecNum; i++)
        cout << "        "<< i <<".Course name: " << ec[i]->getName() << "    Credit hour: " << ec[i]->getCreditHour() << endl;
    cout << "        0.Back\n";
    cout << "Please input order number of the course that you want: ";
    cin >> inp2;

    if (inp2<0 || inp2>ecNum) throw MyException("Out of range.\n");

    if (inp2==0) return ;
    else {
        if (stu->selected(ec[inp2]))
            {
                stu->addCourse(ec[inp2]);
                cout << "You have selected " << ec[inp2]->getName() << " successfully!\n";
            }
        else cout << "You have selected this course!\n";
    }
}

void Console::setGrade()
{
    if (stu->getCourseNumber()==0) printf("You have not selected any course!\n");
    else {
        cout << "Course List:\n";
        stu->printCourse();
        cout << "0.Back\n";
        cout << "Please input the order number of the course you want to set: ";
        cin >> inp4;

        if (inp4<0 || inp4>stu->getCourseNumber()) throw MyException("Out of range.\n");

        if (inp4==0) return ;
        else {
            while (1){
                try {stu->setGrade(inp4);break;}
                catch(MyException ex){
                    cout << "\nException:" << ex.what() << endl;
                }
            }
        }
    }
}

void Console::remCourse()
{
    if (stu->getCourseNumber()==0) printf("You have not selected any course!\n");
    else {
        cout << "Course List:\n";
        stu->printCourse();
        cout << "0.Back\n";
        cout << "Please input the order number of the course that you need to drop: ";
        cin >> inp5;

        if (inp5<0 || inp5>stu->getCourseNumber()) throw MyException("Out of range.\n");

        if (inp5==0) return ;
        else if (stu->removeCourse(inp5))
            cout << "You have removed the course successfully!\n";
    }
}

void Console::expose()
{
    ofstream of;
    of.open("information of the student.txt");
    of << *stu << endl;
    of.close();
    cout << "You have exposed the information successfully!" << endl;
}

void Console::run()
{
    this->buildCourse();
    this->buildStudent();

    while (1){
        this->mainMenu();

        switch(inp){
            case 0:{return ;}
            case 1:{
                while (1){
                    try {this->obCourse();break;}
                    catch(MyException ex){
                        cout << "\nException:" << ex.what() << endl;
                    }
                }
                break;
            }
            case 2:{
                while (1){
                    try {this->elCourse();break;}
                    catch(MyException ex){
                        cout << "\nException:" << ex.what() << endl;
                    }
                }
                break;
            }
            case 3:{cout << *stu;break;}
            case 4:{
                while (1){
                    try {this->setGrade();break;}
                    catch(MyException ex){
                        cout << "\nException:" << ex.what() << endl;
                    }
                }
                break;
            }
            case 5:{
                while (1){
                    try {this->remCourse();break;}
                    catch(MyException ex){
                        cout << "\nException:" << ex.what() << endl;
                    }
                }
                break;
            }
            case 6:{this->expose();break;}
            default:break;
        }

        cout << "\nPlease input any key to continue.";
        ch=getch();
    }
}

Console::~Console()
{
    delete stu;
    for(int i=1; i<=ocNum; i++) delete oc[i];
    for(int i=1; i<=ecNum; i++) delete ec[i];
}
