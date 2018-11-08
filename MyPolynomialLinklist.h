/*************************************************************************
    > File Name: MyPolynomialLinklist.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年11月07日 星期三 21时37分17秒
 ************************************************************************/

#ifndef _MYPOLYNOMIALLINKLIST_H
#define _MYPOLYNOMIALLINKLIST_H
template <typename Elemtype>
class MyPolynomialLinklist:public Linklist<Elemtype>
{
public:
	MyPolynomialLinklist<Elemtype> operator + (MyPolynomialLinklist<Elemtype> &L2);

	MyPolynomialLinklist<Elemtype> operator - (MyPolynomialLinklist<Elemtype> &L2);

	void randomInitalFill(int display=0);

	//////////////////////////////////////////////////////

	void read(istream &in);
	void display(ostream &out) const;
};

////////////////////////////////////////////////

template <typename Elemtype>
MyPolynomialLinklist<Elemtype> MyPolynomialLinklist<Elemtype>::operator + (MyPolynomialLinklist<Elemtype> &L2)
{
	NodePointer p1 = head;
	NodePointer p2 = L2.head;
	MyPolynomialLinklist<Elemtype> L3;

	NodePointer r3 = NULL;
	NodePointer p3 = NULL;

	while(p1 && p2)
	{
		if(p1->data.expn == p2->data.expn && p1->data.coef + p2->data.coef == 0)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		else
		{
			p3 = new LinkNode;
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

	NodePointer pt;
	if(p1) pt = p1;
	else pt = p2; 
	while(pt) 
	{
		p3 = new LinkNode;
		assert(p3 != 0);

		p3->data.coef = pt->data.coef;
		p3->data.expn = pt->data.coef;

		pt = pt->nex;
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

template <typename Elemtype>
MyPolynomialLinklist<Elemtype> MyPolynomialLinklist<Elemtype>::operator -(MyPolynomialLinklist<Elemtype>& L2)
{
	NodePointer p2 = L2.head;
	MyPolynomialLinklist<Elemtype> L3;

	while(p2)
	{
		p2->data.coef = -p2->data.coef;
		p2 = p2->next;
	}
	L3 = (*this)+L2;
	return L3;
}

template<typename Elemtype>
void MyPolynomialLinklist<Elemtype>::randomInitalFill(int display)
{
	int  n;
	NodePointer r,p;
	NodePointer s;
	clear();

	srand((unsigned)time(NULL));

	n = rand()%8 + 1;
	if(display)
	{
		cout << "create " << n << "term:"<<endl;
		cout << "\t";
	}

	for(int i =  0; i < n; ++i)
	{
		s = new LinkNode;
		assert(s != 0);
		if(rand()%2)
			s->data.coef = rand()%100 + 1;
		else
			s->data.coef = -(rand()%100 + 1);

		while(1)
		{
			s->data.expn = rand()%10;

			r = NULL;
			p = head;

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
			head = s;
		else
			r->next = s;
		s->next = p;
		if(display)
			cout << s->data << " ";
	}
	if(display)
		cout << endl;
}

template<typename Elemtype>
void MyPolynomialLinklist<Elemtype>::read(istream &in)
{
	int n;
	NodePointer r,p;
	NodePointer s;

	clear();
	cout << "Please enter number of term :";
	in >> n;

	cout << "Please enter trem of polynomial:"<<endl;

	for(int i = 0;i < n;i++)
	{
		cout << "'\t the " << i + 1 <<"term";

		s = new LinkNode;
		assert(s !=0);

		while(1)
		{
			in >> s->data;
			r = NULL, p = head;
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
			head = s;
		else
			r->next = s;
		s->next = p;
	}
	cout << "/n the term number have reach " << n <<endl;
}

istream & operator >>(istream &in, MyPolynomialLinklist<Elemtype> &pL)
{
	pL.read(in);
	return in;
}

template<Elemtype>
void MyPolynomialLinklist<Elemtype>::display(ostream & out) const
{
	NodePointer p = head;
	if(!head)
	{
		cout << "the polynomial is empty" <<endl;
		return;
	}

	cout<<"  ";
	while(p)
	{
		if(p != head && p->data.coef>0)
			cout << "+";
		if(p != head && p->data.coef<0)
			cout << "-";
		out << p->data;
		p = p->next;
	}
	out << endl;
}

template<Elemtype>
ostream& operator <<(ostream &out, const MyPolynomialLinklist<Elemtype> &L)
{
	L.display(out);
	return out;
}
#endif
