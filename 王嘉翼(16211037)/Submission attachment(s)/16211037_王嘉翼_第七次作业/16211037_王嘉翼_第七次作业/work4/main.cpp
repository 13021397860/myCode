#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "student.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Interaction.h"
using namespace std;

int main()
{
    while(1)
    {
    system("cls");
    printf("input student information please\n");
    student a;
    char sss[100];
//    printf("������ѧ������\n");
    printf("input name\n");
    scanf("%s",sss);
//    printf("������������� �� �� �� �� ����ʽ\n");
    printf("input birth date\n");
    Date y;
    cin>>y;
    /*������+��������ܵĲ���
    cout<<(y+5)<<endl;
    */
    a.setBirthDate(y);
    a.setname(sss);
    Interaction x;
    int opt;
    bool st=true;
    while(st)
    {
        st=x.engine(a);
//        system("cls");
//        printf("    �����б�\n");
//        printf("����1 ����ѡ�μ���������\n");
//        printf("����2 ����ѧ����Ϣ\n");
//        printf("����3 ��ѯ��ѧ������\n");
//        printf("����4 �����ѧ����Ϣ\n");
//        printf("����5 ������ѧ������\n");
//        scanf("%d",&opt);
//        if(opt==1)
//            x.chooseCourse(a);
//        else if(opt==2)
//        {
//            ofstream out((string)a.getname()+".txt");
//            out<<a;
//        }
//        else if(opt==3)
//            {
//                cout<<a.calcCredit()<<endl;
//                system("pause");
//            }
//        else if(opt==4)
//            {
//                cout<<a<<endl;
//                system("pause");
//            }
//        else
//            throw (-1);



//    int ttem=0;
//    printf("������ѧ�ɼ�\n");

//    printf("input maths score\n");
//    scanf("%d",&ttem);
//    a.fen("Maths",&ttem);
//    printf("Maths over\n");

//    char teem='C';char tt[30];
//    printf("Games�÷�ΪC\n");
//    printf("����Games�ɼ�\n");
//    printf("inpt games score\n");
//    scanf("%s",tt);
//    teem=tt[0];
//    a.fen("Games",&teem);

//    cout<<a.calcCredit()<<endl;

    /*��ȥ���εĲ���
    cout<<a;
    a.removeCourse(3);
    cout<<a;
    a.removeCourse(2);
    cout<<a;
    */
    }
    printf("����1�������� ����2��������\n");
    scanf("%d",&opt);
    if(opt==1)
        continue;
    else
        break;
    }
    return 0;
}
