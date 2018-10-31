/*************************************************************************
    > File Name: class_outfunction.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年10月31日 星期三 18时24分57秒
	>function:class function to use
 ************************************************************************/

#ifndef _CLASS_OUTFUNCTION_H
#define _CLASS_OUTFUNCTION_H

//show i elem
template<class ElemType>
int equal(ElemType e1,ElemType e2);
//class funtion need equal;


template<class ElemType>
int equal(ElemType e1,ElemType e2)
{
	if(e1 == e2) return 1;
	else return 0;
}

#endif
