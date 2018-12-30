/*************************************************************************
    > File Name: main.cpp
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Thu 29 Nov 2018 09:51:22 PM CST
 ************************************************************************/

#include "const.h"
#include "header.h"
#include "SqString.h"

int main()
{
	SqString L("abcefdsfsd");
	SqString L1("sadf");
	L.show();
	L1.show();
	L.insert(1,L1);
	L.insert(L.getLength()+1,L1);
	L.show();
}