#include "Console.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <typeinfo>
#include <cstdio>
#include <cstring>
#include "Student.h"
#include "Date.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "MyException.h"
using namespace std;
#define ecMax 10
#define ocMax 10

Console::Console()
{
	cout<<"***************************** ��ӭʹ��ѧ��ѡ��ϵͳ *****************************\n";
	initConsole();
	/*
	string ecn[ecMax]={"ec1","ec2","ec3","ec4","ec5","ec6","ec7","ec8","ec9","ec10"};
	string ocn[ocMax]={"oc1","oc2","oc3","oc4","oc5","oc6","oc7","oc8","oc9","oc10"};
	int ecc[ecMax]={1,2,3,4,5,6,7,8,9,10};
	int occ[ocMax]={1,2,3,4,5,6,7,8,9,10};

	for(int i=0;i<ocMax;i++)
	{
		oc[i].setName(ocn[i]);
		oc[i].setCreditHour(occ[i]);
	}
	for(int i=0;i<ecMax;i++)
	{
		ec[i].setName(ecn[i]);
		ec[i].setCreditHour(ecc[i]);
	}
	*/
}



int Console::initConsole()//��Ҫtxt�ļ��еĿγ�˳����Ŀ�����ں궨�����
{
	ocn=0;ecn=0;
	string s;int c;

	ifstream in("InitObligatoryCourse.txt");
	if(!in.is_open())
	{
		cerr<<"Ԥ�ÿγ��ļ���ʧ�ܣ����������\n";//************throw**************
		//exit(0);
	}
	while(in>>s>>c)
	{
		//cout<<1<<endl;
		if(ocn==ocMax)
		{
			cerr<<"���޿γ��������࣡\n";
			break;
		}
		oc[ocn].setName(s);
		oc[ocn++].setCreditHour(c);
	}
	in.close();

	in.open("InitElectiveCourse.txt");
    while(in>>s>>c)
	{
		if(ecn==ecMax)
		{
			cerr<<"ѡ�޿γ��������࣡\n";
			break;
		}
		ec[ecn].setName(s);
		ec[ecn++].setCreditHour(c);
	}
	in.close();
}

int Console::ObligatoryCourseElect(Student &a)
{
	int n;
	cout<<"\n����ѡ����...\n";
	cout<<"������¿γ���ѡ��\n";

	int ch[ocn];
	for(int i=0;i<ocn;i++)
	{
		if(a.checkCourse(oc[i].getName()))ch[i]=1;
		else ch[i]=0;
	}

	for(int i=0;i<ocn;i++)
	{
		if(ch[i]==0)cout<<setw(3)<<left<<i+1<<" �γ����ƣ�"<<setw(10)<<left<<oc[i].getName()<<"ѧ�֣�"<<oc[i].getCreditHour()<<"\n";
	}
	cout<<"��������ţ����棺��������ֻᵼ�����ش��󣡣���";
	cin>>n;
	while(cin.fail()||n<1||n>ocn||ch[n-1]==1)
	{
		cin.clear();
		cin.ignore();
		cout<<"����ȷ���룺";
		cin>>n;
	}
	--n;

	ObligatoryCourse *acourse=new ObligatoryCourse(oc[n]);
	a.addCourse(acourse);
	cout<<"����ӿγ�<"<<oc[n].getName()<<">��"<<a.getName()<<"�Ŀγ��б�\n";
}

int Console::ElectiveCourseElect(Student &a)
{
	int n;
	cout<<"\nѡ��ѡ����...\n";
	cout<<"������¿γ���ѡ��\n";

	int ch[ecn];
	for(int i=0;i<ecn;i++)
	{
		if(a.checkCourse(ec[i].getName()))ch[i]=1;
		else ch[i]=0;
	}

	for(int i=0;i<ecn;i++)
	{
		if(ch[i]==0)cout<<setw(3)<<left<<i+1<<" �γ����ƣ�"<<setw(10)<<left<<ec[i].getName()<<"  ѧ�֣�"<<ec[i].getCreditHour()<<"\n";
	}
	cout<<"��������ţ����棺��������ֻᵼ�����ش��󣡣���";
	cin>>n;
	while(cin.fail()||n<1||n>ecn||ch[n-1]==1)
	{
		cin.clear();
		cin.ignore();
		cout<<"����ȷ���룺";
		cin>>n;
	}
	--n;

	ElectiveCourse *acourse=new ElectiveCourse(ec[n]);
	a.addCourse(acourse);
	cout<<"����ӿγ�<"<<ec[n].getName()<<">��"<<a.getName()<<"�Ŀγ��б�\n";
}

int Console::CourseRemove(Student &a)
{
	int n;
	cout<<"\n�˿���...\n";
	cout<<"������ѡ�γ����£�\n\n";
	a.printCourse();
	cout<<"\n��������ѡ�γ̵���ţ����棺��������ֻᵼ�����ش��󣡣���";
	cin>>n;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout<<"���������֣�";
		cin>>n;
	}
	if(a.removeCourse(n))
	{
		cout<<"��ѡ�ɹ���\n";
	}
	else
	{
		cout<<"����Ŷ�Ӧ�γ̲����ڣ�\n";
	}
}

int Console::setCourseMark(Student &a)
{
	int n;
	cout<<"\n�ɼ�¼����...\n";
	cout<<"������ѡ�γ����£�\n\n";
	a.printCourse();
	cout<<"\n������¼��γ̵���ţ����棺��������ֻᵼ�����ش��󣡣���";
	cin>>n;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout<<"���������֣�";
		cin>>n;
	}
	/*
	if(n<1||n>a.getCourseNumber()+1)
	{
		cout<<"����Ŷ�Ӧ�γ̲����ڣ�\n";
	}
	else*/
	{
		Course *ptrc=a.getCourse(n);//************
		if(typeid(*ptrc)==typeid(ObligatoryCourse))
		{
			cout<<"������<"<<ptrc->getName()<<">�ĳɼ����ٷ��ƣ���";
			int ti;
			while(1)
			{
				try
				{
					cin>>ti;
					if(cin.fail())
					{
						cin.clear();
						cin.ignore();
						throw MyException("�ɼ��Ƿ���");
					}
					if(ti<0||ti>100)throw MyException("�ɼ��Ƿ���");
					break;
				}
				catch(MyException &me)
				{
					me.printerror();
				}
			}
			/*
			cin>>ti;
			while(cin.fail()||ti<0||ti>100)
			{
				cin.clear();
				cin.ignore();
				cout<<"����ȷ���룺";
				cin>>ti;
			}
			*/
			ObligatoryCourse *ptro=dynamic_cast<ObligatoryCourse*>(ptrc);
			if(ptro)
			{
				ptro->setMark(ti);
				cout<<"¼��ɹ���<"<<ptrc->getName()<<">�ĳɼ�������Ϊ"<<ptro->getScore()<<".\n";
			}
			else
			{
				cout<<"¼��ʧ�ܣ�\n";
			}
		}
		else
		{
			cout<<"������<"<<ptrc->getName()<<">�ĳɼ���ABCDE����";
			char tc;

			while(1)
			{
				try
				{
					cin>>tc;
					if(tc<'A'||tc>'E')throw MyException("�ɼ��Ƿ���");
					break;
				}
				catch(MyException &me)
				{
					me.printerror();
				}
			}

			/*
			cin>>tc;
			while(tc<'A'||tc>'E')
			{
				//**********
					throw MyException("�ɼ��Ƿ���");
				//**********
				cout<<"����ȷ���룺";
				cin>>tc;
			}
			*/
			ElectiveCourse *ptre=dynamic_cast<ElectiveCourse*>(ptrc);
			if(ptre)
			{
				ptre->setGrade(tc);
				cout<<"¼��ɹ���<"<<ptrc->getName()<<">�ĳɼ�������Ϊ"<<ptre->getGrade()<<".\n";
			}
			else
			{
				cout<<"¼��ʧ�ܣ�\n";
			}
		}
	}
}

int ten(int i)
{
	int sum=1;
	for(int j=0;j<i;j++)
	{
		sum*=10;
	}
	return sum;
}

int Console::run()
{
	int n;

	cout<<"��ѡ�����Ĳ�����\n";
	cout<<"1���½�ѧ����ע�⣺�ѱ����ѧ���ᱻ���ǣ���\n";
	cout<<"2����ȡѧ��\n";
	cout<<"-1: �˳�����\n";
	cout<<"��������ţ����棺��������ֻᵼ�����ش��󣡣���";
	cin>>n;
	while(cin.fail()||n!=1&&n!=2&&n!=-1)
	{
		cin.clear();
		cin.ignore();
		cout<<"����ȷ���룺";
		cin>>n;
	}
	char *x=new char;
	int y,m,d;
	Date adate;
	Course *acourselist[Maxsize];
	int acoursenum=-1;

	if(n==1)
	{
		cout<<"�����������������������ڣ���ʽΪ��<����> <��> <��> <��>��\n";
		cin>>x>>y>>m>>d;
		while(cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout<<"����ȷ���룺\n";
			cin>>x>>y>>m>>d;
		}

		while(1)
		{
			try
			{
				adate.set(y,m,d);
				break;
			}
			catch(MyException &me)
			{
				me.printerror();
			}
			//cout<<"������Ϸ����ڣ���ʽΪ��<��> <��> <��>��\n";
			cin>>y>>m>>d;
			while(cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout<<"����ȷ���룺\n";
				cin>>y>>m>>d;
			}
		}
		//Student a(x,adate);
		//
	}
	else if(n==2)
	{
		ifstream in("Student.txt");
	    if(in.is_open())
	    {
			//char *aname;
	    	char f;
	    	int fl;
	    	//int y,m,d;
	    	in>>x;
	    	in>>y>>f>>m>>f>>d;
	    	adate.set(y,m,d);
	    	//Student b(aname,y,m,d);
	    	int sum,num;
	    	string cna,fstr,agrade;
	    	in>>sum;
	    	if(sum>0)
	    	{
	    		for(int i=0;i<sum;i++)
	    		{

	    			in>>fstr;
	    			//cout<<fstr<<endl;//
					in>>cna>>fstr;
					//cout<<fstr<<endl;//
					in>>fstr;
					//cout<<fstr<<endl;//
					in>>fstr>>agrade;
	    			fl=-1;
	    			for(int j=0;j<ocn;j++)
	    			{
	    				if(oc[j].getName()==cna)
	    				{
	    					fl=j;
	    					ObligatoryCourse *acourse=new ObligatoryCourse(oc[j]);
	    					if(agrade!="none")
	    					{
	    						int agr=0;
	    						for(int k=0;k<agrade.size();k++)
	    						{
	    							agr+=(agrade[k]-'0')*ten(agrade.size()-k-1);
								}

								acourse->setMark(agr);
							}
							acourselist[++acoursenum]=acourse;
	    					break;
						}
					}

					if(fl==-1)
					{
						for(int j=0;j<ecn;j++)
		    			{

							if(ec[j].getName()==cna)
		    				{
		    					fl=j;
		    					ElectiveCourse *acourse=new ElectiveCourse(ec[j]);
		    					if(agrade!="none")
		    					{
		    						char agr;
		    						if(agrade=="95")agr='A';
		    						else if(agrade=="85")agr='B';
		    						else if(agrade=="75")agr='C';
		    						else if(agrade=="65")agr='D';
		    						else if(agrade=="55")agr='E';
									acourse->setGrade(agr);
								}

								acourselist[++acoursenum]=acourse;
		    					break;
							}
						}
					}
				}
			}
			cout<<"ѧ����Ϣ��ȡ��ɡ�\n";
			in.close();
		}
		else
		{
			cerr<<"ѧ����Ϣ��ȡʧ�ܣ�\n";//************throw**************
			//exit(0);
		}
	}
	else
	{
		return 0;
	}

	Student a(x,adate);
	if(n==2)
	{
		a.initCourse(acourselist,acoursenum);
		//cout<<acoursenum<<endl;
	}

	cout<<a.getName()<<"�������ѧ���б�\n\n";

	while(1)
	{
		cout<<"--------------------------------------------------------------------------------\n";
		cout<<a.getName()<<"ͬѧ����ѡ�������\n";
		cout<<"1: ����ѡ��\n";
		cout<<"2: ѡ��ѡ��\n";
		cout<<"3: ��ѡ�γ�\n";
		cout<<"4����ѡ�γ�\n";
		cout<<"5���ɼ�¼��\n";
		cout<<"6���ɼ���ѯ\n";
		cout<<"7�������ѯ\n";
		cout<<"-1: �˳�����\n";
		cout<<"��������ţ����棺��������ֻᵼ�����ش��󣡣���";
		cin>>n;
		while(cin.fail()||n!=1&&n!=2&&n!=3&&n!=4&&n!=5&&n!=6&&n!=7&&n!=-1)
		{
			cin.clear();
			cin.ignore();
			cout<<"����ȷ���룺";
			cin>>n;
		}

		if(n==1)
		{
			do
			{
				if(a.courseFull())
				{
					cout<<"�γ���������ѡ����������\n";
					break;
				}
				ObligatoryCourseElect(a);
				cout<<"\n���Ƿ���Ҫ����ѡ�Σ�(1/������)�����棺��������ֻᵼ�����ش��󣡣�\n";
				cin>>n;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout<<"����ȷ���룺\n";
					cin>>n;
				}
			}
			while(n==1);
		}
		else if(n==2)
		{
			do
			{
				if(a.courseFull())
				{
					cout<<"�γ���������ѡ����������\n";
					break;
				}
				ElectiveCourseElect(a);
				cout<<"\n���Ƿ���Ҫ����ѡ�Σ�(1/������)�����棺��������ֻᵼ�����ش��󣡣�\n";
				cin>>n;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout<<"����ȷ���룺\n";
					cin>>n;
				}
			}
			while(n==1);
		}
		else if(n==3)
		{
			cout<<"\n";
			a.printCourse();
		}
		else if(n==4)
		{
			do
			{
				if(a.getCourseNumber()==-1)
				{
					cout<<"���Ŀγ��б�Ϊ�գ�\n";
					break;
				}
				try
				{
					CourseRemove(a);
				}
				catch(MyException &me)
				{
					me.printerror();
				}

				cout<<"\n���Ƿ���Ҫ�����˿Σ�(1/������)\n";
				cin>>n;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout<<"����ȷ���룺\n";
					cin>>n;
				}
			}
			while(n==1);
		}
		else if(n==5)
		{
			do
			{
				if(a.getCourseNumber()==-1)
				{
					cout<<"���Ŀγ��б�Ϊ�գ�\n";
					break;
				}
				try
				{
					setCourseMark(a);
				}
				catch(MyException &me)
				{
					me.printerror();
				}

				cout<<"\n���Ƿ���Ҫ����¼�룿(1/������)\n";
				cin>>n;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout<<"����ȷ���룺\n";
					cin>>n;
				}
			}
			while(n==1);
		}
		else if(n==6)
		{
			cout<<"\n";
			a.printCourse();
		}
		else if(n==7)
		{
			cout<<"\n";
			cout<<"����GPAΪ��"<<a.calcCredit()<<"\n";
		}
		else if(n==-1)
		{
			break;
		}
		cout<<"\n";
		//system("pause");
	}
	if(saveStudent(a))
	{
		cout<<"ѧ����Ϣ�洢�ɹ���\n";
	}
	delete []x;
	return 0;
}

int Console::saveStudent(Student &a)
{
	ofstream out("Student.txt");
    if(out.is_open())
    {
    	out<<a.getName()<<"\n"<<a.getDate2()<<"\n";
    	out<<a.getCourseNumber()+1<<"\n";
    	Course *p;
    	for(int i=0;i<=a.getCourseNumber();i++)
    	{
    		p=a.getCourse(i+1);
    		out<<*p<<"\n";
		}
		out<<a.calcCredit()<<"\n";
		out.close();
	}
	else
	{
		cerr<<"ѧ����Ϣ�洢ʧ�ܣ�\n";//************throw**************
		return 0;//exit(0);
	}

	return 1;
}

Console::~Console()
{
	cout<<"\n***************************** ��лʹ��ѧ��ѡ��ϵͳ *****************************\n";
}
