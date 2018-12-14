/*************************************************************************
    > File Name: sqQueue.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Mon 26 Nov 2018 08:01:19 PM CST
 	> 队列
 ************************************************************************/

#ifndef _SQQUEUE_H
#define _SQQUEUE_H


template <typename T>
class sqQueue
{
public:
	Status enQueue(T e);
	Status deQueue();
	Status getFront(T &e);
	int getLength();
	void clear();
	bool isFull();
	bool isEmpty();

	sqQueue<T> operator = (const sqQueue<T> otherL);
	//***********系统自动调用函数*************

	sqQueue();
	~sqQueue();
	sqQueue(const sqQueue<T> & otherL);

	//******tmp***************
	void show();
protected:
	int queueSize;
	int front;
	int rear;
	T * base;
};

template<typename T>
Status sqQueue<T>::enQueue(T e)
{	
	if(isFull())
		return ERROR;
	base[rear] = e;
	rear = (rear+1)%queueSize;
	return OK;
}

template<typename T>
Status sqQueue<T>::deQueue()
{
	if(isEmpty())
		return ERROR;
	front = (front + 1)%queueSize;
}

template<typename T>
Status sqQueue<T>::getFront(T &e)
{
	if(isEmpty())
		return ERROR;
	e = base[front];
	return OK;
}

template<typename T>
int sqQueue<T>::getLength()
{
	return (rear - front + queueSize)%queueSize;
}

template<typename T>
void sqQueue<T>::clear()
{
	rear = front = 0;
}

template<typename T>
bool sqQueue<T>::isFull()
{
	if(front == (rear+1)%queueSize)
		return 1;
	return 0;
}



template<typename T>
bool sqQueue<T>::isEmpty()
{
	if(front == rear)
		return 1;
	return 0;
}


template<typename T>
sqQueue<T> sqQueue<T>::operator = (const sqQueue<T> otherL)
{
	clear();

	base = new T[otherL.queueSize];
	queueSize = otherL.queueSize;
	front = otherL.front;
	rear = otherL.rear;
	int i = otherL.front;
	while(i != otherL.rear)
	{
		base[i] = otherL.base[i];
		i = (i+1)%queueSize;
	}
	return *this;
}


//***********系统自动调用函数*************
template<typename T>
sqQueue<T>::sqQueue()
{
	base = new T[QueueSize];
	assert(base != 0);
	rear = front = 0;
	queueSize =QueueSize;

}

template<typename T>
sqQueue<T>::~sqQueue()
{
	delete []base;
}

template<typename T>
sqQueue<T>::sqQueue(const sqQueue<T> & otherL)
{
	base = new T[otherL.queueSize];
	queueSize = otherL.queueSize;
	front = otherL.front;
	rear = otherL.rear;
	int i = otherL.front;
	while(i != otherL.rear)
	{
		base[i] = otherL.base[i];
		i = (i+1)%queueSize;
	}
}

//%%%%%%%%%%%%%%%%tmp%%%%%%%%%%%%%555
template<typename T>
void sqQueue<T>::show()
{
	int i = front;
	while(i != rear)
	{
		cout << base[i] << endl;
		i = (i+1)%queueSize;
	}
}

#endif