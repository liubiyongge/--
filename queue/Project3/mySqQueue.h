#ifndef MYSQQUEUE_H
    #define MYSQQUEUE_H
    #include "SqQueue.h"
template <typename elemtype>
class mySqQueue:public SqQueue<elemtype>
{
public:
    void display();

    void getByRand(int display);

};

template <typename elemtype>
void mySqQueue<elemtype>::getByRand(int display)
{
    this->clear();

    int n = rand() % 8 + 1;
    int array[10];
	for(int i=0;i<= n - 1;i++)
    {
        array[i] = rand() % 100;
        if(display)
        {
            cout.width(5);
            cout.fill(' ');
            cout << array[i];
        }
        this->enQueue(array[i]);
    }
    if(display)
        cout << endl;
}

template <typename elemtype>
void mySqQueue<elemtype>::display()
{
    for(int j=1;j<=this->queueSize;j++)
        cout << " [" << setw(2) << j << "]";
    cout << endl;
    int rear = this->rear;
    int front = this->front;
    if(rear < front)
    {
        for(int i=0;i<= this->queueSize - 1;i++)
        {
            cout.width(5);
            cout.fill(' ');
            if(i < rear)
                cout << this->base[i];
            else if(i < front)
                cout << ' ';
            else
                cout << this->base[i];
        }
    }
    else
    {
        for(int i=0;i<=this->queueSize - 1;i++)
        {
            cout.width(5);
            cout.fill(' ');
            if(i < front)
                cout << ' ';
            else if(i < rear)
                cout << this->base[i];
            else
                cout << ' ';
        }
    }
    cout << endl;
    
    for(int i=0;i<= this->queueSize - 1;i++)
    {
        if(i == rear || i == front)
            cout << "   ↑ ";
        else
        {
            cout.width(5);
            cout.fill(' ');
            cout << ' ';
        }
    }
    cout << endl;

    for(int i=0;i<=this->queueSize - 1;i++)
    {
        cout.width(5);
        cout.fill(' ');
        if(i == rear)
            cout << " rear";
        else if(i == front)
            cout << " front";
        else
            cout << ' ';
    }
    cout << endl;
}

#endif