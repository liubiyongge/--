/*************************************************************************
    > File Name: tmp.cpp
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Mon 17 Dec 2018 03:12:46 PM CST
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>
#include<iostream>
#include<assert.h>
#include<iomanip>
#include<stdlib.h>
#include <string.h>

#include "./charpter4_1/const.h"
#include "./charpter4_1/sqQueue.h"
using namespace std;


int main()
{
	sqQueue<int *> queue;
	int *p;
	int *q;
	queue.enQueue(p);
	queue.enQueue(q);
	queue.deQueue();
	queue.deQueue();


}
