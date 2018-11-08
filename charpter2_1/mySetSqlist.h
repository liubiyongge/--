/*************************************************************************
    > File Name: mySetSqlist.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年11月02日 星期五 10时02分03秒
	>function: A - B; A + B; A^B 
 	>rely on :class_function.h
 ************************************************************************/

#ifndef _MYSETSQLIST_H
#define _MYSETSQLIST_H

//function: A + B
//input: firstL secondL
//output: A + B
template <typename ElemType>
Sqlist<ElemType> unionSet(Sqlist<ElemType> firstL, Sqlist<ElemType> secondL)
{
	ElemType e;
	Sqlist<ElemType> thirdL(firstL);

	for(int i=1; i<secondL.getLength(); ++i)
	{
		secondL.getElem(i, e);
		if(!firstL.LocateElem_Sq(e, equal))
		{
			thirdL.ListInsert_Sq(thirdL.getLength() + 1, e);

		}
	}
	return thirdL;	
}

//funtion:A^B
//input:firstL secondL
//output:A^B
template<typename ElemType>
Sqlist<ElemType> intersectionSet(Sqlist<ElemType> firstL,  Sqlist<ElemType> secondL)
{
	int k = 0;
	ElemType e;
	Sqlist<ElemType> thirdL;
	for(int i = 1; i<=firstL.getLength(); ++i)
	{
		firstL.getElem(i, e);
		if(secondL.LocateElem_Sq(e, equal))
		{
			thirdL.ListInsert_Sq(++k, e);
		}
	}
	return thirdL;

}

//function: A - B
//input: firstL secondL
//output: A - B
template<typename ElemType>
Sqlist<ElemType> differenceSet(Sqlist<ElemType> firstL,  Sqlist<ElemType> secondL)
{
	int k=0;
	ElemType e;
	Sqlist<ElemType> thirdL;
	for(int i=1; i<=firstL.getLength(); ++i)
	{
		firstL.getElem(i, e);
		if(!secondL.LocateElem_Sq(e, equal))
		{
			thirdL.ListInsert_Sq(++k, e);
		}
	
	}
	return thirdL;
}


#endif

