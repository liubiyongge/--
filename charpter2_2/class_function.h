/*************************************************************************
    > File Name: class_functioin.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年11月07日 星期三 13时21分49秒
 ************************************************************************/

#ifndef _CLASS_FUNCTIOIN_H
#define _CLASS_FUNCTIOIN_H

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
