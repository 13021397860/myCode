#include "Console.h"
#include "MyException.h"
Console::Console()
{
//    O_course[0].setName("Math");                O_course[0].setCreditHour(4);
//    O_course[1].setName("Physics");             O_course[1].setCreditHour(2);
//    O_course[2].setName("Data Structure");      O_course[2].setCreditHour(3);
//    O_course[3].setName("Java");                O_course[3].setCreditHour(3);
//    O_course[4].setName("English");             O_course[4].setCreditHour(2);
//    E_course[0].setName("神奇的激光世界");      E_course[0].setCreditHour(1);
//    E_course[1].setName("高等数学方法应用");    E_course[1].setCreditHour(1);
//    E_course[2].setName("网站分析工具");        E_course[2].setCreditHour(1);
//    E_course[3].setName("职业规划");            E_course[3].setCreditHour(1);
    s = NULL;
    //ctor
}

Console::~Console()
{
    //dtor
}

void Console::Print_ObCourse() const{
    for(int i=0; i<maxO; i++){
        printf("\t%d. ", i+1);
        cout<<O_course[i] << endl;
    }
}
void Console::Print_ElCourse() const{
    for(int i=0; i<maxE; i++){
        printf("\t%d. ", i+1);
        cout<<E_course[i] << endl;
    }
}
void Console::CreateStudent(){
    system("cls");
    Date date; char name[20];
    system("cls");
    puts("请输入姓名");
    cin >> name;
    puts("请输入出生日期, 格式：年 月 日");
    while(1){
        try{
            cin >> date;
            break;
        }catch(MyException e){
            cout << "日期异常" << e.what() << endl;
            puts("请重新输入出生日期, 格式：年 月 日");
        }
    }
    s = new Student(name, date);
    //puts("###");
    //system("cls");
}
void Console::ChooseCourse(){
    int choice; int option;
    const char Command_Hint[100] = "请选择课程\n输入1选择必修课程，输入2选择选修课程, 输入110查看已选课程, 输入0返回上一级菜单";

    system("cls");
    puts(Command_Hint);
    while(1){
        cin >> option;
        while(cin.fail()){
            puts("输入错误，请重新输入");
            cin.clear();
            cin.ignore(1024, '\n');
            cin >> option;
        }
        if(option==110){
            if(s) cout << *s << endl;
        }
        else if(option==0) return;
        else if(option==1){
            puts("输入相应的课程序号以选择必修课程");
            Print_ObCourse();
            cin >> choice;
            while(1){
                while(cin.fail() || choice<1 || choice>maxO){
                    puts("输入错误, 请输入相应的课程序号以选择必修课程");
                    cin.clear();
                    cin.ignore(1024, '\n');
                    cin >> choice;
                }
                try{
                    s->addCourse(&O_course[choice-1]);
                    break;
                }catch(MyException ex){
                    cout << ex.what() << "，请重新输入正确的课程序号: ";
                    cin >> choice;
                }
            }
            puts("选课成功");
            Sleep(sleepTime);
            system("cls");
            puts(Command_Hint);
        }
        else if(option==2){
            puts("输入相应的课程序号以选择选修课程");
            Print_ElCourse();
            cin >> choice;
            while(1){
                while(cin.fail() || choice<1 || choice>maxE){
                    puts("输入错误, 请输入相应的课程序号以选择选修课程");
                    cin.clear();
                    cin.ignore(1024, '\n');
                    cin >> choice;
                }
                try{
                    s->addCourse(&E_course[choice-1]);
                    break;
                }catch(MyException ex){
                    cout << ex.what() << "，请重新输入正确的课程序号: ";
                    cin >> choice;
                }
            }
            puts("选课成功");
            Sleep(sleepTime);
            system("cls");
            puts(Command_Hint);
        }
        else{
            puts("输入错误，请重新输入");
            cin.clear();
            cin.ignore(1024, '\n');
        }
    }
}
void Console::RemoveCourse(){
    system("cls");
    int choice;
    while(1){
        puts("\n请输入相应序号退选课程，输入0返回上一级菜单");
        cout << *s << endl;
        cin >> choice;
        while(1){
            while(cin.fail() || choice<0 || choice>s->getCourseNumber()){
                puts("输入错误，请重新输入");
                cin.clear();
                cin.ignore(1024, '\n');
                cin >> choice;
            }
            if(choice==0){
                return;
            }
            try{
                s->removeCourse(choice);
                break;
            }catch(MyException ex){
                cout << ex.what() << "，请重新输入正确的课程序号: ";
                cin >> choice;
            }
        }
        puts("退课成功");
        //cout << *s << endl;
    }
}
void Console::SetGrade(){
    system("cls");
    int choice;
    while(1){
        puts("请输入相应序号设置课程成绩，输入0返回上一级菜单");
        cout << *s << endl;
        cin >> choice;
        while(1){
            while(cin.fail()){
                puts("输入错误，请重新输入");
                cin.clear();
                cin.ignore(1024, '\n');
                cin >> choice;
            }
            try{
                if(choice==0) return;
                s->setGrade(choice);
                break;
            }catch(MyException ex){
                cout << ex.what() << "，请重新输入正确的课程序号: ";
                cin >> choice;
            }
        }

/*    &&&&&&setScore函数直接在console中实现的方式
//        if(typeid((*s)[choice]) == typeid(ObligatoryCourse)){
//            puts("输入成绩(百分制)");
//            int mark; cin >> mark;
//            dynamic_cast<ObligatoryCourse &>((*s)[choice]).setScore(mark);
//        }
//        else{
//            puts("输入成绩(等级制)");
//            char mark; cin >> mark;
//            dynamic_cast<ElectiveCourse &>((*s)[choice]).setScore(mark);
//        }
*/
        //Sleep(sleepTime);
    }
}
void Console::printScore() const{
    cout << *s;
    //cout << "绩点成绩：" << s->calcCredit() << "\n" << endl;
}
void Console::Window(){
    system("cls");
    int choice;

    if(!ReadCourse()){
        puts("读入课程错误!");
        return;
    }
    puts("=================================================");
    puts("欢迎来到教务(雾)系统");
    puts("1. 创建学生信息   0. 退出系统");
    cin >> choice;
    while(cin.fail() || choice<0 || choice>1){
        puts("输入错误，请重新输入");
        cin.clear();
        cin.ignore(1024, '\n');
        cin >> choice;
    }
    if(choice==0) Exit();
    CreateStudent();
    while(1){
        //system("cls");
        puts("1. 查看学生信息   2. 选课   3. 退课   4. 设置成绩   5. 查询成绩  0. 退出系统");
        cin >> choice;
        while(cin.fail()){
            puts("输入错误，请重新输入");
            cin.clear();
            cin.ignore(1024, '\n');
            cin >> choice;
        }
        if(choice==0) Exit();
        else if(choice==1){
            if(s) cout << *s << endl;
        }
        else if(choice==2){
            ChooseCourse();
        }
        else if(choice==3){
            RemoveCourse();
        }
        else if(choice==4){
            SetGrade();
        }
        else if(choice==5){
            printScore();
        }
        else{
            puts("输入错误，请重新输入");
        }
    }
}

bool Console::ReadCourse(){
    ifstream in("course_data.txt", ifstream::in);
    string name;
    int type, creditHour;

    if(!in) return false;
    maxO = maxE = 0;
    while(in >> name >> creditHour >> type){
        if(type==1){
            O_course[maxO++] = ObligatoryCourse(name, creditHour, 0);
            //cout << O_course[maxO-1] << endl;
        }
        else{
            E_course[maxE++] = ElectiveCourse(name, creditHour, 'N');
            //cout << E_course[maxE-1] << endl;
        }
    }
    in.close();
    return true;
}
bool Console::Save_Student_Data() const{
    ofstream out;
    out.open("student_data.txt", ofstream::out);
    if(!out) return false;
    if(s==NULL){
        out.close();
        return false;
    }
    out << *s;
    out.close();
    return true;
}
void Console::Exit() const{
    if(!Save_Student_Data()){
        puts("储存信息出错!");
    }
    exit(0);
}
