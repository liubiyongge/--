/*************************************************************************
    > File Name: function.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年10月31日 星期三 18时21分16秒
 ************************************************************************/

#ifndef _FUNCTION_H
#define _FUNCTION_H


template<class ElemType> 
void show(Sqlist<ElemType>& L, int i);
//show elem 
template<class ElemType>
void show(Sqlist<ElemType>& L, int i)
{	
	ElemType e = 0;
	cout<<"length is "<<L.getLength()<<endl;
	if(!L.getElem( i, e)) 
		cout<<i<<" is wrong"<<endl;
	else 	
		cout<< e <<endl;
}

#endif
