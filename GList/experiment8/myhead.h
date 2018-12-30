#ifndef MYHEAD_H_INCLUDE
#define MYHEAD_H_INCLUDE
#include <iostream>
#include <assert.h>
#include <time.h>
using namespace std;
typedef int Status;

#define OK 1
#define ERROR 0
#define STACK_MAX_SIZE 20
#define STACKINCREMENT 10

/*判断两数是否相等*/
bool equal(int x, int y)
{
	return x == y;
}

bool greater(int x, int y)
{
	return x > y;
}

bool Less(int x, int y)
{
	return x < y;
}

//是否继续的小程序
void ContinueOrNot(char& continueChar)
{
	std::cout << "\t*********************************************************" << std::endl << std::endl;
	std::cout << "\t还继续吗？ （Y.继续\tN.结束）?";
	std::cin >> continueChar;
}

#endif