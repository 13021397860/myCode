#include <iostream>
#include"Student.h"
#include"Course.h"
#include"Date.h"
#include"ElectiveCourse.h"
#include"ObligatoryCourse.h"
#include"Console.h"
#include<iomanip>
#include<fstream>
#include<typeinfo>
#include"MyException.h"
using namespace std;
int main()
{
    Console con;
    con.run();






//********���ߵĻ�*******
//�ļ�����Ĭ��Ŀ¼����
//studentclass.txt�Ƕ���γ��ļ�������д�ã�
//�ܹ���������Ƿ��ַ��������
//���Զ��ѡ�κ���ѡ���������ظ�ѡһ�ſ�
//��������������ѧ����Ϣ������Ĭ��Ŀ¼��student.txt
//�ɼ����������Դ��ѡ�޿�ֻ��5���ɼ�����A��95,B:85,C:75,D:65,E:55

    /*  ifstream tFile("studentclass.txt", ios::in);
      int num;
      string str1;
      string str2;
      int i=0;
      while(tFile>>str1>>str2>>num)
      {
          //cout<<str1<<str2<<num;
          if(str1=="ElectiveCourse")
          {
              courseListmain[i]=new ElectiveCourse();
              courseListmain[i]->setCreditHour(num);
              courseListmain[i]->setName(str2);
              //  cout<<courseListmain[i]->getName();
          }
          else if(str1=="ObligatoryCourse")
          {
              courseListmain[i]=new ObligatoryCourse();
              courseListmain[i]->setCreditHour(num);
              courseListmain[i]->setName(str2);
          }
          ++i;
      }
      for(int j=0; j<i; j++)
      {
          if(typeid(ObligatoryCourse)==typeid(*courseListmain[j]))
          {
              ObligatoryCourse*temp=dynamic_cast<ObligatoryCourse*>(courseListmain[j]);
              cout<<" "<<*temp;
          }
          else if(typeid(ElectiveCourse)==typeid(*courseListmain[j]))
          {
              ElectiveCourse*temp1=dynamic_cast<ElectiveCourse*>(courseListmain[j]);
              cout<<" "<<*temp1;
          }
      }
      */
    /*  Student xiaoming("xiaoming",1997,1,1);
      Course*cPtr0=new ObligatoryCourse();
      cPtr0->setScore(100);
      cPtr0->setCreditHour(2);
      cPtr0->setName("music");
      //  cout<<cPtr0->getScore()<<endl;

      Course*cptr1=new ElectiveCourse();
      cptr1->setScore(100);
      cptr1->setCreditHour(2);
      cptr1->setName("math");
      //  cout<<cptr1->getScore()<<endl;


      Course*aa=new ObligatoryCourse();
      aa->setScore(100);
      aa->setCreditHour(1);
      aa->setName("ads");


      xiaoming.addCourse(cPtr0).addCourse(cptr1).addCourse(aa);
      cout<<xiaoming<<endl;
      cout<<xiaoming.calcCredit()<<endl;
      xiaoming.removeCourse(0);
      cout<<xiaoming;      //��ѧ����Ϣ������ļ�����д���ļ�
      ofstream outfile("D:\\student.txt", ios::out);

      outfile<<xiaoming;
      */
    return 0;
}
