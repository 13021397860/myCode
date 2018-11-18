#include "Console.h"
#include "Student.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Date.h"
#include "MyExpection.h"
#include <iostream>
#include <string.h>
#include <fstream> 

using namespace std;

int Console::num=0;

	
Console::Console()
{
}

int Console::run()
{
	char a;
	char* b;
	int occ=0;
	int ecc=0;
	cout<<"��ѡ���޿γ̣�"<<endl;
	string name;
	int mark;
	char grade;
	int credit;
	ifstream infile("Course.txt",ios::in);
	if(!infile)
	{
		cout<<"error"<<endl;
	}
	for(int i=0;i<6;i++)
	{
		if(i<=2)
		{
			infile>>name>>credit>>mark;
			cout<<"�γ̣�"<<name<<" ѧ��:"<<credit<<endl;
		}
		else
		{
			infile>>name>>credit>>grade;
			cout<<"�γ̣�"<<name<<" ѧ��:"<<credit<<endl;
		}
	}
	infile.close();
	char f[100];
	char *h=f;
	int i,j,k; 
	cout<<"�������֣�"; 
	cin>>h;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout<<"�����������������"<<endl;
		cin>>h;
	}
	cout<<endl;
	cout<<"�������գ�";
	cin>>i>>j>>k;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout<<"�����������������"<<endl;
		cin>>i>>j>>k;
	}
	int huhu=0;
	MyExpection ex("ʱ��");
	try
	{
		cout<<"������"<<ex.time(i,j,k)<<endl; 
	}
	catch(MyExpection ex)
	{
		cout<<ex.what()<<"�쳣"<<endl;
		huhu=1;
	}
	if(huhu==1)
	{
		cout<<"��������"<<endl;
		cin>>i>>j>>k;
	}
	Student t1(h,Date(i,j,k));
	cout<<"��ѡ��γ̣�(ѡ���밴#,ɾ���밴7,���޿γɼ�����0~100��ѡ�޿�ΪA-E)"<<endl;
	int n;
	int m;
	ObligatoryCourse *oc[3];
	ElectiveCourse *ec[3];
	cin>>a;
	char c;
	while(a!='#')
	{
		if(cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout<<"�����������������"<<endl;
		}
		else
		{
			if(a=='1')
			{
				oc[occ]=(new ObligatoryCourse("���ݽṹ",2,98));
				occ++;
				cout<<"��ѡ"<<endl;
			}
			else if(a=='2')
			{
				oc[occ]=(new ObligatoryCourse("�������",2,98));
				occ++;
				cout<<"��ѡ"<<endl;
			}
			else if(a=='3')
			{
				oc[occ]=(new ObligatoryCourse("��ɢ��ѧ",2,98));
				occ++;
				cout<<"��ѡ"<<endl;
			}
			else if(a=='4')
			{
				c='A';
				ec[ecc]=(new ElectiveCourse("����",1,c));
				ecc++;
				cout<<"��ѡ"<<endl;
			}
			else if(a=='5')
			{
				c='A';
				ec[ecc]=(new ElectiveCourse("Ӣ��",1,c));
				ecc++;
				cout<<"��ѡ"<<endl;
			} 
			else if(a=='6')
			{
				c='A';
				t1.addElectiveCourse(new ElectiveCourse("����",1,c));
				ec[ecc]=(new ElectiveCourse("����",1,c));
				ecc++;
				cout<<"��ѡ"<<endl;
			}
			else if(a=='7')
			{
				cin>>n;
				if(n>=1&&n<=3)
				{
					if(n>occ)
					{
						cout<<"�˲�������"<<endl;
					}
					else
					{
						cout<<1<<endl;
						for(int i=n-1;i<occ-1;i++)
						{
							oc[i]=oc[i+1];
						}
						delete oc[occ-1];
						occ--;
						cout<<"�˿γ�����ѡ"<<endl; 
					}
				}
				else
				{
					if(n>ecc)
					{
						cout<<"�˲�������"<<endl;
					}
					else
					{
						for(int i=n-1;i<ecc;i++)
						{
						ec[i]=ec[i+1];
						}
						delete ec[ecc-1];
						ecc--;
						cout<<"�˿γ�����ѡ"<<endl;
					}
				}
			}
			else
			{
				cin.clear();
				cin.ignore();
				cout<<"�����������������"<<endl;
			}
		}
		cin>>a;

}	
	int p;
	char q;
	string t;
	int d;
	for(int i=0;i<=2;i++)
	{
		cout<<"������޿�"<<oc[i]->getCoursename()<<"�ĳɼ���"; 
		cin>>p;
		int u=0;
		MyExpection ex("�ɼ�����");
		try
		{
			cout<<ex.ograde(p)<<endl;;
		}
		catch(MyExpection ex)
		{
			u=1;
			cout<<ex.what()<<"�쳣"<<endl;
		}
		if(u==1)
		{
			i--;
		}
		else
		{
			t=oc[i]->getCoursename();
		d=oc[i]->getCoursecreditHour();
		oc[i]=new ObligatoryCourse(t,d,p);
		t1.addObligatoryCourse(oc[i]);
		}
	}
	for(int i=0;i<=2;i++)
	{
		int u=0;
		cout<<"����ѡ�޿�"<<ec[i]->getCoursename()<<"�ĵȼ���"; 
		cin>>q;
		try
		{
			cout<<ex.egrade(q)<<endl;;
		}
		catch(MyExpection ex)
		{
			u=1;
			cout<<ex.what()<<"�쳣"<<endl;
		}
		if(u==1)
		{
			i--;
		}
		else
		{
			t=ec[i]->getCoursename();
		d=ec[i]->getCoursecreditHour();
		ec[i]=new ElectiveCourse(t,d,q);
		t1.addElectiveCourse(ec[i]);
		}
	}
	cout<<t1; 
	int g;
	cout<<"��������Ҫ��ѯ�Ŀ�Ŀ��ţ����˳���ѯ������#��"<<endl;
	t1.search();
	cout<<"��Ҫ��ѯ����������YES��������������"<<endl;
	char *chi;
	char chi1[100];
	chi=chi1;
	cin>>chi;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout<<"�����������������"<<endl;
		cin>>chi;
	}
	if(strcmp(chi,"YES")==0)
	{
		t1.calcCredit();
	}
	ofstream outfile("Student.txt",ios::out);
	if(!outfile)
	{
		cout<<"error"<<endl;
	}
	outfile<<t1;     
	outfile.close();
}
Console::~Console()
{

}
