#include <iostream>
#include<vector>
#include"course.h"
#include"date.h"
#include"stu.h"
#include"cishi.h"
#define Max 1000
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) 
{
	cishi x;
	x.yunxing();
	return 0;
}
/*
下面测试数据为新建一个选修课，一个必修课，然后建立三个学生类并打印名单 然后可测试 退课 打分 操作 
3
ascsave
4

4
asccccccc
5

0
liyuan 1998 7 27
1
1
4
1
2
2
1
-1

0
xu 1999 9 9
1
1
3
1
2
2
4
-1

0
xiao 1996 6 6
1
1
0
1
2
2
0
-1

2

6
0
0
66
1
78
2
A
-1
2


*/

