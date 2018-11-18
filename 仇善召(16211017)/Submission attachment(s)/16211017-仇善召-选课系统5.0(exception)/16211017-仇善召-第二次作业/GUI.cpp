#include "GUI.h"
#include <fstream>
GUI::GUI()
{
    //ctor
}
int GUI::run()
{
    int i;
    cout<<"*******************�����ļ��������***************"<<endl;
    ifstream ifile("data.txt");
     int isObli;
     string name;
     int hour;
    while (ifile>>isObli>>name>>hour)
    {
         Course *p;
    if ( 1==isObli)
     {
         p=new ObligatoryCourse;
         p->setname(name);
         p->setHour(hour);
     }
    if (2==isObli )
     {
          p=new ElectiveCourse;
         p->setname(name);
         p->setHour(hour);
     }
     cout<<*p;
    }
    cout<<"*******************�����ļ��������***************"<<endl;


    Student a;
    cout<<" ������ѧ��������";
    char s[20];
    cin>> s;
    a.setName(s);

    cout<<" ������ѧ������: ";
    int y,m,d;
    while (1){
     cin>>y>>m>>d;
     try
      {
        Date date(y,m,d);
        a.setDate( date );
        break;
      }catch (My_Exception ex)
      {
        cout<<ex.what()<<endl;
      }
    }


   cout<<" ѧ�����󹹽���ϡ����������룺\n����1�鿴ѧ����Ϣ\n����2��ӿγ�\n����3��ӿγ̳ɼ�\n����4��ѡ�γ�\n����5�˳�����\n����6����ѧ����Ϣ\n";


    while ( 1 )

    {
        int i;
        cin>>i;
       while ( cin.fail() || i>=7 || i<=0 )
       {
           cout<<"ָ��������������룺\n";
           cin.clear();
           cin.ignore();
           cin>>i;
       }
        if ( i==5 )
        return 0;
       else if ( i==1 )
      {

        cout<<a;
        cout<<" �鿴��Ϣ��ϡ����������룺\n����2��ӿγ�\n����3��ӿγ̳ɼ�\n����4��ѡ�γ�\n����5�˳�����\n����6����ѧ����Ϣ\n";

      }
      else if ( i==6 )
      {
        ofstream ofile("student.txt");
        ofile<<a;
        ofile.flush();
        ofile.close();
        cout<<"������Ϣ��ϡ����������룺\n����1�鿴ѧ����Ϣ\n����2��ӿγ�\n����3��ӿγ̳ɼ�\n����4��ѡ�γ�\n����5�˳�����\n";
      }
   else  if ( i==2 )
    {

        cout<<"\n��ӱ��޿�������1\n���ѡ�޿�������2\n";
        int m;
        cin>>m;
        cout<<" ������γ����֣� "<<endl;
        string z;
        cin>>z;
        cout<<" ������γ�ѧ�֣� "<<endl;
        int hour;
        cin>>hour;
        /*cout<<" ������γ̳ɼ��� "<<endl;
        int mark;
        cin>>mark;*/
        if ( m==1 )
        {
            Course *c=new ObligatoryCourse();
            c->setname(z);
            c->setHour(hour);
           // c->setScore(mark);
            a.addCourse(c);
        }
        else if ( m==2 )
        {

            Course *c=new ElectiveCourse();
            c->setname(z);
            c->setHour(hour);
           // c->setScore(mark);
            a.addCourse(c);
        }
    cout<<" �γ������ϡ����������룺\n����1�鿴ѧ����Ϣ\n����2������ӿγ�\n����3��ӿγ̳ɼ�\n����4��ѡ�γ�\n����5�˳�����\n����6����ѧ����Ϣ\n";


    }
    else if ( i==3 )
    {
        int x,chengji;
        cout<<"������Ҫ��ӿε����"<<endl;
       while(1){
          try{
               cin>>x;
               if ( x<=0 || x>a.courseNumber)
                throw My_Exception(2);
               break;
          }catch ( My_Exception ex)
          {
              cout<<ex.what()<<endl;
          }

       }
        cout<<"������ÿεĳɼ�"<<endl;
        while(1){
          try{
               cin>>chengji;
               if ( chengji<0 || chengji>100)
                throw My_Exception(3);
               break;
          }catch ( My_Exception ex)
          {
              cout<<ex.what()<<endl;
          }

       }
        a.courseList[x-1]->setScore(chengji);
        cout<<" �ɼ������ϡ����������룺\n����1�鿴ѧ����Ϣ\n����2������ӿγ�\n����3��ӿγ̳ɼ�\n����4��ѡ�γ�\n����5�˳�����\n����6����ѧ����Ϣ\n";
    }
    else if ( i==4 )
    {
        int x;
        cout<<"��������ѡ�ε����"<<endl;
         while(1){
          try{
               cin>>x;
               if ( x<=0 || x>a.courseNumber)
                throw My_Exception(2);
               break;
          }catch ( My_Exception ex)
          {
              cout<<ex.what()<<endl;
          }

       }
        a.removeCourse(x);
         cout<<" �γ���ѡ��ϡ����������룺\n����1�鿴ѧ����Ϣ\n����2������ӿγ�\n����3��ӿγ̳ɼ�\n����4��ѡ�γ�\n����5�˳�����\n����6����ѧ����Ϣ\n";
    }
    }
    return 0;
}
GUI::~GUI()
{
    //dtor
}
