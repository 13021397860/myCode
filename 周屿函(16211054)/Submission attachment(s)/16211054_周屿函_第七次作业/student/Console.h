#ifndef CONSOLE_H
#define CONSOLE_H
#define Max_Size 10
#include"Exception.h"


class Console
{
    public:
        Console();
        virtual ~Console();
        int run();    //���п���̨
    private:
        int displayMenu() const;    //��ʾϵͳ���˵�
        Course* selectCourse(int op);
        bool setCourseScore();       //�������еĿγ̳ɼ�
        Console& buildStudent();//����ѧ������
        Console& buildCourse();//�������еĿ�ѡ�γ̣��������޺�ѡ�޿Σ�
        void removeC();
        Student student;           //��ǰѧ������
        Course *oc[Max_Size];	//ȫ����ѡ�ı��޿γ��嵥
        Course *ec[Max_Size];	//ȫ����ѡ��ѡ�޿γ��嵥
        int ocNum;      //��ѡ�ı��޿γ�ʵ������
        int ecNum;
    protected:
};

#endif // CONSOLE_H
