#include"interaction.h"
#include"MyException.h"
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void interaction::j()
{
	
	obligatorycourse *bx;
	electivecourse *xx;
	int bxwz = 0, xxwz = 0;
	vector<course*> xxlb, bxlb;
	ifstream fin;
	fin.open("obligatorycourse.txt");
	if (!fin.is_open())
	{
		cout << "���޿γ��ļ���ʧ�ܣ������ļ���\n";
		exit(0);
	}
	string s;
	int xf;
	while (fin >> s >> xf)
	{
		bx = new obligatorycourse;
		bx->setname(s);
		bx->setch(xf);
		bx->setgrade(-1);
		bxlb.push_back(bx);
	}
	fin.close();
	fin.open("electivecourse.txt");
	if (!fin.is_open())
	{
		cout << "ѡ�޿γ��ļ���ʧ�ܣ������ļ���\n";
		exit(0);
	}
	while (fin >> s >> xf)
	{
		xx = new electivecourse;
		xx->setname(s);
		xx->setch(xf);
		xx->setgrade('F');
		xxlb.push_back(xx);
	}
	fin.close();
	cout << "������ѧ������:";
	string ss;
	date bt;
	cin >> ss;
	cout << "\n������ѧ������:";
	cin >> bt;
	stu s1(ss, bt);
	while (1)
	{
		cout << "*************ѧ��ѡ��ϵͳ-���˵�*************\n";
		cout << "           1.ѡ���޿γ�\n";
		cout << "           2.ѡѡ�޿γ�\n";
		cout << "           3.�鿴ѡ�����\n";
		cout << "           4.��ѡ�γ�\n";
		cout << "           5.���ÿγ̳ɼ�\n";
		cout << "           6.��ѯ�γ̳ɼ�\n";
		cout << "           7.��ѯ����ɼ�\n";
		cout << "           8.��ѧ������ѡ����Ϣ���浽�ļ���\n";
		cout << "           0.�˳�ϵͳ\n";
		cout << "��ѡ����Ҫ���еĲ���(0~8):";
		int xz;
		cin >> xz;
		if (xz == 1)
		{
			cout << "��ӿ�ѡ�γ�����ѡ��һ�ſγ̣�\n";
			for (int i = 0; i < bxlb.size(); ++i)
			{
				cout << i + 1 << "." << *bxlb[i];
				cout << "\n";
			}
			cout << "0.ȡ������ѡ��\n";
			cout << "Ҫѡ��Ŀγ��ǣ�";
			int xk;
			while (1)
			{
				cin >> xk;
				if (!cin)
				{
					cin.clear();
					cin.ignore();
					cout << "���������淶���룡\nҪѡ��Ŀγ��ǣ�";
					continue;
				}
				else if (xk > bxlb.size())
				{
					
					cout << "���������淶���룡\nҪѡ��Ŀγ��ǣ�";
				}
				else
					break;
			}
			if (xk == 0)
				continue;
			s1.addcourse(bxlb[xk - 1]);
			vector<course*>::iterator iter = bxlb.begin() + xk - 1;
			bxlb.erase(iter);
		}
		else if (xz == 2)
		{
			cout << "��ӿ�ѡ�γ�����ѡ��һ�ſγ̣�\n";
			for (int i = 0; i < xxlb.size(); ++i)
			{
				cout << i + 1 << "." << *xxlb[i];
				cout << "\n";
			}
			cout << "0.ȡ������ѡ��\n";
			cout << "Ҫѡ��Ŀγ��ǣ�";
			int xk;
			while (1)
			{
				cin >> xk;
				if (!cin)
				{
					cin.clear();
					cin.ignore();
					cout << "���������淶���룡\nҪѡ��Ŀγ��ǣ�";
					continue;
				}
				if (xk > xxlb.size())
					cout << "���������淶���룡\nҪѡ��Ŀγ��ǣ�";
				else
					break;
			}
			if (xk == 0)
				continue;
			s1.addcourse(xxlb[xk - 1]);
			vector<course*>::iterator iter = xxlb.begin() + xk - 1;
			xxlb.erase(iter);
		}
		else if (xz == 3)
		{
			if (!s1.getcoursenum())
			{
				cout << "��ѧ���γ̱�Ϊ�ա�\n";
				continue;
			}
			s1.showcourse();
		}
		else if (xz == 4)
		{
			cout << "��ѡ����Ҫ��ѡ�Ŀγ̣�\n";
			s1.showcourse();
			cout << "0.ȡ�������˿�\n";
			cout << "Ҫ��ѡ�ɼ��Ŀγ��ǣ�";
			int tx;
			while (1)
			{
				cin >> tx;
				if (!cin)
				{
					cin.clear();
					cin.ignore();
					cout << "���������淶���룡\nҪ��ѡ�Ŀγ��ǣ�";
					continue;
				}
				else if (!tx)
					break;
				try
				{
					s1.removecourse(tx);
				}
				catch (bad_doman& bd)
				{
					cout << bd.what();
					cout << "\n���������룡\nҪ��ѡ�Ŀγ��ǣ�";
					continue;
				}
				break;
				/*
				else if (!s1.removecourse(tx))
				{
					cout << "���������淶���룡\nҪ��ѡ�Ŀγ��ǣ�";
				}
				else
					break;
				*/
			}
		}

		/*    �õ���type()�麯��
		else if (xz == 5)
		{
		cout << "��ѡ����Ҫ���õĿγ̣�\n";
		s1.showcoursead();
		cout << "0.ȡ�����γɼ�����\n";
		cout << "Ҫ���óɼ��Ŀγ��ǣ�";
		int sz;
		while (cin >> sz)
		{
		if (sz > s1.getcoursenum())
		cout << "���������淶���룡\nҪ���óɼ��Ŀγ��ǣ�";
		else
		break;
		}
		if (!sz)
		continue;
		if (s1.getcourse(sz - 1)->type())//bx
		{
		cout << "���������(0~100)��";
		int fs;
		cin >> fs;
		s1.getcourse(sz - 1)->setgrade(fs);
		}
		else if (!s1.getcourse(sz - 1)->type())
		{
		cout << "���������(A~E)��";
		char fs;
		cin >> fs;
		s1.getcourse(sz - 1)->setgrade(fs);
		}
		}
		*/
		else if (xz == 5)//�õ���RTTI
		{
			cout << "��ѡ����Ҫ���õĿγ̣�\n";
			s1.showcourse();
			cout << "0.ȡ�����γɼ�����\n";
			cout << "Ҫ���óɼ��Ŀγ��ǣ�";
			int sz;
			while (1)
			{
				cin >> sz;
				if (!cin)
				{
					cin.clear();
					cin.ignore();
					cout << "���������淶���룡\nҪ���óɼ��Ŀγ��ǣ�";
					continue;
				}
				else if (sz > s1.getcoursenum())
					cout << "���������淶���룡\nҪ���óɼ��Ŀγ��ǣ�";
				else
					break;
			}
			if (!sz)
				continue;
			if (dynamic_cast<obligatorycourse*>(s1.getcourse(sz - 1)) != NULL)//bx
			{
				cout << "���������(0~100)��";
				int fs;
				while (cin >> fs)
				{
					try
					{
						if (fs > 100 || fs < 0)
							throw bad_grade();
					}
					catch (bad_grade &bg)
					{
						cout << bg.what();
						cout << "\n���������룡\n���������(0~100)��";
						continue;
					}
					s1.getcourse(sz - 1)->setgrade(fs);
					break;
				}
			}
			else if (dynamic_cast<electivecourse*>(s1.getcourse(sz - 1)) != NULL)
			{
				cout << "���������(A~E)��";
				char fs;
				while (cin >> fs)
				{
					try
					{
						if (fs<'A' || fs>'E')
							throw bad_grade();
					}
					catch (bad_grade &bg)
					{
						cout << bg.what();
						cout << "\n���������룡\n���������(A~E)��";
						continue;
					}
					s1.getcourse(sz - 1)->setgrade(fs);
					break;
				}
			}
		}

		else if (xz == 6)
		{
			//cout << "��ѡ����Ҫ��ѯ�Ŀγ̣�\n";
			if (!s1.getcoursenum())
			{
				cout << "��ѧ���γ̱�Ϊ�ա�\n";
				continue;
			}
			s1.showcourse();
		}
		else if (xz == 7)
		{
			cout << "��ѧ���ļ���Ϊ��" << s1.calccredit() << "\n";
		}
		else if (xz == 8)
		{
			ofstream fout;
			fout.open("StuInfo.txt");
			if (!fout.is_open())
			{
				cerr << "�洢ѧ����Ϣ�ļ���ʧ�ܣ������ļ���\n";
				exit(0);
			}
			fout << s1 << "\n";
			cout << "���浽�ļ��ɹ���\n";
			fout.close();
		}

		else if (xz == 0)
		{
			break;
		}
		else
		{
			cout << "���������淶���룡\n";
		}
	}
}