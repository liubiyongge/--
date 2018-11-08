/*************************************************************************
    > File Name: struct1.cpp
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年10月01日 星期一 15时48分53秒
	>fuction: test Liner struct
 ************************************************************************/
//线性表顺序存储结构
#include "header.h"

#include "class_function.h"
#include "function.h"
#include "mySetSqlist.h"

//Origal================================================

int main()
{
	Sqlist<int> L;
	L.ListInsert_Sq(1, 2);
	L.ListInsert_Sq(2, 3);
	L.ListInsert_Sq(3, 4);
	L.ListInsert_Sq(4, 5);
	L.ListInsert_Sq(5, 6);
	L.ListInsert_Sq(6, 7);
	L.ListInsert_Sq(7, 8);
	Sqlist<int> L1;
	L1.ListInsert_Sq(1, 3);
	L1.ListInsert_Sq(2, 5);
	L1.ListInsert_Sq(3, 7);
	L1.ListInsert_Sq(4, 9);
	L1.ListInsert_Sq(5, 11);
	L1.ListInsert_Sq(6, 19);
	L1.ListInsert_Sq(7, 3);
	Sqlist<int> L2;
	L2 = differenceSet(L, L1);
	int e;
	for(int i = 1;i <= L2.getLength(); i++)
	{
		L2.getElem(i, e);
		cout<<e<<endl;
	}
	return 0;
}





