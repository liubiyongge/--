#ifndef SQQUEUE_H_INCLUDE
#define SQQUEUE_H_INCLUDE

#include "myhead.h"

/*循环循环顺序队列数据结构的C++声明（基类）*/
template<typename ElementType>
class SqQueue
{
public:

	/*把循环队列置空*/
	void clear();

	/*出队列*/
	Status deQueue(ElementType& e);

	/*入队*/
	Status enQueue(ElementType& e);

	/*取队头元素*/
	Status getFront(ElementType& e);

	/*求循环循环顺序队列中元素个数*/
	int getLength() const;

	/*判断循环循环顺序队列是否为空*/
	bool IsEmpty() const;

	/*判断队列是否已满*/
	bool IsFull();

	/*重载赋值运算符的定义*/
	SqQueue<ElementType>& operator = (const SqQueue<ElementType>& rightQ);

	/***********下面是系统自动调用的构造函数和析构函数的声明************/

	/*构造函数*/
	SqQueue(int size=10 );

	/*析构函数*/
	virtual ~SqQueue();

	/*拷贝构造函数*/
	SqQueue(const SqQueue<ElementType>& otherQ);

protected:
	int rear;				//队尾下标
	int front;				//队头下标
	int queueSize;			//循环循环顺序队列最大存储空间
	ElementType *base;		//循环循环顺序队列首地址
};

/*把循环队列置空,只是清除元素，不回收空间*/
template<typename ElementType>
void SqQueue<ElementType>::clear()
{
	rear = front;

}

/*出队列*/
template<typename ElementType>
Status SqQueue<ElementType>::deQueue(ElementType& e)
{
	if (IsEmpty())
		return ERROR;
	else
		e = base[front];
	front = (front + 1) % queueSize;		//队头下标加一
	return OK;
}

/*入队*/
template<typename ElementType>
Status SqQueue<ElementType>::enQueue(ElementType& e)
{
	if (IsFull())
		return ERROR;
	else
		base[rear] = e;
	rear = (rear + 1) % queueSize;
	return OK;
}

/*取队头元素*/
template<typename ElementType>
Status SqQueue<ElementType>::getFront(ElementType& e)
{
	if (IsEmpty())
		return ERROR;
	else
		e = base[front];
	return OK;

}

/*求循环循环顺序队列中元素个数*/
template<typename ElementType>
int SqQueue<ElementType>::getLength() const
{
	return (rear - front + queueSize) % queueSize;			//不能是(rear - front) % queueSize,否则可能会得出负数
}

/*判断循环循环顺序队列是否为空*/
template<typename ElementType>
bool SqQueue<ElementType>::IsEmpty() const
{
	return rear == front;
}

/*判断队列是否已满*/
template<typename ElementType>
bool SqQueue<ElementType>::IsFull()
{
	return (rear + 1) % queueSize == front;
}

/*重载赋值运算符的定义*/
template<typename ElementType>
SqQueue<ElementType>& SqQueue<ElementType>::operator = (const SqQueue<ElementType>& rightQ)
{
	if (this != &rightQ)
	{
		if (queueSize != rightQ.queueSize)		//最大存储空间不等的话，释放原来的空间，重新分配空间
		{
			delete[] base;
			base = new ElementType[rightQ.getLength()];
			assert(base != NULL);
			queueSize = rightQ.queueSize;

		}
		front = rightQ.front;
		rear = rightQ.rear;


		for (int i = front; i != rear; i = (i + 1) % queueSize)
			base[i] = rightQ.base[i];

	}

	return *this;
}


/*构造函数*/
template<typename ElementType>
SqQueue<ElementType>::SqQueue(int size = 10)
{
	base = new ElementType[size];
	assert(base != NULL);

	front = rear = 0;
	queueSize = size;
}

/*析构函数*/
template<typename ElementType>
SqQueue<ElementType>::~SqQueue()
{
	delete[] base;
}

/*拷贝构造函数*/
template<typename ElementType>
SqQueue<ElementType>::SqQueue(const SqQueue<ElementType>& rightQ)
{

	base = NULL;
	base = new ElementType[rightQ.getLength()];
	assert(base != NULL);
	queueSize = rightQ.queueSize;


	front = rightQ.front;
	rear = rightQ.rear;


	for (int i = front; i != rear; i = (i + 1) % queueSize)
		base[i] = rightQ.base[i];

}



#endif
