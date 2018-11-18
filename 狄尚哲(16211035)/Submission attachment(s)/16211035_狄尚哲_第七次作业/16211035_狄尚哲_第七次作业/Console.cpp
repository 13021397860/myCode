#include "Console.h"
#include "MyException.h"
Console::Console()
{
//    O_course[0].setName("Math");                O_course[0].setCreditHour(4);
//    O_course[1].setName("Physics");             O_course[1].setCreditHour(2);
//    O_course[2].setName("Data Structure");      O_course[2].setCreditHour(3);
//    O_course[3].setName("Java");                O_course[3].setCreditHour(3);
//    O_course[4].setName("English");             O_course[4].setCreditHour(2);
//    E_course[0].setName("����ļ�������");      E_course[0].setCreditHour(1);
//    E_course[1].setName("�ߵ���ѧ����Ӧ��");    E_course[1].setCreditHour(1);
//    E_course[2].setName("��վ��������");        E_course[2].setCreditHour(1);
//    E_course[3].setName("ְҵ�滮");            E_course[3].setCreditHour(1);
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
    puts("����������");
    cin >> name;
    puts("�������������, ��ʽ���� �� ��");
    while(1){
        try{
            cin >> date;
            break;
        }catch(MyException e){
            cout << "�����쳣" << e.what() << endl;
            puts("�����������������, ��ʽ���� �� ��");
        }
    }
    s = new Student(name, date);
    //puts("###");
    //system("cls");
}
void Console::ChooseCourse(){
    int choice; int option;
    const char Command_Hint[100] = "��ѡ��γ�\n����1ѡ����޿γ̣�����2ѡ��ѡ�޿γ�, ����110�鿴��ѡ�γ�, ����0������һ���˵�";

    system("cls");
    puts(Command_Hint);
    while(1){
        cin >> option;
        while(cin.fail()){
            puts("�����������������");
            cin.clear();
            cin.ignore(1024, '\n');
            cin >> option;
        }
        if(option==110){
            if(s) cout << *s << endl;
        }
        else if(option==0) return;
        else if(option==1){
            puts("������Ӧ�Ŀγ������ѡ����޿γ�");
            Print_ObCourse();
            cin >> choice;
            while(1){
                while(cin.fail() || choice<1 || choice>maxO){
                    puts("�������, ��������Ӧ�Ŀγ������ѡ����޿γ�");
                    cin.clear();
                    cin.ignore(1024, '\n');
                    cin >> choice;
                }
                try{
                    s->addCourse(&O_course[choice-1]);
                    break;
                }catch(MyException ex){
                    cout << ex.what() << "��������������ȷ�Ŀγ����: ";
                    cin >> choice;
                }
            }
            puts("ѡ�γɹ�");
            Sleep(sleepTime);
            system("cls");
            puts(Command_Hint);
        }
        else if(option==2){
            puts("������Ӧ�Ŀγ������ѡ��ѡ�޿γ�");
            Print_ElCourse();
            cin >> choice;
            while(1){
                while(cin.fail() || choice<1 || choice>maxE){
                    puts("�������, ��������Ӧ�Ŀγ������ѡ��ѡ�޿γ�");
                    cin.clear();
                    cin.ignore(1024, '\n');
                    cin >> choice;
                }
                try{
                    s->addCourse(&E_course[choice-1]);
                    break;
                }catch(MyException ex){
                    cout << ex.what() << "��������������ȷ�Ŀγ����: ";
                    cin >> choice;
                }
            }
            puts("ѡ�γɹ�");
            Sleep(sleepTime);
            system("cls");
            puts(Command_Hint);
        }
        else{
            puts("�����������������");
            cin.clear();
            cin.ignore(1024, '\n');
        }
    }
}
void Console::RemoveCourse(){
    system("cls");
    int choice;
    while(1){
        puts("\n��������Ӧ�����ѡ�γ̣�����0������һ���˵�");
        cout << *s << endl;
        cin >> choice;
        while(1){
            while(cin.fail() || choice<0 || choice>s->getCourseNumber()){
                puts("�����������������");
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
                cout << ex.what() << "��������������ȷ�Ŀγ����: ";
                cin >> choice;
            }
        }
        puts("�˿γɹ�");
        //cout << *s << endl;
    }
}
void Console::SetGrade(){
    system("cls");
    int choice;
    while(1){
        puts("��������Ӧ������ÿγ̳ɼ�������0������һ���˵�");
        cout << *s << endl;
        cin >> choice;
        while(1){
            while(cin.fail()){
                puts("�����������������");
                cin.clear();
                cin.ignore(1024, '\n');
                cin >> choice;
            }
            try{
                if(choice==0) return;
                s->setGrade(choice);
                break;
            }catch(MyException ex){
                cout << ex.what() << "��������������ȷ�Ŀγ����: ";
                cin >> choice;
            }
        }

/*    &&&&&&setScore����ֱ����console��ʵ�ֵķ�ʽ
//        if(typeid((*s)[choice]) == typeid(ObligatoryCourse)){
//            puts("����ɼ�(�ٷ���)");
//            int mark; cin >> mark;
//            dynamic_cast<ObligatoryCourse &>((*s)[choice]).setScore(mark);
//        }
//        else{
//            puts("����ɼ�(�ȼ���)");
//            char mark; cin >> mark;
//            dynamic_cast<ElectiveCourse &>((*s)[choice]).setScore(mark);
//        }
*/
        //Sleep(sleepTime);
    }
}
void Console::printScore() const{
    cout << *s;
    //cout << "����ɼ���" << s->calcCredit() << "\n" << endl;
}
void Console::Window(){
    system("cls");
    int choice;

    if(!ReadCourse()){
        puts("����γ̴���!");
        return;
    }
    puts("=================================================");
    puts("��ӭ��������(��)ϵͳ");
    puts("1. ����ѧ����Ϣ   0. �˳�ϵͳ");
    cin >> choice;
    while(cin.fail() || choice<0 || choice>1){
        puts("�����������������");
        cin.clear();
        cin.ignore(1024, '\n');
        cin >> choice;
    }
    if(choice==0) Exit();
    CreateStudent();
    while(1){
        //system("cls");
        puts("1. �鿴ѧ����Ϣ   2. ѡ��   3. �˿�   4. ���óɼ�   5. ��ѯ�ɼ�  0. �˳�ϵͳ");
        cin >> choice;
        while(cin.fail()){
            puts("�����������������");
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
            puts("�����������������");
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
        puts("������Ϣ����!");
    }
    exit(0);
}
