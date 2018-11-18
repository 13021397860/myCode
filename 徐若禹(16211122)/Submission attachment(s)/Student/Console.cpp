#include "Console.h"

Console::Console()
{
    char *n = new char[20];
    cout << "Please enter your name£º";
    cin >> n;

    Date b;
    int y,m,d,f = 0;
    cout << "Please enter your birthday£¨year month day£©£º";
    while(f == 0)
    {
        try
        {
            cin >> y >> m >> d;
            if(b.checkDate(y,m,d))
            {
                b.setDate(y,m,d);
                f = 1;
            }
            else
            {
                throw MyException("Wrong date!Please enter again:");
            }
        }
        catch(MyException &e)
        {
            e.what();
        }
    }
    s = new Student(n,b);
}

void Console::menu()
{
    cout << "1.Select course     ";
    cout << "2.Add mark/grade     ";
    cout << "3.Remove course     ";
    cout << "4.Query score     ";
    cout << "5.Query GPA     ";
    cout << "6.Print     ";
    cout << "7.Save" << endl;
    loadCourse();
    operate();
}

void Console::operate()
{
    int i;
    cout << "Please enter the number of operation:";
    cin >> i;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore();
        cout << "Wrong!Please enter again!" << endl;
        operate();
    }
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
        queryScore();
        break;
    case 5:
        queryCalcCredit();
        break;
    case 6:
        print();
        break;
    case 7:
        save();
        break;
    default:
        cout << "Wrong!Please enter again!!" << endl;
        break;
    }
    operate();
}

void Console::loadCourse()
{
    char fileName[] = "Course.txt";
    ifstream ifile(fileName);
    int tag,credit;
    string cName;
    ocNum = ecNum = 0;
    if(!ifile)
    {
        cerr << "The list of course can't be find!" << endl;
        operate();
    }
    else
    {
        while(ifile >> tag >> cName >> credit)
        {
            if(tag == 1)
                oc[ocNum++] = new ObligatoryCourse(cName,credit,0);
            else
                ec[ecNum++] = new ElectiveCourse(cName,credit,'A');
        }
        ifile.close();
    }
}

void Console::selectCourse()
{
    string cn;
    int c,f;
    cout << "1.Obligatory course  2.Elective course  3.Finish" << endl;
    cout << "You want to select:";
    cin >> f;
    if(cin.fail() || f <= 0 || f >= 4)
    {
        cin.clear();
        cin.ignore();
        cout << "Wrong!Please enter again!" << endl;
        selectCourse();
    }
    else if(f == 1)
    {
        cout<<"Select an obligatory course from: "<<endl;
        for(int i = 0; i < ocNum; i++)
            cout << i+1 << *oc[i] << endl;
        cout << "You want to select:";
        int f1;
        cin >> f1;
        while(cin.fail() || f1 <= 0 || f1 >= 4)
        {
            cin.clear();
            cin.ignore();
            cout << "Wrong!Please enter again!" << endl;
            cout << "You want to select:";
            cin >> f1;
        }
        cn = oc[f1-1]->getName();
        c = oc[f1-1]->getCreditHour();
        s->addCourse(cn,c,1);
        cout << "\"" << cn << "\" is selected." << endl;
        selectCourse();
    }
    else if(f == 2)
    {
        cout<<"Select an obligatory course from: "<<endl;
        for(int i = 0; i < ecNum; i++)
            cout << i+1 << *ec[i] << endl;
        cout << "You want to select:";
        int f1;
        cin >> f1;
        while(cin.fail() || f1 <= 0 || f1 >= 4)
        {
            cin.clear();
            cin.ignore();
            cout << "Wrong!Please enter again!" << endl;
            cout << "You want to select:";
            cin >> f1;
        }
        cn = ec[f1-1]->getName();
        c = ec[f1-1]->getCreditHour();
        s->addCourse(cn,c,'A');
        cout << "\"" << cn << "\" is selected." << endl;
        selectCourse();
    }
    else if(f == 3)
        ;
}

void Console::addMG()
{
    s->setFlag();
    for(int i = 0; i < s->getCourseNumber(); i++)
    {
        Course *courseList = s->getCourseList(i);
        ObligatoryCourse *ob = dynamic_cast<ObligatoryCourse*>(courseList);
        if(ob != NULL)
        {
            cout << "\"" << courseList->getName() << "\"" << " is an Obligatory Course,please enter its mark: ";
            int mark,f = 0;
            while(f == 0)
            {
                try
                {
                    cin >> mark;
                    while(cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Wrong mark!Please enter again:";
                        cin >> mark;
                    }
                    if(mark < 0 || mark > 100)
                        throw MyException("Wrong mark!Please enter again:");
                    else
                        f = 1;
                }
                catch(MyException &e)
                {
                    e.what();
                }
            }
            string name = courseList->getName();
            int creditHour = courseList->getCreditHour();
            courseList->setCourse(name,creditHour,mark);
        }
        else
        {
            cout << "\"" << courseList->getName() << "\" is an Elective Course,please enter its grade: ";
            char grade,f = 0;
            while(f == 0)
            {
                try
                {
                    cin >> grade;
                    while(cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Wrong grade!Please enter again:";
                        cin >> grade;
                    }
                    if(grade != 'A' && grade != 'B' && grade != 'C' && grade != 'D' && grade != 'E')
                        throw MyException("Wrong grade!Please enter again:");
                    else
                        f = 1;
                }
                catch(MyException &e)
                {
                    e.what();
                }
            }
            string name = courseList->getName();
            int creditHour = courseList->getCreditHour();
            courseList->setCourse(name,creditHour,grade);
        }
    }
}

void Console::removeCourse()
{
    cout << "Please enter the number of course to remove:";
    int i,f = 0;
    while(f == 0)
    {
        cin >> i;
        if(i >= 1 && i <= s->getCourseNumber())
        {
            cout << "\"" << s->getCourseList(i-1)->getName() << "\" is removed" << endl;
            s->removeCourse(i,*s);
            f = 1;
        }
        else
            cout << "Wrong number!Please enter again:";
    }
}

void Console::queryScore()
{
    cout << "Please enter the number of course to query the score:";
    int i;
    cin >> i;
    if(i >= 1 && i <= s->getCourseNumber())
        cout << "The score of \"" << s->getCourseList(i-1)->getName() << "\" is " << s->queryScore(i) << endl;
    else
        cout << "Error!" << endl;
}

void Console::queryCalcCredit()
{
    cout << "Your CalcCredit is " << s->calcCredit(*s) << endl;
}

void Console::print() const
{
    cout << *s;
}

void Console::save()
{
    cout << "Please enter the name of file: ";
    char fileName[30];
    cin >> fileName;
    ofstream ofile2(fileName,ios::out);
    if(!ofile2)
    {
        cerr << "Wrong!"<<endl;
        operate();
    }
    ofile2 << *s;
    ofile2.close();
    cout << "The information of the student has been saved in \"" << fileName << "\"" << endl;
}

Console::~Console()
{
    //dtor
}
