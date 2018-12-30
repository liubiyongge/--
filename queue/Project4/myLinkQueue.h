#ifndef MYLINKQUEUE_H
    #define MYLINKQUEUE_H
    #include "linkQueue.h"
template <typename elemtype>
class myLinkQueue:public linkQueue<elemtype>
{
public:
    void display(ostream& out) const;

    void getByRand(int display);

    // void read(istream& in);
};

template <typename elemtype>
void myLinkQueue<elemtype>::getByRand(int display)
{
    this->clear();
    int n = rand() % 6 + 1;
    
    if(display)
        cout << " ";

   // fei(1, n)
	for(int i = 1; i <= n; i++)
    {
        int tmp = rand() % 100;
        if(display)
            cout << " " << tmp;
        this->enQueue(tmp);
    }
    if(display)
        cout << endl;
}

template <typename elemtype>
void myLinkQueue<elemtype>::display(ostream& out) const
{
    int n = 0;
    out << " ";
    typename myLinkQueue<elemtype>::nodeP tmp = this->front;
    while(tmp != this->rear)
    {
        n++;
        out.width(5);
        out.fill(' ');
        out.setf(ios::right, ios::adjustfield);
        out << tmp->data;
        out << "¡ú";
        tmp = tmp->next;
    }
    out.width(5);
    out.fill(' ');
    out.setf(ios::right, ios::adjustfield);
    out << tmp->data << endl;
    n++;

    out << "    ¡ü";
  //  fei(1, n - 2)
	for(int i = 1; i <= n-2; i++)
        out << "      ";
    out << "     ¡ü" << endl;
    out << " front";
	for(int i = 1; i <= n-2; i++)
    //fei(1, n - 2)
        out << "      ";
    out << "  rear" << endl;
}

template <typename elemtype>
ostream& operator <<(ostream& out, const myLinkQueue<elemtype>& x)
{
    x.display(out);
    return out;
}
/*
template <typename elemtype>
void myLinkQueue<elemtype>::read(istream& in)
{
}
template <typename elemtype>
istream& operator >>(istream& in, const myLinkQueue<elemtype>& x)
{
    x.read(in);
    return in;
}
*/
#endif
