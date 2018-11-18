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
    //cout<<"请输入学生的名字及出生日期"<<endl;
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
       //cout<<"该日期下一天是"<<rq++<<endl;
         outfile<<"该日期下一天是"<<rq++<<endl;
         c1=0,c2=0;
         cout<<"输入1选课"<<endl;
         cout<<"输入3退课"<<endl;
         cout<<"输入4查成绩"<<endl;
         cout<<"输入5查GPA"<<endl;
         cout<<"输入6打印学生信息"<<endl;
         cout<<"输入0或其它结束程序"<<endl;
         cout<<"所有可选课程："<<"\n"<<"必修课"<<'\t'<<"      学分\n"<<"1、math "
         <<'\t'<<"4\n"<<"2、oop   "<<'\t'<<"2\n"<<"3、english"<<'\t'<<"2\n"<<"选修课"<<'\t'
         <<"      学分\n"<<"4、3dprint"<<'\t'<<"1\n"<<"5、shuxuejianmo"<<'\t'<<"3\n";
        while(1)
        {
            Course *cp1[105];Course *cp2[105];
           cin>>i;
           if(cin.fail())
            {
                outfile<<"请输入数字"<<endl;
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
                        outfile<<"请输入数字"<<endl;
                        break;
                    }
                    else if(t==1)
                    {
                       int h1,xuhao1;
                        cout<<"请输入选第几门必修课及设置成绩"<<endl;
                        while(cin>>h1)
                        {
                            if(cin.fail())
                            {
                                cout<<"请输入数字"<<endl;
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
                                    cout<<"序号错误"<<endl;break;
                                }
                            }
                        }
                    }
                    else if(t==2)
                    {
                        /*int h2,xuhao2;
                        cout<<"请输入选第几门选修课及设置成绩"<<endl;
                        while(cin>>h2)
                        {
                            if(cin.fail())
                            {
                                cout<<"请输入数字"<<endl;
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
                                    cout<<"序号错误"<<endl;break;
                                }
                            }
                        }*/
                        int h2,xuhao2;
                        cout<<"请输入选第几门选修课及设置成绩"<<endl;
                        while(cin>>h2)
                        {
                            if(cin.fail())
                            {
                                cout<<"请输入数字"<<endl;
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
                                    cout<<"序号错误"<<endl;break;
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
                        cout<<"退必修课请输入1，退选修课请输入2"<<endl;
                        int e,f;
                     while(cin>>e)
                    {
                        if(e==1)
                        {
                            cout<<"请输入退第几门课"<<endl;
                            cin>>f;
                            if(f>c1)
                            {
                                cout<<"超出已选课范围"<<endl;
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
                             cout<<"请输入退第几门课"<<endl;
                            cin>>f;
                            if(f>c2)
                            {
                                cout<<"超出已选课范围"<<endl;
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
                cout<<"查必修课成绩请输入1，查选修课成绩请输入2"<<endl;
                int t;
                while(cin>>t)
                {
                    if(t==1)
                    {
                        cout<<"查第几门课成绩"<<endl;
                        int h;
                       while(cin>>h)
                       {
                            if(h>c1)
                            {
                                cout<<"超出查询范围"<<endl;
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
                        cout<<"查第几门课成绩"<<endl;
                        int h;
                        while(cin>>h)
                        {
                            if(h>c2)
                            {
                                cout<<"超出查询范围"<<endl;
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
                   cout<<"该学生GPA是"<<gpa<<endl;
               }
               else if(sum3==0)
               {
                    gpa=0.4*sum2/sum4;cout<<"该学生GPA是"<<gpa<<endl;
               }
               else if(sum4==0)
               {
                   gpa=0.6*sum1/sum3;cout<<"该学生GPA是"<<gpa<<endl;
               }
               else
               {
                cout<<"0"<<endl;
               }
            }
            else if(i==6)
            {
               outfile<<"该学生信息如下:"<<endl;
               outfile<< xuesheng;
               for(int k=1;k<=c1;k++)
               {
                   outfile<<*cp1[k]<<endl;
               }
               for(int k=1;k<=c2;k++)
               {
                   outfile<<*cp2[k]<<endl;
               }
               //outfile<<"GPA为"<<gpa<<endl;
            }
            else if(i>6)
            {
               outfile<<"输入值超出范围或输入值不符合规范，结束程序"<<endl; break;
            }
        }
}
Console::~Console()
{
    //dtor
}
