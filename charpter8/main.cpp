/*************************************************************************
    > File Name: main.cpp
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Mon 03 Dec 2018 07:24:02 PM CST
 ************************************************************************/
#include "const.h"
#include "header.h"
#include "GList.h"


int main(int argc, char const *argv[])
{
	
	GList<char> L;
	cin >> L;
	
	cout << L.getLength() << endl;
	return 0;
}