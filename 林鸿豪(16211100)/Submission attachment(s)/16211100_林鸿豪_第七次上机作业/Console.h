#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
#include "Student.h"
#include "Course.h"
#include "Date.h"
#include <fstream>
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "MyException.h"
#ifndef DISPLAY_H
#define DISPLAY_H

#define Max 10
/*
typedef struct {
    int num;
    char name[50];
    int CreditHour;
}CourseInf;
*/
class Console {
//private:
  //  CourseInf ci[Max];
public:
    Student& informationcin()
    {
        cout<<"������ѧ������\n";
        char *n=new char;
        cin>>n;
        cout<<"������ѧ�����������գ�����ʽ���� �� �գ��м�ո�\n";
        int y,m,d;
        cin>>y>>m>>d;
        try{
            Date a(y,m,d);
        }
        catch(MyException ex){
            cout<<ex.what()<<endl;
            Student s=informationcin();
            return s;
        }
        Student *s=new Student(n,y,m,d);
        return *s;

    }
    Course* getCourse(string a)
    {
        cout<<a<<endl;
        int aa=a.length();
        string b,c;
        int mid=0,midd=0;
        for (int j=2;j<aa;j++)
        {
            if (a[j]==' ')
            {
                mid=j;
                break;
            }
            b+=a[j];
        }
        for (int j=mid+1;j<aa;j++)
        {
            if (a[j]==' '){
                midd=j;
                break;
            }
            c+=a[j];
        }
        int d=a[midd+1]-'0';
        if (b=="ObligatoryCourse") {
            ObligatoryCourse *p=new ObligatoryCourse(c,d);
            return p;
        }
        else if (b=="ElectiveCourse"){
            ElectiveCourse *p=new ElectiveCourse(c,d);
            return p;
        }
    }
/*    void getstring(int a[])
    {
        string bb;
        int t=0;
        bool wip=0;
        getline(cin,bb);
        for (int i=0;i<bb.length();i++)
        {
            if (bb[i]!=' '&&(bb[i]>'9'||bb[i]<'0')){
                wip=1;
                break;
            }
            if (bb[i]!=' ') a[t++]=bb[i]-'0';
        }
        if (wip==1){
            cout<<"����Υ�������������룺"<<endl;
            getstring(a);
        }
    }*/
    void addCoursedisplay(Student &s){
        //if (s.CourseMax()==1)   {
        //    cout<<"��ѡ��10�ţ�ѡ��ʧ�ܡ�\n";
      //      return;
      //  }
        cout<<"����Ϊ��ѡ�γ̣�\n";
        ifstream file;
        int t=0;
        string a;
        file.open("Course_list.txt");
        int  total;
        file>>total;
        while (getline(file,a))
        {
           // a=file.getline;
            cout<<a<<endl;
        }
      //  string bb;
        cout<<"��������ѡ�γ�����: \n";
        int num;
        cin>>num;
        while(cin.fail()||num>total||num<=0)
        {
            cin.clear();
            cin.ignore();
            cout<<"����ȷ���룺\n";
            cin>>num;
        }
        cout<<"��������ѡ�γ���ţ�\n";
      //  getstring(aa);
        int bb,aa[num];
        t=0;
        for (int i=0;i<num;i++)
        {
            cin>>bb;
            while(cin.fail()||bb<=0||bb>total)
            {
                cin.clear();
                cin.ignore();
                cout<<"����ȷ���룺\n";
                cin>>bb;
            }
            aa[t++]=bb;
        }

        file.close();
        ifstream file2;
        file2.open("Course_list.txt");
        getline(file2,a);
      //  cout<<total<<endl;
        int i=0;
        t=0;
       // for (int i=0;i<num;i++) cout<<aa[i]<<endl;
        while (getline(file2,a))
        {
            i++;
            if (i==aa[t])   {
                Course *p=getCourse(a);
                try{
                    s.addCourse(p);
                }
                catch(MyException ex){
                    throw ex;
                }
             //   cout<<*p<<endl;
                t++;
            }
        }
        //for (int i=0;i<)
        cout<<"ѡ�γɹ���\n";
        file2.close();
    }
    void setMark(Student &s)
    {
        cout<<"������γ�λ��\n";
        int i;
        cin>>i;
        if(i<=0||i>10)  {
            cout<<"����Υ��\n";
            return;
        }
        else if (s.CourseEmpty()==1)
        {
            cout<<"û�пɲ�����������ʧ��\n";
            return;
        }
        cout<<"������γ̳ɼ�\n";
        try{
            s.setMark(i);
        }
        catch(MyException ex){
            throw ex;
        }
        cout<<"���óɹ���\n";
    }
    void removeCourse(Student &s){
        cout<<"��������Ҫ��ѡ�Ŀγ�λ��(һ��һ��)\n";
        int i;
        cin>>i;
       //if (s.CourseEmpty()==1){
       //     cout<<"��ѡ�γ�����Ϊ0���˿�ʧ�ܡ�\n";
       //     return;
      //  }
        try{
            s.removeCourse(i);
        }
        catch(MyException ex){
            throw ex;
        }
        cout<<"�˿γɹ���\n";
    }
    void getCourseScore(Student &s)
    {
        cout<<"��������Ҫ�鿴�Ŀγ�λ��\n";
        int i;
        cin>>i;
        s.getCourseScore(i);
    }
    void getCredit(Student &s)          //ΪʲôҪ�����ò���
    {
        cout<<"ѧ������Ϊ:"<<s.calCredit()<<endl;
    }
    int initialscreem(Student &s){
        cout<<endl;
        cout<<"---��Ҫѡ��������1\n"
            <<"---��Ҫ�˿�������2\n"
            <<"---��Ҫ���óɼ�������3\n"
            <<"---��Ҫ�鿴������ѧ����Ϣ������4\n"
            <<"---��Ҫ�鿴�γ̳ɼ�������5\n"
            <<"---��Ҫ�鿴ѧ������������6\n"
            <<"---��Ҫ�˳�������7\n";
        string i;
        cin>>i;
        if (i.length()>1)   {
            cout<<"����Υ�������������롣";
            return 1;
        }
        int j=(int )i[0]-'0';
        switch(j)
        {
            case 1:{
                while (1){
                    try{
                        addCoursedisplay(s);
                    }
                    catch(MyException ex){
                        cout<<ex.what()<<endl;
                    }
                    break;
                }
                break;
            }
            case 2:{
                while (1){
                    try{
                        removeCourse(s);
                    }
                    catch(MyException ex){
                        cout<<ex.what()<<endl;
                    }
                    break;
                }
                break;
            }
            case 3:{
                while (1){
                    try{
                        setMark(s);
                    }
                    catch(MyException ex){
                        cout<<ex.what()<<endl;
                        continue;
                    }
                    break;
                }
                break;
            }
            case 4:{
                cout<<s;
                ofstream file("Student-information.txt");
                file<<s;
                break;
            }
            case 5:{
                getCourseScore(s);
                break;
            }
            case 6:{
                getCredit(s);
                break;
            }
            case 7:{
                return 0;
            }
            default:
                {
                    cout<<"����Υ�������������롣";
                    return 1;
                }
        }
        return 1;
    }
};
#endif // DISPLAY_H
