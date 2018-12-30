/*************************************************************************
    > File Name: SeqTree.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Wed 26 Dec 2018 07:31:15 PM CST
 ************************************************************************/

#ifndef _SEQTREE_H
#define _SEQTREE_H
template <typename T>
class SeqTree
{
public:
	int getFinalIndex();
	void clear();
	void autoCreate();
//automatic call
	SeqTree();
	~SeqTree();
protected:
	T *initAddress;
	int finalIndex;
};

template <typename T>
int SeqTree<T>::getFinalIndex()
{
	return finalIndex;
}

template <typename T>
void SeqTree<T>::clear()
{
	delete initAddress;
	finalIndex = -1;
}

template <typename T>
void SeqTree<T>::autoCreate()
{
	initAddress = (T *)malloc(sizeof(T)*20);
	initAddress[0] = 'A';
	initAddress[1] = 'B';
	initAddress[2] = 'C';
	initAddress[3] = 'D';
	initAddress[4] = 'E';
	initAddress[6] = 'G';
	initAddress[8] = 'I';
	initAddress[9] = 'J';
	initAddress[10] = 'K';

}

//automatic call----------------------------
template <typename T>
SeqTree<T>::SeqTree()
{
	initAddress = NULL;
	finalIndex = -1;
}

template <typename T>
SeqTree<T>::~SeqTree()
{
	delete initAddress;
}

#endif
