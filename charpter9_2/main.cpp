/*************************************************************************
    > File Name: main.cpp
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Wed 26 Dec 2018 08:04:45 PM CST
 ************************************************************************/
#include "header.h"
#include "const.h"
#include "ChainTree.h"
	
int main(int argc, char const *argv[])
{
	ChainTree<char> C;
	C.create();
	C.preorderTraversal();
	C.inorderTraversal();
	C.postorderTraversal();
	cout << C.getDepth() << endl;
	return 0;
}

