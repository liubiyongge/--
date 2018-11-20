/*************************************************************************
    > File Name: Doublelinklist.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年11月16日 星期五 16时44分16秒
 ************************************************************************/
#ifndef _DOUBLELINKLIST_H
#define _DOUBLELINKLIST_H

template<typename Elemtype>
class Doublelinklist
{
public:
	class LinkNode
	{
	public:
		Elemtype data;
		LinkNode * next;
		LinkNode *prior;
	};
	typedef LinkNode* NodePointer;


	void clear();
	
	Status deleteElem(Elemtype e);

	Status getElem(int i, Elemtype &e);

	NodePointer getHead();

	int getLength();

	Status insert(int i, Elemtype e);

	bool isEmpty();

	//return NodePointer that data  is equal to e
	Status locateElem(Elemtype find_e, NodePointer &r);

	Status nextElem(Elemtype e, Elemtype &next_e);

	Doublelinklist<Elemtype> operator = (Doublelinklist<Elemtype> rightL);

	Status priorElem(Elemtype e, Elemtype &prior_e);
	void show();
	//*****************own*************88
	Doublelinklist();
	~Doublelinklist();
	Doublelinklist(const Doublelinklist<Elemtype> & rightL);

protected:
	NodePointer head;
};

template<typename Elemtype>
void Doublelinklist<Elemtype>::clear()
{
	if(!head)
		return;
	NodePointer p = head->prior;
	NodePointer r;
	while(p != head)
	{
		r = p->prior;
		delete p;
		p = r;
	}
	delete p;
	head = NULL;
	
}

template<typename Elemtype>
Status Doublelinklist<Elemtype>::deleteElem(Elemtype e)
{
	NodePointer p;
	if(!locateElem(e, p))
		return 0;

	if(head->next == head)
		head = NULL;
	else
	{
		if(p == head)
			head = p->next;
		p->prior->next = p->next;
		p->next->prior = p->prior;
	}
	delete p;
	return 1;
}

template<typename Elemtype>
Status Doublelinklist<Elemtype>::getElem(int i, Elemtype &e)
{
	int j = 1;
	NodePointer p =head;
	while(p && p->next != head && j < i)
	{
		p = p->next;
		++j;
	}
	if(j == i)
	{
		e = p->data;
		return 1;
	}
	return 0;
}

template<typename Elemtype>
typename Doublelinklist<Elemtype>::NodePointer Doublelinklist<Elemtype>::getHead()
{
	return head;
}

template<typename Elemtype>
int Doublelinklist<Elemtype>::getLength()
{
	NodePointer p = head;
	int length = 0;
	while(p)
	{
		length++;
		p = p->next;
		if(p == head)
			break;
	}
	return length;
}

template<typename Elemtype>
Status Doublelinklist<Elemtype>::insert(int i, Elemtype e)
{
	// 1 =< i <= getLength() + 1
	if(i < 1 || i > getLength() + 1)
		return 0;

	NodePointer p = head;
	NodePointer s;
	int j = 1;
	while(p && p->next != head && j < i)
	{
		p = p->next;
		++j;
	}

	s = new LinkNode;
	assert(s != 0);
	s->data = e;

	if(!p)
	{
		
		head = s->prior = s->next = s;
		return 1;
	}

	if(i == 1)
	{
		head = s;
	}

	if(i == getLength() + 1)
		p = p->next;
	p->prior->next = s;
	s->prior = p->prior;
	p->prior = s;
	s->next = p;
	
	return 1;
}

template<typename Elemtype>
bool Doublelinklist<Elemtype>::isEmpty()
{
	return (head?0:1);
}

// only find right status
template<typename Elemtype>
Status Doublelinklist<Elemtype>::locateElem(Elemtype e, NodePointer &r)
{
	NodePointer p = head;
	while(p && p->next != head && p->data != e)
		p = p->next;
	if(p->data  == e)
	{
		r = p;
		return 1;
	}
	else
		return 0;
}

template<typename Elemtype>
Status Doublelinklist<Elemtype>::nextElem(Elemtype e, Elemtype &next_e)
{
	NodePointer p;
	if(locateElem(e, p))
	{
		next_e = p->next->data;
		return 1;
	}
	else
		return 0;
}



template<typename Elemtype>
Doublelinklist<Elemtype> Doublelinklist<Elemtype>::operator = (Doublelinklist<Elemtype> rightL)
{
	clear();	
	if(this != &rightL && rightL.head)
	{
		NodePointer p, q, r;
		p = rightL.head;
		q = r = NULL;
		while(p)
		{
			q = new LinkNode;
			assert(q != 0);
			q->data = p->data;
			if(!head)
				head = q ;
			else
			{
				r->next = q;
				q->prior = r;
			}
			r = q; 
			p = p->next;
			if(p == rightL.head)
				break;
		}
		head->prior = q;
		q->next = head;
	}
	return *this;
}

template<typename Elemtype>
Status Doublelinklist<Elemtype>::priorElem(Elemtype e, Elemtype &prior_e)
{
	NodePointer p;
	if(locateElem(e, p))
	{
		prior_e = p->prior->data;
		return 1;
	}
	else
		return 0;
}
//*******************own function***************8
template<typename Elemtype>
Doublelinklist<Elemtype>::Doublelinklist()
{
	head = NULL;
}

template<typename Elemtype>
Doublelinklist<Elemtype>::~Doublelinklist()
{
	clear();
}

//可能没有调用构造初始化函数
template<typename Elemtype>
 Doublelinklist<Elemtype>::Doublelinklist(const Doublelinklist<Elemtype> & rightL)
{
	if(this != &rightL && rightL.head)
	{
		NodePointer p, q, r;
		p = rightL.head;
		head = q = r = NULL;
		while(p)
		{
			q = new LinkNode;
			assert(q != 0);
			q->data = p->data;
			if(!head)
				head = q ;
			else
			{
				r->next = q;
				q->prior = r;
			}
			r = q; 
			p = p->next;
			if(p == rightL.head)
				break;
		}
		head->prior = q;
		q->next = head;
	}
}

template<typename Elemtype>
void Doublelinklist<Elemtype>::show()
{
	if(!head)
	{
		cout << "空." << endl;
		return;
	}


	NodePointer p = head;
	int i = 1;
	while(p->next != head)
	{
		cout << setw(7) << "[" << i << "]";
		i++;
		p = p->next;
	}
	cout << setw(7) << "[" << i << "]";
	cout << endl;
	p = head;
	while(p->next != head)
	{
		cout << setw(7) << p->data << "->";
		p = p->next;
	}
	cout << setw(7)<< p->data << "->"<<endl;
	cout << "     ";
	cout << "|";
	for(int j=7; j<=i*9 - 2;j++) cout<<"_";
	cout << "|" << endl;
}
#endif
