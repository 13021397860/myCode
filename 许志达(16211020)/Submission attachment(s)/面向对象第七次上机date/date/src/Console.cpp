#include "Console.h"
#include "student.h"
#include"date.h"
#include "ElectiveCourse.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include<string.h>
#include<iostream>
#include<fstream>
using namespace std;
Console::Console()
{
    //ctor
}
void Console::run()
{
    int x,y,z;
    char p[100];
    //cout<<"������ѧ�������ּ���������"<<endl;
    //ifstream fin("student.txt");
      ifstream ifile("student.txt",ios::in);
    //ofstream fout("res.txt");
    ofstream outfile("res.txt",ios::out);
   ifile>>p>>x>>y>>z;
    //cin>>p>>x>>y>>z;
        student xuesheng(p,x,y,z);//cout<<<xuesheng<<endl;
        date rq(x,y,z);
        rq.getday();
        rq.getmonth();
        rq.getyear();
        //rq.setdate(x,y,z);
       //cout<<"��������һ����"<<rq++<<endl;
         outfile<<"��������һ����"<<rq++<<endl;
         c1=0,c2=0;
         cout<<"����1ѡ��"<<endl;
         cout<<"����3�˿�"<<endl;
         cout<<"����4��ɼ�"<<endl;
         cout<<"����5��GPA"<<endl;
         cout<<"����6��ӡѧ����Ϣ"<<endl;
         cout<<"����0��������������"<<endl;
         cout<<"���п�ѡ�γ̣�"<<"\n"<<"���޿�"<<'\t'<<"      ѧ��\n"<<"1��math "
         <<'\t'<<"4\n"<<"2��oop   "<<'\t'<<"2\n"<<"3��english"<<'\t'<<"2\n"<<"ѡ�޿�"<<'\t'
         <<"      ѧ��\n"<<"4��3dprint"<<'\t'<<"1\n"<<"5��shuxuejianmo"<<'\t'<<"3\n";
        while(1)
        {
            Course *cp1[105];Course *cp2[105];
           cin>>i;
           if(cin.fail())
            {
                outfile<<"����������"<<endl;
                break;
            }
            else if(i==0)
            {
                return ;
            }
            else if(i==1)
            {
                int t;
                while(cin>>t)
                {
                   if(cin.fail())
                    {
                        outfile<<"����������"<<endl;
                        break;
                    }
                    else if(t==1)
                    {
                       int h1,xuhao1;
                        cout<<"������ѡ�ڼ��ű��޿μ����óɼ�"<<endl;
                        while(cin>>h1)
                        {
                            if(cin.fail())
                            {
                                cout<<"����������"<<endl;
                                break;
                            }
                            else
                            {
                                c1++;
                                ifile>>xuhao1>>xuefeng[c1]>>kecheng[c1];

                                if(h1==xuhao1)
                                {   cin>>chengji[c1];
                                    cp1[c1]=new ObligatoryCourse();
                                    cp1[c1]->setname(kecheng[c1]);

                                    cp1[c1]->setcreditHour(xuefeng[c1]);
                                    cp1[c1]->getcreditHour();
                                    cp1[c1]->setmark(chengji[c1]);
                                    cp1[c1]->getmark();
                                    //cp1->print();
                                    outfile<<*cp1[c1]<<endl;
                                }
                                else
                                {
                                    cout<<"��Ŵ���"<<endl;break;
                                }
                            }
                        }
                    }
                    else if(t==2)
                    {
                        /*int h2,xuhao2;
                        cout<<"������ѡ�ڼ���ѡ�޿μ����óɼ�"<<endl;
                        while(cin>>h2)
                        {
                            if(cin.fail())
                            {
                                cout<<"����������"<<endl;
                                break;
                            }
                            else
                            {
                                c2++;
                                ifile>>xuhao2>>xuefeng[c2]>>kecheng[c2];

                                if(h2==xuhao2)
                                {
                                    cin>>chengji[c2];
                                    cp2[c2]=new ElectiveCourse();
                                    cp2[c2]->setname(kecheng[c2]);

                                    cp2[c2]->setcreditHour(xuefeng[c2]);
                               //cp2->print();
                                    cp2[c2]->getcreditHour();
                                    cp2[c2]->setmark(chengji[c2]);
                                    cp1[c1]->getmark();
                                    fout<<*cp2[c2]<<endl;
                                }
                                else
                                {
                                    cout<<"��Ŵ���"<<endl;break;
                                }
                            }
                        }*/
                        int h2,xuhao2;
                        cout<<"������ѡ�ڼ���ѡ�޿μ����óɼ�"<<endl;
                        while(cin>>h2)
                        {
                            if(cin.fail())
                            {
                                cout<<"����������"<<endl;
                                break;
                            }
                            else
                            {
                                c2++;
                                ifile>>xuhao2>>xuefeng[c2]>>kecheng[c2];

                                if(h2==xuhao2)
                                {   cin>>chengji[c2];
                                    cp2[c2]=new ObligatoryCourse();
                                    cp2[c2]->setname(kecheng[c2]);

                                    cp2[c2]->setcreditHour(xuefeng[c2]);
                                    cp2[c2]->getcreditHour();
                                    cp2[c2]->setmark(chengji[c2]);
                                    cp2[c2]->getmark();
                                    //cp1->print();
                                    outfile<<*cp2[c2]<<endl;
                                }
                                else
                                {
                                    cout<<"��Ŵ���"<<endl;break;
                                }
                            }
                        }
                    }
                            else
                            {
                            break;
                            }
                    }
            }
            else if(i==3)
            {
                        cout<<"�˱��޿�������1����ѡ�޿�������2"<<endl;
                        int e,f;
                     while(cin>>e)
                    {
                        if(e==1)
                        {
                            cout<<"�������˵ڼ��ſ�"<<endl;
                            cin>>f;
                            if(f>c1)
                            {
                                cout<<"������ѡ�η�Χ"<<endl;
                            }
                            else if(f==c1)
                            {
                                c1--;
                            }
                            else
                            {
                                for(int j=f;j<c1;j++)
                                {
                                 cp1[j]=cp1[j+1];
                                }
                                c1--;
                            }
                            //xuesheng.removeCourse(f);
                        }
                        else if(e==2)
                        {
                             cout<<"�������˵ڼ��ſ�"<<endl;
                            cin>>f;
                            if(f>c2)
                            {
                                cout<<"������ѡ�η�Χ"<<endl;
                            }
                            else if(f==c2)
                            {
                                c2--;
                            }
                            else
                            {
                                for(int j=f;j<c2;j++)
                                {
                                    cp2[j]=cp2[j+1];
                                }
                                c2--;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
             }
            else if(i==4)
            {
                cout<<"����޿γɼ�������1����ѡ�޿γɼ�������2"<<endl;
                int t;
                while(cin>>t)
                {
                    if(t==1)
                    {
                        cout<<"��ڼ��ſγɼ�"<<endl;
                        int h;
                       while(cin>>h)
                       {
                            if(h>c1)
                            {
                                cout<<"������ѯ��Χ"<<endl;
                                break;
                            }
                            else
                            {
                               cout<<cp1[h]->getmark()<<endl;
                            }
                       }

                    }
                    else if(t==2)
                    {
                        cout<<"��ڼ��ſγɼ�"<<endl;
                        int h;
                        while(cin>>h)
                        {
                            if(h>c2)
                            {
                                cout<<"������ѯ��Χ"<<endl;
                                break;
                            }
                            else
                            {
                               cout<<cp2[h]->getmark()<<endl;
                            }
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else if(i==5)
            {
                //cout<<"1"<<endl;
               double sum1=0,sum2=0,sum3=0,sum4=0;
               for(int j=1;j<=c1;j++)
               {
                   sum1+=cp1[j]->getmark()*xuefeng[j];
                   sum3+=xuefeng[j];
               }
               for(int j=1;j<=c2;j++)
               {
                   sum2+=cp2[j]->getmark()*xuefeng[j];
                   sum4+=xuefeng[j];
               }
               if(sum3!=0&&sum4!=0)
               {
                   gpa=(0.6*sum1)/sum3+(0.4*sum2)/sum4;
                   cout<<"��ѧ��GPA��"<<gpa<<endl;
               }
               else if(sum3==0)
               {
                    gpa=0.4*sum2/sum4;cout<<"��ѧ��GPA��"<<gpa<<endl;
               }
               else if(sum4==0)
               {
                   gpa=0.6*sum1/sum3;cout<<"��ѧ��GPA��"<<gpa<<endl;
               }
               else
               {
                cout<<"0"<<endl;
               }
            }
            else if(i==6)
            {
               outfile<<"��ѧ����Ϣ����:"<<endl;
               outfile<< xuesheng;
               for(int k=1;k<=c1;k++)
               {
                   outfile<<*cp1[k]<<endl;
               }
               for(int k=1;k<=c2;k++)
               {
                   outfile<<*cp2[k]<<endl;
               }
               //outfile<<"GPAΪ"<<gpa<<endl;
            }
            else if(i>6)
            {
               outfile<<"����ֵ������Χ������ֵ�����Ϲ淶����������"<<endl; break;
            }
        }
}
Console::~Console()
{
    //dtor
}
