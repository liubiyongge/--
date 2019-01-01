/*************************************************************************
    > File Name: main.cpp
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Mon 31 Dec 2018 09:08:27 AM CST
 ************************************************************************/

#include<iostream>

using namespace std;


struct Linkrow
{
	int data;
	int next;
};
#include "Sort.h"

int main(int argc, char const *argv[])
{
	//int a[7] = {2,5,19,3,8,4,2};
	//binaryInsertSort(a, 7);
	//print_R(a,7)
	Linkrow a[8];
	a[7].data = 2;
	a[1].data = 5;
	a[2].data = 19;
	a[3].data = 3;
	a[4].data = 8;
	a[5].data = 4;
	a[6].data = 2;
	staticLinkSort(a, 8);
	print_R(a,8)
	a[1].next = 1;
	return 0;
}

