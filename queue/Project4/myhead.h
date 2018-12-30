//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// myhead.h �����Լ��趨��һЩ����������

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <new>
using namespace std;

#include <time.h>
#ifndef MYHEAD_H
    #define MYHEAD_H
    #include "myhead.h"
const int	OK=1;
const int	ERROR=0;
const int	INFEASIBLE=-1;
//const int	OVERFLOW=-2;

typedef int Status;	//��ʾ���������״̬

////////////////////////////////////////////////////////////////////////////////

//���ܣ��ж��������Ƿ����
//���룺������ֵ��a��bΪ��Ҫ�Ƚϵ���������
//�������a����b�������ķ���ֵΪOK;����ΪERROR
Status equal(int a,int b)
{
	if(a==b)
		return OK;
	else
		return ERROR;
}
				
//���ܣ��ж�һ�������Ƿ������һ������
//���룺������ֵ��a��bΪ��Ҫ�Ƚϵ���������
//�������a����b�������ķ���ֵΪOK������ΪERROR
Status great(int a,int b)
{
	if(a>b)
		return OK;
	else
		return ERROR;
}	

//���ܣ��ж�һ�������Ƿ�С����һ������
//���룺������ֵ��a��bΪ��Ҫ�Ƚϵ���������
//�������aС��b�������ķ���ֵΪOK������ΪERROR
Status Less(int a,int b)
{
	if(a<b)
		return OK;
	else
		return ERROR;
}
#endif