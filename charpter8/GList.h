/*************************************************************************
    > File Name: GList.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Fri 14 Dec 2018 03:43:49 PM CST
 ************************************************************************/

#ifndef _GLIST_H
#define _GLIST_H

#include "./charpter4_1/const.h"
#include "./charpter3_1/const.h"

#include "./charpter4_1/sqQueue.h"
#include "./charpter3_1/SqStack.h"
#include "./charpter5/SqString.h"

template <typename T>
class GList
{
public:
	///////////////////////type////////////////
	class GLNode
	{
	public:
		int tag;
		union
		{ 
			T atom;
			struct  
			{
				GLNode *hp;
				GLNode *tp;
			}ptr;
		};
	};

	typedef GLNode* GlistNodePointer;

	////tmp
	void CreatGList(GlistNodePointer *L,SqString S);
	void separate(SqString &S, SqString &hS);
	void destory(GlistNodePointer p);
	//get depth of GList
	int depth();
	int depth_aux(GlistNodePointer p);
	int getLength();
	////////////////////auto function//////////////////
	GList(); 
	~GList();

	void read(istream& in);
	//void display(ostream& out);
private:
	GlistNodePointer root;

};
///tmp
template <typename T>
void GList<T>::CreatGList(GlistNodePointer *L, SqString S)
{
	SqString hS;
	SqString empty("()");
	char c;
	
	if(!(S == empty))
	{
		*L = NULL;
		return;
	}

	*L = (GlistNodePointer)malloc(sizeof(GLNode));
	assert(*L!=0);
	if(S.getLength() == 1)
	{
		S.getChar(1, c);
		(*L)->tag = Atom;
		(*L)->atom = c;
		return;
	}

	separate(S, hS);
	(*L)->tag = List;
	CreatGList(&((*L)->ptr.hp), hS);
	CreatGList(&((*L)->ptr.tp), S);

}

template <typename T>
void  GList<T>::separate(SqString &S, SqString &hS)
{
	char c;
	int k = 0;
	int i = 1;
	int n = S.getLength() - 2;
	SqString tS;

	S.subString(tS, 2, n);
	while(i < n)
	{
		tS.getChar(i, c);
		if(c == ',' && k == 0)
			break;

		if(c == '(')
			++k;
		else if(c==')')
			--k;

		++i;
	}

	if(i < n)
	{
		tS.subString(hS, 1, i-1);
		tS.subString(S, i+1, n-i);
		S.insert(1, "(");
		S.insert(S.getLength()+1, ")");
	}
	else
	{
		hS = tS;
		S="()";
	}

}

template <typename T>
void GList<T>::destory(GlistNodePointer p)
{
	if(!p)
		return;
	if(p->tag==List)
	{
		destory(p->ptr.hp);
		destory(p->ptr.tp);
	}
	delete p;
}

template <typename T>
int GList<T>::depth()
{
	return depth_aux(root);

}

template <typename T>
int GList<T>::depth_aux(GlistNodePointer p)
{
	int dep, maxDep=0;
	if(!p || p->tag==Atom)
		return 0;
	for(GlistNodePointer q=p;q;q=q->ptr.tp)
	{
		dep = depth_aux(q->ptr.hp);
		if(dep>maxDep)
			maxDep = dep;
	}
	return maxDep+1;
}

template <typename T>
int GList<T>::getLength()
{
	GlistNodePointer p = root;
	int len = 0;
	while(p != NULL)
	{
		p = p->ptr.tp;
		len++;
	}
	return len;
}


	////////////////////auto function//////////////////
template <typename T>
GList<T>::GList()
{
	root = NULL;
}
	
template <typename T>
GList<T>::~GList()
{
	destory(root);
}



template <typename T>
void GList<T>::read(istream & in)
{
	cout<<"Please enter Generalized List:"<<endl;
	char ch[100];
	in >> ch;
	SqString S(ch);
	CreatGList(&root, S);

}

/*
template<typename T>
void GList<T>::display(ostream &out)
{

}
*/

//////////
template<typename T>
istream & operator >>(istream &in, GList<T> &L)
{
	L.read(in);
	return in;
}

/*
template<typename T>
ostream & operator <<(ostream &out, GList<T> &L)
{
	L.display();
	return out;
}
*/
#endif
