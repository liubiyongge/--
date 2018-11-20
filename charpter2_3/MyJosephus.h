/*************************************************************************
    > File Name: MyJosephus.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年11月16日 星期五 15时54分04秒
 ************************************************************************/

#ifndef _MYJOSEPHUS_H
#define _MYJOSEPHUS_H

template<typename ElemType>
void Josephus(CircularLinklist<ElemType> L, int start, int i)
{
	int times = 0;
	ElemType e;
	if(L.isEmpty())
	{
		cout << "CircularLinklist is empty, ti is unable to out of sequence!" << endl;
		return;
	}
	L.moveHead(start);
	while(!L.isEmpty())
	{
		L.deleteElem(i, e);
		cout << "\n  第" << ++times << " 次出队列的结点为" << e << "，出队列后约瑟夫环为";
		cout << ":\n" ;
		L.show();
	}
}

#endif
