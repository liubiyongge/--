/*************************************************************************
    > File Name: ChainTree.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Wed 26 Dec 2018 08:06:08 PM CST
 ************************************************************************/

#ifndef _CHAINTREE_H
#define _CHAINTREE_H
#include "./charpter3_1/SqStack.h"


template <typename T>
class ChainTree
{
public:
	class Node
	{
	public:
		T data;
		Node * lchild;
		Node * rchild;
	};

	typedef Node* nodePointer;

	void create();
	int  getNodeNum();
	int getLeafNum();
	int getDepth();
	//Preorder traversal
	void preorderTraversal();
	void inorderTraversal();
	void postorderTraversal();
private:
	int calDepth(nodePointer p);

public:
	ChainTree();
	~ChainTree();
private:
	nodePointer root;	
};

template <typename T>
int ChainTree<T>::getDepth()
{
	return calDepth(root);
}

template <typename T>
int ChainTree<T>::calDepth(nodePointer p)
{
	int m, n;
	if(!p) return 0;
	if(!p->lchild && !p->rchild) 
		return 1;
	else
	{
		m = calDepth(p->lchild);
		n = calDepth(p->rchild);
		return 1+(m>n?m:n);
	}
}


template <typename T>
int ChainTree<T>::getLeafNum()
{
	SqStack<nodePointer> S;
	nodePointer p = root;
	int num = 0;
	while(p!= NULL || !S.isEmpty())
	{
		if(p == NULL)
			S.pop(p);	
		if(p->rchild != NULL)
			S.push(p->rchild);
		if(p->lchild == NULL && p->rchild == NULL)
			num++;
		p = p->lchild;
	}
	return num;
}

template <typename T>
int ChainTree<T>::getNodeNum()
{

	SqStack<nodePointer> S;
	nodePointer p = root;
	int num = 0;
	while(p!= NULL || !S.isEmpty())
	{
		if(p == NULL)
			S.pop(p);	
		if(p->rchild != NULL)
			S.push(p->rchild);
		num++;
		p = p->lchild;
	}
	return num;
}



template <typename T>
void ChainTree<T>::preorderTraversal()
{

	SqStack<nodePointer> S;
	nodePointer p = root;
	while(p!= NULL || !S.isEmpty())
	{
		if(p == NULL)
			S.pop(p);	
		if(p->rchild != NULL)
			S.push(p->rchild);
		cout << p->data;
		p = p->lchild;
	}
	cout << endl;
}

template <typename T>
void ChainTree<T>::inorderTraversal()
{

	SqStack<nodePointer> S;
	nodePointer p = root;
	while(p!= NULL || !S.isEmpty())
	{
		if(p)
		{
			S.push(p);
			p = p->lchild;
		}
		else
		{
			S.pop(p);
			cout << p->data;
			p = p->rchild;
		}
	}
	cout << endl;
}


//main idea --pre pointer
template <typename T>
void ChainTree<T>::postorderTraversal()
{
	SqStack<nodePointer> S;
	nodePointer p = root, pre = NULL;
	S.push(p);
	while(!S.isEmpty())
	{
		S.getTop(p);
		if((p->lchild == NULL && p->rchild == NULL) || (pre != NULL &&( (pre == p->lchild) || (pre == p->rchild))))
		{
			cout << p->data;
			pre = p;
			S.pop(p);
		}
		else 
		{
			if(p->rchild != NULL)
			{
				S.push(p->rchild);
			}
			
			if(p->lchild != NULL)
			{
				S.push(p->lchild);
			}
		}
			
	}
	cout << endl;
}



template <typename T>
void ChainTree<T>::create()
{
	nodePointer p;
	nodePointer q;
	root = (nodePointer)malloc(sizeof(Node));
	p = root;
	p->data = 'A';
	p->lchild = (nodePointer)malloc(sizeof(Node));
	p->rchild = (nodePointer)malloc(sizeof(Node));
	p->lchild->data = 'B';
	p->rchild->data = 'C';
	q = p->rchild;
	p = p->lchild;
	p->lchild = (nodePointer)malloc(sizeof(Node));
	p->rchild = (nodePointer)malloc(sizeof(Node));
	p->lchild->data = 'D';
	p->rchild->data = 'E';
	p->lchild->lchild = NULL;
	p->lchild->rchild = NULL;
	p->rchild->lchild = NULL;
	p->rchild->rchild = NULL;

	q->rchild = (nodePointer)malloc(sizeof(Node));
	q->lchild = NULL;
	q->rchild->data = 'F';
	q->rchild->lchild = NULL;
	q->rchild->rchild = NULL;

}

//*****************************8
template <typename T>
ChainTree<T>::ChainTree()
{
	root = NULL;
}

template <typename T>
ChainTree<T>::~ChainTree()
{
	SqStack<nodePointer> S;
	nodePointer p = root, q;
	while(p!= NULL || !S.isEmpty())
	{
		if(p == NULL)
			S.pop(p);	
		if(p->rchild != NULL)
			S.push(p->rchild);
		q = p->lchild;
		delete p;
		p = q;
	}
}
#endif
