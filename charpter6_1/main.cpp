/*************************************************************************
    > File Name: main.cpp
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Mon 03 Dec 2018 07:24:02 PM CST
 ************************************************************************/
#include "const.h"
#include "header.h"
#include "SMatrix.h"

/*
   [0][1][2][3]
[0]  0  8  0  0
[1]  4  0 23  7
[2] 11  7  4  0
[3]  0  8  0  0

*/

int main(int argc, char const *argv[])
{
	
	SMatrix<int> S;
	S.init();
	SMatrix<int> S1;
	S1 = S * S;
	S.displayMatrix();
	cout << endl;
	S1.displayMatrix();
	
	
	return 0;
}