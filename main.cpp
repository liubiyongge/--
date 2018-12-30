/*************************************************************************
    > File Name: main.cpp
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Sun 30 Dec 2018 10:05:22 AM CST
 ************************************************************************/
#include "header.h"
#include "const.h"
#include "MGraph.h"

int main(int argc, char const *argv[])
{
	MGraph<char> M;
	M.input();
	M.printMGraph();
	M.Prim();
	M.kruskal();
	return 0;
}