/*************************************************************************
    > File Name: linkStack.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Sat 24 Nov 2018 09:08:09 AM CST
 ************************************************************************/

#ifndef _LINKSTACK_H
#define _LINKSTACK_H


template <typename Elem>
class LinkStack
{
	private:

		class LinkNode
		{
		public:
			Elem data;
			LinkNode *next;
			
		};


		typedef LinkNode *NodePoint;



	public:

		void clear();
		int getLength();
		bool getTop(Elem &e);
		bool isEmpty();
		LinkStack <Elem>    operator = (LinkStack <Elem>  otherS);
		bool pop(Elem &e);
		bool push(Elem  e);
		LinkStack();
		~LinkStack();
		LinkStack(const LinkStack<Elem> & otherS);
		//******************88888
		void show();	
	protected:
		NodePoint top;
	
};

template <typename Elem> 
void	LinkStack<Elem> ::show()
	{
		NodePoint p = top;
		while(p)
		{
			cout << p->data << "->";
			p = p-> next;	 
		}
		cout << "\b\b" << "  ";

	}

template <typename Elem> 
	LinkStack<Elem> :: LinkStack(){
		top = NULL;
	}


template <typename Elem> 
	LinkStack<Elem> :: ~LinkStack(){
		clear();
	}

template <typename Elem> 
	LinkStack<Elem> ::LinkStack(const LinkStack<Elem> & otherS)
	{
		NodePoint p = NULL;
		NodePoint op =otherS.top;
		NodePoint s;
		top = NULL;
		while(op)
		{
			s = new LinkNode;
			assert(s != 0);
			s->data = op->data;
			if(!top)
				top=s;
			else
				p->next = s;
			p = s;
			op = op->next;
		}
		if(p)
			p->next = NULL;
	}
template <typename Elem>
	LinkStack<Elem>  LinkStack<Elem>::operator = (LinkStack <Elem>  otherS)
	{
			NodePoint p = NULL;
		NodePoint op =otherS.top;
		NodePoint s;
		top = NULL;
		while(op)
		{
			s = new LinkNode;
			assert(s != 0);
			s->data = op->data;
			if(!top)
				top=s;
			else
				p->next = s;
			p = s;
			op = op->next;
		}
		if(p)
			p->next = NULL;
		return *this;
	}


template <typename Elem> 
	int	LinkStack<Elem>::getLength()
	{
		NodePoint p = top;
		int i = 0;
		while(p)
		{
			p = p-> next;
			i++;	 
		}
		return i;
	}

template <typename Elem> 
	void	LinkStack<Elem> :: clear(){

		NodePoint p;
				while(top){
					p = top -> next;
					delete top ; 
					top = p;

				}


		top = NULL;
	}





template <typename Elem> 
	bool LinkStack<Elem> :: getTop(Elem  &e){


		e = top -> data;

	}



template <typename Elem> 
	bool LinkStack<Elem> :: isEmpty(){
		if( top == NULL )
			return TRUE;
		return FALSE;

	}


template <typename Elem> 
	bool LinkStack<Elem> :: pop(Elem &e){

		if (top == NULL )
			return FALSE;

		e = top -> data;
		NodePoint p;
		p = top -> next;
		delete top ; 
		top = p;

		return TRUE;

	}



template <typename Elem> 
	bool LinkStack<Elem> :: push(Elem e){
		NodePoint p;
		p = new LinkNode;
		p -> data = e;
		p -> next = top;
		top = p;

	}

#endif
