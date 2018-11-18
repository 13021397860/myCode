#include "Interface.h"

typedef enum{O,E}TypeOfCourse;
struct NowCourse{
    string NameOfCourse;
    TypeOfCourse Type;
    bool isSelected;
    int id,creditHour;
}P[8];

ifstream &operator>>(ifstream &in,Interface &a){
    a.IniCourse(in);
}

void Interface::IniCourse(ifstream &in){
    in.open("ElectiveCourse.txt",ios::in);
    for(int j=1;j<=3;j++){   //初始化选修课
        in>>P[j].NameOfCourse>>P[j].creditHour;
        P[j].id=0;     P[j].Type=E;
        P[j].isSelected=false;
    }
    in.close(); in.open("ObligatoryCourse.txt",ios::in);
    for(int j=4;j<=6;j++){   //初始化必修课
        in>>P[j].NameOfCourse>>P[j].creditHour; P[j].id=0;
        P[j].Type=O;
        P[j].isSelected=false;
    }
}

Interface::Interface()
{
    is_have=false;
}

void Interface::PrintFirstFace(){
    printf("******************************************************************************\n");
    for(int i=1;i<=3;i++)     printf("*                                                                            *\n");
    if(!is_have){
        printf("*                                 1.输入相关信息                             *\n");
        printf("*                                 2.退出                                     *\n");
    }
    else{
        printf("*                                 welcome!                                   *\n");
        printf("*                                 1.进入选课界面                             *\n");
        printf("*                                 2.查看选课结果                             *\n");
        printf("*                                 3.输入成绩                                 *\n");
        printf("*                                 4.退选                                     *\n");
        printf("*                                 0.退出选课系统                             *\n");
    }
    for(int i=1;i<=11;i++) printf("*                                                                            *\n");
    printf("******************************************************************************\n");
    if(is_have){
        MainSelectCourseFace();
    }
}

Student *Interface::PrintInputInformation(){
    if(!is_have){
        string name;   int y,m,d;
        is_have=true;
        scanf("%d",&op);
        if(op==2) exit(0);

        system("cls");
        cout<<"(从文件中读取)输入姓名:\n";
        ifstream File("Student.txt",ios::in);
        if(!File) cerr<<"文件打开错误"<<endl;
        File>>name;

        cout<<"输入出生年月日:";
        File>>y>>m>>d;
        p=new Student(y,m,d,name);
        File.close();
        return p;
    }
    return NULL;
}

void Interface::PrintNeedingSelectCourse()const{
    system("cls");
    cout<<"     可选科目      学分 "<<endl;
    for(int i=1;i<=6;i++){
        if(P[i].isSelected==false){
            cout<<i<<"."<<setw(14)<<setfill(' ')<<P[i].NameOfCourse<<"    "<<P[i].creditHour;
            if(P[i].Type==E) cout<<"  选修课"<<endl;
            else cout<<"  必修课"<<endl;
        }
    }
    cout<<"请输入所选课程(输入0结束选课):"<<endl;
}

void Interface::SelectingCourse(){
   while((cin>>op&&op)||cin.fail()){
        while(cin.fail()){
            cerr<<"请重新输入一个数字"<<endl;
            cin.clear(); cin.ignore();
            cin>>op;
        }
        try{
            if(op<0||op>4){
                throw MyException();
            }
        }
        catch(MyException &ex){
            ex.wtfOfCourse();  continue;
        }
        if( P[op].isSelected==true ){
            printf("已选过该课程!\n"); continue;
        }
        if( P[op].Type==E ) p->addCourse(new ElectiveCourse(P[op].NameOfCourse,P[op].creditHour));
        else p->addCourse(new ObligatoryCourse(P[op].NameOfCourse,P[op].creditHour));
        P[op].id=p->GetCourseNum(); P[op].isSelected=true;
        cout<<"添加课程"<<P[op].NameOfCourse<<endl;
    }
}

void Interface::PrintSelectedCourse()const{
    system("cls");
    ofstream FileName;
    if(FileName.is_open()) cerr<<"文件打开错误"<<endl;
    else{
        FileName.open("information.txt",ios::out);
        FileName<<(*p);
        cout<<(*p);
    }
    FileName.close();
}

void Interface::PrintInputingGrade(){
    printf("输入1写入成绩，输入2返回上一页，0退出\n");
    while(~scanf("%d",&op)){
        if(op==0) exit(0);
        else if(op==1){
            cout<<"输入要写入的成绩的科目的相应序号及成绩(输入0返回上一页):\n";
            int i,Gra; char ch;
            while(~scanf("%d",&i)&&i){
                Course *ptr=p->getCourse(i);
                ObligatoryCourse *opt=dynamic_cast<ObligatoryCourse *>(ptr);
                //也可使用 if(typeid()==typeid());
                if(opt==NULL){
                    printf("选修课，请输入A,B,C,D,E五个等级:\n"); scanf(" %c",&ch);
                    try{
                        if(ch>'E'||ch<'A'){
                            throw MyException();
                        }
                    }catch(MyException &Ex){
                        Ex.wtfOfGrade(); continue;
                    }
                    ElectiveCourse *ept=dynamic_cast<ElectiveCourse *>(ptr);
                    ept->setScore(ch);
                }
                else {
                    printf("必修课，请输入0~100之间的数字:\n"); scanf("%d",&Gra);
                    try{
                        if(Gra>100||Gra<0){
                            throw MyException();
                        }
                    }catch(MyException &Ex){
                        Ex.wtfOfGrade(); continue;
                    }
                    opt->setScore(Gra);
                }
            }
            if(i==0) break;
            continue;
        }
        else break;
    }
}

void Interface::RemoveCourse(int i){
    if(p->removeCourse(i)){
        printf("退选成功\n");
        for(int j=0;j<6;j++){
            if(P[j].id==i){
                P[j].isSelected=false;
                break;
            }
        }
        system("cls"); p->print_birthDate();
        PrintSelectedCourse();
        printf("输入要退选的课程:(输入0返回上一页)\n");
    }
    else{
        printf("未选择该课程\n");
    }
}

void Interface::MainSelectCourseFace(){
    ifstream in;  in>>(*this);
    in.close();
    while(cin>>op||cin.fail()){
        try{
            if(op<0||op>4){
                throw InputException();
            }
        }
        catch(InputException ex){
            ex.wtf(); continue;
        }
        while(cin.fail()){
            cerr<<"请重新输入一个数字";
            cin.clear(); cin.ignore();
            cin>>op;
        }
        switch(op){
            case 1:{
                PrintNeedingSelectCourse();
                SelectingCourse();
                break;
            }
            case 2:{
                PrintSelectedCourse();
                printf("输入1返回上一页，0退出\n");
                scanf("%d",&op); if(op==0) exit(0);
                break;
            }
            case 3:{
                PrintSelectedCourse();
                PrintInputingGrade();
                break;
            }
            case 4:{
                PrintSelectedCourse();
                printf("输入要退选的课程:(输入0返回上一页)\n");
                while(~scanf("%d",&op)&&op){
                    RemoveCourse(op);
                }
                for(int i=1;i<=6;i++){
                    printf("%d  %d\n",i,P[i].isSelected);
                }
                break;
            }
            case 0:{
                exit(0);
            }
        }
        system("cls");
        PrintFirstFace();
    }
}

Interface::~Interface()
{
    //dtor
}
