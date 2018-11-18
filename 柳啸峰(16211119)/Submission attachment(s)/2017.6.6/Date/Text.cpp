#include "Text.h"
#include <iostream>
#include <iomanip>
#include "Date.h"
#include "Students.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h" 
#include <cstdio>
#include <cstring>
#include <typeinfo>
#include <fstream> 
#include "MyException.h"
Text::Text(){
}
void Text::run()
{
	cout<<"������ѧ��������";
	char p[10]; 
	cin>>p;
	MyException MyEx;
	cout<<"������ѧ�����գ�";
	int a, b, c;
	Date t1;
	while(cin>>a>>b>>c)
	{	
		Date t2(a, b, c);
		try
		{
			if(t2.getMonth()==0||t2.getDay()==0)
				throw t2;
		 }catch(Date t2)
		 {
		 	cout<<"������������ղ��Ϸ������������룡"<<endl; 
		 	MyEx.MyExceptionOfDate(a ,b, c, "������������ղ��Ϸ�");
			continue; 
		  }
		t1=t2;
		break; 		
	}
	/*try
        {
            if(num>2||num<0)
            {
                throw MyException("The array bounds");//����������������ֱ�Ӻ��ι��� 
            }
            else
                cout<<a.getCourse(num)->getScore()<<"��"<<endl;
        }
        catch (MyException &e)//catch��MyException���͵ģ�ֱ�Ӹ���e��&���õ����壩 
        {
            e.what();
        }*/ 
	cout<<"��ѧ�������ڣ�"; 
	cout<<t1<<endl;
	cout<<(t1++)<<endl;//a++���غ�����Ҫ���ô���&�����򱨴�[Error]no match for 'operator<<' (operand types are 'std::ostream {aka std::basic_ostream<char>}' and 'Date')
	cout<<t1<<endl;
	cout<<++t1<<endl;
	cout<<t1<<endl;
    Students s1(p,t1);
    cout<<"���ǵ�"<<s1.getCounter()<<"��ѧ��"<<endl;
	//s1.print();
	ifstream infileo("���޿�.txt",ios::in);
	string x;
	int t;
	ObligatoryCourse *o[10];
	int ii=1;
	while(infileo>>x>>t)
	{
		if(x!="0")
		{
			o[ii++]=new  ObligatoryCourse(0 ,x ,t );
		}
		else
			break;
	} 
	infileo.close();
	ifstream infilee("ѡ�޿�.txt",ios::in);
	ElectiveCourse *e[10];
	string xx;
	int tt;
	int jj=1;
	while(infilee>>xx>>tt)
	{
		if(xx!="0")
		{
			e[jj++]=new  ElectiveCourse('A' ,xx ,tt );
		}
		else
			break;
	 } 
	 infilee.close();
	/*ObligatoryCourse *o1=new  ObligatoryCourse(0 ,"Chinese" ,4 );
    ObligatoryCourse *o2=new  ObligatoryCourse(0 ,"maths" ,5 );
    ObligatoryCourse *o3=new  ObligatoryCourse(0 ,"English" ,3 );
    ElectiveCourse *e1=new ElectiveCourse('A' ,"PE" ,2 );
    ElectiveCourse *e2=new ElectiveCourse('B' ,"music" ,2 );*/
    /*ObligatoryCourse o1(90 ,"Chinese" ,32 );���ִ���������main�����βϵͳ��Ĭ�ϵ�free����Щ���� 
    ObligatoryCourse o2(90 ,"maths" ,32 );���������������������deleteһ�ߵĻ��ͻ�� 
    ObligatoryCourse o3(90 ,"English" ,32 );
    ElectiveCourse e1('A' ,"PE" ,16 );
    ElectiveCourse e2('D' ,"music" ,16 );*/
    cout<<"���޿��У�"<<endl; 
    cout<<"��ţ�o1 "<<"�γ�����"<<o[1]->getName()<<" ѧ�֣�"<<o[1]->getCreditHour()<<endl;//o1��ָ�� 
    cout<<"��ţ�o2 "<<"�γ�����"<<o[2]->getName()<<" ѧ�֣�"<<o[2]->getCreditHour()<<endl;
    cout<<"��ţ�o3 "<<"�γ�����"<<o[3]->getName()<<" ѧ�֣�"<<o[3]->getCreditHour()<<endl;
	cout<<"ѡ�޿��У�"<<endl; 
	cout<<"��ţ�e1 "<<"�γ�����"<<e[1]->getName()<<" ѧ�֣�"<<e[1]->getCreditHour()<<endl;
	cout<<"��ţ�e2 "<<"�γ�����"<<e[2]->getName()<<" ѧ�֣�"<<e[2]->getCreditHour()<<endl;
	cout<<"��������ѡ�ı��޿γ̱����(����0ֹͣ)��\n";
	string oo;
	while(cin>>oo)
	{
		if(oo=="0")
			break;
		else if(oo=="o1")
			s1.addCourse(o[1]);
		else if(oo=="o2")
			s1.addCourse(o[2]); 
		else if(oo=="o3")
			s1.addCourse(o[3]);
		else 
			cout<<"�ÿγ̲�����\n"; 
	 } 
	cout<<"��������ѡ��ѡ�޿γ̱��Ϊ������0ֹͣ����\n";
	string ee;
	while(cin>>ee)
	{
		if(ee=="0")
			break;
		else if(ee=="e1")
			s1.addCourse(e[1]);
		else if(ee=="e2")
			s1.addCourse(e[2]);
		else
			cout<<"�ÿγ̲�����\n";
	}	
	/*for(int i=0;i<s1.getCourseNumber();i++)
	{
		s1.getCourseList(i)->printCourse();//�麯����ʹ�� 
	}*/
	if(s1.getCourseNumber()==0)
		cout<<"��ѧ����û��ѡ�Σ�����ѧ��"<<endl;
	else
	{
		cout<<"�밴������ѡ��˳��Ϊ��Ӧ�γ��趨Ŀ��ɼ�:\n";
		s1.SetCourseGrade(MyEx);
		ofstream *outClientFile;
		outClientFile=new ofstream("stud.txt");
		if(!outClientFile) cout<<"filed"<<endl;
		(*outClientFile)<<s1;//���ѧ��ѡ�����
		outClientFile->close(); 
		cout<<s1;
		cout<<"����������ѡ�ڼ��ſΣ�"<<endl;
		int i;
		while(cin>>i)
		{
			try
			{
				if(i<0||i>=s1.getCourseNumber())
					throw i;
			}catch(int i)
			{
				cout<<"����ѡ�Ŀ�Ŀ������!���������룡"<<endl;
				MyEx.MyExceptionOfStud(i);
				continue;
			}
			break;
		}
		s1.removeCourse(i); 
		int Gpa=s1.calcCredit();
		cout<<"������ѡ�γ̵ļ���ɼ��ǣ�"<<Gpa<<endl;
	}
	 
}
Text::~Text(){
}
