/*************************************************************************
    > File Name: test.cpp
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Thu 27 Dec 2018 02:07:39 PM CST
 ************************************************************************/
#include "./const.h"
#include "./header.h"
#include "SqStack.h"

#include "calculate.h"
#include "expresion.h"
#include "maze.h"
#include "test.h"

int main()
{
	SqStack<int> S;
	int a;
	S.push(2);
	S.push(3);
	S.pop(a);
	cout << a << endl;
	S.pop(a);
	cout << a << endl;


}
