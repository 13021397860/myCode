#include <iostream>
#include "date.h"
using namespace std;

int main()
{
    //���Գ���
    cout<<"�������� �� ��:"<<endl;
    int year,month,day;
    cin>>year>>month>>day;
    //���캯��
    date mydate(year,month,day);
    //������һ��
    mydate.print();
    cout<<"��һ����:";
    mydate.nextDay();
    //get�������˽�б���
    cout<<mydate.getYear()<<"."<<mydate.getMonth()<<"."<<mydate.getDay()<<endl;
    //�ж��Ƿ�������
    if(mydate.isLeapYear()) cout<<"It's leap year\n";
    else cout<<"It isn't leap year\n";
    //set����������������
    cout<<"���������޸ĵ�����:";
    cin>>year>>month>>day;
    mydate.setDate(year,month,day);

    cout<<"��ǰ����Ϊ:";
    mydate.print();
    return 0;
}


