/*************************************************************************
    > File Name: main.cpp
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Mon 26 Nov 2018 09:30:58 PM CST
 ************************************************************************/

#include "header.h"
#include "const.h"
#include "sqQueue.h"

int main(int argc, char const *argv[])
{
	
	sqQueue<int> S;
	S.enQueue(4);
	S.enQueue(5);
	sqQueue<int> S1;
	S1 = S;
	S1.show();
	return 0;
}

