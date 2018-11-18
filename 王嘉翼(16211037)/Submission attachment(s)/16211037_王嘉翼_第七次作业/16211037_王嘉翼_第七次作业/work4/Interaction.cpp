#include "Interaction.h"
#include "ElectiveCourse.h"
#include "student.h"
#include "ObligatoryCourse.h"
#include "Course.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "Exception.h"
using namespace std;
Interaction::Interaction()
{
    //ctor
}

Interaction::~Interaction()
{
    //dtor
}
void Interaction::ObligatoryCourseChoice(string Name,int CreditHour,student &a)
{
    ObligatoryCourse *ke;
    ke=new(ObligatoryCourse);
//    ObligatoryCourse ke(CreditHour);
    (*ke).setName(Name);
    (*ke).setCreditHour(CreditHour);
    char tem[20];
    cout<<"Obligatory "<<(*ke).getName()<<" credit "<<(*ke).getCreditHour()<<"\n";
//    printf("是否选课 输入Y选课 N不选\n");
//    printf("if choose input Y else input N\n");
    cout<<"if choose input Y else input N\n";
//    scanf("%s",tem);
    cin>>tem;
    if(tem[0]=='Y')
    {
        a.addCourse(&(*ke));
        printf("input ");
        cout<<(*ke).getName()<<" scores\n";
        int ttem;
//        try{
        scanf("%d",&ttem);
        try
        {
            if(ttem<0||ttem>100)
            throw Illegal_OC_Score_Exception();
        }
        catch(Exception &x)
        {
            cout<<x.what()<<endl;
            return;
        }
//        }
//        catch (int)
//        {
//            cout<<"illegal score!\n";
//            return ;
//        }
        a.fen((*ke).getName(),&ttem);
    }
    return;
}
void Interaction::ElectiveCourseChoice(string Name,int CreditHour,student &a)
{
    ElectiveCourse *zz;
    zz=new(ElectiveCourse);
//    ElectiveCourse zz(CreditHour);
    (*zz).setName(Name);
    (*zz).setCreditHour(CreditHour);
    char tem[20];
    cout<<"Elective "<<(*zz).getName()<<" credit "<<(*zz).getCreditHour()<<"\n";
//    printf("是否选课 输入Y选课 N不选\n");
    printf("if choose input Y else input N\n");
    scanf("%s",tem);
    if(tem[0]=='Y')
        {
            a.addCourse(&(*zz));
            char tt[10],teem;
            printf("input ");
            cout<<(*zz).getName()<<" scores\n";

            scanf("%s",tt);
            try
            {if(tt[0]<'A'||tt[0]>'E')
                throw Illegal_EC_Score_Exception();
            }
            catch(Exception &x)
            {
                cout<<x.what()<<endl;
                return;
            }
            teem=tt[0];
            a.fen((*zz).getName(),&teem);
        }
    return;
}
void Interaction::chooseCourse(student &a)
{
    int i=0;
    ifstream in("ob.txt");
    int zhi;
    for(string tem;in>>tem;)
    {
        in>>zhi;
        ObligatoryCourseChoice(tem,zhi,a);
    }
    in.close();
    /*原本代码*/
//    while(ObCreditHour[i])
//    {
//        ObligatoryCourseChoice(Obligatory[i],ObCreditHour[i],a);
//        ++i;
//    }
    /*原本代码*/
    i=0;
    ifstream in2("ec.txt");
    for(string tem;in2>>tem;)
    {
//        cout<<"!!"<<endl;
        in2>>zhi;
        ElectiveCourseChoice(tem,zhi,a);
    }
    /*原本代码
    while(ElCreditHour[i])
    {
        ElectiveCourseChoice(Elective[i],ElCreditHour[i],a);++i;
    }
    原本代码*/

    ofstream out((string)a.getname()+".txt");
    out<<a;
//    out.close();
    return;
}
bool Interaction::engine(student &a)
{
        int opt;
        system("cls");
        printf("    功能列表\n");
        printf("输入1 进行选课及给定分数\n");
        printf("输入2 保存学生信息\n");
        printf("输入3 查询该学生绩点\n");
        printf("输入4 输出该学生信息\n");
        printf("输入5 结束该学生操作\n");
        scanf("%d",&opt);
//        if(cin.fail())
//        {
//            cin.clear();
//            cin.ignore();
//            cin>>opt;
//        }
//        int num=-1;
        try
        {
            if(opt==1)
                chooseCourse(a);
            else if(opt==2)
            {
                ofstream out((string)a.getname()+".txt");
                out<<a;
            }
            else if(opt==3)
                {
                    cout<<a.calcCredit()<<endl;
                    system("pause");
                }
            else if(opt==4)
                {
                    cout<<a<<endl;
                    system("pause");
                }
            else if(opt==5)
                return false;
            else
                throw NonExistent_Option_Exception();
        }
        catch(Exception &x)
        {
            cout<<x.what()<<endl;
        }
        return true;
}
