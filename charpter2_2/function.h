/*************************************************************************
    > File Name: function.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年11月07日 星期三 13时23分55秒
 ************************************************************************/

#ifndef _FUNCTION_H
#define _FUNCTION_H

template<class ElemType> 
void show(Linklist<ElemType>& L);
//show elem 
template<class ElemType>
void show(Linklist<ElemType>& L)
{	
	int e;
	cout<<"length is "<<L.getLength()<<endl;
	for(int i = 1; i <= L.getLength(); i++)
		{
			L.getElem(i, e);
			cout<<e<<endl;
		}
}
#endif
