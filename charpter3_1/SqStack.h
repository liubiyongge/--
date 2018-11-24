/*************************************************************************
    > File Name: SqStack.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Fri 23 Nov 2018 09:52:18 AM CST
 ************************************************************************/

#ifndef _SQSTACK_H
#define _SQSTACK_H
//SqStack class , squence store
template <typename T>
class SqStack
{
	public:
		void clear();
		int getLength();
		bool isEmpty();
		void push(T e);
		Status pop(T &e);
		Status getTop(T &e);
		SqStack<T> operator = (SqStack<T> rightL);
		//****************tmp**************8
		void show();
		//*******自动调用函数************
		// initial function
		SqStack();
		//destory function
		~SqStack();
		//copy function
		SqStack(const SqStack<T>& rightL);

	protected:
		T* base;
		T* top;
		int StackSize;
};

template<typename T>
void SqStack<T>::show()
{
	T* p ;
	for(p = base;p < top;  p++)
		cout  << setw(7) << *p;
	cout << endl;
	cout << "     |";
	for(int i=0; i < 7*(top-base) + 3; i++)
		cout << ' ';
	cout << '|';
	cout << endl;
	cout << "   base";
	for(int i=0; i < 7*(top-base) -1; i++)
		cout << ' ';
	cout << "  top" << endl;
}

template<typename T>
void SqStack<T>::clear()
{
	if(base)
		delete []base;
	base = top = NULL;
	StackSize = 0;
}

template<typename T>
int SqStack<T>::getLength()
{
	return top - base;
}

template<typename T>
bool SqStack<T>::isEmpty()
{
	if(base == top)
		return 1;
	return 0;
}

template<typename T>
void SqStack<T>::push(T e)
{

	if((top - base) >= StackSize - 1)
	{
		int length = top - base;
		base = (T  *)realloc(base, (StackSize + StackIncrement) * sizeof(T));
		assert(base != 0);
		top = base + length;
		StackSize += StackIncrement;
	}
	*top++ = e;
}
template<typename T>
Status SqStack<T>::pop(T &e)
{
	if(base == top)
		return ERROR;
	e = *(--top);
	return OK;

}

template<typename T>
Status SqStack<T>::getTop(T &e)
{
	if(base == top)
		return ERROR;
	e = *(top - 1);
	return OK;

}

template<typename T>
SqStack<T> SqStack<T>:: operator = (SqStack<T> rightL)
{
	clear();
	int length = rightL.top - rightL.base;
	StackSize = rightL.StackSize;
	base = new T[StackSize];
	assert(base !=0 );
	for(int i=0; i < length; i++)
		*(base + i) = *(rightL.base + i);
	top = base + length;
	return *this;
}
//*********自动调用函数************

template <typename T>
SqStack<T>::SqStack()
{
	top = base = new T[StackMaxSize];
	assert(top != 0);
	StackSize = StackMaxSize;
}


template <typename T>
SqStack<T>::~SqStack()
{
	if(base)
		delete []base;
	base = top = NULL;
	StackSize = 0;
}

template <typename T>
SqStack<T>::SqStack(const SqStack<T>& rightL)
{
	int length = rightL.top - rightL.base;
	StackSize = rightL.StackSize;
	base = new T[StackSize];
	assert(base !=0 );
	for(int i=0; i < length; i++)
		*(base + i) = *(rightL.base + i);
	top = base + length;
}
#endif
