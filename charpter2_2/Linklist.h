/*************************************************************************
    > File Name: Linklist.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年11月02日 星期五 11时16分06秒
	>funtion: class define-unloop Link list
	>L-->|d1|  |----->...----->|dn |NULL|
 ************************************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H


template <typename ElemType>
class Linklist
{
public:
	//Link node class
	class LinkNode
	{
	public:
		ElemType data;
		LinkNode *next;

	};
	typedef LinkNode *NodePointer;//point type 

	//adverse list
	void adverse();

	//clear list
	void clear();

	//delete fisrt node that data is equal to e
	Status deleteElem(ElemType e);

	//delete repeat data in list
	void deleteRepeat();

	//get i node data
	Status getElem(int i, ElemType& e);

	//get first node pointer of list
	NodePointer getHead();

	//get length of list
	int getLength();

	//insert e to list before i node
	Status insert(int i, ElemType e); 

	//is empty or not
	bool isEmpty();

	//get first node that data is equal to e 
	Status locateElem(ElemType e, Status (*compare)(ElemType, ElemType), int &i);

	//get data of  one node's next node
	Status nextElem(ElemType e, ElemType & next_e);

	// =
	Linklist<ElemType> operator =(const Linklist<ElemType> &rightR);

	Status priorElem(ElemType e, ElemType & prior_e);

	//***************************auto****************88
	Linklist();

	~Linklist();

	Linklist(const Linklist<ElemType>& otherL);

protected:
	NodePointer head;
	
};

////////////////////////////////////////////

//function: adverse list
template <typename ElemType>
void Linklist<ElemType>::adverse()
{
	NodePointer r,p,q;
	if(!head)
		return;
	r = NULL;
	p = head;
	q = p->next;
	while(p)
	{
		p->next  = r;
		r = p;
		p = q;
		if(q) q = q->next;
	}
	head = r;
}

//function;clear list
template <typename ElemType>
void Linklist<ElemType>::clear()
{
	NodePointer p, q;

	p = NULL;
	q = head;
	while(q)
	{
		p = q;
		q = q->next;
		delete p;
	}
	head = NULL;
}

//function:delete fisrt node that data is equal to e
template <typename ElemType>
Status Linklist<ElemType>::deleteElem(ElemType e)
{
	NodePointer r, p;
	r = NULL;
	p = head;
	while(p && !equal(p->data, e))
	{
		r = p;
		p = p->next;
	}

	if(p==NULL)
		return ERROR;
	if(r == NULL)
	{
		head = head->next;
	}
	else
		r->next = p->next;

	free(p);
	return OK;
}

//function: delete repeat data node
//L-->|d1|  |----->...----->|dn |NULL|
//     |           |
//     s           p
//		 |
//       s
template <typename ElemType>
void Linklist<ElemType>::deleteRepeat()
{
	NodePointer r, p;
	NodePointer s;
	r = NULL;
	p = head;
	while(p)
	{
		s = head;
		while(s != p)
		{
			if(s->data == p->data)
			{
				r->next = p->next;
				delete p;
				p = r;
				break;
			}
			s = s->next;
		}
	
		r = p;
		if(p)
			p = p->next;
	}
}

//funtion:get i node data
template<typename ElemType>
Status Linklist<ElemType>::getElem(int i, ElemType & e)
{
	int j = 1;
	NodePointer p = head;
	while(p && j < i)
	{
		p = p->next;
		++j;
	}
	if(!p || j > i)
		return ERROR;
	e = p->data;
	return OK;
}

//function:get head
template<typename ElemType>
typename Linklist<ElemType>::NodePointer Linklist<ElemType>::getHead()
{
	return head;
}

//function: get length
template<typename ElemType>
int Linklist<ElemType>::getLength()
{
	int n = 0;
	NodePointer p = head;
	while(p)
	{
		++n;
		p = p->next;
	}
	return n;
}

//function:insert e to list before i node
template<typename  ElemType>
Status Linklist<ElemType>::insert(int i, ElemType e)
{
	int j = 1;
	NodePointer p = head;
	NodePointer s;

	while(p && j < i - 1)
	{
		++j;
		p= p->next;
	}

	if((!p && i != 1) || j > i)
		return ERROR;

	s = new LinkNode;
	assert(s != 0);
	s->data = e;
	if(i == 1)
	{
		s->next = head;
		head = s;
	}
	else
	{
		s->next = p->next;
		p->next = s;
	}
	return OK;
}

//function: empty or not
template <typename ElemType>
bool Linklist<ElemType>::isEmpty()
{
	return (head?0:1);
}

//function:get first node that data is equal to e
template<typename ElemType>
Status Linklist<ElemType>::locateElem(ElemType e, Status (*compare)(ElemType, ElemType), int &i )
{
	NodePointer p = head;
	i = 1;
	while(p && !compare(p->data, e))
	{
		p = p->next;
		++i;
	}
	if(!p)
	{
		i = 0;
		return ERROR;
	}

	return OK;
}


//function;next elem
template <typename ElemType>
Status Linklist<ElemType>::nextElem(ElemType e, ElemType & next_e)	
{
	NodePointer p = head;
	while(p && !equal(p->data, e))
		p = p->next;
	if(!p || !p->next)
		return ERROR;
	next_e = p->next->data;
	return OK;	
}

//function:reload =
template<typename ElemType>
Linklist<ElemType> Linklist<ElemType>::operator = (const Linklist<ElemType> &rightR)
{
	NodePointer p = NULL;
	NodePointer rp = rightR.head;
	NodePointer s;

	if(this != &rightR)
	{
		clear();

		while(rp)
		{
			s = new LinkNode;
			assert(s != 0);
			s->data = rp->data;
			if(!head)
				head = s;
			else
				p->next = s;
			p = s;
			rp = rp->next;
		}
		if(p)
			p->next = NULL;
	}
	return *this;
}

template <typename ElemType>
Status Linklist<ElemType>::priorElem(ElemType e, ElemType& prior_e)
{
	NodePointer r = NULL;
	NodePointer p = head;
	while(p && !equal(p->data, e))
	{
		r = p;
		p = p->next;
	}

	if(!p || !r)
		return ERROR;
	prior_e = r->data;
	return OK;
}

//******************************88

template<typename ElemType>
Linklist<ElemType>::Linklist()
{
	head = NULL;
}

template<typename ElemType>
Linklist<ElemType>::~Linklist()
{
	clear();
}

template<typename ElemType>
Linklist<ElemType>::Linklist(const Linklist<ElemType>& otherL)
{
	NodePointer p;
	NodePointer op = otherL.head;
	NodePointer s;
	head = p = NULL;
	while(op)
	{
		s = new LinkNode;
			assert(s != 0);
			s->data = op->data;
			if(!head)
				head = s;
			else
				p->next = s;

			p=s;
			op = op->next;
	}
	if(head)
		p->next = NULL;
}
#endif

