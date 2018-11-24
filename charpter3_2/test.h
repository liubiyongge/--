/*************************************************************************
    > File Name: test.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Sat 24 Nov 2018 09:20:02 AM CST
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

template <typename Elem>
void ex3_1_1(LinkStack<Elem> &S)
{
	cout << "** 在栈顶压入元素e***\n";
	
	Elem e;
	cout << "请输入压到栈顶元素的数值：";
	cin >> e;
	S.push(e);
	cout << "压入元素" << e << "后新的栈为:\n";
	S.show();
	cout << "*******************\n";
}

template <typename Elem>
void ex3_1_2(LinkStack<Elem> &S)
{
	cout << "**弹出栈顶元素到e***\n";
	Elem e;
	S.pop(e);
	cout<<"弹出栈顶元素为:"<< e << endl;
	cout << "弹出栈顶元素后，新的栈为：\n";
	S.show(); 
	cout << "*******************\n";
}


template <typename Elem>
void ex3_1_3(LinkStack<Elem> &S)
{
	cout << "**读栈顶元素***\n";
	Elem e;
	S.getTop(e);
	cout << "栈顶元素为:" << e << endl;
	cout << "*******************\n";
}


template <typename Elem>
void ex3_1_4(LinkStack<Elem> &S)
{
	cout << "**判读链栈是否为空***\n";
	if(S.isEmpty())
		cout << "链栈为空\n";
	else
		cout << "链栈不为空'\n";

	cout << "*******************\n";
}


template <typename Elem>
void ex3_1_5(LinkStack<Elem> &S)
{
	cout << "**求链栈中元素的个数***\n";
	cout << "链栈中元素的个数为" << S.getLength() << endl;
	cout << "*******************\n";
}

template <typename Elem>
void ex3_1_6(LinkStack<Elem> &S)
{
	cout << "***把一个链栈赋值给另一个链栈**\n";
	LinkStack<int> S1;
	S1 = S;
	cout << "当前链栈赋值给另一个链栈为:\n";
	S1.show();
	cout << "*******************\n";
}


template <typename Elem>
void ex3_1_7(LinkStack<Elem> &S)
{
	cout << "**把链栈置空***\n";
	S.clear();
	cout << "当前链栈元素个数为:" << S.getLength() << endl ;
	cout << "*******************\n";
}

template <typename Elem>
void ex3_1_8(LinkStack<Elem> &S)
{
	cout << "**随机生成链栈***\n";
	S.clear();
	int i = rand()%20; //结点个数
	Elem e;
	for(int j=1; j <= i; j++)
	{
		e = rand()%500 + 1;
		S.push(e);
	}
	cout << "随机生成链栈为:" << endl;
	S.show();
	cout << "*******************\n";
}



template <typename Elem>
void ex3_1_9(LinkStack<Elem> &S)
{
	cout << "**用已有的链栈初始化另一个链栈***\n";
	LinkStack<int> S1(S);
	cout << "当前链栈初始化另一个链栈为:\n";
	S1.show();
	cout << "*******************\n";
}

#endif
