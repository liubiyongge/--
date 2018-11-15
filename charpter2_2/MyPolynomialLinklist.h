/*************************************************************************
    > File Name: MyPolynomialLinklist.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年11月07日 星期三 21时37分17秒
 ************************************************************************/

#ifndef _MYPOLYNOMIALLINKLIST_H
#define _MYPOLYNOMIALLINKLIST_H
template <typename ElemType>
class MyPolynomialLinklist:public Linklist<ElemType>
{
public:
	//Link node class
	/*class typename Linklist<ElemType>::LinkNode
	{
	public:
		ElemType data;
		typename Linklist<ElemType>::LinkNode *next;

	};
	typedef typename Linklist<ElemType>::LinkNode *typename Linklist<ElemType>::NodePointer;//point type 
*/
	MyPolynomialLinklist<ElemType> operator + (const MyPolynomialLinklist<ElemType> &L2);

	MyPolynomialLinklist<ElemType> operator - (const MyPolynomialLinklist<ElemType> &L2);

	void randomInitalFill(int display=0);

	//////////////////////////////////////////////////////

	void read(istream &in);
	void display(ostream &out) const;
};

////////////////////////////////////////////////

template <typename ElemType>
MyPolynomialLinklist<ElemType> MyPolynomialLinklist<ElemType>::operator + (const MyPolynomialLinklist<ElemType> &L2)
{
	typename Linklist<ElemType>::NodePointer p1 = this->head;
	typename Linklist<ElemType>::NodePointer p2 = L2.head;
	MyPolynomialLinklist<ElemType> L3;

	typename Linklist<ElemType>::NodePointer r3 = NULL;
	typename Linklist<ElemType>::NodePointer p3 = NULL;

	while(p1 && p2)
	{
		if(p1->data.expn == p2->data.expn && p1->data.coef + p2->data.coef == 0)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		else
		{
			p3 = new typename Linklist<ElemType>::LinkNode;
			assert(p3 != 0);

			if(p1->data.expn > p2->data.expn)
			{
				p3->data.coef = p1->data.coef;
				p3->data.expn = p1->data.expn;
				p1 = p1->next;
			}
			else if(p1->data.expn == p2->data.expn)
			{
				p3->data.coef = p1->data.coef + p2->data.coef;
				p3->data.expn = p1->data.expn;
				p1 = p1->next;
				p2 = p2->next;

			}
			else
			{
				p3->data.coef = p2->data.coef;
				p3->data.expn = p2->data.expn;
				p2 = p2->next;
			}
			if(!L3.head)
				L3.head = p3;
			else
				r3->next = p3;

			r3 = p3;
		}
	}

	typename Linklist<ElemType>::NodePointer pt;
	if(p1) pt = p1;
	else pt = p2; 
	while(pt) 
	{
		p3 = new typename Linklist<ElemType>::LinkNode;
		assert(p3 != 0);

		p3->data.coef = pt->data.coef;
		p3->data.expn = pt->data.expn;
		pt = pt->next;
		if(!L3.head)
			L3.head = p3;
		else
			r3->next = p3;

		r3 = p3;
	}
	if(p3)
		p3->next = NULL;
	return L3;
}

template <typename ElemType>
MyPolynomialLinklist<ElemType> MyPolynomialLinklist<ElemType>::operator -(const MyPolynomialLinklist<ElemType>& L2)
{
	typename Linklist<ElemType>::NodePointer p2 = L2.head;

	while(p2)
	{
		p2->data.coef = -p2->data.coef;
		p2 = p2->next;
	}
	return (*this)+L2;
}

template<typename ElemType>
void MyPolynomialLinklist<ElemType>::randomInitalFill(int display)
{
	int  n;
	typename Linklist<ElemType>::NodePointer r,p;
	typename Linklist<ElemType>::NodePointer s;
	this->clear();

	n = rand()%8 + 1;
	if(display)
	{
		cout << "create " << n << "term:"<<endl;
		cout << "\t";
	}

	for(int i =  0; i < n; ++i)
	{
		s = new typename Linklist<ElemType>::LinkNode;
		assert(s != 0);
		if(rand()%2)
			s->data.coef = rand()%100 + 1;
		else
			s->data.coef = -(rand()%100 + 1);

		while(1)
		{
			s->data.expn = rand()%10;

			r = NULL;
			p = this->head;

			while(p && s->data.expn < p->data.expn)
			{
				r = p;
				p = p->next;
			}

			if(p && s->data.expn == p->data.expn)
				continue;
			else
				break;
		}
		if(!r)
			this->head = s;
		else
			r->next = s;
		s->next = p;
		if(display)
			cout << s->data << " ";
	}
	if(display)
		cout << endl;
}

template<typename ElemType>
void MyPolynomialLinklist<ElemType>::read(istream &in)
{
	int n;
	typename Linklist<ElemType>::NodePointer r,p;
	typename Linklist<ElemType>::NodePointer s;

	this->clear();
	cout << "Please enter number of term :";
	in >> n;

	cout << "Please enter term of polynomial:"<<endl;

	for(int i = 0;i < n;i++)
	{
		cout << "'\t the " << i + 1 <<" term" <<endl;

		s = new typename Linklist<ElemType>::LinkNode;
		assert(s !=0);

		while(1)
		{
			in >> s->data;
			r = NULL, p = this->head;
			while(p && s->data.expn < p->data.expn)
			{
				r = p;
				p = p->next;
			}
			if(p && s->data.expn == p->data.expn)
			{
				cout << "the term is repeated, please input again"<<endl;
				continue;
			}
			else
				break;
		} 
		if(!r)
			this->head = s;
		else
			r->next = s;
		s->next = p;
	}
	cout << "/n the term number have reach " << n <<endl;
}

template<typename ElemType>
istream & operator >>(istream &in, MyPolynomialLinklist<ElemType> &pL)
{
	pL.read(in);
	return in;
}

template<typename ElemType>
void MyPolynomialLinklist<ElemType>::display(ostream & out) const
{
	typename Linklist<ElemType>::NodePointer p = this->head;
	if(!this->head)
	{
		cout << "the polynomial is empty" <<endl;
		return;
	}

	cout<<"  ";
	while(p)
	{
		if(p != this->head && p->data.coef>0)
			cout << "+";
		out << p->data;
		p = p->next;
	}
	out << endl;
}

template<typename ElemType>
ostream& operator <<(ostream &out, const MyPolynomialLinklist<ElemType> &L)
{
	L.display(out);
	return out;
}
#endif
