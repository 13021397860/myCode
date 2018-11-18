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
    for(int j=1;j<=3;j++){   //��ʼ��ѡ�޿�
        in>>P[j].NameOfCourse>>P[j].creditHour;
        P[j].id=0;     P[j].Type=E;
        P[j].isSelected=false;
    }
    in.close(); in.open("ObligatoryCourse.txt",ios::in);
    for(int j=4;j<=6;j++){   //��ʼ�����޿�
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
        printf("*                                 1.���������Ϣ                             *\n");
        printf("*                                 2.�˳�                                     *\n");
    }
    else{
        printf("*                                 welcome!                                   *\n");
        printf("*                                 1.����ѡ�ν���                             *\n");
        printf("*                                 2.�鿴ѡ�ν��                             *\n");
        printf("*                                 3.����ɼ�                                 *\n");
        printf("*                                 4.��ѡ                                     *\n");
        printf("*                                 0.�˳�ѡ��ϵͳ                             *\n");
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
        cout<<"(���ļ��ж�ȡ)��������:\n";
        ifstream File("Student.txt",ios::in);
        if(!File) cerr<<"�ļ��򿪴���"<<endl;
        File>>name;

        cout<<"�������������:";
        File>>y>>m>>d;
        p=new Student(y,m,d,name);
        File.close();
        return p;
    }
    return NULL;
}

void Interface::PrintNeedingSelectCourse()const{
    system("cls");
    cout<<"     ��ѡ��Ŀ      ѧ�� "<<endl;
    for(int i=1;i<=6;i++){
        if(P[i].isSelected==false){
            cout<<i<<"."<<setw(14)<<setfill(' ')<<P[i].NameOfCourse<<"    "<<P[i].creditHour;
            if(P[i].Type==E) cout<<"  ѡ�޿�"<<endl;
            else cout<<"  ���޿�"<<endl;
        }
    }
    cout<<"��������ѡ�γ�(����0����ѡ��):"<<endl;
}

void Interface::SelectingCourse(){
   while((cin>>op&&op)||cin.fail()){
        while(cin.fail()){
            cerr<<"����������һ������"<<endl;
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
            printf("��ѡ���ÿγ�!\n"); continue;
        }
        if( P[op].Type==E ) p->addCourse(new ElectiveCourse(P[op].NameOfCourse,P[op].creditHour));
        else p->addCourse(new ObligatoryCourse(P[op].NameOfCourse,P[op].creditHour));
        P[op].id=p->GetCourseNum(); P[op].isSelected=true;
        cout<<"��ӿγ�"<<P[op].NameOfCourse<<endl;
    }
}

void Interface::PrintSelectedCourse()const{
    system("cls");
    ofstream FileName;
    if(FileName.is_open()) cerr<<"�ļ��򿪴���"<<endl;
    else{
        FileName.open("information.txt",ios::out);
        FileName<<(*p);
        cout<<(*p);
    }
    FileName.close();
}

void Interface::PrintInputingGrade(){
    printf("����1д��ɼ�������2������һҳ��0�˳�\n");
    while(~scanf("%d",&op)){
        if(op==0) exit(0);
        else if(op==1){
            cout<<"����Ҫд��ĳɼ��Ŀ�Ŀ����Ӧ��ż��ɼ�(����0������һҳ):\n";
            int i,Gra; char ch;
            while(~scanf("%d",&i)&&i){
                Course *ptr=p->getCourse(i);
                ObligatoryCourse *opt=dynamic_cast<ObligatoryCourse *>(ptr);
                //Ҳ��ʹ�� if(typeid()==typeid());
                if(opt==NULL){
                    printf("ѡ�޿Σ�������A,B,C,D,E����ȼ�:\n"); scanf(" %c",&ch);
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
                    printf("���޿Σ�������0~100֮�������:\n"); scanf("%d",&Gra);
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
        printf("��ѡ�ɹ�\n");
        for(int j=0;j<6;j++){
            if(P[j].id==i){
                P[j].isSelected=false;
                break;
            }
        }
        system("cls"); p->print_birthDate();
        PrintSelectedCourse();
        printf("����Ҫ��ѡ�Ŀγ�:(����0������һҳ)\n");
    }
    else{
        printf("δѡ��ÿγ�\n");
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
            cerr<<"����������һ������";
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
                printf("����1������һҳ��0�˳�\n");
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
                printf("����Ҫ��ѡ�Ŀγ�:(����0������һҳ)\n");
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
