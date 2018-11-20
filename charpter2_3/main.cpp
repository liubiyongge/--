/*************************************************************************
    > File Name: main.cpp
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年11月08日 星期四 19时41分13秒
 ************************************************************************/

#include "const.h"
#include "header.h"
#include "CircularLinklist.h"
#include "MyJosephus.h"
int main()
{
	srand((unsigned)time(NULL));
	int i, j;
	CircularLinklist<int> C;
	C.setCir();
	cout << "当前约瑟夫环为当前约瑟夫环为:" << endl;
	C.show();
	cout << "请输入起始序号:" ;
	cin >> i;
	cout << "其输入间隔结点数";
	cin >> j;
	Josephus(C, i, j);
}

