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
		cout << "必修课程文件打开失败，请检查文件！\n";
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
		cout << "选修课程文件打开失败，请检查文件！\n";
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
	cout << "请输入学生姓名:";
	string ss;
	date bt;
	cin >> ss;
	cout << "\n请输入学生生日:";
	cin >> bt;
	stu s1(ss, bt);
	while (1)
	{
		cout << "*************学生选课系统-主菜单*************\n";
		cout << "           1.选必修课程\n";
		cout << "           2.选选修课程\n";
		cout << "           3.查看选课情况\n";
		cout << "           4.退选课程\n";
		cout << "           5.设置课程成绩\n";
		cout << "           6.查询课程成绩\n";
		cout << "           7.查询绩点成绩\n";
		cout << "           8.将学生及其选课信息保存到文件中\n";
		cout << "           0.退出系统\n";
		cout << "请选择需要进行的操作(0~8):";
		int xz;
		cin >> xz;
		if (xz == 1)
		{
			cout << "请从可选课程里面选择一门课程：\n";
			for (int i = 0; i < bxlb.size(); ++i)
			{
				cout << i + 1 << "." << *bxlb[i];
				cout << "\n";
			}
			cout << "0.取消本次选课\n";
			cout << "要选择的课程是：";
			int xk;
			while (1)
			{
				cin >> xk;
				if (!cin)
				{
					cin.clear();
					cin.ignore();
					cout << "输入错误，请规范输入！\n要选择的课程是：";
					continue;
				}
				else if (xk > bxlb.size())
				{
					
					cout << "输入错误，请规范输入！\n要选择的课程是：";
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
			cout << "请从可选课程里面选择一门课程：\n";
			for (int i = 0; i < xxlb.size(); ++i)
			{
				cout << i + 1 << "." << *xxlb[i];
				cout << "\n";
			}
			cout << "0.取消本次选课\n";
			cout << "要选择的课程是：";
			int xk;
			while (1)
			{
				cin >> xk;
				if (!cin)
				{
					cin.clear();
					cin.ignore();
					cout << "输入错误，请规范输入！\n要选择的课程是：";
					continue;
				}
				if (xk > xxlb.size())
					cout << "输入错误，请规范输入！\n要选择的课程是：";
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
				cout << "该学生课程表为空。\n";
				continue;
			}
			s1.showcourse();
		}
		else if (xz == 4)
		{
			cout << "请选择需要退选的课程：\n";
			s1.showcourse();
			cout << "0.取消本次退课\n";
			cout << "要退选成绩的课程是：";
			int tx;
			while (1)
			{
				cin >> tx;
				if (!cin)
				{
					cin.clear();
					cin.ignore();
					cout << "输入错误，请规范输入！\n要退选的课程是：";
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
					cout << "\n请重新输入！\n要退选的课程是：";
					continue;
				}
				break;
				/*
				else if (!s1.removecourse(tx))
				{
					cout << "输入错误，请规范输入！\n要退选的课程是：";
				}
				else
					break;
				*/
			}
		}

		/*    用的是type()虚函数
		else if (xz == 5)
		{
		cout << "请选择需要设置的课程：\n";
		s1.showcoursead();
		cout << "0.取消本次成绩设置\n";
		cout << "要设置成绩的课程是：";
		int sz;
		while (cin >> sz)
		{
		if (sz > s1.getcoursenum())
		cout << "输入错误，请规范输入！\n要设置成绩的课程是：";
		else
		break;
		}
		if (!sz)
		continue;
		if (s1.getcourse(sz - 1)->type())//bx
		{
		cout << "请输入分数(0~100)：";
		int fs;
		cin >> fs;
		s1.getcourse(sz - 1)->setgrade(fs);
		}
		else if (!s1.getcourse(sz - 1)->type())
		{
		cout << "请输入分数(A~E)：";
		char fs;
		cin >> fs;
		s1.getcourse(sz - 1)->setgrade(fs);
		}
		}
		*/
		else if (xz == 5)//用的是RTTI
		{
			cout << "请选择需要设置的课程：\n";
			s1.showcourse();
			cout << "0.取消本次成绩设置\n";
			cout << "要设置成绩的课程是：";
			int sz;
			while (1)
			{
				cin >> sz;
				if (!cin)
				{
					cin.clear();
					cin.ignore();
					cout << "输入错误，请规范输入！\n要设置成绩的课程是：";
					continue;
				}
				else if (sz > s1.getcoursenum())
					cout << "输入错误，请规范输入！\n要设置成绩的课程是：";
				else
					break;
			}
			if (!sz)
				continue;
			if (dynamic_cast<obligatorycourse*>(s1.getcourse(sz - 1)) != NULL)//bx
			{
				cout << "请输入分数(0~100)：";
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
						cout << "\n请重新输入！\n请输入分数(0~100)：";
						continue;
					}
					s1.getcourse(sz - 1)->setgrade(fs);
					break;
				}
			}
			else if (dynamic_cast<electivecourse*>(s1.getcourse(sz - 1)) != NULL)
			{
				cout << "请输入分数(A~E)：";
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
						cout << "\n请重新输入！\n请输入分数(A~E)：";
						continue;
					}
					s1.getcourse(sz - 1)->setgrade(fs);
					break;
				}
			}
		}

		else if (xz == 6)
		{
			//cout << "请选择需要查询的课程：\n";
			if (!s1.getcoursenum())
			{
				cout << "该学生课程表为空。\n";
				continue;
			}
			s1.showcourse();
		}
		else if (xz == 7)
		{
			cout << "该学生的绩点为：" << s1.calccredit() << "\n";
		}
		else if (xz == 8)
		{
			ofstream fout;
			fout.open("StuInfo.txt");
			if (!fout.is_open())
			{
				cerr << "存储学生信息文件打开失败，请检查文件！\n";
				exit(0);
			}
			fout << s1 << "\n";
			cout << "保存到文件成功！\n";
			fout.close();
		}

		else if (xz == 0)
		{
			break;
		}
		else
		{
			cout << "输入错误！请规范输入！\n";
		}
	}
}