/*************************************************************************
    > File Name: expresion.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Fri 23 Nov 2018 03:26:49 PM CST
 ************************************************************************/

#ifndef _EXPRESION_H
#define _EXPRESION_H

void test1(char *expresion, char *suffixS)
{
	cout << "×××中缀表达式变为后缀表达式×××\n";
	transform(expresion, suffixS);
	cout << "后缀表达式为:\n" << suffixS << endl;
	cout << "***************8\n";
}

void test2(char *suffixS)
{
	cout << "×××后缀表达式的的计算×××\n";
	cout << "计算结果为" << calculateall(suffixS) << endl;
	cout << "***************8\n";
}

void test3(char *expresion)
{	
	cout << "×××输入中缀表达式×××\n";
	cout << "请输入中缀表达式:";
	cin >> expresion;
	cout << "你输入中缀表达式为:\n" << expresion << endl;
	cout << "***************8\n";
}
#endif
