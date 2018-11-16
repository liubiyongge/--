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
			cout << setw(7) << "[" << i << "]";
		}
	cout << endl;
	for(int i = 1; i <= L.getLength(); i++)
		{
			L.getElem(i, e);
			cout << setw(7) << e << "->";
		}
		cout << "\b" << "\b" << "^ " << endl;
}

//elemtype is int
template<typename ElemType>
int bigger(ElemType e, ElemType e1)
{
	if(e > e1)
		return 1;
	else
		return 0;
}

template<typename ElemType>
int lesser(ElemType e, ElemType e1)
{
	if(e < e1)
		return 1;
	else
		return 0;
}
#endif
