#include "Console.h"
#include <iostream>

#include "Student.h"

#include "Obligatorycourse.h"
#include "electivecourse.h"
#include "course.h"
#include <vector>
#include <fstream>
#include <string>
#include "MyException.h"
#include<stdlib.h>
using namespace std;


Console::Console()
{
}


Console::~Console()
{
}
void Console::run() {

    try{

        string name;
        Date  brithday;
        //����ѧ��
        cout << "������ѧ������:";
        cin >> name;
        cout << "������ѧ������(��ʽ:xxxx-mm-dd):";
        cin >> brithday;

        Student* stu = new Student(name, brithday);


        //�����ű��޿κ�ѡ�޿ε�����
        std::vector<ObligatoryCourse*> obligatoryCourses;
        std::vector<ElectiveCourse*> electiveCourses;

        obligatoryCourses.push_back(new ObligatoryCourse("c++", 4));
        obligatoryCourses.push_back(new ObligatoryCourse("��ɢ��ѧ", 4));
        obligatoryCourses.push_back(new ObligatoryCourse("�ߵ���ѧ", 3));

        electiveCourses.push_back(new ElectiveCourse("��������", 2));
        electiveCourses.push_back(new ElectiveCourse("�������", 1));
        electiveCourses.push_back(new ElectiveCourse("�Ļ���չʷ", 2));



        while (1){
            cout << "��������Ҫѡ��Ŀγ�����" << endl;
            cout << "1.���޿�" << endl;
            cout << "2.ѡ�޿�" << endl;
            cout << "-1.�˳�ѡ��" << endl;
            int op;
            cin >> op;

            if (op == 1){
                int k = 5;
                while (k--) {
                    cout << "������ѡ�εı��" << endl;
                    for (int i = 0; i < obligatoryCourses.size(); ++i) {
                        cout << i+1<<"." << *obligatoryCourses[i] << endl;
                    }
                    cout << "-1.����ѡ��" << endl;
                    cin >> op;
                    if (op == -1)
                        break;
                    if (op <= 0 || op > obligatoryCourses.size()) {
                        cerr << "���������Ϣ���󣬳��������˳���" << endl;
                        exit(1);
                    }
                    cout << "������ÿεķ���:";
                    int scor;
                    cin >> scor;
                    obligatoryCourses[op - 1]->setMark(scor);
                    stu->addCourse(obligatoryCourses[op - 1]);
                    cout << "��ӳɹ�" << endl;
                }


            }
            else if (op == 2) {
                int k = 5;
                while (k--) {
                    cout << "������ѡ�εı��" << endl;
                    for (int i = 0; i < electiveCourses.size(); ++i) {
                        cout << i+1<<"." << *electiveCourses[i] << endl;
                    }
                    cout << "-1.����ѡ��" << endl;
                    cin >> op;
                    if (op == -1) {
                        break;
                    }
                    if (op <= 0 || op > electiveCourses.size()) {
                        cerr << "���������Ϣ���󣬳��������˳���" << endl;
                        exit(1);
                    }
                    cout << "������ÿεĳɼ�(A-E):";
                    char scor;
                    cin >> scor;
                    electiveCourses[op - 1]->setGrade(scor);
                    stu->addCourse(electiveCourses[op - 1]);
                    cout << "��ӳɹ�!" << endl;
                }
            }
            else if(op == -1){
                break;
            }
            else {
                cerr << "���������Ϣ���󣬳��������˳���" << endl;
                exit(1);
            }



        }

        //�����еı��޿κ�ѡ�޿δ��뵽�ļ���

        //�����ļ������
        std::ofstream of_c("�γ���Ϣ.txt");

        //of_c << "------------------���޿�------------------- " << endl;
        //�������޿�
        for (int i = 0; i < obligatoryCourses.size(); ++i) {

            //������ļ��С�
            of_c << *obligatoryCourses[i] << endl;
        }
        //of_c << endl<< endl;
        //of_c << "------------------ѡ�޿�------------------- " << endl;

        //����ѡ�޿�
        for (int i = 0; i < electiveCourses.size(); ++i) {

            //������ļ��С�
            of_c << *electiveCourses[i] << endl;
        }

        //�ر��ļ���
        of_c.close();



        //�����ļ������������ڶ�ȡ�ļ��е�����

        std::ifstream if_c("�γ���Ϣ.txt");

        string line;

        cout << endl << endl << "�ļ��е�����Ϊ-------------------------->" << endl;

        //��û����������һֱѭ��
        while (!if_c.eof()) {

            //���ļ����ж���һ�У�����line��
            getline(if_c,line);

            //��ӡ������̨��ʾ
            cout << line << endl;
        }

        //�ر���
        if_c.close();

        //�洢ѧ������Ϣ����ѡ�ε���Ϣ���ļ���

        //�����ļ������
        std::ofstream stu_of("ѧ����Ϣ��ѡ����Ϣ.txt");

        stu_of << *stu;
        stu_of.close();
    //	std::cout << *stu << std::endl;

        Student stu2;

        //�ٴ��ļ��ж�ȡ�γ���Ϣ���ָ�
        std::ifstream stu_if("ѧ����Ϣ��ѡ����Ϣ.txt");
        stu_if >> stu2;

        //�ر��ļ�������

        stu_if.close();

        cout << "���ļ��ж����ѧ������ϢΪ-------------------------->" << endl;
        cout << stu2 << endl;
    }catch(const MyException& e){
        cout<<"catch excepton:"<<e.info<<endl;
    }


	//stu->removeCourse(1);
	//std::cout << "ɾ����" << std::endl;
	//cout << *stu << std::endl;
}
