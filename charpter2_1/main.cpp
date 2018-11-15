/*************************************************************************
    > File Name: struct1.cpp
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年10月01日 星期一 15时48分53秒
	>fuction: test Liner struct
 ************************************************************************/
//线性表顺序存储结构
#include "header.h"

#include "const.h"
#include "class_outfunction.h"
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
	show(L);
	return 0;
}





